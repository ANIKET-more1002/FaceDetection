#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> 
#include<opencv2/objdetect.hpp>
#include <iostream> 
using namespace cv;
using namespace std;
///////////////// Face detection  on webcam ////////////////////// 
int main() {
	VideoCapture cap(0);
	Mat img;
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) {        /// not necessary step. it's only checking for xml file load or not
		cout << "cascade file is not loaded" << endl;
	}
	vector<Rect>faces;

	while (true)
	{

		cap.read(img);
		faceCascade.detectMultiScale(img, faces, 1.1, 10);
		for (int i = 0; i < faces.size(); i++) {
			Mat imgCrop = img(faces[i]);
			//imshow(to_string(i),imgCrop);
			imwrite("Resources/Faces/" + to_string(i) + ".png", imgCrop);
			rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
		}
		//imshow("Image", img);
		imshow("face detector", img);
		waitKey(1);
	}
}

