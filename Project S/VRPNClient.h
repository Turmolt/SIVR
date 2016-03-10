#pragma once
#include <vrpn_XInputGamepad.h>
#include <vrpn_Tracker.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "Glob.h"


ref class VRPNClient
{
public:
	VRPNClient(DevType t, std::string dn);
	void makeClient();
	void enableDevice(DevType t, std::string devName);
};

