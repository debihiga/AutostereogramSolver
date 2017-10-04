#include "solver.h"
#include "image.h"

#define BLOCK_SIZE  4

Mat Solver::get_disparity_map(Mat image_left, Mat image_right, int max_disparity) {

    Mat disparity_map = Mat::zeros(image_left.size().height, image_left.size().width, CV_8U);
    Mat image_left_gray;
    cvtColor(image_left, image_left_gray, CV_BGR2GRAY);

    qDebug() << "max disparity" << max_disparity;
    int tx_min_min=max_disparity;
    for(int row=0; row<image_left.rows-BLOCK_SIZE; row=row+BLOCK_SIZE) {
        for(int col=0; col<image_left.cols-BLOCK_SIZE-max_disparity; col=col+BLOCK_SIZE) {

            Mat block_left_gray = image_left_gray(Rect(col, row, BLOCK_SIZE, BLOCK_SIZE));
            if((int)mean(block_left_gray)[0]>0) { // Analiza solo si no es el fondo negro.

                Mat block_left = image_left(Rect(col, row, BLOCK_SIZE, BLOCK_SIZE));

                int mean_min=255;
                int tx_min=0;
                int _mean;
                for(int tx=10; tx<max_disparity; tx++) {
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
                if(mean_min>0 && tx_min>10) {
                    if(tx_min<tx_min_min) {
                        tx_min_min = tx_min;
                    }
                    //qDebug() << "tx_min" << tx_min;
                    //int value = tx_min*255/max_disparity;
                    //qDebug() << "value" << value;
                    disparity_map(Rect(col+tx_min, row,
                              BLOCK_SIZE, BLOCK_SIZE)) = tx_min;
                    emit show_image_map_depth(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map))));
                }
            }
            /*
            Mat block_left = Mat::zeros(image_left.rows, image_left.cols, CV_8UC1);
            Mat mask = Mat::zeros(image_left.rows, image_left.cols, CV_8UC1);
            mask(Rect(col, row, BLOCK_SIZE, BLOCK_SIZE)) = Scalar(255,255,255);
            if((int)mean(image_left_gray, mask)[0]>0) { // Analiza solo si no es el fondo negro.
                image_left.copyTo(block_left, mask);
                int mean_min=255;
                int tx_min=0;
                int _mean;
                for(int tx=10; tx<max_disparity; tx++) {
                    // Translate.
                    Mat block_left_translated;
                    Mat mask_translated;
                    Mat block_right = Mat::zeros(image_right.rows, image_right.cols, CV_8UC1);
                    Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, 0);
                    warpAffine(block_left, block_left_translated, transformation_matrix, autostereogram.size());
                    warpAffine(mask, mask_translated, transformation_matrix, autostereogram.size());
                    image_right.copyTo(block_right, mask);
                    //emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&translated2))));
                    // Absolute difference between images.
                    Mat difference;
                    absdiff(block_left_translated, block_right, difference);   // This must be done with colored images.
                    //emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&difference))));
                    // Get mean of difference.
                    Mat gray;
                    cvtColor(difference, gray, CV_BGR2GRAY);
                    emit show_image_right(QPixmap::fromImage(matGray2QImage(resize_image(&gray))));
                    _mean = (int)mean(gray)[0];
                    qDebug()<<_mean;
                    if(_mean<mean_min) {
                        mean_min = _mean;
                        tx_min = tx;
                    }
                }
                */
                /*
                if(mean_min>0) {
                    Mat mask = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
                    mask(Rect(col+tx_min, row,
                              BLOCK_SIZE, BLOCK_SIZE))=Scalar(255,255,255);
                    translated.copyTo(image_right, mask);
                }




            }

*/
            //emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));

            //Mat block = autostereogram(Rect(row, col,
            //                                BLOCK_SIZE, BLOCK_SIZE));
        }
    }

    qDebug() << tx_min_min;

    double min = tx_min_min;
    double max = max_disparity;
    double b = 255/(1-(max/min));
    double a = -b/min;

    qDebug() << a;
    qDebug() << b;

    Mat disparity_map_quant = Mat::zeros(disparity_map.size().height, disparity_map.size().width, CV_8U);
    for(int row=0; row<disparity_map.rows; row++) {
        for(int col=0; col<disparity_map.cols; col++) {
            //qDebug()<<disparity_map.at<unsigned char>(col, row);
            unsigned char x = disparity_map.at<unsigned char>(row, col);
            if(x!=0) {
                unsigned char y = a*x+b;
                disparity_map_quant(Rect(col, row, 1, 1)) = y;
            }
        }
    }

    emit show_image_map_depth(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map_quant))));
    return disparity_map;
}



/*
 * get_image_right
 *
 * Dividir en pequeñas submatrices a image_left.
 * Match to the left solo las submatrices que superen una mean.
 * No recorrer todo, solo hasta max_disparity
 * Crear una imagen negra.
 * Poner en blanco donde se encontro la mean minima de cada bloque.
 *

Mat Solver::get_image_right(Mat translated, Mat image_left, int max_disparity) {

    Mat image_right = Mat::zeros(image_left.rows, image_left.cols, CV_8UC1);
    Mat image_left_gray;
    cvtColor(image_left, image_left_gray, CV_BGR2GRAY);

    for(int row=0; row<autostereogram.rows-BLOCK_SIZE; row=row+BLOCK_SIZE) {
        for(int col=0; col<autostereogram.cols-BLOCK_SIZE; col=col+BLOCK_SIZE) {

            Mat block = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
            Mat mask = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
            mask(Rect(col, row,
                      BLOCK_SIZE, BLOCK_SIZE))=Scalar(255,255,255);
            if((int)mean(image_left_gray, mask)[0]>0) { // Analiza solo si no es el fondo negro.
                image_left.copyTo(block, mask);
                int mean_min=255;
                int tx_min=0;
                int _mean;
                for(int tx=10; tx<max_disparity; tx++) {
                    // Translate.
                    Mat translated2;
                    Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, 0);
                    warpAffine(block, translated2, transformation_matrix, autostereogram.size());
                    //emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&translated2))));
                    // Absolute difference between images.
                    Mat difference;
                    absdiff(translated, translated2, difference);   // This must be done with colored images.
                    emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&difference))));
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
                if(mean_min>0) {
                    Mat mask = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
                    mask(Rect(col+tx_min, row,
                              BLOCK_SIZE, BLOCK_SIZE))=Scalar(255,255,255);
                    translated.copyTo(image_right, mask);
                }


            }


            //emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));

            //Mat block = autostereogram(Rect(row, col,
            //                                BLOCK_SIZE, BLOCK_SIZE));
        }
    }

    return image_right;
}

*/
