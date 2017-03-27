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

void CallBackFunc1(int event, int x, int y, int flags, void* userdata)
{
  if (event == EVENT_LBUTTONDOWN)
  {
	cout << "Left button of the mouse is clicked - position (" << x << ", " << y
	  << ")" << endl;
  }
  else if (event == EVENT_RBUTTONDOWN)
  {
	cout << "Right button of the mouse is clicked - position (" << x << ", " << y
	  << ")" << endl;
  }
  else if (event == EVENT_MBUTTONDOWN)
  {
	cout << "Middle button of the mouse is clicked - position (" << x << ", " << y
	  << ")" << endl;
  }
  else if (event == EVENT_MOUSEMOVE)
  {
	cout << "Mouse move over the window - position (" << x << ", " << y << ")" <<
	  endl;
  }

}

void CallBackFunc2(int event, int x, int y, int flags, void* userdata)
{
  if (flags == EVENT_FLAG_CTRLKEY + EVENT_FLAG_LBUTTON)
  {
	cout << "Left mouse button is clicked while pressing CTRL key - position ("
	  << x << ", " << y << ")" << endl;
  }
  else if (flags == EVENT_FLAG_SHIFTKEY + EVENT_FLAG_RBUTTON)
  {
	cout << "Right mouse button is clicked while pressing SHIFT key - position ("
	  << x << ", " << y << ")" << endl;
  }
  else if (event == EVENT_MOUSEMOVE && flags == EVENT_FLAG_ALTKEY)
  {
	cout << "Mouse is moved over the window while pressing ALT key - position ("
	  << x << ", " << y << ")" << endl;
  }

}

int opencv_test9()
{
  //Read image from file
  Mat img = imread("MyPic.jpg");

  //if fali to read the image
  if (img.empty())
  {
	cout << "Error loading the image" << endl;
	return -1;
  }

  //Create a window
  namedWindow("My Window", 1);

  //set the callback function 1 or 2 for different mouse event
  setMouseCallback("My Window", CallBackFunc2, NULL);

  //show the image
  imshow("My Window", img);

  //Wait until user press some key
  waitKey(0);

  return 0;
}

int opencv_test10()
{
  //Load the image
  Mat imgOriginal = imread("MyPic.jpg", 1);

  //show the original image
  const char* pzOriginalImage = "Original Image";
  namedWindow(pzOriginalImage, CV_WINDOW_AUTOSIZE);
  imshow(pzOriginalImage, imgOriginal);

  const char* pzRotatedImage = "Rotated Image";
  namedWindow(pzRotatedImage, CV_WINDOW_AUTOSIZE);

  int iAngle = 180;
  createTrackbar("Angle", pzRotatedImage, &iAngle, 360);

  int iImageHeight = imgOriginal.rows / 2;
  int iImageWidth = imgOriginal.cols / 2;

  while (true)
  {
	Mat matRotation = getRotationMatrix2D( Point(iImageWidth, iImageHeight),
	  (iAngle - 180), 1);

	//Rotate the image
	Mat imgRotated;
	warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size());

	imshow(pzRotatedImage, imgRotated);

	int iRet = waitKey(30);
	if (iRet == 27)
	{
	  break;
	}
  }

  return 0;
}

int iAngle = 180;
int iScale = 50;
int iBorderMode = 0;
Mat imgOriginal;
int iImageCenterY = 0;
int iImageCenterX = 0;
const char* pzRotatedImage = "Rotated Image";

void CallbackForTrackBar(int, void*)
{
  Mat matRotation = getRotationMatrix2D(Point(iImageCenterX, iImageCenterY),
	(iAngle - 180), iScale / 50.0);

  //Rotate the image
  Mat imgRotated;
  warpAffine(imgOriginal, imgRotated, matRotation, imgOriginal.size(),
	INTER_LINEAR, iBorderMode, Scalar());

  imshow(pzRotatedImage, imgRotated);
}

