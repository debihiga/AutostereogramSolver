#include "solver.h"
#include "image.h"
#include "opencv_disparity_filtering.h"

#define BLOCK_SIZE_1  5
#define BLOCK_SIZE_2  16

bool change_block_size = true;
bool apply_filter = true;

void Solver::method_2() {

    disparity_max = get_max_disparity_2();
    if(disparity_max!=-1) {
        get_disparity_map_2();
    }
}

int Solver::get_max_disparity_2() {

    bool abort;

    // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html
    int tx_i = autostereogram.size().width*0.1;
    int tx_f = autostereogram.size().width*0.9;
    int sad_min = 255*autostereogram.size().width*autostereogram.size().height;

    Mat autostereogram_grayscale;
    cvtColor(autostereogram, autostereogram_grayscale, CV_BGR2GRAY);

    for(int tx=tx_i; tx<tx_f; tx++) {

        mutex_finish.lock();
        abort = _finish;
        mutex_finish.unlock();
        if(abort) {
            break;
        }

        // Translation.
        // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html#translation
        Mat shifted;
        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, 0);
        warpAffine(autostereogram_grayscale, shifted, transformation_matrix, autostereogram_grayscale.size());

        // Absolute difference between images.
        Mat difference;
        absdiff(autostereogram_grayscale, shifted, difference);   // This must be done with colored images.

        // SAD (Sum of Absolute Differences).
        double sad = sum(difference)[0];

        if(sad<sad_min) {
            sad_min = sad;
            disparity_max = tx;
        }

        emit show_image_left(QPixmap::fromImage(matGray2QImage(resize_image(&shifted))));
        //QThread::msleep(40);
    }

    if(abort) {
        return -1;
    }

    return disparity_max;
}

void Solver::get_disparity_map_2() {

    Mat autostereogram_gray;
    cvtColor(autostereogram, autostereogram_gray, CV_BGR2GRAY);

    disparity_map = Mat::zeros(autostereogram_gray.size().height, autostereogram_gray.size().width, CV_32S);
        // 32S -> medianBlur
    disparity_min = disparity_max;

    bool abort;
    for(unsigned int row=0; row<autostereogram_gray.rows-BLOCK_SIZE_2; row=row+BLOCK_SIZE_2) {
        for(unsigned int col=0; col<autostereogram_gray.cols-BLOCK_SIZE_2-disparity_max; col=col+BLOCK_SIZE_2) {
                                                            // ^ sino toma el borde derecho.
            mutex_finish.lock();
            abort = _finish;
            mutex_finish.unlock();
            if(abort) {
                break;
            }

            Mat block = autostereogram_gray(Rect(col, row, BLOCK_SIZE_2, BLOCK_SIZE_2));
            Mat epipolar_row = autostereogram_gray(Rect(col, row, BLOCK_SIZE_2+disparity_max, BLOCK_SIZE_2));
            unsigned int disparity = get_disparity_2(block, epipolar_row, BLOCK_SIZE_2);

            if(!change_block_size) {
                if(disparity<disparity_max-1) {
                    if(disparity<disparity_min) {
                        disparity_min = disparity;
                    }
                    disparity_map(Rect(col, row,
                              BLOCK_SIZE_2, BLOCK_SIZE_2)) = (int)disparity;
                }
            } else {
                if(disparity!=0 && disparity<disparity_max-1) {

                    unsigned int row_max = row+BLOCK_SIZE_2;
                    unsigned int col_max = col+BLOCK_SIZE_2;
                    for(unsigned int subrow=row; subrow<=row_max-BLOCK_SIZE_1; subrow++) {
                        for(unsigned int subcol=col; subcol<=col_max-BLOCK_SIZE_1; subcol++) {

                            mutex_finish.lock();
                            abort = _finish;
                            mutex_finish.unlock();
                            if(abort) {
                                break;
                            }

                            Mat block = autostereogram_gray(Rect(subcol, subrow, BLOCK_SIZE_1, BLOCK_SIZE_1));
                            Mat epipolar_row = autostereogram_gray(Rect(subcol, subrow, BLOCK_SIZE_1+disparity_max, BLOCK_SIZE_1));
                            unsigned int disparity = get_disparity_2(block, epipolar_row, BLOCK_SIZE_1);

                            if(disparity>disparity_max*0.7 && disparity<disparity_max-1) {
                                if(disparity<disparity_min) {
                                    disparity_min = disparity;
                                }
                                disparity_map(Rect(subcol, subrow,
                                          BLOCK_SIZE_1, BLOCK_SIZE_1)) = (int)disparity;
                            }
                        }
                    }
                }
            }
        }

        // Convertion due to format limitation.
        // http://docs.opencv.org/2.4/modules/imgproc/doc/filtering.html?highlight=medianblur#medianblur

        Mat disparity_map_8U;
        disparity_map.convertTo(disparity_map_8U, CV_8U);
        emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map_8U))));
    }

    if(!abort) {


        if(apply_filter) {

            /*
            Mat disparity_map_32F;
            disparity_map.convertTo(disparity_map_32F, CV_32F);
            medianBlur(disparity_map_32F, disparity_map_32F, 5);
            disparity_map_32F.convertTo(disparity_map, CV_32S);
            */
            ///*
            Mat mask = find_mask_1();

            // Get image right.
            Mat image_left = apply_mask(autostereogram, mask);
            emit show_image_left(QPixmap::fromImage(matRGB2QImage(resize_image(&image_left))));
            // Get image left.
            Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, disparity_max, 0, 1, 0);
            Mat autostereogram_shifted_2_right;
            warpAffine(autostereogram, autostereogram_shifted_2_right, transformation_matrix, autostereogram.size());
            Mat image_right = apply_mask(autostereogram_shifted_2_right, mask);
            emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));
            transformation_matrix = (Mat_<double>(2, 3) << 1, 0, -((int)disparity_max), 0, 1, 0);
            warpAffine(image_right, image_right, transformation_matrix, autostereogram.size());
            // Filter.
            //disparity_map.convertTo(disparity_map, CV_16S);   // disparity_map_left.depth() == CV_16S
            image_left.convertTo(image_left, CV_8U);
            Mat disparity_map_filtered;
            Mat disparity_map_16S;
            disparity_map.convertTo(disparity_map_16S, CV_16S);   // disparity_map_left.depth() == CV_16S
            filter(disparity_map_16S, image_right,
                        BLOCK_SIZE_1, 8000.0, 1.5,
                        &disparity_map_filtered);
            disparity_map_filtered.convertTo(disparity_map, CV_32S);

            Mat disparity_map_8U;
            disparity_map.convertTo(disparity_map_8U, CV_8U);
            emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map_8U))));

        }
        //*/

        imwrite("imgs/out/disparity_map.jpg", disparity_map);

        ///*
        //emit set_slider_minimum(disparity_min);
        //emit set_slider_maximum(disparity_max);
        //emit set_slider_value(disparity_min);
        set_depth_map();
        //emit set_slider_enabled();
        //*/
    }
}

