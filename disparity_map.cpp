#include "solver.h"
#include "image.h"
#include "disparity_filtering.h"

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

                    /*
                    compare();
                    cvtColor(difference, gray, CV_BGR2GRAY);
                    Mat block_left_float = Mat::zeros(image_left.size().height, image_left.size().width, CV_32F);
                    block_left.convertTo(block_left_float, CV_32FC3);
                    */

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

                }
            }
        }
        emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&tx_map))));
    }

    if(!abort) {
        emit set_slider_minimum(int(tx_min_min));
        emit set_slider_maximum(int(max_disparity));
        emit set_slider_value(int(max_disparity));  // Cambio dos veces porque si no se cambio previamente no toma el cambio.
        emit set_slider_value(int(tx_min_min));
        emit set_slider_enabled();
    }
}

#define BLOCK_SIZE_1  4
#define BLOCK_SIZE_2  16
#define BLOCK_SIZE_3  (BLOCK_SIZE_2*2)

int Solver::match_block(Mat block_left, Mat row_right, int block_size) {
    int mean_min = 255;
    int tx_min = 0;
    for(int tx=max_disparity*0.2; tx<max_disparity && tx<row_right.size().width-block_size; tx++) {
        Mat block_right = row_right(Rect(tx, 0, block_size, block_size));
        Mat difference;
        absdiff(block_left, block_right, difference);   // This must be done with colored images.
        Mat gray;
        cvtColor(difference, gray, CV_BGR2GRAY);
        int _mean = (int)mean(gray)[0];
        if(_mean<mean_min) {
            mean_min = _mean;
            tx_min = tx;
        }
    }
    if(mean_min<=0)
        return -1;
    else
        return tx_min;
}

#define MAX_ITERATIONS 0

bool Solver::match_image(int block_size, int n_iteration,
                         int _row_min, int _col_min) {

    int row_min, col_min, row_max, col_max;
    if(n_iteration==0) {
        row_min = 0;
        col_min = 0;
        row_max = autostereogram.rows-block_size;
        col_max = autostereogram.cols-block_size-max_disparity;
    } else {
        row_min = _row_min;
        col_min = _col_min;
        row_max = _row_min+(block_size*2)-block_size;
        col_max = _row_min+(block_size*2)-block_size;
        qDebug() << row_min << " " << row_max;
        qDebug() << block_size;
    }

    for(int row=row_min; row<row_max; row=row+block_size) {
        for(int col=col_min; col<col_max; col=col+block_size) {

            mutex_finish.lock();
            bool abort = _finish;
            mutex_finish.unlock();
            if(abort) {
                return false;
            }

            Mat block = autostereogram(Rect(col, row, block_size, block_size));
            Mat row_match = autostereogram(Rect(col, row, autostereogram.cols-col, block_size));
            int tx_min = match_block(block, row_match, block_size);

            qDebug() << n_iteration;
            qDebug() << "!!!";
            if(n_iteration<MAX_ITERATIONS) {
                if(tx_min>0 && tx_min<max_disparity-1) {
                    abort = match_image(block_size/2, ++n_iteration, row, col);
                    if(abort) {
                        return false;
                    }
                }
            } else {
                if(tx_min<tx_min_min) {
                    tx_min_min = tx_min;
                }
                tx_map(Rect(col+tx_min, row,
                          block_size, block_size)) = tx_min;
            }
        }
            emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&tx_map))));
    }

}