int opencv_test11()
{
  //Load the image
  imgOriginal = imread("MyPic.jpg", 1);

  iImageCenterY = imgOriginal.rows / 2;
  iImageCenterX = imgOriginal.cols / 2;

  //show the original image
  const char* pzOriginalImage = "Original Image";
  namedWindow(pzOriginalImage, CV_WINDOW_AUTOSIZE);
  imshow(pzOriginalImage, imgOriginal);

  //create the "Rotated Image" window and 3 trackbars in it
  namedWindow(pzRotatedImage, CV_WINDOW_AUTOSIZE);
  createTrackbar("Angle", pzRotatedImage, &iAngle, 360, CallbackForTrackBar);
  createTrackbar("Scale", pzRotatedImage, &iScale, 100, CallbackForTrackBar);
  createTrackbar("Border Mode", pzRotatedImage, &iBorderMode, 5, CallbackForTrackBar);

  int iDummy = 0;

  CallbackForTrackBar(iDummy, &iDummy);

  waitKey(0);

  return 0;
}

int opencv_test12()
{
  //open the video file for reading
  VideoCapture cap("SampleVideo.avi");

  //if not success, exit program
  if (!cap.isOpened())
  {
	cout << "Cannot open the video file!" << endl;
	return -1;
  }

  const char* pzOriginalWindowName = "Original Video";
  namedWindow(pzOriginalWindowName, CV_WINDOW_AUTOSIZE);

  const char* pzRotatingWindowName = "Rotated Video";
  namedWindow(pzRotatingWindowName, CV_WINDOW_AUTOSIZE);

  int iAngle = 180;
  createTrackbar("Angle", pzRotatingWindowName, &iAngle, 360);

  while (true)
  {
	Mat matOriginalFrame;

	//read a new fram from video
	bool bSuccess = cap.read(matOriginalFrame);

	//if not success, break up
	if (!bSuccess)
	{
	  cout << "Cannot read the frame from video file!" << endl;
	  break;
	}

	imshow(pzOriginalWindowName, matOriginalFrame);

	//get the affine trasnformation matrix
	Mat matRotation = getRotationMatrix2D(Point(matOriginalFrame.cols / 2,
	  matOriginalFrame.rows / 2), (iAngle - 180), 1);

	//rotate the image
	Mat matRotatedFrame;
	warpAffine(matOriginalFrame, matRotatedFrame, matRotation,
	  matOriginalFrame.size());

	imshow(pzRotatingWindowName, matRotatedFrame);

	//wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
	if (waitKey(30) == 27)
	{
	  cout << "esc key is pressed by user" << endl;
	  break;
	}

  }

  return 0;
}

int opencv_test13()
{
  VideoCapture cap(0); //capture the video from web cam
  
  if (!cap.isOpened()) //if not success, exit program
  {
	cout << "Cannot opne the web cam!" << endl;
	return -1;
  }

  namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

  int iLowH = 0;
  int iHighH = 179;

  int iLowS = 0;
  int iHighS = 255;

  int iLowV = 0;
  int iHighV = 255;

  //create trackbars in "Control" window
  cvCreateTrackbar("LowH", "Control", &iLowH, 179); //Hue (0, -179)
  cvCreateTrackbar("HighH", "Control", &iHighH, 179);

  cvCreateTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0, -255)
  cvCreateTrackbar("HighS", "Control", &iHighS, 255);

  cvCreateTrackbar("LowV", "Control", &iLowV, 255); //Value (0, -255)
  cvCreateTrackbar("HighV", "Control", &iHighV, 255);

  while (true)
  {
	Mat imgOriginal;

	bool bSuccess = cap.read(imgOriginal); //read a new frame from video

	if (!bSuccess) //i fnot success, break loop
	{
	  cout << "Cannot read a frame from video stream!" << endl;
	  break;
	}

	Mat imgHSV;

	//convert the captured from from BGR to HSV
	cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); 
  
	Mat imgThresholded;

	inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV),
	  imgThresholded); //Threshold the image

	//morphological opening (remove small objects from the foreground)
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE,
	  Size(5, 5)));
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE,
	  Size(5, 5)));

	//morphological closing (fill small holes in the foreground)
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE,
	  Size(5, 5)));
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE,
	  Size(5, 5)));

	imshow("Thresholded Image", imgThresholded); //show the thresholded image
	imshow("Original", imgOriginal); //show the original image

	if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key pressed, break loop
	{
	  cout << "esc key is pressed by user" << endl;
	  break;
	}
  }

  return 0;
}

