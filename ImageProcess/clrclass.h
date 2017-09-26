#pragma once
# include "cameradisplay.h"

public ref class ClrClass
{
public:
	ClrClass();
	~ClrClass();
	void displayCam();

private:
	CameraDisplay *clrCam;
};