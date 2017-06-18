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

#define TESTVERSION 0
#define SILENT 1

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include "types.hpp"
#include <iostream>
#include <stdio.h>
//#include <ctime> //for time measuring
#include <sys/time.h> //for u_sec

using namespace std;
using namespace cv;

/**
 * @function main
 */
int main( int argc, char** argv )
{
  Mat src, dst;
  int x,y;
  x = 1;
  y = 0;

  int i,j;
  uchar* p;

  /// Load image
  src = imread( argv[1], 1 );

  if( !src.data )
    { printf("reading image unsuccessfull");return -1; }

  /// Separate the image in 3 places ( B, G and R )
  vector<Mat> bgr_planes;
  split( src, bgr_planes );

  #if TESTVERSION
  cout << "number of matrix channels: " << src.channels() << endl;
  cout << "    matrix size: " << src.size() << endl;
  cout << "\tpx: " << src.rows*src.cols<< endl << endl;

  for (i=0;i<9;i++){
    p = src.ptr<uchar>(0);
    cout << (float)p[i] << " ; ";
    if(i==2||i==5||i==8)cout<<endl;
  }
  #endif

//================================== HSV
Mat hsv;
#if TESTVERSION
  cout << "converting to hsv" << endl;
#endif
cvtColor( src, hsv, CV_RGB2HSV );
//cout << "number of hsv matrix channels: " << hsv.channels() << endl;
#if TESTVERSION
  cout << "hsv matrix size: " << hsv.size() << endl;
#endif

Vec3b hsv_intensity = hsv.at<Vec3b>(y,x);

#if TESTVERSION
  cout << "Hue \t[0]: \t" << (float)hsv_intensity.val[0] << endl; //cast to display value
  cout << "Saturation [1]: " << (float)hsv_intensity.val[1] << endl;
  cout << "Value \t[2]: \t" << (float)hsv_intensity.val[2] << endl << endl;
#endif

float sum = 0;
struct timeval t1, tend;


//cout << "value: " << (float)hsv.at<Vec3b>(y,x)[2]/2.55 <<endl;
#if TESTVERSION
  cout << "isContinuous: " << hsv.isContinuous() << endl;
#endif

//from: http://docs.opencv.org/2.4/doc/tutorials/core/how_to_scan_images/how_to_scan_images.html


int channels = hsv.channels();

int nRows = hsv.rows;
int nCols = hsv.cols * channels;

if (hsv.isContinuous())
{
    nCols *= nRows;
    nRows = 1;
}
#if TESTVERSION
  for (i=0;i<9;i++){
    p = hsv.ptr<uchar>(0);
    cout << (float)p[i] << " ; ";
    if(i==2||i==5||i==8)cout<<endl;
  }
#endif

//t1 = time(0);
gettimeofday(&t1,NULL);

for( i = 0; i < nRows; ++i)
{
    p = hsv.ptr<uchar>(i);
    for ( j = 2; j < nCols; j+=3)
    {

        //sum = hsv.at<Vec3b>(i,j)[2]/2.55;
        sum += p[j];
        if(j%nRows)cout<<"sum: "<<sum<<endl;
    }
}
//tend = time(0);
gettimeofday(&tend,NULL);

#if TESTVERSION
  cout << "! mind this value are not normalized to 100% - [divide by 256]" << endl;
#endif
#if SILENT
  cout << sum/(hsv.rows*hsv.cols) ;
#endif
#if !SILENT
  cout << "average intensity: " << sum/(hsv.rows*hsv.cols) << endl;
#endif

#if !SILENT
  cout << "loop duration: " << tend.tv_sec - t1.tv_sec  <<":"<< (tend.tv_usec - t1.tv_usec)/1000.0<< " seconds" << endl;
                                                                //this might be negative due to low capacity 4 bytes integer
#endif
//cout << "what hsv 2d: " << (float)hsv.at<uchar>(y,x) << endl; // I don't know return value represents?

//waitKey(0);

  return 0;
}

//prototype, if i wanted to build a function
//float calc_hsv(Mat* src,Mat*dst,)
