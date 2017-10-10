#include "solver.h"
#include "image.h"

void Solver::set_depth_map() {

    Mat depth_map = Mat::zeros(disparity_map.size().height, disparity_map.size().width, CV_8U);
    for(int row=0; row<depth_map.rows; row++) {
        for(int col=0; col<depth_map.cols; col++) {
            int disparity = disparity_map.at<int>(row, col);
            if(disparity!=0) {
                unsigned char depth = (255.0*(disparity_max))/((double)disparity);
                depth_map(Rect(col, row, 1, 1)) = depth;
            }
        }
    }
    emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&depth_map))));
}
