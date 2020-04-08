#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	Mat srcMat = imread("lena_rot.jpg");
	Mat dstMat;
	int col = srcMat.cols;
	int row = srcMat.rows;
	int xfr=0;
	int yfr=0;
	int xfc = 0;
	int yfc = 0;
	int xlr = 0;
	int ylr = 0;
	int xlc = 0;
	int ylc = 0;
	//������һ��
	for (int i = 0; i < col-1; i++) {
		int a = srcMat.at<Vec3b>(0, i)[0]<250;
		int b = srcMat.at<Vec3b>(0, i)[1]<250;
		int c = srcMat.at<Vec3b>(0, i)[2]<250;
		//cout << a << b << c << endl;
		int test = a&&b&&c;
		//cout << "У����" << test << endl;
		if (test == 1) {
			yfr = i;
			break;
		}
	}
	//������һ��
	for (int i = 0; i < row-1; i++) {
		int a = srcMat.at<Vec3b>(i, 0)[0]<250;
		int b = srcMat.at<Vec3b>(i, 0)[1]<250;
		int c = srcMat.at<Vec3b>(i, 0)[2]<250;
		//cout << a << b << c << endl;
		int test = a&&b&&c;
		//cout << "У����" << test << endl;
		if (test == 1) {
			xfc = i;
			break;
		}
	}
	//�������һ��
	for (int i = 0; i < col-1; i++) {
		int a = srcMat.at<Vec3b>(row-1, i)[0]<250;
		int b = srcMat.at<Vec3b>(row-1, i)[1]<250;
		int c = srcMat.at<Vec3b>(row-1, i)[2]<250;
		//cout << a << b << c << endl;
		int test = a&&b&&c;
		//cout << "У����" << test << endl;
		if (test == 1) {
			ylr = i;
			break;
		}
	}
	//�������һ��
	for (int i = 0; i < row; i++) {
		int a = srcMat.at<Vec3b>(i , col-1)[0]<250;
		int b = srcMat.at<Vec3b>(i , col-1)[1]<250;
		int c = srcMat.at<Vec3b>(i , col-1)[2]<250;
		//cout << a << b << c << endl;
		int test = a&&b&&c;
		//cout << "У����" << test << endl;
		if (test == 1) {
			xlc = i;
			break;
		}
	}
	/*const Point2f src_pt[] = {
								Point2f(0,yfr),
								Point2f(xlc,col-1),
								Point2f(xfc ,0),
								Point2f(row - 1,ylr)};
	const Point2f dst_pt[] = {
								Point2f(0,0),
								Point2f(0,col - 1),
								Point2f(row - 1,0),
								Point2f(row - 1,col - 1)};*/
	const Point2f src_pt[] = {
								Point2f(yfr,0),
								Point2f(col - 1,xlc),
								Point2f(0,xfc ),
								Point2f(ylr,row - 1) };
	const Point2f dst_pt[] = {
								Point2f(0,0),
								Point2f(col - 1,0),
								Point2f(0,row - 1),
								Point2f(col - 1,row - 1) };
	//cout << src_pt << endl;
	Mat perspective_matrix = getPerspectiveTransform(src_pt, dst_pt);
	warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
	/*cout<<"��һ�б������:" << yfr << endl; 
	cout<<"��һ�б������:" << xfc << endl;
	cout<<"���һ�б������:" << ylr << endl;
	cout <<"���һ�б������"<< xlc << endl;
	cout << row << endl;
	cout << col << endl;
	system("pause");*/
}