int opencv_test14()
{
  VideoCapture cap(0); //capture the video from webcam

  if (!cap.isOpened())  // if not success, exit program
  {
	cout << "Cannot open the web cam" << endl;
	return -1;
  }

  namedWindow("Control", CV_WINDOW_AUTOSIZE); //create a window called "Control"

  int iLowH = 170;
  int iHighH = 179;

  int iLowS = 150;
  int iHighS = 255;

  int iLowV = 60;
  int iHighV = 255;

  //Create trackbars in "Control" window
  createTrackbar("LowH", "Control", &iLowH, 179); //Hue (0 - 179)
  createTrackbar("HighH", "Control", &iHighH, 179);

  createTrackbar("LowS", "Control", &iLowS, 255); //Saturation (0 - 255)
  createTrackbar("HighS", "Control", &iHighS, 255);

  createTrackbar("LowV", "Control", &iLowV, 255);//Value (0 - 255)
  createTrackbar("HighV", "Control", &iHighV, 255);

  int iLastX = -1;
  int iLastY = -1;

  //Capture a temporary image from the camera
  Mat imgTmp;
  cap.read(imgTmp);

  //Create a black image with the size as the camera output
  Mat imgLines = Mat::zeros(imgTmp.size(), CV_8UC3);;

  while (true)
  {
	Mat imgOriginal;

	bool bSuccess = cap.read(imgOriginal); // read a new frame from video

	if (!bSuccess) //if not success, break loop
	{
	  cout << "Cannot read a frame from video stream" << endl;
	  break;
	}

	Mat imgHSV;

	cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV); //Convert the captured frame from BGR to HSV

	Mat imgThresholded;

	inRange(imgHSV, Scalar(iLowH, iLowS, iLowV), Scalar(iHighH, iHighS, iHighV)
	  , imgThresholded); //Threshold the image

	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, 
	  Size(5, 5)));
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, 
	  Size(5, 5)));

	//morphological closing (removes small holes from the foreground)
	dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, 
	  Size(5, 5)));
	erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, 
	  Size(5, 5)));

	//Calculate the moments of the thresholded image
	Moments oMoments = moments(imgThresholded);

	double dM01 = oMoments.m01;
	double dM10 = oMoments.m10;
	double dArea = oMoments.m00;

	// if the area <= 10000, I consider that the there are no object in the image and it's because of the noise, the area is not zero 
	if (dArea > 10000)
	{
	  //calculate the position of the ball
	  int posX = dM10 / dArea;
	  int posY = dM01 / dArea;

	  if (iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
	  {
		//Draw a red line from the previous point to the current point
		line(imgLines, Point(posX, posY), Point(iLastX, iLastY), Scalar(0, 0, 255), 2);
	  }

	  iLastX = posX;
	  iLastY = posY;
	}

	imshow("Thresholded Image", imgThresholded); //show the thresholded image

	imgOriginal = imgOriginal + imgLines;
	imshow("Original", imgOriginal); //show the original image

	if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
	{
	  cout << "esc key is pressed by user" << endl;
	  break;
	}
  }

  return 0;
}

