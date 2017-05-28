
/*
  27.05.'17
  v01
  jarvis

  check image brightness, if satisfactory append to video

  might help:
    VideoWriter::write
    project histogram (perhaps project grayscale)
    example changing contras and brightness of an image [source: http://docs.opencv.org/3.0-beta/doc/tutorials/core/basic_linear_transform/basic_linear_transform.html#basic-linear-transform]
    cvtColor(src, dst, code, dst n channel) [http://docs.opencv.org/2.4/modules/imgproc/doc/miscellaneous_transformations.html]
      - convert to HSV and check V channel
      - code: CV_BGR2HSV
    accesing pixel intensity values [http://docs.opencv.org/2.4.13.2/doc/user_guide/ug_mat.html#accessing-pixel-intensity-values]
    MAT basics - need to access the V value [http://docs.opencv.org/2.4/doc/tutorials/core/mat_the_basic_image_container/mat_the_basic_image_container.html#matthebasicimagecontainer]
*/



#include <opencv/cv.h>
#include "opencv2/highgui/highgui.hpp" //#include <highgui.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

#include <raspicam/raspicam_cv.h>

using namespace cv;

int main( int argc, char** argv )
{

  if (argc<2) char* pathname = argv[1];

  Mat src;
  Mat dst;
  Mat hsv;
  //set camera params
  raspicam::RaspiCam_Cv Camera;
  Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );
  if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}
  
  //could be simplified with Camera.read(src)
  Camera.grab();
  Camera.retrieve(src);


  //CONVERT
  cvtColor( src, hsv, CV_BGR2HSV );

  //imwrite( "Gray_Image.jpg", gray_image );


  return 0;
}
