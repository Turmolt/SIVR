#pragma once
#include "Glob.h"
#include <string>

class VrpnBridge {
public:
	VrpnBridge(DevType x, std::string devName);
	void StartButtonHandler(int*);
	void StartAnalogHandler();


	//set this to false when the thread should stop running vrpn mainloop
	bool running;

	//The variables for different device types found below
	int &buttonState;
	int &buttonNumber;

	float &analogArray;

	std::string deviceName;

	DevType deviceType;
};