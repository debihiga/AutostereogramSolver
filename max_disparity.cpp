#include "solver.h"
#include "image.h"

#include <QThread>

/*
 * find_mask
 *
 * + image_in: autostereogram shifted.
 * + mask: difference in grayscale between the autostereogram
 * and itself shifted the size of the pattern to the right.

 */
int Solver::get_max_disparity() {

    bool abort;

    // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html
    int tx_i = autostereogram.size().width*0.1;
    int tx_f = autostereogram.size().width*0.9;
    int mean_min = 255;
    int max_disparity = -1;

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
        warpAffine(autostereogram, shifted, transformation_matrix, autostereogram.size());

        // Absolute difference between images.
        Mat difference;
        absdiff(autostereogram, shifted, difference);   // This must be done with colored images.

        // Get mean of difference.
        Mat gray;
        cvtColor(difference, gray, CV_BGR2GRAY);
        Mat mask_aux = Mat::zeros(gray.size().height, gray.size().width, CV_8UC1);
        mask_aux(Rect(tx,0,gray.size().width-tx,gray.size().height))=255;
        int _mean = (int)mean(gray, mask_aux)[0];
        if(_mean<mean_min) {
            mean_min = _mean;
            max_disparity = tx;
            gray(Rect(0,0,max_disparity,autostereogram.size().height))=0;    // Don't show back image.
        }

        emit show_image_left(QPixmap::fromImage(matGray2QImage(resize_image(&gray))));
        //QThread::msleep(40);
    }

    if(abort) {
        return -1;
    }

    return max_disparity;
}
