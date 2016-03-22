#pragma once
#include "Glob.h"
#include <string>

class VrpnBridge {
public:
	VrpnBridge(DevType x, std::string devName);
	void StartButtonHandler(int*);
	void StartAnalogHandler();
	void StartGamepadHandler();


	//set this to false when the thread should stop running vrpn mainloop
	bool running;

	//The variables for different device types found below
	int &buttonState;
	int &buttonNumber;

	//float &analogArray;
	bool &changed;
	std::array<float, 7> &analogArray;

	std::string deviceName;

	DevType deviceType;
};