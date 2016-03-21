#include "Boss.h"

#include "MainWindow.h"


using namespace System::Windows::Forms;
using namespace System;
using namespace System::Runtime::InteropServices;
#define ARRAY_SIZE 15


Boss::Boss()
{
	curMax = 0;
	clientArray = gcnew cli::array<VRPNClient^>(ARRAY_SIZE);
}


VRPNClient ^ Boss::newClient(DevType t, String^ devName)
{
	switch (t) {
	case DevType::HMD:
		this->Head = gcnew VRPNClient(t, devName);
		return this->Head;
		break;
	case DevType::Gamepad:
		this->Gamepad = gcnew VRPNClient(t, devName);
		return this->Gamepad;
		break;
	case DevType::Tracker:
		this->Tracker = gcnew VRPNClient(t, devName);
		return this->Tracker;
		break;
	case DevType::Mouse:
		this->Mouse = gcnew VRPNClient(t, devName);
		return this->Mouse;
		break;
	}
}

VRPNClient ^ Boss::getClient(DevType type)
{
	switch (type) {
	case DevType::HMD:
		return this->Head;
		break;
	case DevType::Gamepad:
		return this->Gamepad;
		break;
	case DevType::Tracker:
		return this->Tracker;
		break;
	case DevType::Mouse:
		return this->Mouse;
		break;
	}
}

void Boss::killClient(DevType t) {
	try{
		switch (t) {
		case DevType::HMD:
			this->Head->stopThread();
			break;
		case DevType::Gamepad:
			this->Gamepad->stopThread();
			break;
		case DevType::Tracker:
			this->Tracker->stopThread();
			break;
		case DevType::Mouse:
			this->Mouse->stopThread();
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