
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

using namespace cv;

int main( int argc, char** argv )
{
 char* imageName = argv[1];

 Mat image;
 image = imread( imageName, 1 );

 if( argc != 2 || !image.data )
 {
   printf( " No image data \n " );
   return -1;
 }

//CONVERT
 Mat hsv_image;
 cvtColor( image, hsv_image, CV_BGR2HSV );

 //imwrite( "Gray_Image.jpg", gray_image );


 return 0;
}
