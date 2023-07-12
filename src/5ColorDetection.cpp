#include "opencv4/opencv2/core.hpp"
#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

Mat hsvImg, bgrImg, mask;
int hmin = 0, smin = 120, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;

int main(){

    string path = "/home/bhavik/projects/cv/img/apple4.jpg";

    bgrImg = imread(path);                              // Read Image in BGR format

    cvtColor(bgrImg, hsvImg, COLOR_BGR2HSV);            // Convert to HSV Space

    Scalar lower(hmin, smin, vmin); 
    Scalar upper(hmax, smax, vmax);

    inRange(hsvImg, lower, upper, mask);

    imshow("BGR Img", bgrImg);
    imshow("HSV Img", hsvImg);
    imshow("mask", mask);

    waitKey(3000);
    
    return 0;

}