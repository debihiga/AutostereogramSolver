#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "image.h"

#include <QFileDialog>
#include <QSignalMapper>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btn_stop->setEnabled(false);

    autostereogram = imread("imgs/sample.jpg", IMREAD_COLOR);
    set_new_autostereogram(&autostereogram);

    qDebug()<<"MainWindow constructor Thread "<<this->QObject::thread();

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_start_clicked() {

    t_solver = new QThread();
    solver = new Solver(&autostereogram);
    solver->moveToThread(t_solver);
    connect(solver, SIGNAL(workRequested()), t_solver, SLOT(start()));
    connect(t_solver, SIGNAL(started()), solver, SLOT(solve()));
    connect(solver, SIGNAL(finished()), t_solver, SLOT(quit()));
    connect(t_solver, SIGNAL(finished()), t_solver, SLOT(deleteLater()));
    connect(solver, SIGNAL(finished()), solver, SLOT(deleteLater()));
    // GUI.
    // https://fabienpn.wordpress.com/2013/05/01/qt-thread-simple-and-stable-with-sources/
    connect(solver, SIGNAL(show_image_processed(const QPixmap &)), ui->label_image_map_depth, SLOT(setPixmap(const QPixmap &)));
    // https://stackoverflow.com/questions/5153157/passing-an-argument-to-a-slot
    // https://artandlogic.com/2013/09/qt-5-and-c11-lambdas-are-your-friend/
    connect(solver, &Solver::workRequested, this, [=](){ui->btn_stop->setEnabled(true);});
    connect(solver, &Solver::workRequested, this, [=](){ui->btn_start->setEnabled(false);});
    connect(solver, &Solver::workRequested, this, [=](){ui->btn_select_autostereogram->setEnabled(false);});
    connect(t_solver, &QThread::finished, this, [=](){ui->btn_stop->setEnabled(false);});
    connect(t_solver, &QThread::finished, this, [=](){ui->btn_start->setEnabled(true);});
    connect(t_solver, &QThread::finished, this, [=](){ui->btn_select_autostereogram->setEnabled(true);});

    solver->requestWork();
}

void MainWindow::on_btn_stop_clicked() {
    if(t_solver->isRunning()) {
        solver->requestFinish();
        //t_solver->wait();
    }
}

void MainWindow::set_new_autostereogram(Mat* image) {
    Mat resized_image = resize_image(image);
    ui->label_image_autostereogram->setPixmap(QPixmap::fromImage(matRGB2QImage(resized_image)));
    Mat black_image = Mat::zeros(resized_image.size(), CV_8U);
    ui->label_image_map_depth->setPixmap(QPixmap::fromImage(matGray2QImage(black_image)));
}

void MainWindow::on_btn_select_autostereogram_clicked() {
    QString file = QFileDialog::getOpenFileName(this,
         tr("Seleccionar autoestereograma"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    if(!file.isEmpty()) {
        autostereogram = imread(file.toStdString(), IMREAD_COLOR);
        set_new_autostereogram(&autostereogram);
    }
}
