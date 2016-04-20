#include "Boss.h"

#include "MainWindow.h"
#include "DeviceWindow.h"



using namespace System::Windows::Forms;
using namespace System;
using namespace System::Runtime::InteropServices;
//#define ARRAY_SIZE 15


Boss::Boss()
{
	this->hands=false;
	this->head = false;
	this->tracker = false;
	this->misc = false;
	this->mouse = false;

	curMax = 0;
	//clientArray = gcnew cli::array<VRPNClient^>(ARRAY_SIZE);
}

//create new client for VRPN based on type fed in
void Boss::newClient(DevType t, String^ devName, SIVConfig^ cfg)
{
	switch (t) {
	case DevType::HeadTracker:
		if (!this->head)
		{
			this->Head = gcnew VRPNClient(t, devName,cfg);
			this->headCfg = cfg;
			//this->Head->config = cfg;
			this->head = true;
		}
		else
			Console::WriteLine("Head already has a device assigned.");
		break;
	case DevType::Misc:
		if (!this->misc){
			this->Misc = gcnew VRPNClient(t, devName,cfg);
			Console::WriteLine(cfg->channels);
			this->miscCfg = cfg;
			//this->Misc->config = cfg;
			this->misc = true;
		}
		else
			Console::WriteLine("Gamepad already has a device assigned.");
		break;
	case DevType::Spatial:
		if (!this->tracker){
			this->Spatial = gcnew VRPNClient(t, devName, cfg);
			this->spatialCfg = cfg;
			//this->Tracker->config = cfg;
			this->tracker = true;
		}
		else
			Console::WriteLine("Spatial already has a device assigned.");
		break;
	case DevType::Mouse:
		if (!this->mouse){
			this->Mouse = gcnew VRPNClient(t, devName, cfg);
			this->miscCfg = cfg;
			this->mouse = true;
		}
		else
			Console::WriteLine("Mouse already has a device assigned.");
		break;
	case DevType::HandTracker:
		if (!this->hands) {
			this->Hands = gcnew VRPNClient(t, devName, cfg);
			this->handCfg = cfg;
			this->hands = true;
		}
		else
			Console::WriteLine("Hands already has a device assigned.");
		break;
	}
	Console::WriteLine("End New Client");
}

//return the client of selected type
VRPNClient ^ Boss::getClient(DevType type)
{
	switch (type) {
	case DevType::HeadTracker:
		return this->Head;
		break;
	case DevType::Misc:
		return this->Misc;
		break;
	case DevType::Spatial:
		return this->Spatial;
		break;
	case DevType::Mouse:
		return this->Mouse;
		break;
	case DevType::HandTracker:
		return this->Mouse;
		break;
	}
}

void Boss::killServer() {
	if (this->server->running) {
		this->server->running = false;
	}
}
//kill client of type t, swap the bool related to it.
void Boss::killClient(DevType t) {
	try{
		switch (t) {
		case DevType::HeadTracker:
			this->Head->stopThread();
			//delete this->Head;
			this->head = false;
			break;
		case DevType::Misc:
			this->Misc->stopThread();
			this->misc = false;
			break;
		case DevType::Spatial:
			this->Spatial->stopThread();
			this->tracker = false;
			break;
		case DevType::Mouse:
			this->Mouse->stopThread();
			this->mouse = false;
			break;
		case DevType::HandTracker:
			this->Hands->stopThread();
			this->hands = false;
			break;
		}
	}
	catch (System::NullReferenceException^) {
		Console::WriteLine("No client available");
	}
}


SIVRServer^ Boss::startServer()
{
	String^ head = "n";
	String^ hands = "n";
	String^ spatial = "n";
	String^ misc = "n";

	System::Console::WriteLine("startServer()");

	//DETERMINE DATA TYPES TO SEND HAND
	if (this->hands) {
		Console::WriteLine(this->handCfg->dataTypes->ToString() + " chosen for hand\n");
		if (this->handCfg->dataTypes->Equals("Rotation")) {
			hands = "r";
		}
		else if (this->handCfg->dataTypes->Equals("Position")) {
			hands = "p";
		}
		else if (this->handCfg->dataTypes->Equals("Both")) {
			hands = "b";
		}
		else if (this->handCfg->dataTypes->Equals("None")) {
			hands = "n";
		}
	}
	//DETERMINE DATA TYPES TO SEND HEAD
	if (this->head) {
		if (this->headCfg->dataTypes->Equals("Rotation")) {
			head = "r";
		}
		else if (this->headCfg->dataTypes->Equals("Position")) {
			head = "p";
		}
		else if (this->headCfg->dataTypes->Equals("Both")) {
			head = "b";
		}
		else if (this->headCfg->dataTypes->Equals("None")) {
			head = "n";
		}
	}
	//DETERMINE DATA TYPES TO SEND SPATIAL
	if (this->tracker) {
		if (this->spatialCfg->dataTypes->Equals("Rotation")) {
			spatial = "r";
		}
		else if (this->spatialCfg->dataTypes->Equals("Position")) {
			spatial = "p";
		}
		else if (this->spatialCfg->dataTypes->Equals("Both")) {
			spatial = "b";
		}
		else if (this->spatialCfg->dataTypes->Equals("None")) {
			spatial = "n";
		}
	}
	//DETERMINE DATA TYPES TO SEND MISC
	if (this->misc) {
		Console::WriteLine(this->miscCfg->dataTypes->ToString() + " chosen for misc\n");
		if (this->miscCfg->dataTypes->Equals("Rotation")) {
			misc = "r";
		}
		else if (this->miscCfg->dataTypes->Equals("Position")) {
			misc = "p";
		}
		else if (this->miscCfg->dataTypes->Equals("Both")) {
			misc = "b";
		}
		else if (this->miscCfg->dataTypes->Equals("None")) {
			misc = "n";
		}
	}

	this->server = gcnew SIVRServer(7777, head, hands, spatial, misc);

	//System::Console::WriteLine(this->server->activePurposes);

	//assign server reference toe ach client
	this->server->StartServer();
	if (this->head) {
		this->Head->server = this->server;

		this->Head->startAnalogThread();
	}
	if (this->hands) {
		this->Hands->server = this->server;

		this->Hands->startAnalogThread();
	}
	if (this->tracker) {
		this->Spatial->server = this->server;

		this->Spatial->startAnalogThread();
	}
	if (this->misc) {
		this->Misc->server = this->server;

		this->Misc->startAnalogThread();
	}

	return this->server;
}

SIVRServer^ Boss::getServer()
{
	return this->server;
}

void Boss::stopServer()
{
	throw gcnew System::NotImplementedException();
}

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ProjectS::DeviceWindow());
	
	return 0;
}