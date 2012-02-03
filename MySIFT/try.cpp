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

using namespace cv;

int main()
{
	Mat img;
	Mat img_rotate;
	Mat dst;
	Mat big;
	Mat small;
	int height;
	int width;
	int step;
	int channels;

	// Read image & 
	img = imread("./cat.jpg");
	printf("Dims: %d \n", img.dims);
	printf("Row & Col: %d x %d \n", img.rows, img.cols);

	if (img.rows >= img.cols) {
		height = img.rows;
		width = img.rows * 2 + 100;
	}
	else {
		height = img.cols;
		width = img.cols * 2 + 100;
	}
		
	dst = img.t();
	big = Mat(height, width, img.type());
	big = Scalar(110, 10, 50);
	small = big(Rect(0, 0, img.rows, img.cols));
	img.copyTo(small);
	//img.copyTo((big(Range(0, img.rows), Range(0, img.cols))));
	//dst.copyTo(big.colRange(img.cols+100, img.cols+100+dst.cols));
	
	// ---------- Another way to rotate at arbitirary angle ---------- 
	//Point2f img_center(img.rows/2.0F, img.cols/2.0F);
	//img_rotate = getRotationMatrix2D(img_center, 90, 1.0);
	//warpAffine(img, dst, img_rotate, img.size());
	// ---------------------------------------------------------------
	printf("Dims: %d \n", dst.dims);
	printf("Size of image: %d x %d \n", dst.rows, dst.cols);
	
	// Create a window
	namedWindow("my_cat", CV_WINDOW_AUTOSIZE);	
	imshow("my_cat", big);
	//namedWindow("small", CV_WINDOW_AUTOSIZE);	
	//imshow("small", small);

	waitKey(0);
	img.release();
	dst.release();
	return 0;
}

