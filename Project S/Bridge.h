#pragma once
#include "Glob.h"
#include <string>
#include "SIVConfig.h"
#include <array>

class VrpnBridge {
public:
	VrpnBridge(DevType x,SIVConfig^ cfg);
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

	std::string path;

	std::string VRPNname;
	std::string dataTypes;

	std::array<float,4> Rotation;
	std::array<float, 3> Position;


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