#include "VRPNClient.h"

#include "Boss.h"
#include "DeviceNames.h"
#include "ProcWorker.h"
#include <time.h>
#include <msclr\marshal_cppstd.h>
#include "Bridge.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
using namespace System::IO;

DevType x;


struct Mutex2 {
	int taken = 0;

};
Mutex2 m2;
//create a VRPNClient with a device type and a device name to use on the VRPN Server
VRPNClient::VRPNClient(DevType t,String^ dev)
{
	//VrpnBridge* b = new VrpnBridge(external);
	if (t == DevType::Gamepad) {
		Console::WriteLine(dev);
		startThread();
	}
	s = gcnew String("");
	dName = dev;
	
}

//idk?
void VRPNClient::makeClient()
{

}

//Listen is the function in which the thread runs, when this ends the thread ends.
//TODO: Create a "listen" func for each device
void VRPNClient::listen() {
	
	
	//const char* deviceName = msclr::interop::marshal_as<const char*>(dName->ToString()+"@localhost");

	//vrpn_Analog_Remote* vrpnAnalog = new vrpn_Analog_Remote(deviceName);

	//myCallbackDelegate^ del = gcnew myCallbackDelegate(&ButtonCb);

	//vrpn_Button_Remote* vrpnButton = new vrpn_Button_Remote(deviceName);
	
	
	//vrpnButton->register_change_handler(0,ButtonCb);
	
	
	VrpnBridge* b = new VrpnBridge(1.0f);
	//device specific stuff here
	b->StartHandler(external);
}

void VRPNClient::listen2() {

	//device specific stuff here
	while(1) {
		Console::Write(external);
		Sleep(100.0);
	}
}



void VRPN_CALLBACK VRPNClient::ButtonCb(void* userData,  const vrpn_BUTTONCB b)
{
	
	Console::WriteLine(b.button + ": " + b.state);

}

void VRPN_CALLBACK VRPNClient::AnalogCb(void* userData, const vrpn_ANALOGCB a) {
	int channels = a.num_channel;
	Console::Write("Analog: ");
	for (int i = 0; i < channels; i++) {
		Console::Write(a.channel[i]);
	}
	Console::Write("\n");
}

//ensure that the device type is enabled in the config file
void VRPNClient::enableDevice(DevType t, System::String^ devName) {
	
	//const char* cfgPath = (const char*)Marshal::StringToHGlobalAnsi(ProcWorker::configDir()).ToPointer();
	String^ cfgPath = ProcWorker::configDir();
	if (t == DevType::Gamepad) {
		StreamWriter^ sw = gcnew StreamWriter(cfgPath);
		sw->Write(DeviceNames::xinput->ToString()+" " + devName->ToString());
	}

	

}

//start a thread for listening information

void VRPNClient::startThread()
{
	//ThreadWork^ tw = gcnew ThreadWork();
	this->aThread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::listen));
	this->a2Thread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::listen2));
	this->aThread->Start();
	this->a2Thread->Start();
	while (!this->aThread->IsAlive); //waiting for the thread to start
	Thread::Sleep(100);
}


//call when ending device listening
void VRPNClient::stopThread()
{
	if (this->aThread != nullptr) {
		//delete objects before closing the thread?
		if (this->aThread && this->aThread->IsAlive) {
			System::TimeSpan waitTime = System::TimeSpan(0, 0, 1);
			if (this->aThread->Join(waitTime) != true) {
				this->aThread->Abort(); //if doesnt close through other means
			}
				
		}
	}
}

/*

ref class ThreadWork {
public:
	ThreadWork();
	void ThreadProc(System::String s);
};

ThreadWork::ThreadWork() {

}

void ThreadWork::ThreadProc(System::String s) {
	char* cs = s.ToCharArray();
	for (int i = 0; i < 100; i++) {
		printf();
	}
}
*/