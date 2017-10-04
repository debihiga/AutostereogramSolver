#ifndef DISPARITY_FILTERING_H
#define DISPARITY_FILTERING_H

#include "opencv2/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/ximgproc/disparity_filter.hpp"
#include <iostream>
#include <string>
#include <QString>

using namespace cv;
using namespace cv::ximgproc;
using namespace std;

#define ALGORITHM   "bm"
#define FILTER      "wls_conf"
#define VIS_MULT    1.0

Mat disparity_filtering(Mat left, Mat right,
                        String algorithm="bm", String filter="wls_conf",
                        bool no_downscale=false,
                        double vis_mult=1.0, int max_disparity=160, int window_size=-1,
                        double wls_lambda=8000.0, double wls_sigma=1.5);

Rect computeROI(Size2i src_sz, Ptr<StereoMatcher> matcher_instance);


#endif // DISPARITY_FILTERING_H
