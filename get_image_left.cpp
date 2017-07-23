#include "solver.h"
#include "image.h"

/*
 * get_image_right
 *
 * Gets the right or left image from the autostereogram.
 *
 * Creates a mask from the difference in grayscale between the autostereogram
 * and itself shifted the size of the pattern to the right or left
 * and applies it to the autostereogram
 * to obtain the right or left image.
 *
 * Parameters:
 * + type: right or left.
 *
 * https://stackoverflow.com/questions/31133903/opencv-remove-background
 */
bool Solver::get_image_left(int* shift, Mat* image) {

    Mat shifted, mask;
    bool abort = find_mask(shift, &shifted, &mask);
    if(abort) {
        return abort;
    } else {
        *image = get_image(shifted, mask, -(*shift));
        emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&*image))));
        return abort;
    }
}

/*
 * find_mask

 *  * + image_in: autostereogram shifted.
 * + mask: difference in grayscale between the autostereogram
 * and itself shifted the size of the pattern to the right.

 */
bool Solver::find_mask(int* tx_min, Mat* shifted_out, Mat* mask_out) {

    bool abort;

    // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html
    int tx_i = autostereogram.size().width*0.1;
    int tx_f = autostereogram.size().width*0.9;
    int tx = tx_i;
    int mean_min = 255;

    while(_working) {
        mutex_finish.lock();
        abort = _finish;
        mutex_finish.unlock();
        if(abort) {
            break;
        }
        if( tx<tx_f ) {

            // Translation.
            // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html#translation
            Mat shifted;
            Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, 0);
            warpAffine(autostereogram, shifted, transformation_matrix, autostereogram.size());

            // Absolute difference between images.
            Mat difference;
            absdiff(autostereogram, shifted, difference);   // This must be done with colored images.

            // Get mean of difference.
            Mat gray;
            cvtColor(difference, gray, CV_BGR2GRAY);
            Mat mask = Mat::zeros(gray.size().height, gray.size().width, CV_8UC1);
            mask(Rect(tx,0,mask.size().width-tx,mask.size().height))=255;
            int _mean = (int)mean(gray, mask)[0];
            if(_mean<mean_min) {
                mean_min = _mean;
                *tx_min = tx;
                gray(Rect(0,0,*tx_min,autostereogram.size().height))=0;    // Don't show back image.
                shifted.copyTo(*shifted_out);
                gray.copyTo(*mask_out);
            }

            emit show_image_right(QPixmap::fromImage(matGray2QImage(resize_image(&gray))));
            tx++;

            //QThread::msleep(40);

        } else {
            break;
        }
    }

    return abort;
}
