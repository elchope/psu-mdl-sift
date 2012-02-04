/****************************************************** 
 *	Code by Yang Xiao
 ******************************************************/

// try.cpp : Read and rotate the original image and display them.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cv.h"
#include "highgui.h"

// Namespace for CPP API
using namespace cv;

int main()
{
	IplImage* img = 0;
	IplImage* img_rotate = 0;
	IplImage* dst = 0;
	IplImage* big = 0;
	IplImage* small = 0;
	int height;
	int width;
	int step;
	int channels;

	// Read image & 
	img = cvLoadImage("./cat.jpg");
	height = img-> height;
	width = img-> width;
	printf("Row & Col: %d x %d \n", height, width);

	//Rotate image, for other angle refer to cvWarpAffine, cv2DRotationMatrix
	CvSize img_size;
	img_size.width = height;
	img_size.height = width;
	int flipmode;
	img_rotate = cvCreateImage(img_size, img-> depth, img-> nChannels);
	// clockwise 90 degree
	cvTranspose(img, img_rotate);
	flipmode = 1;
	cvFlip(img_rotate, img_rotate, flipmode);	
	// counter-clockwise 90 degree
	//cvTranspose(img, img_rotate);
	//flipmode = -1;
	//cvFlip(img_rotate, img_rotate, flipmode);	
	 

	
	// Create a window
	cvNamedWindow("my_cat", CV_WINDOW_AUTOSIZE);	
	cvShowImage("my_cat", img);
	cvNamedWindow("rotate", CV_WINDOW_AUTOSIZE);	
	cvShowImage("rotate", img_rotate);

	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&img_rotate);
	return 0;
}

