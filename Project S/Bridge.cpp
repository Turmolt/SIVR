#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vrpn_Button.h>
#include <vrpn_Tracker.h>
#include <vrpn_Analog.h>
#include <vrpn_XInputGamepad.h>
#include "Bridge.h"
#include <array>
#include <msclr\marshal_cppstd.h>
#include <sstream>


using namespace std;

bool chng = false;

int butState = 0;
int butNumber = -1;


array<typename float,7> analogState;
float analogChan;
int totalChannels;

VrpnBridge::VrpnBridge(DevType x, SIVConfig^ cfg)
	:buttonState(butState), buttonNumber(butNumber), changed(chng), analogArray(analogState)
{
	char pth[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pth);

	switch (x) {
	case DevType::HandTracker:
		this->path = string(pth)+"/Purposes/Hands.sivd";
		break;
	case DevType::HeadTracker:
		this->path = string(pth) + "/Purposes/Head.sivd";
		break;
	case DevType::Spatial:
		this->path = string(pth) + "/Purposes/Spatial.sivd";
		break;
	case DevType::Misc:
		this->path = string(pth) + "/Purposes/Misc.sivd";
		break;
	}
	cout << this->path<<endl;

	//ex = external;
	this->deviceType = x;
	this->running = true;
	msclr::interop::marshal_context ctx;
	this->deviceName = ctx.marshal_as<string>(cfg->deviceName->Trim());
	this->VRPNname =ctx.marshal_as<string>(cfg->VRPNname->Trim());
	this->dataTypes = ctx.marshal_as<string>(cfg->dataTypes->Trim());
	this->buttons = cfg->buttons;
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
	cout << this->deviceName << " " << this->channels << " " << this->VRPNname << " "<< this->dataTypes<<" "<<this->buttons << endl;
	if (this->rot)
		cout << "Rotation: (" << this->XRot << "," << this->YRot << "," << this->ZRot << "," << this->WRot << ")" << endl;
	if (this->pos)
		cout << "Position: (" << this->XPos << "," << this->YPos << "," << this->ZPos << "," << this->Scale << ")" << endl;
	

	/*if (this->buttons > 0 && this->channels > 0) {
		StartGamepadHandler();
	}*/
	
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
	cout << "Starting " << this->deviceName << " handler" << endl;
	ofstream SIVRData;
	SIVRData.open(this->path, std::ofstream::trunc);
	std::string m = this->VRPNname + "@localhost";
	const char* host = m.c_str();
	vrpn_Analog_Remote* vrpnAnalog = new vrpn_Analog_Remote(host);
	vrpn_Button_Remote* vrpnButton = new vrpn_Button_Remote(host);

	vrpnAnalog->register_change_handler(0, AnalogHandler);
	vrpnButton->register_change_handler(0, ButtonHandler);
	while (this->running != NULL) {
		
		vrpnAnalog->mainloop();
		//vrpnButton->mainloop();
		SIVRData.seekp(0);
		for (int i = 0; i < this->channels; i++)
		{
			
			if (this->rot) {
				if (i+1 == (int)this->XRot) {
					this->Rotation[0] = analogArray[i];
				}
				else if (i+1 == (int)this->YRot) {
					this->Rotation[1] = analogArray[i];
				}
				else if (i+1 == (int)this->ZRot) {
					this->Rotation[2] = analogArray[i];
				}
				else if (i+1 == (int)this->WRot) {
					this->Rotation[3] = analogArray[i];
				}
			}
			if (this->pos) {
				if (i+1 == (int)this->XPos) {
					this->Position[0] = analogArray[i];
				}
				else if (i+1 == (int)this->YPos) {
					this->Position[1] = analogArray[i];
				}
				else if (i+1 == (int)this->ZPos) {
					this->Position[2] = analogArray[i];
				}
			}
			
		}
		//SIVRData << this->Position.at(0) << " " << this->Position.at(1) << " " << this->Position.at(2) << endl;
		//SIVRData << this->Rotation.at(0) << " " << this->Rotation.at(1) << " " << this->Rotation.at(2) << " " << this->Rotation.at(3) <<endl;
		//
		//SIVRData.flush();
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
