#include "Boss.h"

#include "MainWindow.h"


using namespace System::Windows::Forms;
using namespace System;
using namespace System::Runtime::InteropServices;
#define ARRAY_SIZE 15


Boss::Boss()
{
	this->hands=false;
	this->head = false;
	this->tracker = false;
	this->gamepad = false;
	this->mouse = false;

	curMax = 0;
	clientArray = gcnew cli::array<VRPNClient^>(ARRAY_SIZE);
}

//create new client for VRPN based on type fed in
VRPNClient ^ Boss::newClient(DevType t, String^ devName, SIVConfig^ cfg)
{
	switch (t) {
	case DevType::HMD:
		if (!this->head)
		{
			this->Head = gcnew VRPNClient(t, devName);
			this->Head->config = cfg;
			this->head = true;
		}
		else
			Console::WriteLine("Head already has a device assigned.");
		return this->Head;
		break;
	case DevType::Gamepad:
		if (!this->gamepad){
			this->Gamepad = gcnew VRPNClient(t, devName);
			this->Gamepad->config = cfg;
			this->gamepad = true;
		}
		else
			Console::WriteLine("Gamepad already has a device assigned.");
		return this->Gamepad;
		break;
	case DevType::Spatial:
		if (!this->tracker){
			this->Tracker = gcnew VRPNClient(t, devName);
			this->Tracker->config = cfg;
			this->tracker = true;
		}
		else
			Console::WriteLine("Spatial already has a device assigned.");
		return this->Tracker;
		break;
	case DevType::Mouse:
		if (!this->mouse){
			this->Mouse = gcnew VRPNClient(t, devName);
			this->mouse = true;
		}
		else
			Console::WriteLine("Mouse already has a device assigned.");
		return this->Mouse;
		break;
	case DevType::HandTracker:
		if (!this->hands) {
			this->Hands = gcnew VRPNClient(t, devName);
			this->hands = true;
		}
		else
			Console::WriteLine("Hands already has a device assigned.");
		return this->Mouse;
		break;
	}
}

//return the client of selected type
VRPNClient ^ Boss::getClient(DevType type)
{
	switch (type) {
	case DevType::HMD:
		return this->Head;
		break;
	case DevType::Gamepad:
		return this->Gamepad;
		break;
	case DevType::Spatial:
		return this->Tracker;
		break;
	case DevType::Mouse:
		return this->Mouse;
		break;
	case DevType::HandTracker:
		return this->Mouse;
		break;
	}
}

//kill client of type t, swap the bool related to it.
void Boss::killClient(DevType t) {
	try{
		switch (t) {
		case DevType::HMD:
			this->Head->stopThread();
			delete this->Head;
			this->head = false;
			break;
		case DevType::Gamepad:
			this->Gamepad->stopThread();
			this->gamepad = false;
			break;
		case DevType::Spatial:
			this->Tracker->stopThread();
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

[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ProjectS::MainWindow());
	
	return 0;
}