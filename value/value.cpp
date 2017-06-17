/*

  17.06.'17
  v01
  jarvis

  test two ways of determine a given images brightness

  cloned ./histogram.cpp

  found : http://docs.opencv.org/trunk/df/d9d/tutorial_py_colorspaces.html
  for colored object tracking
*/


#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "types.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/**
 * @function main
 */
int main( int argc, char** argv )
{
  Mat src, dst;
  int x,y;
  x = y = 5;

  /// Load image
  src = imread( argv[1], 1 );

  if( !src.data )
    { printf("reading image  unsuccessfull");return -1; }

  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  cout << "number of matrix channels: " << src.channels() << endl;
  cout << "matrix size: " << src.size() << endl;

 Vec3b intensity = src.at<Vec3b>(y,x);
 uchar blue = intensity.val[0];
 uchar green = intensity.val[1];
 uchar red = intensity.val[2];

cout << "blue: " << (int)blue << endl; //cast to display value
cout << "green: " << (int)green << endl;
cout << "red: " << (int)red << endl << endl;

//================================== GRAY
Mat gray_image;
cout << "converting to grayscale" << endl;
cvtColor( src, gray_image, CV_BGR2GRAY );
cout << "number of gray matrix channels: " << gray_image.channels() << endl;
cout << "gray matrix size: " << gray_image.size() << endl;

Scalar gray_intensity = gray_image.at<uchar>(y,x);
cout << "gray: " << (int)gray_intensity[0] << endl << endl;

//================================== HSV
Mat hsv;
cout << "converting to hsv" << endl;
cvtColor( src, hsv, CV_RGB2HSV );
cout << "number of hsv matrix channels: " << hsv.channels() << endl;
cout << "hsv matrix size: " << hsv.size() << endl;

Vec3b hsv_intensity = hsv.at<Vec3b>(y,x);

cout << "Hue [0]: \t\t" << (float)hsv_intensity.val[0] << "/123"<< endl; //cast to display value
cout << "Saturation [1]: \t" << (float)hsv_intensity.val[1] << "/25" << endl;
cout << "Value [2]: \t\t" << (float)hsv_intensity.val[2] << "/35" << endl << endl;



cout << "what src: " << (int)src.at<uchar>(y,x) << endl;
cout << "what hsv 2d: " << (float)hsv.at<uchar>(y,x) << endl;
cout << "sizeof: " << sizeof(hsv.at<uchar>(y,x)) << endl;
//cout << "what hsv 1d: " << (int)hsv.at<uchar>(0) << endl;
cout << "hsv.dims " << (int)hsv.dims << endl;


 cout<< "completed" <<endl;
  //waitKey(0);

  return 0;
}
