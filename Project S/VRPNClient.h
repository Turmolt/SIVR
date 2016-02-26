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
	VRPNClient(Type t);
	void makeClient();
	void enableDevice(char);

};

