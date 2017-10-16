#include "solver.h"
#include "image.h"
#include "opencv_disparity_filtering.h"
#include <QThread>

unsigned int getNextDivisibleBy16(unsigned int n);

void Solver::method_1() {

    // Get mask.
    Mat mask = find_mask_1();

    if(countNonZero(mask)>1) {

        // Get image right.
        Mat image_right = apply_mask(autostereogram, mask);
        imwrite("imgs/out/6_image_right.jpg", image_right);
        emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));

        // Get image left.
        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, disparity_max, 0, 1, 0);
        Mat autostereogram_shifted_2_right;
        warpAffine(autostereogram, autostereogram_shifted_2_right, transformation_matrix, autostereogram.size());
        Mat image_left = apply_mask(autostereogram_shifted_2_right, mask);
        transformation_matrix = (Mat_<double>(2, 3) << 1, 0, -((int)disparity_max), 0, 1, 0);
        warpAffine(image_left, image_left, transformation_matrix, autostereogram.size());
        imwrite("imgs/out/7_image_left.jpg", image_left);
        emit show_image_left(QPixmap::fromImage(matRGB2QImage(resize_image(&image_left))));

        /*
        // https://docs.opencv.org/3.1.0/d3/d14/tutorial_ximgproc_disparity_filtering.html
        image_left = imread("imgs/test/ambush_5_left.jpg",IMREAD_COLOR);
        image_right = imread("imgs/test/ambush_5_right.jpg",IMREAD_COLOR);
        disparity_map = opencv_disparity_filter(image_left, image_right,
                                                "bm", "wls_no_conf",
                                                false,
                                                1.0, 160, -1,
                                                8000.0, 1.5);
        */
        ///*
        ///*
        transformation_matrix = (Mat_<double>(2, 3) << 1, 0, disparity_max/2, 0, 1, 0);
        warpAffine(image_right, image_right, transformation_matrix, autostereogram.size());
        transformation_matrix = (Mat_<double>(2, 3) << 1, 0,  -((int)disparity_max/2), 0, 1, 0);
        warpAffine(image_left, image_left, transformation_matrix, autostereogram.size());
        ///*/
        // Get disparity map.
        disparity_map = opencv_disparity_filter(image_right,image_left,
                                                "bm", "wls_no_conf",
                                                false,
                                                1.0, 160, 7,
                                                8000.0, 1.5);
        //*/
        imwrite("imgs/out/disparity_map.jpg", disparity_map);
        double min, max;
        cv::minMaxLoc(disparity_map, &min, &max);
        qDebug() << "min"<<min;
        qDebug() <<"max"<<max;
        set_depth_map();
        emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map))));
    }

}

#define THRESHOLD           60
#define BORDER_SIZE         10  // Parameter specifying how many pixels in each direction from the source image rectangle to extrapolate. For example, top=1, bottom=1, left=1, right=1 mean that 1 pixel-wide border needs to be built.
#define KERNEL_SIZE_MAX     15  // As it must be odd -> if KERNEL_SIZE_MAX=15 -> 2*KERNEL_SIZE_MAX+1 -> max_real=2*15+1=31
#define CLOSING_N_MAX       1   // Max number of closing iterations.

/*
 * find_mask
 *
 * + image_in: autostereogram shifted.
 * + mask: difference in grayscale between the autostereogram
 * and itself shifted the size of the pattern to the right.

 */
Mat Solver::find_mask_1() {

    Mat mask = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
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
            difference(Rect(0,0,disparity_max,autostereogram_grayscale.size().height))=0;    // Don't show back image.
            //shifted.copyTo(*shifted_out);
            difference.copyTo(mask);
        }

        emit show_image_left(QPixmap::fromImage(matGray2QImage(resize_image(&difference))));
        //QThread::msleep(40);
    }

    if(abort) {
        return Mat::zeros(autostereogram_grayscale.rows, autostereogram_grayscale.cols, CV_8UC1);
    } else {

        imwrite("imgs/out/1_mask_initial.jpg", mask);

        // Threshold (remove background from noisy images).
        Mat mask_thresholded;
        threshold(mask, mask_thresholded, THRESHOLD, 255, CV_THRESH_BINARY);
            // maxval = 255
        imwrite("imgs/out/2_mask_thresholded.jpg", mask_thresholded);

        // Add zero border to reduce the effects on borders.
        Mat mask_thresholded_bordered;
        copyMakeBorder(mask_thresholded, mask_thresholded_bordered,
                       BORDER_SIZE, BORDER_SIZE, BORDER_SIZE, BORDER_SIZE,
                       BORDER_CONSTANT, Scalar(0));
        imwrite("imgs/out/3_mask_thresholded_bordered.jpg", mask_thresholded_bordered);

        // Close.
        for(int i=1; i<KERNEL_SIZE_MAX; i++) {
            // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#getstructuringelement
            Mat kernel = getStructuringElement(MORPH_ELLIPSE, cv::Size(2*i+1, 2*i+1));
                // shape=MORPH_ELLIPSE -> smoothed results.
                // ksize=cv::Size(2*i+1, 2*i+1)
            // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#morphologyex
            morphologyEx(mask_thresholded_bordered, mask_thresholded_bordered,
                         MORPH_CLOSE, kernel, Point(-1,-1), CLOSING_N_MAX);
                // op=MORPH_CLOSE -> dst=close(src,element)=erode(dilate(src,element))
                // anchor=Point(-1, -1) -> Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.
                // iterations=CLOSING_N_MAX
        }
        imwrite("imgs/out/4_mask_thresholded_bordered_closed.jpg", mask_thresholded_bordered);

        // Remove border.
        mask = mask_thresholded_bordered(Rect(BORDER_SIZE, BORDER_SIZE, mask.cols, mask.rows));
        imwrite("imgs/out/5_mask.jpg", mask);

    }

    return mask;
}

void Solver::set_depth_map_1() {

    qDebug() <<disparity_map.type() ;
    Mat depth_map = Mat::zeros(disparity_map.size().height, disparity_map.size().width, CV_8U);
    for(int row=0; row<depth_map.rows; row++) {
        for(int col=0; col<depth_map.cols; col++) {
            unsigned char disparity = disparity_map.at<unsigned char>(row, col);
            if(disparity!=0) {
                unsigned char depth = (5000)/((double)disparity);
                //qDebug() << depth ;
                depth_map(Rect(col, row, 1, 1)) = depth;
            }
        }
    }
    emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&depth_map))));
}

unsigned int getNextDivisibleBy16(unsigned int n) {
    while(n%16!=0) {
        n++;
    }
    return n;
}
