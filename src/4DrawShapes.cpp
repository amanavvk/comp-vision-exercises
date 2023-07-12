#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(){

    Mat Img(512,512,CV_8UC3, Scalar(20,0,200));

    rectangle(Img, Point(50,50),Point(462,462),Scalar(255,255,255),5);

    circle(Img,Point(256,256),150,Scalar(255,255,255),8);
    
    line(Img, Point(25,25),Point(487,25), Scalar(0,0,0),5);             // Point (x,y)
    line(Img, Point(25,25),Point(25,487), Scalar(0,0,0),5);
    line(Img, Point(487,25),Point(487,487), Scalar(0,0,0),5);
    line(Img, Point(25,487),Point(487,487), Scalar(0,0,0),5);

    putText(Img, "Bhavik", Point(200,256),FONT_HERSHEY_PLAIN, 3,Scalar(0,0,0),3);

    imshow("Image",Img);

    waitKey(0);

    return 0;
}