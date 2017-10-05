#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

#include "solver.h"

using namespace cv;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    Mat autostereogram;
    QThread* t_solver;
    Solver* solver;

    ~MainWindow();

private slots:

    void on_btn_start_clicked();
    void on_btn_stop_clicked();
    void on_btn_select_autostereogram_clicked();

    void on_slider_q_valueChanged(int value);

public slots:

    void set_new_autostereogram(Mat* image);

private:

    Mat set_autostereogram();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
