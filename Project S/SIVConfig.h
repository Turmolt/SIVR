#pragma once

ref class SIVConfig {
public:
	SIVConfig();
	System::String^ deviceName;
	System::String^ VRPNname;
	System::String^ dataTypes;

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
