
/*
  26.05.'17
  this may become my very first project

  Aim:
      learn and use raspicam as well as OpenCV 3.0.0

      capture several frames ~ several seconds - concatenate those images to one mp4 file
      process capured images (only for getting used to it)
        - grayscale
        - determine brightness
*/

#define N_COUNT 100

#include <iostream>
#include <raspicam/raspicam_cv.h> // on RPi @ /usr/local/include/
// raspicam_cv.h includes opecv2/core/core.hpp as well as opencv/highgui/highgui.hpp by itself
using namespace std;

int main ( int argc,char **argv ) {

    char pathname[] = "/home/pi/shared/from_project_1.jpg"

    raspicam::RaspiCam_Cv Camera;
    cv::Mat src;
    cv::Mat dst;


    //set camera params
    Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );

    //Open camera
    cout<<"Opening Camera..."<<endl;
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}

    //Start capture
    cout<<"Capturing "<<N_COUNT<<" frames ...."<<endl;

    //for ( int i=0; i<N_COUNT; i++ ) {
        Camera.grab();
        Camera.retrieve ( src);

        dst = src.clone;

      //  if ( i%5==0 )  cout<<"\r captured "<<i<<" images"<<std::flush;
    //}
    cout << endl;
    cout<<"Stop camera..."<<endl;
    Camera.release();

    //process one image

    //save image
    cv::imwrite(pathname,dst);
    cout<<"Image saved at "<< pathname <<endl;

    return 0;
}

/*
============================ COMPILING ============================
Now, create a file named CMakeLists.txt and add:
#####################################
cmake_minimum_required (VERSION 2.8)
project (raspicam_test)
find_package(raspicam REQUIRED)
find_package(OpenCV)
IF  ( OpenCV_FOUND AND raspicam_CV_FOUND)
	MESSAGE(STATUS "COMPILING OPENCV TESTS")
	add_executable (MASK MASK.cpp)
	target_link_libraries (MASK ${raspicam_CV_LIBS})
ELSE()
	MESSAGE(FATAL_ERROR "OPENCV NOT FOUND IN YOUR SYSTEM")
ENDIF()
#####################################

Finally, create,compile and execute
mkdir build
cd build
cmake ..
make
./MASK

*/