unsigned int Solver::get_disparity_2(Mat block_left, Mat row_epipolar, int block_size) {
    unsigned int ssd_min = 0xFFFFFFFF;
    unsigned int disparity = 0;
    for(unsigned int tx=disparity_max*0.2; tx<disparity_max && tx<row_epipolar.size().width-block_size; tx++) {
        //           ^ evita las zonas de interseccion como ocurrian con StereoBM.
        Mat block_right = row_epipolar(Rect(tx, 0, block_size, block_size));
        unsigned int ssd = get_blocks_SSD(block_left, block_right);
        if(ssd<ssd_min) {
            ssd_min = ssd;
            disparity = tx;
        }
    }
    return disparity;
}

unsigned int Solver::get_blocks_SSD(Mat block_left, Mat block_right) {
    unsigned int ssd = 0;
    for(unsigned int row=0; row<block_left.rows; row++) {
        for(unsigned int col=0; col<block_left.cols;  col++) {
            int diff = block_left.at<unsigned char>(row, col) - block_right.at<unsigned char>(row, col);
            ssd += (diff*diff);   // SSD
            //ssd += abs(diff);       // SAD
        }
    }
    return ssd;
}

void Solver::filter(Mat disparity_map_left, Mat left_view,
            int depth_discontinuity_radius, double lambda, double sigma,
            Mat *filtered_disparity_map) {
    // http://docs.opencv.org/3.1.0/da/d17/group__ximgproc__filters.html#gad79c31494e3bb92d4b30e0dcefae1249
    Ptr<DisparityWLSFilter> wls_filter = createDisparityWLSFilterGeneric(false);
        /* use_confidence = false
         * Filtering with confidence requires two disparity maps (for the left and right views)
         * and is approximately two times slower.
         * However, quality is typically significantly better.
         */
        /*
         * createDisparityWLSFilter
         * Currently supports only StereoBM and StereoSGBM.
         */
    wls_filter->setDepthDiscontinuityRadius(depth_discontinuity_radius);
        /* DepthDiscontinuityRadius is a parameter used in confidence computation.
         * It defines the size of low-confidence regions around depth discontinuities.
         */
    wls_filter->setLambda(lambda);
        /* Lambda is a parameter defining the amount of regularization during filtering.
         * Larger values force filtered disparity map edges to adhere more to source image edges.
         * Typical value is 8000.
         */
    wls_filter->setSigmaColor(sigma);
        /* SigmaColor is a parameter defining how sensitive the filtering process is to source image edges.
         * Large values can lead to disparity leakage through low-contrast edges.
         * Small values can make the filter too sensitive to noise and textures in the source image.
         * Typical values range from 0.8 to 2.0.
         */
    wls_filter->filter(disparity_map_left, left_view, *filtered_disparity_map);
        /* Apply filtering to the disparity map.
         * Parameters
         * + disparity_map_left:
         *      disparity map of the left view, 1 channel, CV_16S type.
         *      Implicitly assumes that disparity values are scaled by 16 (one-pixel disparity corresponds to the value of 16 in the disparity map).
         *      Disparity map can have any resolution, it will be automatically resized to fit left_view resolution.
         * + left_view:
         *      left view of the original stereo-pair to guide the filtering process, 8-bit single-channel or three-channel image.
         * + filtered_disparity_map:
         *      output disparity map.
         * + disparity_map_right:
         *      optional argument, some implementations might also use the disparity map of the right view to compute confidence maps, for instance.
         * + ROI:
         *      region of the disparity map to filter.
         *      Optional, usually it should be set automatically.
         * + right_view:
         *      optional argument, some implementations might also use the right view of the original stereo-pair.
         */
}


