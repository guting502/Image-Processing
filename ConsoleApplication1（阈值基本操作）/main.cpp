/*
*����ͨ������trackbar��������ֵ������
*ͨ������trackbar������
*�������ֵ���������£�
*0: THRESH_BINARY ��������ֵ��
*1: THRESH_BINARY_INV ����������ֵ��
*2: THRESH_TRUNC �ض���ֵ��
*3: THRESH_TOZERO ��ֵ��Ϊ0
*4: THRESH_TOZERO_INV ����ֵ��Ϊ0
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
char *outputimage = "��ֵͼ";
void threshold_demo(int, void *);
int main(int agrc, char**agrv){

	src = imread("999.jpg");
	if (src.empty()){
		cout << "û���ҵ�ͼƬ" << endl;
		return -1;
	}
	namedWindow("ԭͼ", CV_WINDOW_NORMAL);
	namedWindow(outputimage, CV_WINDOW_NORMAL);
	imshow("ԭͼ", src);
	createTrackbar("��ֵ��Χ", outputimage, &threshold_value, threshold_max, threshold_demo);
	createTrackbar("��ֵ����", outputimage, &threshold_type_value, threshold_type_max, threshold_demo);
	threshold_demo(0, 0);

	waitKey(0);
	return 0;

}
void threshold_demo(int, void *){
	cvtColor(src, gray_src,CV_BGR2GRAY );
	namedWindow("�Ҷ�ͼ", CV_WINDOW_NORMAL);
	imshow("�Ҷ�ͼ", gray_src);
	threshold(gray_src, dst, threshold_value,255,threshold_type_value);  
	//threshold(gray_src, dst, 0, 255, THRESH_OTSU|threshold_type_value);  //����ǰ�����ֵ0�����Զ���ȡ��ֵ
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
//const char *outputimage = "��ֵͼ";
//
//void threshold_demo(int, void*);
//int main(int agrc, char**agrv){
//	
//	src = imread("guting.jpg");
//	if (src.empty()){
//		cout << "û���ҵ�ͼƬ��" << endl;
//		return -1;
//	}
//	namedWindow("ԭͼ", CV_WINDOW_NORMAL);
//	namedWindow(outputimage, CV_WINDOW_NORMAL);
//	imshow("ԭͼ",src);
//	createTrackbar("��ֵ��Χ", outputimage, &threshold_value, threshold_max, threshold_demo);
//	createTrackbar("��ֵ����", outputimage, &threshold_type_value, threshold_type_max, threshold_demo);
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