TEMPLATE = app
CONFIG += c++11
CONFIG += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    mainwindow.cpp \
    solver.cpp \
    wbase.cpp \
    image.cpp \
    mask.cpp \
    disparity_map.cpp \
    max_disparity.cpp \
    disparity_filtering.cpp \
    method_4.cpp \
    depth_map.cpp

INCLUDEPATH += C:\opencv\build-cpp-mingw-32-wextras\install\include

LIBS += -LC:\opencv\build-cpp-mingw-32-wextras\install\x86\mingw\bin \
    -lopencv_core310 -lopencv_highgui310 -lopencv_imgproc310 -lopencv_imgcodecs310 \
    -lopencv_calib3d310 -lopencv_ximgproc310

HEADERS += \
    mainwindow.h \
    solver.h \
    wbase.h \
    image.h \
    disparity_filtering.h \
    ui_mainwindow.h

FORMS += \
    mainwindow.ui
