#pragma once

ref class SIVConfig {
public:
	SIVConfig(System::String^);
	System::String^ deviceName;
	System::String^ VRPNname;

	//set true if marked in config
	bool rot;
	bool pos;
	//how many VRPN channels will we read
	int channels;
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
