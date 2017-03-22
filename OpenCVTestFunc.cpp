// testing openCV property
#include "OpenCVHeader.h"

int opencv_test1()
{
  Mat img = imread("MyPic.jpg", CV_LOAD_IMAGE_UNCHANGED); //read the image data in the file "MyPic.JPG" and store it in 'img'

  if (img.empty()) //check whether the image is loaded or not
  {
	cout << "Error : Image cannot be loaded..!!" << endl;
	//system("pause"); //wait for a key press
	return -1;
  }

  namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
  imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

  waitKey(0); //wait infinite time for a keypress

  destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

  return 0;
}

int opencv_test1_1()
{
  Mat img(500, 1000, CV_8UC3, Scalar(0, 0, 100)); //create a image (3 channels,
  // 8 bit image depth, 500 high, 1000 wide, (0, 0, 100) assigned for Blue, 
  // Green, and Red plane respectively.)

  if (img.empty()) //check whether the image is loaded or not
  {
	cout << "Error: image cannot be loaded!!!" << endl;
	//system("pause"); //wait for a key press
	return -1;
  }

  namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
  imshow("MyWindow", img); //display the image which is stored in the 'img' in the 
  //"MyWindow" window

  waitKey(0); //wait infinite time for a keypress

  destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

  return 0;
}



int opencv_test2()
{
  VideoCapture cap("SampleVideo.avi"); // open the video file for reading

  if (!cap.isOpened()) // if not success, exit program
  {
    cout << "Cannot open the video file" << endl;
    return -1;
  }

  //cap.set(CV_CAP_PROP_POS_MSEC, 300); //start the video at 300ms
  double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video
  cout << "Frame per seconds: " << fps << endl;

  namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
  while (1)
  {
    Mat frame;

	bool bSuccess = cap.read(frame); //read a new fram from video

	if (!bSuccess) //if not success, break loop
	{
	  cout << "Cannot read the frame from video file" << endl;
	  break;
	}

	imshow("MyVideo", frame); //show the frame in "MyVideo" window

	if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
	{
	  cout << "esc key is pressed by user" << endl;
	  break;
	}
  }

  return 0;
}

int opencv_test3()
{
  VideoCapture cap(0); //open video camera no. 0

  if (!cap.isOpened()) //if not success, exit program
  {
    cout << "Cannot open the video cam" << endl;
	return -1;
  }

  double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
  double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

  cout << "Frame size: " << dWidth << "x" << dHeight << endl;

  namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

  while (1)
  {
	Mat frame;

	bool bSuccess = cap.read(frame); // read a new frame from video

	if (!bSuccess) //if not success, break loop
	{
		cout << "Cannot read a frame from video stream" << endl;
		break;
	}

	imshow("MyVideo", frame); //show the frame in "MyVideo" window

	if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
	{
		cout << "esc key is pressed by user" << endl;
		break;
	}
  }

  return 0;
}

int opencv_test4()
{
  Mat img(650, 600, CV_16UC3, Scalar(0, 50000, 50000)); //create an image (3 
  // channels, 16 bit image depth, 650 high, 600 wide, (0, 50000, 50000) assigned
  // for Blue, Green, and Red plane respectively.)

  if (img.empty()) //check whether the image is loaded or not
  {
	cout << "Error: Image cannot be loaded!!!" << endl;
	//system("pause"); //wait for a key press
	return -1;
  }

  vector<int> compression_params; //vector that store the compression parameters of the image

  compression_params.push_back(CV_IMWRITE_JPEG_QUALITY); //specify the compression technique

  compression_params.push_back(98); //specify the compression quality

  bool bSuccess = imwrite("D:/TestImage.jpg", img, compression_params); //write the image to file

  if (!bSuccess)
  {
	cout << "Error: Failed to save image" << endl;
	//system("pause"); //wait for a key press
  }

  namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
  imshow("MyWindow", img); //display the image which is stored in the 'img' in the "MyWindow" window

  waitKey(0); //watif for a keypress

  destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

  return 0;
}

int opencv_test5()
{


  return 0;
}