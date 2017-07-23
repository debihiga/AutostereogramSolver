#ifndef SOLVER_H
#define SOLVER_H

#include "wbase.h"

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

class Solver: public WBase {
    Q_OBJECT

public:

    explicit Solver(Mat* autostereogram, WBase *parent=0);

private:

    Mat autostereogram;
    void finish();

public slots:

    void solve();
    bool find_mask(int* tx_min, Mat* shifted, Mat* mask);
    bool get_image_left(int* shift, Mat* image);
    void get_image_right(int shift, Mat* image);
    Mat get_image(Mat autostereogram, Mat mask, int shift);

signals:

    void show_image_autostereogram(const QPixmap &);
    void show_image_left(const QPixmap &);
    void show_image_right(const QPixmap &);
    void show_image_map_depth(const QPixmap &);

    void enable_btn_stop(bool);
    void enable_btn_start(bool);
};

#endif // SOLVER_H
