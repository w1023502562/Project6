#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("D:\\4.png", 0);
	cv::Mat binaryMat;
	cv::Mat labels;
	cv::Mat stats;
	cv::Mat centroids;
	cv::bitwise_not(srcMat, srcMat);
	//��ֵ��
	cv::threshold(srcMat, binaryMat, 0, 255, THRESH_OTSU);
	//�����ṹԪ��
	Mat kernel = getStructuringElement(MORPH_RECT, Size(9, 9));
	//������
	morphologyEx(binaryMat, binaryMat, MORPH_OPEN, kernel);
	//�����ͨ��
	int liantongyu = connectedComponentsWithStats(binaryMat,
		labels,
		stats,
		centroids,
		8,
		CV_32S);

	//�����ͨ����Ϣ

	for (int i = 0; i < liantongyu; i++)
	{
		cout << "��ͨ����ţ� " << i << endl;
		cout << "width = " << stats.at<int>(i, 2) << endl;
		cout << "height = " << stats.at<int>(i, 3) << endl;
		cout << "pixels = " << stats.at<int>(i, 4) << endl;

	}
	cout << "sum = " << liantongyu - 1 << endl;
	//����bounding box
	for (int i = 1; i < liantongyu; i++)
	{

		char num[10];
		sprintf_s(num, "%d", i);

		Rect boundingbox;
		//bounding box���Ͻ�����
		boundingbox.x = stats.at<int>(i, 0);
		boundingbox.y = stats.at<int>(i, 1);
		//bouding box�Ŀ�ͳ� 
		boundingbox.width = stats.at<int>(i, 2);
		boundingbox.height = stats.at<int>(i, 3);
		//����
		rectangle(binaryMat, boundingbox, CV_RGB(255, 255, 255), 1, 8, 0);
	}

	imshow("binaryMat", binaryMat);

	imshow("frame", srcMat);
	waitKey(0);
	return 0;
}