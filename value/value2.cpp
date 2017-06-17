/*

  17.06.'17
  v02
  jarvis

  testing is done
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
#include <ctime> //for time measuring

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
    { printf("reading image unsuccessfull");return -1; }

  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  cout << "number of matrix channels: " << src.channels() << endl;
  cout << "matrix size: " << src.size() << endl;
  cout << "rows: " <<  src.rows << "\t cols: " << src.cols << "\tpx: " << src.rows*src.cols<< endl << endl;


//================================== HSV
Mat hsv;
cout << "converting to hsv" << endl;
cvtColor( src, hsv, CV_RGB2HSV );
cout << "number of hsv matrix channels: " << hsv.channels() << endl;
cout << "hsv matrix size: " << hsv.size() << endl;

Vec3b hsv_intensity = hsv.at<Vec3b>(y,x);

cout << "Hue [0]: \t\t" << (float)hsv_intensity.val[0] << endl; //cast to display value
cout << "Saturation [1]: \t" << (float)hsv_intensity.val[1] << endl;
cout << "Value [2]: \t\t" << (float)hsv_intensity.val[2]/2.55 << "/35" << endl << endl;

float sum = 0;
time_t t1 , tend;
t1 = time(0);

//cout << "value: " << (float)hsv.at<Vec3b>(y,x)[2]/2.55 <<endl;
cout << "isContinuous: " << hsv.isContinuous() << endl;

/*
for (int i = 0 ; i < hsv.rows ;  i++){
  for(int j = 0 ; i < hsv.cols ;  j++){
      //sum = (float)hsv_intensity.val[2]/2.55
      sum = hsv.at<Vec3b>(i,j)[2]/2.55;
      if(j==hsv.cols)cout<<sum<<endl;
  }
}
*/

//from: http://docs.opencv.org/2.4/doc/tutorials/core/how_to_scan_images/how_to_scan_images.html


int channels = hsv.channels();

int nRows = hsv.rows;
int nCols = hsv.cols * channels;

if (hsv.isContinuous())
{
    nCols *= nRows;
    nRows = 1;
}

int i,j;
uchar* p;
/*
for( i = 0; i < nRows; ++i)
{
    //p = hsv.ptr<uchar>(i);
    for ( j = 0; j < nCols; ++j)
    {
        //p[j] = table[p[j]];
        //sum = hsv.at<Vec3b>(i,j)[2]/2.55;
        sum = p[j]
        if(j==0)cout<<sum<<endl;
    }
}
*/
for (i=0;i<10;i++){
  p = hsv.ptr<uchar>(0);
  cout << (float)p[i] << endl;
}
tend = time(0);


cout << "average intensity: " << sum/(hsv.rows*hsv.cols) << endl;
cout << "loop duration: " << difftime(t1,tend) << " seconds" << endl;

//cout << "what hsv 2d: " << (float)hsv.at<uchar>(y,x) << endl; // I don't know return value represents?



 cout<< "completed" <<endl;
  //waitKey(0);

  return 0;
}

//prototype, if i wanted to build a function
//float calc_hsv(Mat* src,Mat*dst,)
