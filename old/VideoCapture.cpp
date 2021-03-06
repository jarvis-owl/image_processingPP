/*
  compiles and works with:
  g++ $(pkg-config --libs --cflags opencv) -o SimpleGrab SimpleGrab.cpp

  no output generated yet
*/

//#include "/home/pi/opencv-3.0.0/include/opencv2/opencv.hpp"
//#include "/home/pi/opencv-3.0.0/modules/videoio/include/opencv2/videoio.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    Mat edges;
    namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
