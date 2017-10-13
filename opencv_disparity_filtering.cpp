
#include "opencv_disparity_filtering.h"
#include "solver.h"
#include "image.h"
#include <QString>

const String keys =
    "{help h usage ? |                  | print this message                                                }"
    "{@left          |../data/aloeL.jpg | left view of the stereopair                                       }"
    "{@right         |../data/aloeR.jpg | right view of the stereopair                                      }"
    "{GT             |../data/aloeGT.png| optional ground-truth disparity (MPI-Sintel or Middlebury format) }"
    "{dst_path       |None              | optional path to save the resulting filtered disparity map        }"
    "{dst_raw_path   |None              | optional path to save raw disparity map before filtering          }"
    "{algorithm      |bm                | stereo matching method (bm or sgbm)                               }"
    "{filter         |wls_conf          | used post-filtering (wls_conf or wls_no_conf)                     }"
    "{no-display     |                  | don't display results                                             }"
    "{no-downscale   |                  | force stereo matching on full-sized views to improve quality      }"
    "{dst_conf_path  |None              | optional path to save the confidence map used in filtering        }"
    "{vis_mult       |1.0               | coefficient used to scale disparity map visualizations            }"
    "{max_disparity  |160               | parameter of stereo matching                                      }"
    "{window_size    |-1                | parameter of stereo matching                                      }"
    "{wls_lambda     |8000.0            | parameter of post-filtering                                       }"
    "{wls_sigma      |1.5               | parameter of post-filtering                                       }"
    ;

Mat opencv_disparity_filter(Mat left, Mat right,
                        String algo, String filter,
                        bool no_downscale,
                        double vis_mult, int max_disp, int window_size,
                        double lambda, double sigma) {

    Mat filtered_disp_vis;

    int wsize;
    if(window_size>=0) //user provided window_size value
        wsize = window_size;
    else {
        if(algo=="sgbm")
            wsize = 3; //default window size for SGBM
        else if(!no_downscale && algo=="bm" && filter=="wls_conf")
            wsize = 7; //default window size for BM on downscaled views (downscaling is performed only for wls_conf)
        else
            wsize = 15; //default window size for BM on full-sized views
    }

    Mat left_for_matcher, right_for_matcher;
    Mat left_disp,right_disp;
    Mat filtered_disp;
    Mat conf_map = Mat(left.rows,left.cols,CV_8U);
    conf_map = Scalar(255);
    Rect ROI;
    Ptr<DisparityWLSFilter> wls_filter;

    if(max_disp<=0 || max_disp%16!=0) {
        cout<<"Incorrect max_disparity value: it should be positive and divisible by 16";
    }
    if(wsize<=0 || wsize%2!=1) {
        cout<<"Incorrect window_size value: it should be positive and odd";
    }
    if(filter=="wls_conf") { // filtering with confidence (significantly better quality than wls_no_conf)

        if(!no_downscale) {
            // downscale the views to speed-up the matching stage, as we will need to compute both left
            // and right disparity maps for confidence map computation
            //! [downscale]
            max_disp/=2;
            if(max_disp%16!=0)
                max_disp += 16-(max_disp%16);
            resize(left ,left_for_matcher ,Size(),0.5,0.5);
            resize(right,right_for_matcher,Size(),0.5,0.5);
            //! [downscale]
        }
        else {
            left_for_matcher  = left.clone();
            right_for_matcher = right.clone();
        }

        if(algo=="bm") {
            // http://docs.opencv.org/3.1.0/d9/dba/classcv_1_1StereoBM.html
            Ptr<StereoBM> left_matcher = StereoBM::create(max_disp, wsize);
            wls_filter = createDisparityWLSFilter(left_matcher);
            Ptr<StereoMatcher> right_matcher = createRightMatcher(left_matcher);

            cvtColor(left_for_matcher,  left_for_matcher,  COLOR_BGR2GRAY);
            cvtColor(right_for_matcher, right_for_matcher, COLOR_BGR2GRAY);

            // Computes disparity map for the specified stereo pair.
            left_matcher->compute(left_for_matcher, right_for_matcher,left_disp);
            right_matcher->compute(right_for_matcher, left_for_matcher, right_disp);
        }
        else if(algo=="sgbm") {
            Ptr<StereoSGBM> left_matcher  = StereoSGBM::create(0,max_disp,wsize);
            left_matcher->setP1(24*wsize*wsize);
            left_matcher->setP2(96*wsize*wsize);
            left_matcher->setPreFilterCap(63);
            left_matcher->setMode(StereoSGBM::MODE_SGBM_3WAY);
            wls_filter = createDisparityWLSFilter(left_matcher);
            Ptr<StereoMatcher> right_matcher = createRightMatcher(left_matcher);

            left_matcher-> compute(left_for_matcher, right_for_matcher,left_disp);
            right_matcher->compute(right_for_matcher,left_for_matcher, right_disp);
        }
        else {
            cout<<"Unsupported algorithm";
        }

        wls_filter->setLambda(lambda);
        wls_filter->setSigmaColor(sigma);
        wls_filter->filter(left_disp,left,filtered_disp,right_disp);
        // Get the confidence map that was used in the last filter call.
        conf_map = wls_filter->getConfidenceMap();
        // Get the ROI that was used in the last filter call.
        ROI = wls_filter->getROI();
        if(!no_downscale) {
            // upscale raw disparity and ROI back for a proper comparison:
            resize(left_disp,left_disp,Size(),2.0,2.0);
            left_disp = left_disp*2.0;
            ROI = Rect(ROI.x*2,ROI.y*2,ROI.width*2,ROI.height*2);
        }
    }
    else if(filter=="wls_no_conf") {
        /* There is no convenience function for the case of filtering with no confidence, so we
        will need to set the ROI and matcher parameters manually */

        left_for_matcher  = left.clone();
        right_for_matcher = right.clone();

        if(algo=="bm") {
            Ptr<StereoBM> matcher  = StereoBM::create(max_disp,wsize);
            matcher->setTextureThreshold(0);
            matcher->setUniquenessRatio(0);
            cvtColor(left_for_matcher,  left_for_matcher, COLOR_BGR2GRAY);
            cvtColor(right_for_matcher, right_for_matcher, COLOR_BGR2GRAY);
            ROI = computeROI(left_for_matcher.size(),matcher);
            wls_filter = createDisparityWLSFilterGeneric(false);
            wls_filter->setDepthDiscontinuityRadius((int)ceil(0.33*wsize));

            matcher->compute(left_for_matcher,right_for_matcher,left_disp);
        }
        else if(algo=="sgbm") {
            Ptr<StereoSGBM> matcher  = StereoSGBM::create(0,max_disp,wsize);
            matcher->setUniquenessRatio(0);
            matcher->setDisp12MaxDiff(1000000);
            matcher->setSpeckleWindowSize(0);
            matcher->setP1(24*wsize*wsize);
            matcher->setP2(96*wsize*wsize);
            matcher->setMode(StereoSGBM::MODE_SGBM_3WAY);
            ROI = computeROI(left_for_matcher.size(),matcher);
            wls_filter = createDisparityWLSFilterGeneric(false);
            wls_filter->setDepthDiscontinuityRadius((int)ceil(0.5*wsize));

            matcher->compute(left_for_matcher,right_for_matcher,left_disp);
        }
        else {
            cout<<"Unsupported algorithm";
        }

        wls_filter->setLambda(lambda);
        wls_filter->setSigmaColor(sigma);
        wls_filter->filter(left_disp,left,filtered_disp,Mat(),ROI);
    }
    else {
        cout<<"Unsupported filter";
    }

    Mat raw_disp_vis;
    // Create a disparity map visualization.
    getDisparityVis(left_disp, raw_disp_vis, vis_mult);
    getDisparityVis(filtered_disp, filtered_disp_vis, vis_mult);

    return filtered_disp_vis;
}

