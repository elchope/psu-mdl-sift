/****************************************************** 
 *	Code by Utkarsh Sinha
 *	Based on JIFT by Jun Liu
 *	Visit http://aishack.in/ for more indepth articles and tutorials
 *	on artificial intelligence
 * Use, reuse, modify, hack, kick. Do whatever you want with
 * this code :)
 ******************************************************/

// MySIFT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "SIFT.h"

#include "opencv/cv.h"
#include "opencv/highgui.h"

// The main function!
int main()
{
	// Create an instance of SIFT
	SIFT *sift_1 = new SIFT("./cat.jpg", 4, 2);
	SIFT *sift_2 = new SIFT("./cat_2.jpg", 4, 2);
	
	IplImage* img_org = 0;
	IplImage* img_rotate = 0;
	
	sift_1->DoSift();					// Find keypoints
	sift_1->ShowAbsSigma();				// Display the sigma table
	img_org = sift_1->ReturnKeypoints();	// Show the keypoints

	sift_2->DoSift();					// Find keypoints
	sift_2->ShowAbsSigma();				// Display the sigma table
	img_rotate = sift_2->ReturnKeypoints();	// Show the keypoints
	
	cvShowManyImages("Cats", 2, img_org, img_rotate);	
	
	// Cleanup and exit
	delete sift_1;
	delete sift_2;
	cvReleaseImage(&img_org);
	cvReleaseImage(&img_rotate);
	return 0;
}

