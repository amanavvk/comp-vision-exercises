#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(){
    Mat bgrImg, bigImg, cropImg;

    string path = "/home/bhavik/projects/cv/img/apple4.jpg";

    bgrImg = imread(path);                  // Size of Input img is 225*225

    resize(bgrImg, bigImg,Size(),3,3);      // Scale 3 times in x and y axis = 675*675

    Rect roi(100,100,400,400);                   // x, y , width, height 
    cropImg = bigImg(roi);      
                 

    imshow("Normal Image", bgrImg);
    imshow("Bigger Image", bigImg);
    imshow("Cropped Img", cropImg);

    waitKey(0);

    return 0;
}