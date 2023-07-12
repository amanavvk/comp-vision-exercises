#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(){
    Mat grayImage, bgrImg, rgbImage, blurImg, cannyImg, dilateImg, erodeImg;

    string path = "/home/bk/github/comp-vision-exercises/img/apple4.jpg";

    grayImage = imread(path, IMREAD_GRAYSCALE);         // Read image as grayScale

    bgrImg = imread(path);                              // Read Image in BGR format

    // Functions for various operations on Image

    cvtColor(bgrImg,rgbImage, COLOR_BGR2RGB );          // Changing color scale

    GaussianBlur(bgrImg,blurImg, Size(3,3), 5,0 );      // Applying gaussian blur

    Canny(blurImg, cannyImg, 40,100);                   // Canny edge detection

    Mat kernal = getStructuringElement(MORPH_RECT, Size(5,5));

    dilate(cannyImg, dilateImg, kernal);                // Dilation of detected edge image 

    erode(cannyImg, erodeImg, kernal);                  // Erorded edge detected image

    
    imshow("Gray Img",grayImage );                      // Show gray Scale image
    imshow("bgr Img", bgrImg);                          // Show BGR image
    imshow("RGB Image", rgbImage);
    imshow("Blur Image", blurImg);
    imshow("Canny Edges", cannyImg);
    imshow("Dilated Img", dilateImg);
    imshow("Eroded Img", erodeImg);

    waitKey(0);

    return 0;
}