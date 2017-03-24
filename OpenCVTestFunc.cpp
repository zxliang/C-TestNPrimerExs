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
  VideoCapture cap(0); //open the video camera no.0

  if (!cap.isOpened()) //if not success, exit program
  {
	cout << "Error: Cannot open the video file" << endl;
	return -1;
  }

  namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

  double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
  double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

  cout << "Frame Size = " << dWidth << "x" << dHeight << endl;

  Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

  VideoWriter oVideoWriter("D:/MyVideo.avi", CV_FOURCC('P', 'I', 'M', '1'), 20,
	frameSize, true); //initialize the VideoWriter object

  if (!oVideoWriter.isOpened()) //if not initialize the VideoWriter successfully, exit the program
  {
	cout << "Error: Failed to write the video" << endl;
	return -1;
  }

  while (1)
  {
	Mat frame;

	bool bSuccess = cap.read(frame); //read a new frame from video

	if (!bSuccess) //if not success, break loop
	{
	  cout << "Error: Cannot read a frame from video file" << endl;
	  break;
	}

	oVideoWriter.write(frame); //writer the frame into the file

	imshow("MyVideo", frame); //show the frame in "MyVideo" window

	if (waitKey(10) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
	{
	  cout << "esc key is pressed by user" << endl;
	  break;
	}
  }

  return 0;
}

int opencv_test6_1()
{
  //display the original image
  IplImage* img = cvLoadImage("MyPic.jpg");
  cvNamedWindow("MyWindow");
  cvShowImage("MyWindow", img);

  //erode and display the eroded image
  cvErode(img, img, 0, 2);
  cvNamedWindow("Eroded");
  cvShowImage("Eroded", img);

  cvWaitKey(0);

  //cleaning up
  cvDestroyWindow("MyWindow");
  cvDestroyWindow("Eroded");
  cvReleaseImage(&img);

  return 0;
}

int opencv_test6_2()
{
  //display the original image
  IplImage* img = cvLoadImage("MyPic.jpg");
  cvNamedWindow("MyWindow");
  cvShowImage("MyWindow", img);

  //dilate and display the dilated image
  cvDilate(img, img, 0, 2);
  cvNamedWindow("Dilated");
  cvShowImage("Dilated", img);

  cvWaitKey(0);

  //cleaing up
  cvDestroyWindow("MyWindow");
  cvDestroyWindow("Dilated");
  cvReleaseImage(&img);
  
  return 0;
}

int opencv_test6_3()
{
  //display the original image
  IplImage* img = cvLoadImage("MyPic.jpg");
  cvNamedWindow("MyWindow");
  cvShowImage("MyWindow", img);

  //invert and display the dilated image
  cvNot(img, img);
  cvNamedWindow("Inverted");
  cvShowImage("Inverted", img);

  cvWaitKey(0);

  //cleaing up
  cvDestroyWindow("MyWindow");
  cvDestroyWindow("Inverted");
  cvReleaseImage(&img);

  return 0;
}

int opencv_test7()
{
  //Read original image
  Mat src = imread("MyPic.jpg");

  //if fail to read tje image
  if (!src.data)
  {
	cout << "Error loading the image" << endl;
	return -1;
  }

  //Create a window
  namedWindow("My Window", 1);

  //Create trackbar to change brightness
  int iSliderValue1 = 50;
  createTrackbar("Brightness", "My Window", &iSliderValue1, 100);

  //Create trackbar to change contrast
  int iSliderValue2 = 50;
  createTrackbar("Contrast", "My Window", &iSliderValue2, 100);

  while (true)
  {
	//Change the brightness and contrast of the image (For more information
	//http://opencv-srf.blogspot.com/2013/07/change-contrast-of-image-or-video.html)

	Mat dst;
	int iBrightness = iSliderValue1 - 50;
	double dContrast = iSliderValue2 / 50.0;
	src.convertTo(dst, -1, dContrast, iBrightness);

	//show the brightness and contrast adjusted image
	imshow("My Window", dst);

	//Wait until user press some key for 50ms
	int iKey = waitKey(50);

	//if user press 'ESC' key
	if (iKey == 27)
	{
	  break;
	}

  }

  return 0;
}

//3 functions for trackbar with callback functions
Mat src;

void MyCallbackForBrightness(int iValueForBrightness, void *userData)
{
  Mat dst;
  int iValueForContrast = *( static_cast<int*>(userData) );

  //Calculating brightness and contrast value
  int iBrightness = iValueForBrightness - 50;
  double dContrast = iValueForContrast / 50.0;

  //Calculated contrast and brightness value
  cout << "MyCallbackForBrightness: Contrast = " << dContrast << ", Brightness = "
	<< iBrightness << endl;

  //adjust the brightness and contrast
  src.convertTo(dst, -1, dContrast, iBrightness);

  //show the brightness and contrast adjusted image
  imshow("My Window", dst);
}

void MyCallbackForContrast(int iValueForContrast, void *userData)
{
  Mat dst;
  int iValueForBrightness = *( static_cast<int*>(userData) );

  //Calculating brightness and contrast value
  int iBrightness = iValueForBrightness - 50;
  double dContrast = iValueForContrast / 50.0;

  //Calculated contrast and brightness value
  cout << "MyCallbackForContrast: Contrast = " << dContrast << ", Brightness = "
	<< iBrightness << endl;

  //adjust the brightness and contrast
  src.convertTo(dst, -1, dContrast, iBrightness);

  //show the brightness and contrast adjusted image
  imshow("My Window", dst);
}

int opencv_test8()
{
  //Read original image
  src = imread("MyPic.jpg");

  //if fail to read the iamge
  if (src.data == false)
  {
	cout << "Error loading the iamge" << endl;
	return -1;
  }

  //Create a window
  namedWindow("My Window", 1);

  int iValueForBrightness = 50;
  int iValueForContrast = 50;

  //Create track bar to change brightness
  createTrackbar("Brightness", "My Window", &iValueForBrightness, 100,
	MyCallbackForBrightness, &iValueForContrast);

  //Create track bar to change contrast
  createTrackbar("Contrast", "My Window", &iValueForContrast, 100,
	MyCallbackForContrast, &iValueForBrightness);

  imshow("My Window", src);

  //Wait until user press some key
  waitKey(0);

  return 0;
}