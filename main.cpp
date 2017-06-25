#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

Mat binarizeImage(Mat* image, int value_1, int value_2, int thresh);

int main(int argc, char *argv[])
{
    Mat image = imread("imgs/sample.jpg", IMREAD_COLOR);
    Mat copy;

    if( image.empty() ) {                     // Check for invalid input
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow("Original", WINDOW_AUTOSIZE);
    namedWindow("Difference", WINDOW_AUTOSIZE);
    namedWindow("Nearest", WINDOW_AUTOSIZE);
    imshow("Original", image);

    Mat output;

    //absdiff(image, copy, output);

    //cvtColor(image, image, CV_BGR2GRAY);

    int mean_min = 255;
    int tx_min = 0;
    // http://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_geometric_transformations/py_geometric_transformations.html
    int tx_i = image.size().width*0.1;
    int tx_f = image.size().width*0.9;
    for(int tx=tx_i; tx<tx_f; tx++) {
        Mat M = (Mat_<double>(2, 3) << 1, 0, tx, 0, 1, 0);
        warpAffine(image, copy, M, image.size());
        absdiff(image, copy, output);   // This must be done with colored image.
        Mat gray;
        cvtColor(output, gray, CV_BGR2GRAY);
        Mat roi = gray( Rect(tx,0,gray.size().width-tx,gray.size().height) );
        //imshow("Difference", roi);
        Mat mask = Mat::zeros(gray.size().height, gray.size().width, CV_8UC1);
        mask(Rect(tx,0,mask.size().width-tx,mask.size().height))=255;
        int _mean = (int)mean(gray, mask)[0];
        if(_mean<mean_min) {
            mean_min = _mean;
            tx_min = tx;
        }
        gray(Rect(0,0,tx,image.size().height))=0;
        imshow("Difference", gray);
        waitKey(50);
    }


    Mat M = (Mat_<double>(2, 3) << 1, 0, tx_min, 0, 1, 0);
    warpAffine(image, copy, M, image.size());
    absdiff(image, copy, output);   // This must be done with colored image.
    Mat roi = output( Rect(tx_min,0,output.size().width-tx_min,output.size().height) );
    imshow("Difference", roi);

    Mat result = binarizeImage(&roi, 0, 255, 10);

    imshow("Nearest", result);
    waitKey();

    return 0;
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
