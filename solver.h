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
    Mat get_image_left(Mat image, Mat mask);

signals:

    void show_image_autostereogram(const QPixmap &);
    void show_image_left(const QPixmap &);
    void show_image_right(const QPixmap &);
    void show_image_map_depth(const QPixmap &);

    void enable_btn_stop(bool);
    void enable_btn_start(bool);
};

#endif // SOLVER_H
