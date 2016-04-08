#pragma once
#include "Glob.h"
#include <string>
#include "SIVConfig.h"

class VrpnBridge {
public:
	VrpnBridge(DevType x, std::string devName,SIVConfig^ cfg);
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

	std::string VRPNname;
	std::string dataTypes;

	//set true if marked in config
	bool rot;
	bool pos;
	//how many VRPN channels will we read
	int channels;
	int buttons;
	int XRot;
	int YRot;
	int ZRot;
	int WRot;
	int XPos;
	int YPos;
	int ZPos;

	//device input * scale = real world movement
	float Scale;
};