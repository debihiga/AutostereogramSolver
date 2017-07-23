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

    if( autostereogram.empty() ) {
        qDebug() <<  "Could not open or find the image";
        finish();
    }

    int shift;
    Mat image_left = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
    bool abort = get_image_left(&shift, &image_left);
    if(!abort) {
        Mat image_right = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC1);
        get_image_right(shift, &image_right);

        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, 64, 0, 1, 0);  // Shift porque el disparity filtering recorta a la izquierda.
        warpAffine(image_right, image_right, transformation_matrix, autostereogram.size());
        warpAffine(image_left, image_left, transformation_matrix, autostereogram.size());

        imwrite("imgs/image_right.jpg", image_right);
        imwrite("imgs/image_left.jpg", image_left);
        // ./example_ximgproc_disparity_filtering.exe --right image_left.jpg --
        // left image_right.jpg --window_size=11 --max_disparity=144 --no_downscale --algorithm=sgbm --filter=wls_conf
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

