#ifndef CAMERADISPLAY_H    //预编译头很重要
#define CAMERADISPLAY_H    //不加会编译失败


#include <stdlib.h>  
#include <iostream>  
#include <string>  
#include "OpenNI.h"  
#include "opencv2/core/core.hpp"  
#include "opencv2/highgui/highgui.hpp"  
#include "opencv2/imgproc/imgproc.hpp"  

using namespace std;
using namespace cv;
using namespace openni;

//void CheckOpenNIError(Status result, string status)
//{
//	if (result != STATUS_OK)
//		cerr << status << " Error: " << OpenNI::getExtendedError() << endl;
//}

class CameraDisplay
{
public:
	CameraDisplay();
	~CameraDisplay();
	void display();
};

#endif
