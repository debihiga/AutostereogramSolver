TEMPLATE = app
CONFIG -= console
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += C:\opencv\build-cpp-mingw-32\install\include
LIBS += -LC:\opencv\build-cpp-mingw-32\install\x86\mingw\bin \
    -lopencv_core310 -lopencv_highgui310 -lopencv_imgproc310 -lopencv_imgcodecs310
