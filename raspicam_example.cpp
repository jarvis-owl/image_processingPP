
/*
  25.05.'17
  this is an original example from the raspicam creators

  source:
  https://www.uco.es/investiga/grupos/ava/node/40
  https://sourceforge.net/projects/raspicam/files/?


  fiddeling with compilers
  make

guess i'm going to reinstall raspicam, newer version
26.05.'17 done
compiling with make successfull
this example is slightly simpler than simpleCV, though I create my MASK.cpp from that.
*/


#include <ctime>
#include <fstream>
#include <iostream>
#include <raspicam/raspicam.h>
using namespace std;

int main ( int argc,char **argv ) {
    raspicam::RaspiCam Camera; //Cmaera object
    //Open camera
    cout<<"Opening Camera..."<<endl;
    if ( !Camera.open()) {cerr<<"Error opening camera"<<endl;return -1;}
    //wait a while until camera stabilizes
    cout<<"Sleeping for 3 secs"<<endl;
    sleep(3);
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
    //free resrources
    delete data;
    return 0;
