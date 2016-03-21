#pragma once
#include "Glob.h"

class VrpnBridge {
public:
	VrpnBridge(DevType x);
	void StartButtonHandler(int*);

	//set this to false when the thread should stop running vrpn mainloop
	bool running;

	//The variables for different device types found below
	int &buttonState;
	int &buttonNumber;

	DevType deviceType;
};