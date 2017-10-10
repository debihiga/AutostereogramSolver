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

    if( autostereogram.empty() ) {
        qDebug() <<  "Could not open or find the image";
        finish();
    }

    //method_1();
    //method_2();
    //method_3();
    method_4();

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

void Solver::method_1() {

    // Get mask.
    Mat mask = find_mask();

    if(countNonZero(mask)>1) {

        // Get image right.
        Mat image_right = apply_mask(autostereogram, mask);
        imwrite("imgs/out/6_image_right.jpg", image_right);
        emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));

        // Get image left.
        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, max_disparity, 0, 1, 0);
        Mat autostereogram_shifted_2_right;
        warpAffine(autostereogram, autostereogram_shifted_2_right, transformation_matrix, autostereogram.size());
        Mat image_left = apply_mask(autostereogram_shifted_2_right, mask);
        transformation_matrix = (Mat_<double>(2, 3) << 1, 0, -max_disparity, 0, 1, 0);
        warpAffine(image_left, image_left, transformation_matrix, autostereogram.size());
        imwrite("imgs/out/7_image_left.jpg", image_left);
        emit show_image_left(QPixmap::fromImage(matRGB2QImage(resize_image(&image_left))));

        // Get disparity map.
        get_disparity_map(image_left, image_right);
    }

}

void Solver::method_2() {

    max_disparity = get_max_disparity();
    if(max_disparity!=-1) {
        get_disparity_map();
    }
}

void Solver::method_3() {

    // Get mask.
    Mat mask = find_mask();

    if(countNonZero(mask)>1) {

        // Get image right.
        Mat image_right = apply_mask(autostereogram, mask);
        imwrite("imgs/out/6_image_right.jpg", image_right);
        emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(&image_right))));

        // Get image left.
        Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, max_disparity, 0, 1, 0);
        Mat autostereogram_shifted_2_right;
        warpAffine(autostereogram, autostereogram_shifted_2_right, transformation_matrix, autostereogram.size());
        Mat image_left = apply_mask(autostereogram_shifted_2_right, mask);
        transformation_matrix = (Mat_<double>(2, 3) << 1, 0, -max_disparity, 0, 1, 0);
        warpAffine(image_left, image_left, transformation_matrix, autostereogram.size());
        imwrite("imgs/out/7_image_left.jpg", image_left);
        emit show_image_left(QPixmap::fromImage(matRGB2QImage(resize_image(&image_left))));

        // Get disparity map.
        Mat disparity_map = disparity_filtering(image_right, image_left,
                                                "sgbm", "wls_conf",
                                                false,
                                                1.0, max_disparity, 5,
                                                8000.0, 1.5);
        imwrite("imgs/out/disparity_map.jpg", disparity_map);
        emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&disparity_map))));
    }

}
void Solver::finish() {

    mutex_finish.lock();
    _working = false;
    _finish = false;
    mutex_finish.unlock();

    emit finished();
}

