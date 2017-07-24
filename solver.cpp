#include "solver.h"
#include "image.h"
#include "disparity_filtering.h"

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
    Mat image_left = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC3);
    bool abort = get_image_left(&shift, &image_left);
    if(!abort) {
        Mat image_right = Mat::zeros(autostereogram.rows, autostereogram.cols, CV_8UC3);
        get_image_right(shift, &image_right);

        int EXTENSION = 160;
        Mat image_right_extended = Mat::zeros(autostereogram.rows, autostereogram.cols+EXTENSION, CV_8UC3);
        Mat image_left_extended = Mat::zeros(autostereogram.rows, autostereogram.cols+EXTENSION, CV_8UC3);
        image_right.copyTo(image_right_extended(Rect(0, 0, image_right.cols, image_right.rows)));
        image_left.copyTo(image_left_extended(Rect(0, 0, image_left.cols, image_left.rows)));
        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, EXTENSION, 0, 1, 0);  // Shift porque el disparity filtering recorta a la izquierda.
        warpAffine(image_right_extended, image_right_extended, transformation_matrix, image_right_extended.size());
        warpAffine(image_left_extended, image_left_extended, transformation_matrix, image_left_extended.size());

        imwrite("imgs/image_right.jpg", image_right_extended);
        imwrite("imgs/image_left.jpg", image_left_extended);

        Mat disparity_map = disparity_filtering(image_left_extended, image_right_extended);
        Size size(autostereogram.rows,autostereogram.cols);
        resize(disparity_map, disparity_map, size);
        emit show_image_map_depth(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map))));

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

