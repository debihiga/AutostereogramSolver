#include "solver.h"
#include "image.h"

#define BLOCK_SIZE  4

void Solver::get_disparity_map(Mat image_left, Mat image_right) {

    tx_map = Mat::zeros(image_left.size().height, image_left.size().width, CV_8U);
    Mat image_left_gray;
    cvtColor(image_left, image_left_gray, CV_BGR2GRAY);

    int tx_min_min=max_disparity;
    bool abort = false;
    for(int row=0; row<image_left.rows-BLOCK_SIZE; row=row+BLOCK_SIZE) {
        for(int col=0; col<image_left.cols-BLOCK_SIZE-max_disparity; col=col+BLOCK_SIZE) {

            mutex_finish.lock();
            abort = _finish;
            mutex_finish.unlock();
            if(abort) {
                break;
            }

            Mat block_left_gray = image_left_gray(Rect(col, row, BLOCK_SIZE, BLOCK_SIZE));
            if((int)mean(block_left_gray)[0]>0) { // Analiza solo si no es el fondo negro.

                Mat block_left = image_left(Rect(col, row, BLOCK_SIZE, BLOCK_SIZE));

                int mean_min=255;
                int tx_min=0;
                int _mean;
                for(int tx=max_disparity*0.2; tx<max_disparity; tx++) {
                    Mat block_right = image_right(Rect(col+tx, row, BLOCK_SIZE, BLOCK_SIZE));
                    // Absolute difference between images.
                    Mat difference;
                    absdiff(block_left, block_right, difference);   // This must be done with colored images.
                    // Get mean of difference.
                    Mat gray;
                    cvtColor(difference, gray, CV_BGR2GRAY);
                    //emit show_image_right(QPixmap::fromImage(matGray2QImage(resize_image(&gray))));
                    _mean = (int)mean(gray)[0];
                    if(_mean<mean_min) {
                        mean_min = _mean;
                        tx_min = tx;
                    }

                }
                if(mean_min>0 && tx_min>max_disparity*0.2) {
                    if(tx_min<tx_min_min) {
                        tx_min_min = tx_min;
                    }
                    tx_map(Rect(col+tx_min, row,
                              BLOCK_SIZE, BLOCK_SIZE)) = tx_min;
                    emit show_image_map_depth(QPixmap::fromImage(matGray2QImage(resize_image(&tx_map))));
                }
            }
        }
    }

    if(!abort) {
        emit set_slider_minimum(int(tx_min_min));
        emit set_slider_maximum(int(max_disparity));
        emit set_slider_value(int(tx_min_min));
        emit set_slider_enabled();
    }
}

void Solver::change_disparity_map_grayscale(int _min) {

    double min = _min;
    double max = max_disparity;
    double b = 255/(1-(min/max));
    double a = -b/max;

    Mat disparity_map = Mat::zeros(tx_map.size().height, tx_map.size().width, CV_8U);
    for(int row=0; row<disparity_map.rows; row++) {
        for(int col=0; col<disparity_map.cols; col++) {
            unsigned char x = tx_map.at<unsigned char>(row, col);
            if(x!=0) {
                unsigned char y = a*x+b;
                disparity_map(Rect(col, row, 1, 1)) = y;
            }
        }
    }

    /*
    int i = 8;
    // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#getstructuringelement
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, cv::Size(2*i+1, 2*i+1));
        // shape=MORPH_ELLIPSE -> smoothed results.
        // ksize=cv::Size(2*i+1, 2*i+1)
    // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#morphologyex
    morphologyEx(disparity_map, disparity_map,
                 MORPH_CLOSE, kernel, Point(-1,-1), 1);
        // op=MORPH_CLOSE -> dst=close(src,element)=erode(dilate(src,element))
        // anchor=Point(-1, -1) -> Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.
        // iterations=1
    */
    emit show_image_map_depth(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map))));

}
