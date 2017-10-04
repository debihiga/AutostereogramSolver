#include "solver.h"
#include "image.h"

/*
 * get_image_left
 *
 * Gets left image from the autostereogram.
 *
 * Finds mask to apply to the autostereogram
 * in order to obtain the left image.
 *
 * Parameters:
 * + shift: where to save how much shift was needed.
 * + image: where to save the left image.
 *
 * https://stackoverflow.com/questions/31133903/opencv-remove-background
 */
bool Solver::get_image_left(int* shift, Mat* image_left) {

    Mat shifted, mask;
    //bool abort = find_mask(shift, &shifted, &mask);
    bool abort = false;
    if(abort) {
        return abort;
    } else {
        //*image_left = apply_mask(shifted, mask, -(*shift));
        //emit show_image_left(QPixmap::fromImage(matRGB2QImage(resize_image(&*image_left))));
        return abort;
    }
}


