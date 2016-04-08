#include <string>
#include <iostream>
#include <fstream>
#include <vrpn_Button.h>
#include <vrpn_Tracker.h>
#include <vrpn_Analog.h>
#include <vrpn_XInputGamepad.h>
#include "Bridge.h"
#include <array>
#include <msclr\marshal.h>
#include <sstream>


using namespace std;

bool chng = false;

int butState = 0;
int butNumber = -1;


array<typename float,7> analogState;
float analogChan;
int totalChannels;

VrpnBridge::VrpnBridge(DevType x, std::string devName, SIVConfig^ cfg)
	:buttonState(butState), buttonNumber(butNumber), changed(chng), analogArray(analogState)
{
	//ex = external;
	this->deviceType = x;
	this->running = true;
	this->deviceName = msclr::interop::marshal_as<std::string>(cfg->deviceName->ToString());
	this->VRPNname = msclr::interop::marshal_as<std::string>(cfg->VRPNname->ToString());
	this->dataTypes = msclr::interop::marshal_as<std::string>(cfg->dataTypes->ToString());
	this->channels = cfg->channels;
	totalChannels = this->channels;


	if (this->dataTypes == "Rotation") {
		this->rot = true;
		this->pos = false;
	}
	else if (dataTypes == "Position") {
		this->pos = true;
		this->rot = false;
	}
	else if (dataTypes == "Both") {
		this->pos = true;
		this->rot = true;
	}
	else {
		this->pos = false;
		this->rot = false;
	}

	if (this->pos) {
		this->XPos = cfg->XPos;
		this->YPos = cfg->YPos;
		this->ZPos = cfg->ZPos;
		this->Scale = cfg->Scale;
	}

	if (this->rot) {
		this->YRot = cfg->YRot;
		this->ZRot = cfg->ZRot;
		this->XRot = cfg->XRot;
		this->WRot = cfg->WRot;
	}

	
}

//The Button Handler for the device. Sets butState and butNumber to identify the buttons pressed
void VRPN_CALLBACK ButtonHandler(void* userData, const vrpn_BUTTONCB b) {
	butState = b.state;
	butNumber = b.button;
	chng = true;
}

void VRPN_CALLBACK AnalogHandler(void* userData, const vrpn_ANALOGCB a) {
	
//	totalChannels = a.num_channel;
	for (int i = 0; i < a.num_channel; i++) {
		//cout << a.channel[i]<<" ";
		analogState[i] = a.channel[i];
	}
	//cout << endl;
	chng = true;
}




void VrpnBridge::StartButtonHandler(int* external) {

	//external = &ext;
	std::string m = this->deviceName + "@localhost";
	//cout <<"\nm is: "<< m << endl;
	const char* host = m.c_str();
	//cout << "host is: " << host << endl;

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
// TODO: write handlers to write data to specific spots
void VrpnBridge::StartGamepadHandler() {
	ofstream SIVRData;
	SIVRData.open("S:/Coding/Unity/SIVR Unity/Assets/SIVRData.siv", std::ofstream::trunc);
	std::string m = this->deviceName + "@localhost";
	const char* host = m.c_str();
	vrpn_Analog_Remote* vrpnAnalog = new vrpn_Analog_Remote(host);
	vrpn_Button_Remote* vrpnButton = new vrpn_Button_Remote(host);

	vrpnAnalog->register_change_handler(0, AnalogHandler);
	vrpnButton->register_change_handler(0, ButtonHandler);
	while (this->running != NULL) {
		
		vrpnAnalog->mainloop();
		//vrpnButton->mainloop();
		SIVRData.seekp(0);
		for (int i = 0; i < 7; i++)
		{
			SIVRData << analogArray[i] << endl;
		}
		Sleep(50.0);
		try {
			if (this->running == false)
				break;
		}
		catch (System::NullReferenceException^) {
			cout << "Running null value" << endl;
		}
	}
	SIVRData.close();
	cout << "Closing Time~~\n";

}