void Solver::get_disparity_map() {

    tx_map = Mat::zeros(autostereogram.size().height, autostereogram.size().width, CV_8U);

    //max_disparity = image_left.size().width;

    tx_min_min=max_disparity;
    //bool abort = match_image(16,0,0,0);

    bool abort;
    for(int row=0; row<autostereogram.rows-BLOCK_SIZE_2; row=row+BLOCK_SIZE_2) {
        for(int col=0; col<autostereogram.cols-BLOCK_SIZE_2-max_disparity; col=col+BLOCK_SIZE_2) {
                                                            // ^ sino toma el borde derecho.
            mutex_finish.lock();
            abort = _finish;
            mutex_finish.unlock();
            if(abort) {
                break;
            }

            Mat block = autostereogram(Rect(col, row, BLOCK_SIZE_2, BLOCK_SIZE_2));
            Mat row_match = autostereogram(Rect(col, row, max_disparity+BLOCK_SIZE_2, BLOCK_SIZE_2));
            int tx_min = match_block(block, row_match, BLOCK_SIZE_2);

            if(tx_min>0 && tx_min<max_disparity-1) {
                //qDebug() << row << " " << col;
                // 80   176 (primer elemento no fondo)
                ///*
                int row_max = row+BLOCK_SIZE_2;
                int col_max = col+BLOCK_SIZE_2;
                for(int subrow=row; subrow<=row_max-BLOCK_SIZE_1; subrow=subrow+BLOCK_SIZE_1) {
                    for(int subcol=col; subcol<=col_max-BLOCK_SIZE_1; subcol=subcol+BLOCK_SIZE_1) {

                        if(row==80 && col==176)
                            qDebug() << subrow << " " << subcol;
                        //80   176
                        //80   184
                        //88   176
                        //88   184

                        mutex_finish.lock();
                        abort = _finish;
                        mutex_finish.unlock();
                        if(abort) {
                            break;
                        }

                        Mat block = autostereogram(Rect(subcol, subrow, BLOCK_SIZE_1, BLOCK_SIZE_1));
                        Mat row_match = autostereogram(Rect(subcol, subrow, max_disparity+BLOCK_SIZE_1, BLOCK_SIZE_1));
                        int subtx_min = match_block(block, row_match, BLOCK_SIZE_1);

                        if(subtx_min>0) {

                            if(subtx_min<tx_min_min) {
                                tx_min_min = subtx_min;
                            }
                //*/
                /*
                        if(tx_min<tx_min_min) {
                            tx_min_min = tx_min;
                        }
                        tx_map(Rect(col, row, BLOCK_SIZE_2, BLOCK_SIZE_2)) = tx_min;
                */
                ///*
                            tx_map(Rect(subcol, subrow,
                                      BLOCK_SIZE_1, BLOCK_SIZE_1)) = subtx_min;
                        }
                        /*
                        else {
                            tx_map(Rect(subcol, subrow,
                                      BLOCK_SIZE_1, BLOCK_SIZE_1)) = 20;
                        }*/
                    }
                }
                //*/
            }
        }

        /*
        Mat tx_map_16s;
        tx_map.convertTo(tx_map_16s, CV_16S);
        filter(autostereogram, tx_map_16s, 1, 4000, 0.8, &tx_map_16s);
        tx_map_16s.convertTo(tx_map, CV_8U);
        */


        /*
        int i = 1;
        // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#getstructuringelement
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, cv::Size(2*i+1, 2*i+1));
            // shape=MORPH_ELLIPSE -> smoothed results.
            // ksize=cv::Size(2*i+1, 2*i+1)
        // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#morphologyex
        morphologyEx(tx_map, tx_map,
                     MORPH_CLOSE, kernel, Point(-1,-1), 1);
            // op=MORPH_CLOSE -> dst=close(src,element)=erode(dilate(src,element))
            // anchor=Point(-1, -1) -> Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.
            // iterations=1
        */
        medianBlur(tx_map, tx_map, 5);
        emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&tx_map))));
    }

    if(!abort) {
        //emit set_slider_minimum(int(tx_min_min));
        //emit set_slider_maximum(int(max_disparity));
        //emit set_slider_value(int(tx_min_min));
        emit set_slider_minimum(0);
        emit set_slider_maximum(255);
        emit set_slider_value(255);

        emit set_slider_enabled();
    }
}


