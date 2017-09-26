#include "cameradisplay.h"

CameraDisplay::CameraDisplay()
{

}

CameraDisplay::~CameraDisplay()
{

}

void CameraDisplay::display()
{
	Status result = STATUS_OK;

	//OpenNI2 image  
	VideoFrameRef oniColorImg;

	//OpenCV image  
	cv::Mat cvBGRImg;
	cv::namedWindow("image");


	//【1】  
	// initialize OpenNI2  
	result = OpenNI::initialize();
	//CheckOpenNIError(result, "initialize context");

	// open device    
	Device device;
	result = device.open(openni::ANY_DEVICE);

	//【2】  
	// create depth stream   

	//【3】  
	// set depth video mode  

	// create color stream  
	VideoStream oniColorStream;
	result = oniColorStream.create(device, openni::SENSOR_COLOR);
	// set color video mode  
	VideoMode modeColor;
	modeColor.setResolution(640, 480);
	modeColor.setFps(30);
	modeColor.setPixelFormat(PIXEL_FORMAT_RGB888);
	oniColorStream.setVideoMode(modeColor);

	//【4】  
	// set depth and color imge registration mode  
	if (device.isImageRegistrationModeSupported(IMAGE_REGISTRATION_DEPTH_TO_COLOR))
	{
		device.setImageRegistrationMode(IMAGE_REGISTRATION_DEPTH_TO_COLOR);
	}
	// start color stream  
	result = oniColorStream.start();
	
	char key = 0;
	while (key != 27)
	{
		// read frame  
		if (oniColorStream.readFrame(&oniColorImg) == STATUS_OK)
		{
			// convert data into OpenCV type  
			cv::Mat cvRGBImg(oniColorImg.getHeight(), oniColorImg.getWidth(), CV_8UC3, (void*)oniColorImg.getData());    // 将openni图片转换为opencv图片
			cv::cvtColor(cvRGBImg, cvBGRImg, CV_RGB2BGR);  // 将RGB转换为BGR
			cv::imshow("image", cvBGRImg);    // 显示图片
		}


		//【6】  
		key = cv::waitKey(20);
	}

	//cv destroy  
	cv::destroyWindow("image");

	//OpenNI2 destroy  
	oniColorStream.destroy();
	device.close();
	OpenNI::shutdown();
}
	