int opencv_test15()
{
  IplImage* img = cvLoadImage("FindingContours.png");

  //show the original image
  cvNamedWindow("Raw");
  cvShowImage("Raw", img);

  //converting the original image into grayscale
  IplImage* imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
  cvCvtColor(img, imgGrayScale, CV_BGR2GRAY);

  //thresholding the grayscale image to get better results
  cvThreshold(imgGrayScale, imgGrayScale, 128, 255, CV_THRESH_BINARY);

  CvSeq* contours;  //hold the pointer to a contour in the memory block
  CvSeq* result;   //hold sequence of points of a contour
  CvMemStorage *storage = cvCreateMemStorage(0); //storage area for all contours

  //finding all contours in the image
  cvFindContours(imgGrayScale, storage, &contours, sizeof(CvContour), 
	CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

  //iterating through each contour
  while (contours)
  {
	//obtain a sequence of points of contour, pointed by the variable 'contour'
	result = cvApproxPoly(contours, sizeof(CvContour), storage, CV_POLY_APPROX_DP, 
	  cvContourPerimeter(contours)*0.02, 0);

	//if there are 3  vertices  in the contour(It should be a triangle)
	if (result->total == 3)
	{
	  //iterating through each point
	  CvPoint *pt[3];
	  for (int i = 0; i<3; i++) {
		pt[i] = (CvPoint*)cvGetSeqElem(result, i);
	  }

	  //drawing lines around the triangle
	  cvLine(img, *pt[0], *pt[1], cvScalar(255, 0, 0), 4);
	  cvLine(img, *pt[1], *pt[2], cvScalar(255, 0, 0), 4);
	  cvLine(img, *pt[2], *pt[0], cvScalar(255, 0, 0), 4);

	}

	//if there are 4 vertices in the contour(It should be a quadrilateral)
	else if (result->total == 4)
	{
	  //iterating through each point
	  CvPoint *pt[4];
	  for (int i = 0; i<4; i++) {
		pt[i] = (CvPoint*)cvGetSeqElem(result, i);
	  }

	  //drawing lines around the quadrilateral
	  cvLine(img, *pt[0], *pt[1], cvScalar(0, 255, 0), 4);
	  cvLine(img, *pt[1], *pt[2], cvScalar(0, 255, 0), 4);
	  cvLine(img, *pt[2], *pt[3], cvScalar(0, 255, 0), 4);
	  cvLine(img, *pt[3], *pt[0], cvScalar(0, 255, 0), 4);
	}

	//if there are 7  vertices  in the contour(It should be a heptagon)
	else if (result->total == 7)
	{
	  //iterating through each point
	  CvPoint *pt[7];
	  for (int i = 0; i<7; i++) {
		pt[i] = (CvPoint*)cvGetSeqElem(result, i);
	  }

	  //drawing lines around the heptagon
	  cvLine(img, *pt[0], *pt[1], cvScalar(0, 0, 255), 4);
	  cvLine(img, *pt[1], *pt[2], cvScalar(0, 0, 255), 4);
	  cvLine(img, *pt[2], *pt[3], cvScalar(0, 0, 255), 4);
	  cvLine(img, *pt[3], *pt[4], cvScalar(0, 0, 255), 4);
	  cvLine(img, *pt[4], *pt[5], cvScalar(0, 0, 255), 4);
	  cvLine(img, *pt[5], *pt[6], cvScalar(0, 0, 255), 4);
	  cvLine(img, *pt[6], *pt[0], cvScalar(0, 0, 255), 4);
	}

	//obtain the next contour
	contours = contours->h_next;
  }

  //show the image in which identified shapes are marked   
  cvNamedWindow("Tracked");
  cvShowImage("Tracked", img);

  cvWaitKey(0); //wait for a key press

  //cleaning up
  cvDestroyAllWindows();
  cvReleaseMemStorage(&storage);
  cvReleaseImage(&img);
  cvReleaseImage(&imgGrayScale);

  return 0;
}

int opencv_test16()
{
  IplImage* img = cvLoadImage("DetectingContours.jpg");

  //show the original image
  cvNamedWindow("Original");
  cvShowImage("Original", img);

  //smooth the original image using Gaussian kernel to remove noise
  cvSmooth(img, img, CV_GAUSSIAN, 3, 3);

  //converting the original image into grayscale
  IplImage* imgGrayScale = cvCreateImage(cvGetSize(img), 8, 1);
  cvCvtColor(img, imgGrayScale, CV_BGR2GRAY);

  cvNamedWindow("GrayScale Image");
  cvShowImage("GrayScale Image", imgGrayScale);

  //thresholding the grayscale image to get better results
  cvThreshold(imgGrayScale, imgGrayScale, 100, 255, CV_THRESH_BINARY_INV);

  cvNamedWindow("Thresholded Image");
  cvShowImage("Thresholded Image", imgGrayScale);

  CvSeq* contour;  //hold the pointer to a contour
  CvSeq* result;   //hold sequence of points of a contour
  CvMemStorage *storage = cvCreateMemStorage(0); //storage area for all contours

  //finding all contours in the image
  cvFindContours(imgGrayScale, storage, &contour, sizeof(CvContour), 
	CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

  //iterating through each contour
  while (contour)
  {
	//obtain a sequence of points of the countour, pointed by the variable 'countour'
	result = cvApproxPoly(contour, sizeof(CvContour), storage, 
	  CV_POLY_APPROX_DP, cvContourPerimeter(contour)*0.02, 0);

	//if there are 3 vertices  in the contour and the area of the triangle is more than 100 pixels
	if (result->total == 3 && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
	{
	  //iterating through each point
	  CvPoint *pt[3];
	  for (int i = 0; i<3; i++) {
		pt[i] = (CvPoint*)cvGetSeqElem(result, i);
	  }

	  //drawing lines around the triangle
	  cvLine(img, *pt[0], *pt[1], cvScalar(255, 0, 0), 4);
	  cvLine(img, *pt[1], *pt[2], cvScalar(255, 0, 0), 4);
	  cvLine(img, *pt[2], *pt[0], cvScalar(255, 0, 0), 4);

	}

	//obtain the next contour
	contour = contour->h_next;
  }

  //show the image in which identified shapes are marked   
  cvNamedWindow("Tracked");
  cvShowImage("Tracked", img);

  cvWaitKey(0); //wait for a key press

  //cleaning up
  cvDestroyAllWindows();
  cvReleaseMemStorage(&storage);
  cvReleaseImage(&img);
  cvReleaseImage(&imgGrayScale);

  return 0;
}

IplImage* imgTracking = 0;

int lastX1 = -1;
int lastY1 = -1;

int lastX2 = -1;
int lastY2 = -1;

void trackObject(IplImage* imgThresh) {
  CvSeq* contour;  //hold the pointer to a contour
  CvSeq* result;     //hold sequence of points of a contour
  CvMemStorage *storage = cvCreateMemStorage(0); //storage area for all contours

												 //finding all contours in the image
  cvFindContours(imgThresh, storage, &contour, sizeof(CvContour), CV_RETR_LIST, 
	CV_CHAIN_APPROX_SIMPLE, cvPoint(0, 0));

  //iterating through each contour
  while (contour)
  {
	//obtain a sequence of points of the countour, pointed by the variable 'countour'
	result = cvApproxPoly(contour, sizeof(CvContour), storage, CV_POLY_APPROX_DP, 
	  cvContourPerimeter(contour)*0.02, 0);

	//if there are 3 vertices  in the contour and the area of the triangle is more than 100 pixels
	if (result->total == 3 && fabs(cvContourArea(result, CV_WHOLE_SEQ))>100)
	{
	  //iterating through each point
	  CvPoint *pt[3];
	  for (int i = 0; i<3; i++) {
		pt[i] = (CvPoint*)cvGetSeqElem(result, i);
	  }

	  int posX = (pt[0]->x + pt[1]->x + pt[2]->x) / 3;
	  int posY = (pt[0]->y + pt[1]->y + pt[2]->y) / 3;

	  if (posX > 360) {
		if (lastX1 >= 0 && lastY1 >= 0 && posX >= 0 && posY >= 0) {
		  // Draw a red line from the previous point to the current point
		  cvLine(imgTracking, cvPoint(posX, posY), cvPoint(lastX1, lastY1), 
			cvScalar(0, 0, 255), 4);
		}

		lastX1 = posX;
		lastY1 = posY;
	  }
	  else {
		if (lastX2 >= 0 && lastY2 >= 0 && posX >= 0 && posY >= 0) {
		  // Draw a blue line from the previous point to the current point
		  cvLine(imgTracking, cvPoint(posX, posY), cvPoint(lastX2, lastY2), cvScalar(255, 0, 0), 4);
		}

		lastX2 = posX;
		lastY2 = posY;
	  }
	}

	//obtain the next contour
	contour = contour->h_next;
  }

  cvReleaseMemStorage(&storage);
}


int opencv_test17() {
  //load the video file to the memory
  CvCapture *capture = cvCaptureFromAVI("SampleVideo.avi");

  if (!capture) {
	printf("Capture failure\n");
	return -1;
  }

  IplImage* frame = 0;
  frame = cvQueryFrame(capture);
  if (!frame) return -1;

  //create a blank image and assigned to 'imgTracking' which has the same size of original video
  imgTracking = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 3);
  cvZero(imgTracking); //covert the image, 'imgTracking' to black

  cvNamedWindow("Video");

  //iterate through each frames of the video     
  while (true) {

	frame = cvQueryFrame(capture);
	if (!frame) break;
	frame = cvCloneImage(frame);

	//smooth the original image using Gaussian kernel
	cvSmooth(frame, frame, CV_GAUSSIAN, 3, 3);

	//converting the original image into grayscale
	IplImage* imgGrayScale = cvCreateImage(cvGetSize(frame), 8, 1);
	cvCvtColor(frame, imgGrayScale, CV_BGR2GRAY);

	//thresholding the grayscale image to get better results
	cvThreshold(imgGrayScale, imgGrayScale, 100, 255, CV_THRESH_BINARY_INV);

	//track the possition of the ball
	trackObject(imgGrayScale);

	// Add the tracking image and the frame
	cvAdd(frame, imgTracking, frame);

	cvShowImage("Video", frame);

	//Clean up used images
	cvReleaseImage(&imgGrayScale);
	cvReleaseImage(&frame);

	//Wait 10mS
	int c = cvWaitKey(10);
	//If 'ESC' is pressed, break the loop
	if ((char)c == 27) break;
  }

  cvDestroyAllWindows();
  cvReleaseImage(&imgTracking);
  cvReleaseCapture(&capture);

  return 0;
}

int HomogeneousSmoothing()
{
  //create 2 empty windows
  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("Smoothed Image", CV_WINDOW_AUTOSIZE);

  // Load an image from file
  Mat src = imread("MyPic.JPG", 1);

  //show the loaded image
  imshow("Original Image", src);

  Mat dst;
  char zBuffer[35];

  for (int i = 1; i < 31; i = i + 2)
  {
	//copy the text to the "zBuffer"
	_snprintf_s(zBuffer, 35, "Kernel Size : %d x %d", i, i);

	//smooth the image in the "src" and save it to "dst"
	blur(src, dst, Size(i, i));

	//put the text in the "zBuffer" to the "dst" image
	putText(dst, zBuffer, Point(src.cols / 4, src.rows / 8), 
	  CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));

	//show the blurred image with the text
	imshow("Smoothed Image", dst);

	//wait for 2 seconds
	int c = waitKey(2000);

	//if the "esc" key is pressed during the wait, return
	if (c == 27)
	{
	  return 0;
	}
  }

  //make the "dst" image, black
  dst = Mat::zeros(src.size(), src.type());

  //copy the text to the "zBuffer"
  _snprintf_s(zBuffer, 35, "Press Any Key to Exit");

  //put the text in the "zBuffer" to the "dst" image
  putText(dst, zBuffer, Point(src.cols / 4, src.rows / 2), 
	CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));

  //show the black image with the text
  imshow("Smoothed Image", dst);

  //wait for a key press infinitely
  waitKey(0);

  return 0;

}

