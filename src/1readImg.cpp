#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

int main(){

    // Reading Images

    // string path= "/home/bhavik/projects/cv/img/apple1.jpg";
    // Mat image;
    // image = imread(path);
    // imshow("Image",image);
    // waitKey(0);

    // Reading webcams

    VideoCapture cap(1);
    Mat img;

    while(true){
        cap.read(img);
        imshow("Image",img);
        waitKey(1);
    }

    return 0;
}

