#pragma once
#include <vrpn_XInputGamepad.h>
#include <vrpn_Tracker.h>
#include <string.h>
#include <iostream>
#include <fstream>

ref class VRPNClient
{
public:
	VRPNClient();
	void makeClient();
	void enableDevice(char);

};

