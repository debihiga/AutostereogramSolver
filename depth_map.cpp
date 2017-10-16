#include "solver.h"
#include "image.h"

//bool apply_filter = true;

void Solver::set_depth_map() {

    Mat depth_map = Mat::zeros(disparity_map.size().height, disparity_map.size().width, CV_8U);
    for(int row=0; row<depth_map.rows; row++) {
        for(int col=0; col<depth_map.cols; col++) {
            int disparity = disparity_map.at<int>(row, col);
            if(disparity>0.5*disparity_max) {
                unsigned char depth = (255.0*(disparity_max))/((double)disparity)-255;
                //qDebug() << "disparity" << disparity;
                //qDebug() << "depth " << depth;
                depth_map(Rect(col, row, 1, 1)) = depth;
            }
        }
    }
    /*
    if(apply_filter) {
        medianBlur(depth_map, depth_map, 9);
    }
    */
    imwrite("imgs/out/depth_map.jpg", depth_map);
    emit show_image_depth_map(QPixmap::fromImage(matGray2QImage(resize_image(&depth_map))));
}
