#include <windows.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vrpn_Button.h>
#include <vrpn_Tracker.h>
#include <vrpn_Tracker_isense.h>
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

int index = 0;

array<typename float, 7> analgArray;
array<typename float,4> rotationArray;
array<typename float, 3> positionArray;
float analogChan;
int totalChannels;

VrpnBridge::VrpnBridge(DevType x, SIVConfig^ cfg)
	:buttonState(butState), buttonNumber(butNumber), changed(chng), rotArray(rotationArray), posArray(positionArray), analogArray(analgArray)
{
	char pth[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, pth);
	/*
	switch (x) {
	case DevType::HandTracker:
		this->path = string(pth)+"/Purposes/Hands.sivd";
		break;
	case DevType::HeadTracker:
		cout << "head" << endl;
		this->path = string(pth) + "/Purposes/Head.sivd";
		break;
	case DevType::Spatial:
		this->path = string(pth) + "/Purposes/Spatial.sivd";
		break;
	case DevType::Misc:
		this->path = string(pth) + "/Purposes/Misc.sivd";
		break;
	}*/
	//cout << this->path<<endl;

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

	this->bridgeType = ctx.marshal_as<string>(cfg->bridgeType->Trim());

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
	if (index != 3) {
		index = 0;
	}
//	totalChannels = a.num_channel;
	for (int i = 0; i < a.num_channel; i++) {
		//cout << a.channel[i]<<" ";
		analgArray[i] = a.channel[i];
		//cout << a.channel[i] << " ";
	}
	//cout << "end"<<endl;
	//cout << endl;
	chng = true;
}
void VRPN_CALLBACK TrackerHandler(void* userData, const vrpn_TRACKERCB t) {
	//for (int i = 0; i < 4; i++) {
	//cout << "Tracker '" << t.sensor << "' : " << t.quat[0] << "," << t.quat[1] << "," << t.quat[2] << ","<<t.quat[3]<<endl;
	//}
	for (int i = 0; i < 4; i++) {
		if(i!=3)
			positionArray[i] = t.pos[i];

		rotationArray[i] = t.quat[i];
	}
	chng = true;
}
void VRPN_CALLBACK TrackerRotHandler(void* userData, const vrpn_TRACKERCB t) {
	//for (int i = 0; i < 4; i++) {
		//cout << "Tracker '" << t.sensor << "' : " << t.quat[0] << "," << t.quat[1] << "," << t.quat[2] << ","<<t.quat[3]<<endl;
	//}

	for (int i = 0; i < 4; i++) {
		rotationArray[i] = t.quat[i];
		//cout << analogState[i];
	}
	//cout << endl;
}

