#include "solver.h"
#include "image.h"

void Solver::method_2() {

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