int GaussianSmoothing()
{
  //create 2 empty windows
  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("Smoothed Image", CV_WINDOW_AUTOSIZE);

  // Load an image from file
  Mat src = imread("MyPic.JPG", CV_LOAD_IMAGE_UNCHANGED);

  //show the loaded image
  imshow("Original Image", src);

  Mat dst;
  char zBuffer[35];

  for (int i = 1; i < 31; i = i + 2)
  {
	//copy the text to the "zBuffer"
	_snprintf_s(zBuffer, 35, "Kernel Size : %d x %d", i, i);

	//smooth the image using Gaussian kernel in the "src" and save it to "dst"
	GaussianBlur(src, dst, Size(i, i), 0, 0);

	//put the text in the "zBuffer" to the "dst" image
	putText(dst, zBuffer, Point(src.cols / 4, src.rows / 8), 
	  CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 2);

	//show the blurred image with the text
	imshow("Smoothed Image", dst);

	//wait for 2 seconds
	int c = waitKey(2000);

	//if the "esc" key is pressed during the wait, return
	if (c == 27)
	{
	  return 0;
	}
  }

  //make the "dst" image, black
  dst = Mat::zeros(src.size(), src.type());

  //copy the text to the "zBuffer"
  _snprintf_s(zBuffer, 35, "Press Any Key to Exit");

  //put the text in the "zBuffer" to the "dst" image
  putText(dst, zBuffer, Point(src.cols / 4, src.rows / 2), 
	CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));

  //show the black image with the text
  imshow("Smoothed Image", dst);

  //wait for a key press infinitely
  waitKey(0);

  return 0;
}

