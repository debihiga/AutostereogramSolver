TEMPLATE = app
CONFIG += c++11
CONFIG += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    mainwindow.cpp \
    solver.cpp \
    wbase.cpp \
    image.cpp \
    get_image_left.cpp

INCLUDEPATH += C:\opencv\build-cpp-mingw-32\install\include
LIBS += -LC:\opencv\build-cpp-mingw-32\install\x86\mingw\bin \
    -lopencv_core310 -lopencv_highgui310 -lopencv_imgproc310 -lopencv_imgcodecs310

HEADERS += \
    mainwindow.h \
    solver.h \
    wbase.h \
    image.h

FORMS += \
    mainwindow.ui
