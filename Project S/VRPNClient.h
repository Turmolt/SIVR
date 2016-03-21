#pragma once

#include "vrpn_XInputGamepad.h"
#include "vrpn_Button.h"
#include "vrpn_Tracker.h"
#include <string.h>
#include "Glob.h"

#include <vrpn_XInputGamepad.h>
#include <vrpn_Analog.h>
#include <Xinput.h>




public ref class VRPNClient
{
public:
	VRPNClient(DevType t, System::String^ dn);
	void makeClient();
	void enableDevice(DevType t, System::String^ dev);
	void startThread();
	void stopThread();
	void listen();
	void listen2();
	void VRPN_CALLBACK ButtonCb(void * userData, const vrpn_BUTTONCB);
	void VRPN_CALLBACK AnalogCb(void * userData, const vrpn_ANALOGCB);

	System::String^ dName;
	System::String^ s;
	System::Threading::Thread^ aThread;
	System::Threading::Thread^ a2Thread;

	int* external;
	
	
};