int MedianSmoothing()
{
  //create 2 empty windows
  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("Smoothed Image", CV_WINDOW_AUTOSIZE);

  // Load an image from file
  Mat src = imread("MyPic.JPG", CV_LOAD_IMAGE_UNCHANGED);

  //show the loaded image
  imshow("Original Image", src);

  Mat dst;
  char zBuffer[35];

  for (int i = 1; i < 31; i = i + 2)
  {
	//copy the text to the "zBuffer"
	_snprintf_s(zBuffer, 35, "Kernel Size : %d x %d", i, i);

	//smooth the image using Median kernel in the "src" and save it to "dst"
	medianBlur(src, dst, i);

	//put the text in the "zBuffer" to the "dst" image
	putText(dst, zBuffer, Point(src.cols / 4, src.rows / 8), 
	  CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 2);

	//show the blurred image with the text
	imshow("Smoothed Image", dst);

	//wait for 2 seconds
	int c = waitKey(2000);

	//if the "esc" key is pressed during the wait, return
	if (c == 27)
	{
	  return 0;
	}
  }

  //make the "dst" image, black
  dst = Mat::zeros(src.size(), src.type());

  //copy the text to the "zBuffer"
  _snprintf_s(zBuffer, 35, "Press Any Key to Exit");

  //put the text in the "zBuffer" to the "dst" image
  putText(dst, zBuffer, Point(src.cols / 4, src.rows / 2), 
	CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));

  //show the black image with the text
  imshow("Smoothed Image", dst);

  //wait for a key press infinitely
  waitKey(0);

  return 0;
}

