/*
*程序通过创建trackbar来控制阈值化类型
*通过调节trackbar来调节
*其具体阈值化类型如下：
*0: THRESH_BINARY 二进制阈值化
*1: THRESH_BINARY_INV 反二进制阈值化
*2: THRESH_TRUNC 截断阈值化
*3: THRESH_TOZERO 阈值化为0
*4: THRESH_TOZERO_INV 反阈值化为0
*/
#include<opencv2\opencv.hpp>
#include<iostream>
#include"math.h"
using namespace std;
using namespace cv;
Mat src, dst, gray_src;
int threshold_value = 127;
int threshold_max = 255;
int threshold_type_value = 0;
int threshold_type_max = 4;
char *outputimage = "阈值图";
void threshold_demo(int, void *);
int main(int agrc, char**agrv){

	src = imread("999.jpg");
	if (src.empty()){
		cout << "没有找到图片" << endl;
		return -1;
	}
	namedWindow("原图", CV_WINDOW_NORMAL);
	namedWindow(outputimage, CV_WINDOW_NORMAL);
	imshow("原图", src);
	createTrackbar("阈值范围", outputimage, &threshold_value, threshold_max, threshold_demo);
	createTrackbar("阈值类型", outputimage, &threshold_type_value, threshold_type_max, threshold_demo);
	threshold_demo(0, 0);

	waitKey(0);
	return 0;

}
void threshold_demo(int, void *){
	cvtColor(src, gray_src,CV_BGR2GRAY );
	namedWindow("灰度图", CV_WINDOW_NORMAL);
	imshow("灰度图", gray_src);
	threshold(gray_src, dst, threshold_value,255,threshold_type_value);  
	//threshold(gray_src, dst, 0, 255, THRESH_OTSU|threshold_type_value);  //不管前面的阈值0，会自动的取阈值
	imshow(outputimage, dst);

}

//
//#include<opencv2\opencv.hpp>
//#include<iostream>
//#include<math.h>
//using namespace cv;
//using namespace std;
//Mat src, gray_src,dst;
//int threshold_value = 127;
//int threshold_max = 255;
//int threshold_type_value = 0;
//int threshold_type_max = 4;
//const char *outputimage = "阈值图";
//
//void threshold_demo(int, void*);
//int main(int agrc, char**agrv){
//	
//	src = imread("guting.jpg");
//	if (src.empty()){
//		cout << "没有找到图片！" << endl;
//		return -1;
//	}
//	namedWindow("原图", CV_WINDOW_NORMAL);
//	namedWindow(outputimage, CV_WINDOW_NORMAL);
//	imshow("原图",src);
//	createTrackbar("阈值范围", outputimage, &threshold_value, threshold_max, threshold_demo);
//	createTrackbar("阈值类型", outputimage, &threshold_type_value, threshold_type_max, threshold_demo);
//	threshold_demo(0, 0);
//	waitKey(0);
//	return 0;
//}
//void threshold_demo(int, void*){
//	cvtColor(src, gray_src, CV_BGR2GRAY);
//	threshold(gray_src, dst, threshold_value, 255, THRESH_OTSU|threshold_type_value);
//	imshow(outputimage, dst);
//
//
//
//}