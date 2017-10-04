#include "solver.h"
#include "image.h"

#define THRESHOLD           60
#define BORDER_SIZE         10  // Parameter specifying how many pixels in each direction from the source image rectangle to extrapolate. For example, top=1, bottom=1, left=1, right=1 mean that 1 pixel-wide border needs to be built.
#define KERNEL_SIZE_MAX     15  // As it must be odd -> if KERNEL_SIZE_MAX=15 -> 2*KERNEL_SIZE_MAX+1 -> max_real=2*15+1=31
#define CLOSING_N_MAX       1   // Max number of closing iterations.

/*
 * get_image
 *
 * Gets the left image from the autostereogram.
 *
 * Creates a mask from the difference in grayscale between the autostereogram
 * and itself shifted the size of the pattern to the right
 * and applies it to the autostereogram
 * to obtain the left image.
 *
 * Parameters:
 * + image: autostereogram.
 * + mask: difference in grayscale between the autostereogram
 * and itself shifted the size of the pattern to the right.
 *
 * https://stackoverflow.com/questions/31133903/opencv-remove-background
 */
Mat Solver::get_image(Mat image, Mat mask) {

    //imwrite("imgs/1_mask_left_initial.jpg", mask);

    // Threshold (remove background from noisy images).
    Mat mask_thresholded;
    threshold(mask, mask_thresholded, THRESHOLD, 255, CV_THRESH_BINARY);
        // maxval = 255
    //imwrite("imgs/2_mask_thresholded.jpg", mask_thresholded);

    // Add zero border to reduce the effects on borders.
    Mat mask_thresholded_bordered;
    copyMakeBorder(mask_thresholded, mask_thresholded_bordered,
                   BORDER_SIZE, BORDER_SIZE, BORDER_SIZE, BORDER_SIZE,
                   BORDER_CONSTANT, Scalar(0));
    //imwrite("imgs/3_mask_thresholded_bordered.jpg", mask_thresholded_bordered);

    // Close.
    for(int i=1; i<KERNEL_SIZE_MAX; i++) {
        // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#getstructuringelement
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, cv::Size(2*i+1, 2*i+1));
            // shape=MORPH_ELLIPSE -> smoothed results.
            // ksize=cv::Size(2*i+1, 2*i+1)
        // http://docs.opencv.org/3.0-beta/modules/imgproc/doc/filtering.html#morphologyex
        morphologyEx(mask_thresholded_bordered, mask_thresholded_bordered,
                     MORPH_CLOSE, kernel, Point(-1,-1), CLOSING_N_MAX);
            // op=MORPH_CLOSE -> dst=close(src,element)=erode(dilate(src,element))
            // anchor=Point(-1, -1) -> Anchor position with the kernel. Negative values mean that the anchor is at the kernel center.
            // iterations=CLOSING_N_MAX
    }
    //imwrite("imgs/4_mask_thresholded_bordered_closed.jpg", mask_thresholded_bordered);

    // Remove border.
    mask = mask_thresholded_bordered(Rect(BORDER_SIZE, BORDER_SIZE, mask.cols, mask.rows));
    //imwrite("imgs/5_mask_left.jpg", mask);

    // Apply mask.
    // http://answers.opencv.org/question/74440/opencv-masking-operation-does-not-function-properly/
    Mat image_left = Mat::zeros(mask.rows, mask.cols, CV_8UC1);
    image.copyTo(image_left, mask);
    //imwrite("imgs/6_image_left.jpg", image_left);

    // Shift.
    //Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, shift, 0, 1, 0);
    //warpAffine(image_left, image_left, transformation_matrix, image.size());
    //imwrite("imgs/7_image_left_shifted.jpg", image_left);

    return image_left;
}



