#pragma once
#include "vrpn_XInputGamepad.h"
#include "vrpn_Button.h"
#include "vrpn_Tracker.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include "Glob.h"


using namespace std;
ref class VRPNClient
{
public:
	VRPNClient(DevType t, std::string dn);
	void makeClient();
	void enableDevice(DevType t, std::string devName);
	void startThread();
	void stopThread();
	void listen();
	void VRPN_CALLBACK gamepadCb(void * userData, const vrpn_BUTTONCB b, const vrpn_TRACKERCB t);



	Thread ^ aThread;
};

