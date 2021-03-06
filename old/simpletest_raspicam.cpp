 /*
    21.05.2017
    first example of raspicam with C++
    from: https://www.uco.es/investiga/grupos/ava/node/40

    compile command:
     g++ simpletest_raspicam.cpp -o simpletest_raspicam -I/usr/local/include -lraspicam -lmmal -lmmal_core -lmmal_util
    what the heck of a command. now i have to fiddle with MAKE (26.05.'17 successfully)

    26.05.'17
    ended processing this code futher. obsolet/redundant
  */
#include <ctime>
#include <time.h>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
using namespace std;

int main ( int argc,char **argv ) {
    raspicam::RaspiCam Camera; //Camera object

    struct timespec tim, tim2;
    tim.tv_sec=2;
    tim.tv_nsec = 500;

    //Open camera
    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;return -1;}
    //wait a while until camera stabilizes
    cout<<"Sleeping for 3 secs"<<endl;
    nanosleep(&tim, &tim2);
    //capture
    Camera.grab();
    //allocate memory
    unsigned char *data=new unsigned char[  Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB )];
    //extract the image in rgb format
    Camera.retrieve ( data,raspicam::RASPICAM_FORMAT_RGB );//get camera image
    //save
    std::ofstream outFile ( "raspicam_image.ppm",std::ios::binary );
    outFile<<"P6\n"<<Camera.getWidth() <<" "<<Camera.getHeight() <<" 255\n";
    outFile.write ( ( char* ) data, Camera.getImageTypeSize ( raspicam::RASPICAM_FORMAT_RGB ) );
    cout<<"Image saved at raspicam_image.ppm"<<endl;
    //free resources
    delete data;
    return 0;
}
