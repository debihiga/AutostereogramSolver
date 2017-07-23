#include "solver.h"
#include "image.h"

/*
 * get_image_left
 *
 * Gets the right or left image from the autostereogram.
 *
 * Creates a mask from the difference in grayscale between the autostereogram
 * and itself shifted the size of the pattern to the right or left
 * and applies it to the autostereogram
 * to obtain the right or left image.
 *
 * Parameters:
 * + type: right or left.
 *
 * https://stackoverflow.com/questions/31133903/opencv-remove-background
 */
void Solver::get_image_right(int shift, Mat* image) {

    Mat transformation_matrix = (Mat_<double>(2, 3) << 1, 0, -shift, 0, 1, 0);
    Mat translated;
    warpAffine(autostereogram, translated, transformation_matrix, autostereogram.size());
    Mat difference;
    absdiff(autostereogram, translated, difference);   // This must be done with colored images.
    Mat gray;
    cvtColor(difference, gray, CV_BGR2GRAY);
    gray(Rect(autostereogram.size().width-shift,0,shift,autostereogram.size().height))=0;    // Don't show back image.
    *image = get_image(translated, gray, shift);
    emit show_image_right(QPixmap::fromImage(matRGB2QImage(resize_image(image))));
}
