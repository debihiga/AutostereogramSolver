#include "solver.h"
#include "image.h"

#include <QThread>

Solver::Solver(Mat *_autostereogram, WBase *parent) : WBase(parent) {
    _autostereogram->copyTo(autostereogram);
    _working = false;
    _finish = false;
}

void Solver::solve() {

    qDebug() << "Starting Solver thread.";

    // Check for invalid input.
    if( autostereogram.empty() ) {
        qDebug() <<  "Could not open or find the image";
        finish();
    }

    int mean_min = 255;
    int tx_min = 0;         // tx where mean is min.
    // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html
    int tx_i = autostereogram.size().width*0.1;
    int tx_f = autostereogram.size().width*0.9;
    int tx = tx_i;

    bool abort;

    while(_working) {

        mutex_finish.lock();
        abort = _finish;
        mutex_finish.unlock();
        if (abort) {
            break;
        }
        if(tx<tx_f) {

            // Translation.
            // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html#translation
            Mat translated;
            Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, 0);
            warpAffine(autostereogram, translated, transformation_matrix, autostereogram.size());

            // Absolute difference between images.
            Mat difference;
            absdiff(autostereogram, translated, difference);   // This must be done with colored images.

            // Get mean of difference.
            Mat gray;
            cvtColor(difference, gray, CV_BGR2GRAY);
            Mat mask = Mat::zeros(gray.size().height, gray.size().width, CV_8UC1);
            mask(Rect(tx,0,mask.size().width-tx,mask.size().height))=255;
            int _mean = (int)mean(gray, mask)[0];
            if(_mean<mean_min) {
                mean_min = _mean;
                tx_min = tx;
            }
            //gray(Rect(0,0,tx,autostereogram.size().height))=0;    // Don't show back image.
            emit show_image_left(QPixmap::fromImage(matGray2QImage(resize_image(&gray))));
            //QThread::msleep(20);

            tx++;
        } else {
            break;
        }

    }

    if(!abort) {

        // Translation to where mean was min.
        Mat translated;
        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx_min, 0, 1, 0);
        //Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx_i, 0, 1, 0);
        //Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, tx_f, 0, 1, 0);
        warpAffine(autostereogram, translated, transformation_matrix, autostereogram.size());

        // Absolute difference between images.
        Mat difference;
        absdiff(autostereogram, translated, difference);   // This must be done with colored images.

        Mat gray;
        cvtColor(difference, gray, CV_BGR2GRAY);
        //gray(Rect(0,0,tx_min,autostereogram.size().height))=0;    // Don't show back image.

        // Shift to left.
        transformation_matrix = (Mat_<double>(2, 3) << 1, 0, -tx_min, 0, 1, 0);
        warpAffine(gray, translated, transformation_matrix, autostereogram.size());
        Mat image_left = get_image_left(autostereogram, translated);
        emit show_image_left(QPixmap::fromImage(matRGB2QImage(resize_image(&image_left))));

        qDebug()<<"Max disparity "<< tx_i+tx_min;
    }

    qDebug()<<"Solver Thread "<<this->QObject::thread();

    finish();
}

void Solver::finish() {

    qDebug() << "Killing Solver thread.";

    mutex_finish.lock();
    _working = false;
    _finish = false;
    mutex_finish.unlock();

    emit finished();
}
