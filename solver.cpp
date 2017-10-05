#include "solver.h"
#include "image.h"

#include <QThread>


Solver::Solver(Mat *_autostereogram, WBase *parent) : WBase(parent) {
    _autostereogram->copyTo(autostereogram);
    _working = false;
    _finish = false;
}

void Solver::solve() {

    if( autostereogram.empty() ) {
        qDebug() <<  "Could not open or find the image";
        finish();
    }

    // Get mask.
    Mat mask = find_mask();

    if(countNonZero(mask)>1) {

        // Get image right.
        imwrite("imgs/out/1_mask_right.jpg", mask);
        Mat image_right = apply_mask(autostereogram, mask);
        imwrite("imgs/out/2_image_right.jpg", image_right);
        emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));

        // Get image left.
        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, max_disparity, 0, 1, 0);
        Mat autostereogram_shifted_2_right;
        warpAffine(autostereogram, autostereogram_shifted_2_right, transformation_matrix, autostereogram.size());
        Mat image_left = apply_mask(autostereogram_shifted_2_right, mask);
        transformation_matrix = (Mat_<double>(2, 3) << 1, 0, -max_disparity, 0, 1, 0);
        warpAffine(image_left, image_left, transformation_matrix, autostereogram.size());
        imwrite("imgs/out/3_image_left.jpg", image_left);
        emit show_image_left(QPixmap::fromImage(matRGB2QImage(resize_image(&image_left))));

        // Get disparity map.
        get_disparity_map(image_left, image_right);
    }

    while(_working) {
        mutex_finish.lock();
        bool abort = _finish;
        mutex_finish.unlock();
        if(abort) {
            break;
        }
    }

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

