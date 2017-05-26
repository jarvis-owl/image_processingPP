
/*
  26.05.'17
  this should server as start/mask file for future code.
  derived from old/simpleCV.cpp [standard example from resource]
*/


#include <iostream>
#include <raspicam/raspicam_cv.h>
using namespace std;

int main ( int argc,char **argv ) {


    raspicam::RaspiCam_Cv Camera;
    cv::Mat image;
    int nCount=100;

    //set camera params
    Camera.set( CV_CAP_PROP_FORMAT, CV_8UC1 );

    //Open camera
    cout<<"Opening Camera..."<<endl;
    if (!Camera.open()) {cerr<<"Error opening the camera"<<endl;return -1;}

    //Start capture
    cout<<"Capturing "<<nCount<<" frames ...."<<endl;

    for ( int i=0; i<nCount; i++ ) {
        Camera.grab();
        Camera.retrieve ( image);
        if ( i%5==0 )  cout<<"\r captured "<<i<<" images"<<std::flush;
    }
    cout << endl;
    cout<<"Stop camera..."<<endl;
    Camera.release();


    //save image
    cv::imwrite("raspicam_cv_image.jpg",image);
    cout<<"Image saved at raspicam_cv_image.jpg"<<endl;

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