int BilateralSmoothing()
{
  //create 2 empty windows
  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("Smoothed Image", CV_WINDOW_AUTOSIZE);

  // Load an image from file
  Mat src = imread("MyPic.JPG", CV_LOAD_IMAGE_UNCHANGED);

  //show the loaded image
  imshow("Original Image", src);

  Mat dst;
  char zBuffer[35];

  for (int i = 1; i < 31; i = i + 2)
  {
	//copy the text to the "zBuffer"
	_snprintf_s(zBuffer, 35, "Kernel Size : %d x %d", i, i);

	//smooth the image using Bilateral filter in the "src" and save it to "dst"
	bilateralFilter(src, dst, i, i, i);

	//put the text in the "zBuffer" to the "dst" image
	putText(dst, zBuffer, Point(src.cols / 4, src.rows / 8), 
	  CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255), 2);

	//show the blurred image with the text
	imshow("Smoothed Image", dst);

	//wait for 2 seconds
	int c = waitKey(2000);

	//if the "esc" key is pressed during the wait, return
	if (c == 27)
	{
	  return 0;
	}
  }

  //make the "dst" image, black
  dst = Mat::zeros(src.size(), src.type());

  //copy the text to the "zBuffer"
  _snprintf_s(zBuffer, 35, "Press Any Key to Exit");

  //put the text in the "zBuffer" to the "dst" image
  putText(dst, zBuffer, Point(src.cols / 4, src.rows / 2), 
	CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255, 255, 255));

  //show the black image with the text
  imshow("Smoothed Image", dst);

  //wait for a key press infinitely
  waitKey(0);

  return 0;
}

int ImageContrastChange()
{
  Mat img = imread("MyPic.JPG", CV_LOAD_IMAGE_COLOR); //open and read the image


  if (img.empty())
  {
	cout << "Image cannot be loaded..!!" << endl;
	return -1;
  }

  Mat imgH;
  img.convertTo(imgH, -1, 2, 0); //increase the contrast (double)

  Mat imgL;
  img.convertTo(imgL, -1, 0.5, 0); //decrease the contrast (halve)

								   //create windows
  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("High Contrast", CV_WINDOW_AUTOSIZE);
  namedWindow("Low Contrast", CV_WINDOW_AUTOSIZE);

  //show the image
  imshow("Original Image", img);
  imshow("High Contrast", imgH);
  imshow("Low Contrast", imgL);

  waitKey(0); //wait for key press

  destroyAllWindows(); //destroy all open windows

  return 0;
}


int VideoContrastChange()
{
  VideoCapture cap("SampleVideo.avi"); // open the video file for reading

  if (!cap.isOpened())  // if not success, exit program
  {
	cout << "Cannot open the video file" << endl;
	return -1;
  }

  //create windows
  namedWindow("Original Video", CV_WINDOW_AUTOSIZE);
  namedWindow("Contrast Increased", CV_WINDOW_AUTOSIZE);
  namedWindow("Contrast Decreased", CV_WINDOW_AUTOSIZE);

  while (1)
  {
	Mat frame;

	bool bSuccess = cap.read(frame); // read a new frame from video

	if (!bSuccess) //if not success, break loop
	{
	  cout << "Cannot read the frame from video file" << endl;
	  break;
	}

	Mat imgH;
	frame.convertTo(imgH, -1, 2, 0); //increase the contrast (double)

	Mat imgL;
	frame.convertTo(imgL, -1, 0.5, 0); //decrease the contrast (halve)

									   //show the image
	imshow("Original Video", frame);
	imshow("Contrast Increased", imgH);
	imshow("Contrast Decreased", imgL);

	if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
	{
	  cout << "esc key is pressed by user" << endl;
	  break;
	}
  }
  return 0;
}

