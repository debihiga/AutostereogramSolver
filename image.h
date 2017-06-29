#ifndef IMAGE_H
#define IMAGE_H

#include <QWidget>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;

Mat binarizeImage(Mat* image, int value_1, int value_2, int thresh);
Mat resize_image(Mat* image);
QImage matGray2QImage(const Mat& mat);
QImage matRGB2QImage(const Mat& mat);

#endif // IMAGE_H
