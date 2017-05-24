/*
  08.02.'17
  jarvis
  opencv with c, USB Cam (most internals are connected via USB)
  designed for linux arch
  mind including --libs opencv to compile command

  might(!) belong to:
  https://www.uco.es/investiga/grupos/ava/node/40
*/

#include "/home/pi/opencv-3.0.0/include/opencv/cv.h"
#include "/home/pi/opencv-3.0.0/include/opencv/highgui.h"
#include <stdio.h>

#define XRES 1280
#define YRES 720

int main (/*int argc, char** argc*/) {
  //open camera
  CvCapture* capture = 0;
  capture = cvCaptureFromCAM(-1);
  if(!capture) {
      fprintf(stderr,"could not open Camera Device");
      return -1;
  }

  //set resolution
cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH,XRES);
cvSetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT,YRES);

//grap and show frames
IplImage* frame = cvQueryFrame(capture);
cvNamedWindow(WINDOWNAME,CV_WINDOW_AUTOSIZE);
while(frame != NULL) {
  int key = cvWaitKey(10);
  if (key == 27) break; //stop, when ESC is pressed
  frame = cvQueryFrame(capture);
}

//close Camera
cvReleaseCapture( &capture);
cvDestroyWindow(WINDOWNAME);

return 0;
}
