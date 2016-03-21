#pragma once



#include <windows.h>
#include "VRPNClient.h"
#include <vcclr.h>

ref class Boss
{
public:
	Boss();
	VRPNClient^ newClient(DevType t, System::String^);
	VRPNClient^ getClient(DevType type);
	void killClient(DevType t);
	cli::array<VRPNClient^>^ clientArray;

	VRPNClient^ Hands;
	VRPNClient^ Head;
	VRPNClient^ Tracker;
	VRPNClient^ Gamepad;
	VRPNClient^ Mouse;

	bool hands;
	bool head;
	bool tracker;
	bool gamepad;
	bool mouse;


	int curMax;
	int curKill;

};
