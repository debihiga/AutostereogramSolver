#include "solver.h"
#include "image.h"

#define BLOCK_SIZE  4

/*
 * get_image_right
 *
 * Dividir en pequeñas submatrices a image_left.
 * Match to the left solo las submatrices que superen una mean.
 * No recorrer todo, solo hasta max_disparity
 * Crear una imagen negra.
 * Poner en blanco donde se encontro la mean minima de cada bloque.
 *
 */
Mat Solver::get_image_right(Mat autostereogram, Mat translated, Mat image_left, int max_disparity) {

    Mat image_right = Mat::zeros(image_left.rows, image_left.cols, CV_8UC1);
    Mat image_left_gray;
    cvtColor(image_left, image_left_gray, CV_BGR2GRAY);

    for(int row=0; row<autostereogram.rows-BLOCK_SIZE; row=row+BLOCK_SIZE) {
        for(int col=0; col<autostereogram.cols-BLOCK_SIZE; col=col+BLOCK_SIZE) {

            Mat block = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
            Mat mask = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
            mask(Rect(col, row,
                      BLOCK_SIZE, BLOCK_SIZE))=Scalar(255,255,255);
            if((int)mean(image_left_gray, mask)[0]>0) {
                autostereogram.copyTo(block, mask);
                int mean_min=255;
                int tx_min=0;
                for(int tx=10; tx<max_disparity; tx++) {
                    // Translate.
                    Mat translated2;
                    Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, 0);
                    warpAffine(block, translated2, transformation_matrix, autostereogram.size());
                    // Absolute difference between images.
                    Mat difference;
                    absdiff(translated, translated2, difference);   // This must be done with colored images.
                    // Get mean of difference.
                    Mat gray;
                    cvtColor(difference, gray, CV_BGR2GRAY);
                    int _mean = (int)mean(gray)[0];
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
                /*

                */

            }


            emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));

            /*
            Mat block = autostereogram(Rect(row, col,
                                            BLOCK_SIZE, BLOCK_SIZE));*/
        }
    }

    return image_right;
}

