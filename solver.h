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
    Mat disparity_map;
    unsigned int disparity_min;
    unsigned int disparity_max;

        int max_disparity;
        Mat tx_map;
    int tx_min_min;

private:

    Mat autostereogram;
    void finish();

public slots:

    void solve();

    /*
     * Nota mental: no puedo separar los methods en clases hijas
     * porque es un worker.
     */

    // Method 1. OpenCV StereoBM.
    void method_1();
    Mat find_mask_1();
    void set_depth_map_1();

    // Method 2. Mean.
    void method_2();

    // Method 3. Mean with autostereogram itself.
    void method_3();

    // Method 4. SSD.
    void method_4();
    void get_disparity_map_4();
    unsigned int get_disparity_4(Mat block_left, Mat row_right, int block_size);
    unsigned int get_blocks_SSD(Mat block_left, Mat block_right);


    Mat find_mask();
    int get_max_disparity();

    Mat apply_mask(Mat image, Mat mask);
    void get_disparity_map(Mat image_left, Mat image_right);
    void get_disparity_map();
    int match_block(Mat block_left, Mat row_right, int block_size);
    bool match_image(int block_size, int n_iteration, int _row_min, int _col_min);

    void set_depth_map();

signals:

    void show_image_autostereogram(const QPixmap &);
    void show_image_left(const QPixmap &);
    void show_image_right(const QPixmap &);
    void show_image_depth_map(const QPixmap &);

    void enable_btn_stop(bool);
    void enable_btn_start(bool);

    void set_slider_minimum(int);
    void set_slider_maximum(int);
    void set_slider_value(int);
    void set_slider_enabled();
};

#endif // SOLVER_H
