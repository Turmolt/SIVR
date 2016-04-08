#pragma once

#include "vrpn_XInputGamepad.h"
#include "vrpn_Button.h"
#include "vrpn_Tracker.h"
#include <string.h>
#include "Glob.h"

#include <vrpn_XInputGamepad.h>
#include <vrpn_Analog.h>
#include <Xinput.h>
#include "SIVConfig.h"



public ref class VRPNClient
{
public:
	VRPNClient(DevType t, System::String^ dn, SIVConfig^ cfg);
	void makeClient();
	void enableDevice(DevType t, System::String^ dev);

	void startThread();
	void stopThread();

	void startAnalogThread();
	
	//thread functions
	void buttonListen();
	void buttonListen2();

	void analogListen();
	void analogListen2();

	SIVConfig^ config;

	System::String^ dName;
	System::String^ s;
	System::Threading::Thread^ aThread;
	System::Threading::Thread^ a2Thread;
	DevType deviceType;

	int* external;

	bool running;
	
	
};