Rect computeROI(Size2i src_sz, Ptr<StereoMatcher> matcher_instance) {
    int min_disparity = matcher_instance->getMinDisparity();
    int num_disparities = matcher_instance->getNumDisparities();
    int block_size = matcher_instance->getBlockSize();

    int bs2 = block_size/2;
    int minD = min_disparity, maxD = min_disparity + num_disparities - 1;

    int xmin = maxD + bs2;
    int xmax = src_sz.width + minD - bs2;
    int ymin = bs2;
    int ymax = src_sz.height - bs2;

    Rect r(xmin, ymin, xmax - xmin, ymax - ymin);
    return r;
}

void filter(Mat image, Mat disparity_map,
            int wsize, double lambda, double sigma,
            Mat *disparity_map_filtered) {
    // http://docs.opencv.org/3.1.0/da/d17/group__ximgproc__filters.html#gad79c31494e3bb92d4b30e0dcefae1249
    Ptr<DisparityWLSFilter> wls_filter = createDisparityWLSFilterGeneric(false);
        /* use_confidence = false
         * Filtering with confidence requires two disparity maps (for the left and right views)
         * and is approximately two times slower.
         * However, quality is typically significantly better.
         */
    wls_filter->setDepthDiscontinuityRadius((int)ceil(0.5*wsize));
        /* DepthDiscontinuityRadius is a parameter used in confidence computation.
         * It defines the size of low-confidence regions around depth discontinuities.
         */
    wls_filter->setLambda(lambda);
        /* Lambda is a parameter defining the amount of regularization during filtering.
         * Larger values force filtered disparity map edges to adhere more to source image edges.
         * Typical value is 8000.
         */
    wls_filter->setSigmaColor(sigma);
        /* SigmaColor is a parameter defining how sensitive the filtering process is to source image edges.
         * Large values can lead to disparity leakage through low-contrast edges.
         * Small values can make the filter too sensitive to noise and textures in the source image.
         * Typical values range from 0.8 to 2.0.
         */
    wls_filter->filter(disparity_map, image, *disparity_map_filtered, Mat());
        /* Apply filtering to the disparity map.
         * Parameters
         * + disparity_map_left:
         *      disparity map of the left view, 1 channel, CV_16S type.
         *      Implicitly assumes that disparity values are scaled by 16 (one-pixel disparity corresponds to the value of 16 in the disparity map).
         *      Disparity map can have any resolution, it will be automatically resized to fit left_view resolution.
         * + left_view:
         *      left view of the original stereo-pair to guide the filtering process, 8-bit single-channel or three-channel image.
         * + filtered_disparity_map:
         *      output disparity map.
         * + disparity_map_right:
         *      optional argument, some implementations might also use the disparity map of the right view to compute confidence maps, for instance.
         * + ROI:
         *      region of the disparity map to filter.
         *      Optional, usually it should be set automatically.
         * + right_view:
         *      optional argument, some implementations might also use the right view of the original stereo-pair.
         */
}
