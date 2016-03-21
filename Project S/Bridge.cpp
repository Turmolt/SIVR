#include <string>
#include <iostream>
#include <vrpn_Button.h>
#include <vrpn_Tracker.h>
#include <vrpn_Analog.h>
#include <vrpn_XInputGamepad.h>
#include "Bridge.h"
#include <array>

using namespace std;

int butState = 0;
int butNumber = -1;


array<typename float,2> analogState;
float analogChan;
int totalChannels;

VrpnBridge::VrpnBridge(DevType x, std::string devName)
	:buttonState(butState), buttonNumber(butNumber), analogArray(analogChan)
{
	//ex = external;
	this->deviceType = x;
	this->running = true;
	this->deviceName = devName;
	
}

//The Button Handler for the device. Sets butState and butNumber to identify the buttons pressed
void VRPN_CALLBACK ButtonHandler(void* userData, const vrpn_BUTTONCB b) {
	butState = b.state;
	butNumber = b.button;
}

void VRPN_CALLBACK AnalogHandler(void* userData, const vrpn_ANALOGCB a) {
	
	totalChannels = a.num_channel;
	for (int i = 0; i < totalChannels; i++) {
		cout << a.channel[i]<<" ";
	}
	cout << endl;
}




void VrpnBridge::StartButtonHandler(int* external) {

	//external = &ext;
	std::string m = this->deviceName + "@localhost";
	cout <<"\nm is: "<< m << endl;
	const char* host = m.c_str();
	cout << "host is: " << host << endl;

	vrpn_Button_Remote* vrpnButton = new vrpn_Button_Remote(host);
	
	vrpnButton->register_change_handler(0,ButtonHandler);
	while (this->running!=NULL) {
		vrpnButton->mainloop();
		Sleep(50.0);
		try {
			if (this->running == false)
				break;
		}
		catch (System::NullReferenceException^){
			cout << "Running null value" << endl;
		}
	}
}

void VrpnBridge::StartAnalogHandler() {

	std::string m = this->deviceName + "@localhost";
	cout << "\nm is: " << m << endl;
	const char* host = m.c_str();
	cout << host;
	vrpn_Analog_Remote* vrpnAnalog = new vrpn_Analog_Remote(host);

	vrpnAnalog->register_change_handler(0, AnalogHandler);
	while (this->running != NULL) {
		vrpnAnalog->mainloop();
		Sleep(50.0);
		try {
			if (this->running == false)
				break;
		}
		catch (System::NullReferenceException^) {
			cout << "Running null value" << endl;
		}
	}
}
