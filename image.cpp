
#include "image.h"

QImage matRGB2QImage(const Mat& mat) {
    const uchar *qImageBuffer = (const uchar*)mat.data;
    QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    return img.rgbSwapped();
}

QImage matGray2QImage(const Mat& mat) {
    const uchar *qImageBuffer = (const uchar*)mat.data;
    QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Grayscale8);
    return img.rgbSwapped();
}

Mat resize_image(Mat* image) {
    Mat resized;
    image->copyTo(resized);
    Size size(400,200);
    resize(resized, resized, size);
    return resized;
}

Mat binarizeImage(Mat* image, int value_1, int value_2, int thresh) {

    Mat canny;
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;

    cvtColor(*image, *image, CV_BGR2GRAY);
    Mat result = Mat::zeros( image->size(), CV_8UC3 );

    //blur(*image, *image, Size(5,5) ); // Se pierden los contornos.
    int low_thresh = 50;
    int high_thresh = low_thresh*2;
    //medianBlur(*image,*image,7);
    dilate(*image, *image, Mat(),Point(-1,-1),3);
    erode(*image, *image, Mat(),Point(-1,-1),3);
    Canny(*image, canny, low_thresh, high_thresh, 3 );
    //blur(*image, *image, Size(3,3) ); // Se pierden los contornos.

    //findContours(*image, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    findContours(canny, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point(0, 0) );
    for( int i = 0; i< contours.size(); i++ ) {
        Scalar color = Scalar( 255, 0, 0 );
        drawContours( result, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }

    /*
    Mat gray;
    Mat aux;
    Mat otsu;
    int thr = threshold(gray, aux, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    threshold(gray, otsu, thr, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    */

    result = canny;
    return result;
}
