#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

using namespace cv;


int main() {

	setlocale(LC_ALL, "Russian");
	Mat img = imread("C:/Users/User/Downloads/1111.jpg");
	Mat mask = Mat::zeros(img.size(), CV_8UC1);
	Mat mask2;

	int x = img.cols / 2;
	int y = img.rows / 2;
	Mat first = img(Rect(0, 0, x, y));
	Mat second = img(Rect(x, 0, y, y));
	Mat third = img(Rect(0, y, x, y));
	Mat fourth = img(Rect(x, y, x, y));

	Mat copy = img.clone();

	if (img.empty()) {
		std::cout << "Не удалось загрузить изображение" << std::endl;
		return -1;
	}

	imshow("Original Image", img);
	waitKey(0);

	putText(copy, "Width: " + std::to_string(img.cols) + ", Height: " + std::to_string(img.rows), Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(255, 255, 255), 2);
	rectangle(copy, Rect(300, 300, 100, 400), Scalar(0, 255, 255), 8);
	circle(copy, Point(150, 150), 50, Scalar(0, 128, 128), -1);
	imshow("Original Image", copy);
	waitKey(0);

	imshow("1", first);
	imshow("2", second);
	imshow("3", third);
	imshow("4", fourth);
	waitKey(0);

	circle(mask, Point(172, 200), 77, Scalar(255), FILLED);
	img.copyTo(mask2, mask);
	imshow("Mask", mask2);
	waitKey(0);

	return 0;
}