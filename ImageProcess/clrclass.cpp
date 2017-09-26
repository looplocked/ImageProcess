#include "clrclass.h"
#include "cameradisplay.h"

ClrClass::ClrClass()
{
	clrCam = new CameraDisplay();
}

ClrClass::~ClrClass()
{

}

void ClrClass::displayCam()
{
	clrCam->display();
}