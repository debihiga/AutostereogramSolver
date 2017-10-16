#include "solver.h"
#include "image.h"

#include <QThread>

Solver::Solver(Mat *_autostereogram, WBase *parent) : WBase(parent) {
    _autostereogram->copyTo(autostereogram);
    _working = false;
    _finish = false;
}

void Solver::solve() {

    if( autostereogram.empty() ) {
        qDebug() <<  "Could not open or find the image";
        finish();
    }

    //method_1();
    method_2();
    //method_3();
    //method_4();

    while(_working) {
        mutex_finish.lock();
        bool abort = _finish;
        mutex_finish.unlock();
        if(abort) {
            break;
        }
    }

    finish();
}

void Solver::finish() {

    mutex_finish.lock();
    _working = false;
    _finish = false;
    mutex_finish.unlock();

    emit finished();
}

