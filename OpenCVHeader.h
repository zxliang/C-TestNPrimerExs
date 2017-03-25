// header file to OpenCV library and function tests
#ifndef OPENCVHEADER_H
#define OPENCVHEADER_H
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
// #include "opencv2/opencv.hpp"
#include <iostream>
// #include "stdafx.h"

using namespace cv;
using namespace std;

// OpenCVTestFunc.cpp
int opencv_test1();
int opencv_test1_1();
int opencv_test2();
int opencv_test3();
int opencv_test4();
int opencv_test5();
int opencv_test6_1();
int opencv_test6_2();
int opencv_test6_3();
int opencv_test7();

void MyCallbackForBrightness(int iValueForBrightness, void *userData);
void MyCallbackForContrast(int iValueForContrast, void *userData);
int opencv_test8();

void CallBackFunc1(int event, int x, int y, int flags, void* userdata);
void CallBackFunc2(int event, int x, int y, int flags, void* userdata);
int opencv_test9();

int opencv_test10();

#endif
