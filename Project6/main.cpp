#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("D:\\coin.png", 0);
	cv::Mat binaryMat;
	cv::Mat erodeMat;
	cv::Mat dilateMat;
	cv::Mat openMat;
	cv::Mat closeMat;
	//¶þÖµ»¯
	cv::threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	imshow("binaryMat", binaryMat);
	//´´½¨½á¹¹ÔªËØ¼°¸÷ÖÖÔËËã
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(binaryMat, erodeMat, MORPH_ERODE, kernel);
	morphologyEx(binaryMat, dilateMat, MORPH_DILATE, kernel);
	morphologyEx(binaryMat, openMat, MORPH_OPEN, kernel);
	morphologyEx(binaryMat, closeMat, MORPH_CLOSE, kernel);

	imshow("erodeMat", erodeMat);
	imshow("dilateMat", dilateMat);
	imshow("openMat", openMat);
	imshow("closeMat", closeMat);
	waitKey(0);
	return 0;
}