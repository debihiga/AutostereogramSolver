#include "solver.h"
#include "image.h"

#define BLOCK_SIZE_1  4
#define BLOCK_SIZE_2  16

void Solver::method_4() {

    disparity_max = get_max_disparity();
    if(disparity_max!=-1) {
        get_disparity_map_4();
    }
}

void Solver::get_disparity_map_4() {

    Mat autostereogram_gray;
    cvtColor(autostereogram, autostereogram_gray, CV_BGR2GRAY);

    disparity_map = Mat::zeros(autostereogram_gray.size().height, autostereogram_gray.size().width, CV_32S);
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
            unsigned int disparity = get_disparity_4(block, epipolar_row, BLOCK_SIZE_2);

            if(disparity!=0 && disparity<disparity_max-1) {

                unsigned int row_max = row+BLOCK_SIZE_2;
                unsigned int col_max = col+BLOCK_SIZE_2;
                for(unsigned int subrow=row; subrow<=row_max-BLOCK_SIZE_1; subrow=subrow+BLOCK_SIZE_1) {
                    for(unsigned int subcol=col; subcol<=col_max-BLOCK_SIZE_1; subcol=subcol+BLOCK_SIZE_1) {

                        mutex_finish.lock();
                        abort = _finish;
                        mutex_finish.unlock();
                        if(abort) {
                            break;
                        }

                        Mat block = autostereogram_gray(Rect(subcol, subrow, BLOCK_SIZE_1, BLOCK_SIZE_1));
                        Mat epipolar_row = autostereogram_gray(Rect(subcol, subrow, BLOCK_SIZE_1+disparity_max, BLOCK_SIZE_1));
                        unsigned int disparity = get_disparity_4(block, epipolar_row, BLOCK_SIZE_1);

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

        // Convertion due to format limitation.
        // http://docs.opencv.org/2.4/modules/imgproc/doc/filtering.html?highlight=medianblur#medianblur
        Mat disparity_map_64F;
        disparity_map.convertTo(disparity_map_64F, CV_32F);
        medianBlur(disparity_map_64F, disparity_map_64F, 5);
        disparity_map_64F.convertTo(disparity_map, CV_32S);

        Mat disparity_map_8U;
        disparity_map.convertTo(disparity_map_8U, CV_8U);
        emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map_8U))));
    }

    if(!abort) {
        emit set_slider_minimum(disparity_min);
        emit set_slider_maximum(disparity_max);
        emit set_slider_value(disparity_min);
        set_depth_map();
        emit set_slider_enabled();
    }
}

unsigned int Solver::get_disparity_4(Mat block_left, Mat row_epipolar, int block_size) {
    unsigned int ssd_min = 0xFFFFFFFF;
    unsigned int disparity = 0;
    for(unsigned int tx=disparity_max*0.2; tx<disparity_max && tx<row_epipolar.size().width-block_size; tx++) {
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
            ssd += (diff*diff);
        }
    }
    return ssd;
}