int HistogramEqualizationGrayscaleImage()
{
  Mat img = imread("MyPic.jpg", CV_LOAD_IMAGE_COLOR); //open and read the image

  if (img.empty())
  {
	cout << "Image cannot be loaded..!!" << endl;
	return -1;
  }

  cvtColor(img, img, CV_BGR2GRAY); //change the color image to grayscale image

  Mat img_hist_equalized;
  equalizeHist(img, img_hist_equalized); //equalize the histogram

  //create windows
  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("Histogram Equalized", CV_WINDOW_AUTOSIZE);

  //show the image
  imshow("Original Image", img);
  imshow("Histogram Equalized", img_hist_equalized);

  waitKey(0); //wait for key press

  destroyAllWindows(); //destroy all open windows

  return 0;
}

int HistogramEqualizationColorImage()
{
  Mat img = imread("MyPic.JPG", CV_LOAD_IMAGE_COLOR); //open and read the image

  if (img.empty()) //if unsuccessful, exit the program
  {
	cout << "Image cannot be loaded..!!" << endl;
	return -1;
  }

  vector<Mat> channels;
  Mat img_hist_equalized;

  cvtColor(img, img_hist_equalized, CV_BGR2YCrCb); //change the color image from BGR to YCrCb format

  split(img_hist_equalized, channels); //split the image into channels

  equalizeHist(channels[0], channels[0]); //equalize histogram on the 1st channel (Y)

  merge(channels, img_hist_equalized); //merge 3 channels including the modified 1st channel into one image

  cvtColor(img_hist_equalized, img_hist_equalized, CV_YCrCb2BGR); //change the color image from YCrCb to BGR format (to display image properly)

  //create windows
  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("Histogram Equalized", CV_WINDOW_AUTOSIZE);

  //show the image
  imshow("Original Image", img);
  imshow("Histogram Equalized", img_hist_equalized);

  waitKey(0); //wait for key press

  destroyAllWindows(); //destroy all open windows

  return 0;
}

int ImageBrightnesChange()
{
  Mat img = imread("MyPic.jpg", CV_LOAD_IMAGE_COLOR);

  if (img.empty())
  {
	cout << "Image cannot be loaded..!!" << endl;
	return -1;
  }

  Mat imgH = img + Scalar(75, 75, 75); //increase the brightness by 75 units
									   //img.convertTo(imgH, -1, 1, 75);

  Mat imgL = img + Scalar(-75, -75, -75); //decrease the brightness by 75 units
										  //img.convertTo(imgL, -1, 1, -75);

  namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
  namedWindow("High Brightness", CV_WINDOW_AUTOSIZE);
  namedWindow("Low Brightness", CV_WINDOW_AUTOSIZE);

  imshow("Original Image", img);
  imshow("High Brightness", imgH);
  imshow("Low Brightness", imgL);

  waitKey(0);

  destroyAllWindows(); //destroy all open windows

  return 0;
}

int VideoBrightnessChange()
{
  VideoCapture cap("SampleVideo.avi"); // open the video file for reading

  if (!cap.isOpened())  // if not success, exit program
  {
	cout << "Cannot open the video file" << endl;
	return -1;
  }

  namedWindow("Original Video", CV_WINDOW_AUTOSIZE); //create a window called "Original Video"
  namedWindow("Brightness Increased", CV_WINDOW_AUTOSIZE); //create a window called "Brightness Increased"
  namedWindow("Brightness Decreased", CV_WINDOW_AUTOSIZE); //create a window called "Brightness Decreased"

  while (1)
  {
	Mat frame;

	bool bSuccess = cap.read(frame); // read a new frame from video

	if (!bSuccess) //if not success, break loop
	{
	  cout << "Cannot read the frame from video file" << endl;
	  break;
	}

	Mat imgH = frame + Scalar(50, 50, 50); //increase the brightness by 75 units

	Mat imgL = frame + Scalar(-50, -50, -50); //decrease the brightness by 75 units

	imshow("Original Video", frame); //show the frame in "Original Video" window
	imshow("Brightness Increased", imgH); //show the frame of which brightness increased
	imshow("Brightness Decreased", imgL); //show the frame of which brightness decreased

	if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
	{
	  cout << "esc key is pressed by user" << endl;
	  break;
	}
  }

  return 0;
}