void VRPN_CALLBACK TrackerPosHandler(void* userData, const vrpn_TRACKERCB t) {
	//for (int i = 0; i < 4; i++) {
	//cout << "Tracker '" << t.sensor << "' : " << t.quat[0] << "," << t.quat[1] << "," << t.quat[2] << ","<<t.quat[3]<<endl;
	//}
	for (int i = 0; i < 3; i++) {
		positionArray[i] = t.pos[i];
	}
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
		Sleep(10.0);
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
	vrpn_Tracker_Remote* trackerRemote = new vrpn_Tracker_Remote(host);

	vrpnAnalog->register_change_handler(0, AnalogHandler);
	while (this->running != NULL) {
		vrpnAnalog->mainloop();
		Sleep(10.0);
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
	//cout << "Starting " << this->deviceName << " handler" << endl;
	//ofstream SIVRData;
	//SIVRData.open(this->path, std::ofstream::trunc);
	//cout << this->dataTypes;
	std::string m = this->VRPNname + "@localhost";
	cout << m << endl;
	const char* host = m.c_str();
	
	if (this->bridgeType == "Analog") {
		vrpn_Analog_Remote* vrpnAnalog = new vrpn_Analog_Remote(host);
		vrpnAnalog->register_change_handler(0, AnalogHandler);
		while (this->running != NULL) {
			vrpnAnalog->mainloop();
			//vrpnAnalog->mainloop();
			//cout << "Main Loop";
			//vrpnButton->mainloop();
			//SIVRData.seekp(0);
			//cout << this->dataTypes << " "<<this->deviceType;

			for (int i = 0; i < this->channels; i++)
			{

				if (this->rot) {
					if (i + 1 == abs((int)this->XRot)) {
						this->Rotation[0] = this->analogArray[i] * (this->XRot / abs(this->XRot));
					}
					else if (i + 1 == abs((int)this->YRot)) {
						this->Rotation[1] = this->analogArray[i] * (this->YRot / abs(this->YRot));
					}
					else if (i + 1 == abs((int)this->ZRot)) {
						this->Rotation[2] = this->analogArray[i] * (this->ZRot / abs(this->ZRot));
					}
					else if (i + 1 == abs((int)this->WRot)) {
						this->Rotation[3] = this->analogArray[i] * (this->WRot / abs(this->WRot));
					}
				}
				if (this->pos) {
					if (i + 1 == abs((int)this->XPos)) {
						this->Position[0] = this->analogArray[i] * (this->XPos / abs(this->XPos));
					}
					else if (i + 1 == abs((int)this->YPos)) {
						this->Position[1] = this->analogArray[i] * (this->YPos / abs(this->YPos));
					}
					else if (i + 1 == abs((int)this->ZPos)) {
						this->Position[2] = this->analogArray[i] * (this->ZPos / abs(this->ZPos));
					}
				}



			}
			try {
				if (this->running == false)
					break;
			}
			catch (System::NullReferenceException^) {
				cout << "Running null value" << endl;
			}
		}
	}
	//vrpn_Button_Remote* vrpnButton = new vrpn_Button_Remote(host);
	else if (this->bridgeType == "Tracker") {
		vrpn_Tracker_Remote* vrpnTracker = new vrpn_Tracker_Remote(host);
		if(this->rot&&!this->pos)
			vrpnTracker->register_change_handler(0, TrackerRotHandler);
		else if (this->pos&&!this->rot)
			vrpnTracker->register_change_handler(0, TrackerRotHandler);
		else
			vrpnTracker->register_change_handler(0, TrackerHandler);
		while (this->running != NULL) {
			vrpnTracker->mainloop();
			//vrpnAnalog->mainloop();
			//cout << "Main Loop";
			//vrpnButton->mainloop();
			//SIVRData.seekp(0);
			//cout << this->dataTypes << " "<<this->deviceType;

			for (int i = 0; i < this->channels; i++)
			{

				if (this->rot) {
					if (i + 1 == abs((int)this->XRot)) {
						this->Rotation[0] = rotArray[i] * (this->XRot / abs(this->XRot));
					}
					else if (i + 1 == abs((int)this->YRot)) {
						this->Rotation[1] = rotArray[i] * (this->YRot / abs(this->YRot));
					}
					else if (i + 1 == abs((int)this->ZRot)) {
						this->Rotation[2] = rotArray[i] * (this->ZRot / abs(this->ZRot));
					}
					else if (i + 1 == abs((int)this->WRot)) {
						this->Rotation[3] = rotArray[i] * (this->WRot / abs(this->WRot));
					}
				}
				if (this->pos) {
					if (i + 1 == abs((int)this->XPos)) {
						this->Position[0] = posArray[i] * (this->XPos / abs(this->XPos));
					}
					else if (i + 1 == abs((int)this->YPos)) {
						this->Position[1] = posArray[i] * (this->YPos / abs(this->YPos));
					}
					else if (i + 1 == abs((int)this->ZPos)) {
						this->Position[2] = posArray[i] * (this->ZPos / abs(this->ZPos));
					}
				}



			}
			try {
				if (this->running == false)
					break;
			}
			catch (System::NullReferenceException^) {
				cout << "Running null value" << endl;
			}
		}
	}
	//vrpnButton->register_change_handler(0, ButtonHandler);
	
	//SIVRData.close();
	//cout << "Closing Time~~\n";

}
