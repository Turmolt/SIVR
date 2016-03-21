#include "VRPNClient.h"

#include "Boss.h"
#include "DeviceNames.h"
#include "ProcWorker.h"
#include <time.h>
#include <msclr\marshal_cppstd.h>
#include "Bridge.h"
#include <string>
using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
using namespace System::IO;

VrpnBridge* b;

struct Mutex2 {
	int taken = 0;

};
Mutex2 m2;
//create a VRPNClient with a device type and a device name to use on the VRPN Server
VRPNClient::VRPNClient(DevType t, String^ dev)
{
	//VrpnBridge* b = new VrpnBridge(external);
	s = gcnew String("");
	this->dName = dev;
	std::string dn = msclr::interop::marshal_as<std::string>(dev);
	b = new VrpnBridge(t, dn);
	this->deviceType = t;
	Console::WriteLine(dev);
	if (t == DevType::Gamepad){
		startThread();
	}
	else if (t == DevType::Mouse) {
		startAnalogThread();
	}

	
}

//idk?
void VRPNClient::makeClient()
{

}

//Listen is the function in which the thread runs, when this ends the thread ends.
//TODO: Create a "listen" func for each device
void VRPNClient::buttonListen() {
	b->StartButtonHandler(external);
}

void VRPNClient::buttonListen2() {
	this->running = true;
	//device specific stuff here
	while(this->running) {
		if (b != NULL) {
			Console::WriteLine(b->buttonNumber + " : " + b->buttonState);
		}
		else
		{
			Console::Write("Fak");
			std::string dn = msclr::interop::marshal_as<std::string>(dName->ToString());
			b = new VrpnBridge(this->deviceType,dn);
		}
		
		
		Sleep(100.0);
	}

	b->running = false;
}

//Listen is the function in which the thread runs, when this ends the thread ends.
//TODO: Create a "listen" func for each device
void VRPNClient::analogListen() {
	b->StartAnalogHandler();
}

void VRPNClient::analogListen2() {
	this->running = true;
	//device specific stuff here
	while (this->running) {
		if (b != NULL) {
			//Console::WriteLine(b->buttonNumber);
		}
		else
		{
			Console::Write("Fak");
			std::string dn = msclr::interop::marshal_as<std::string>(dName->ToString());
			b = new VrpnBridge(this->deviceType, dn);
		}


		Sleep(100.0);
	}

	b->running = false;
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
	this->running = true;
	this->aThread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::buttonListen));
	this->a2Thread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::buttonListen2));
	this->aThread->Start();
	this->a2Thread->Start();
	while (!this->aThread->IsAlive); //waiting for the thread to start
	Thread::Sleep(100);
	//this->running = false;
}

void VRPNClient::startAnalogThread()
{
	//ThreadWork^ tw = gcnew ThreadWork();
	this->running = true;
	this->aThread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::analogListen));
	this->a2Thread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::analogListen2));
	this->aThread->Start();
	this->a2Thread->Start();
	while (!this->aThread->IsAlive); //waiting for the thread to start
	Thread::Sleep(100);
	//this->running = false;
}


//call when ending device listening
void VRPNClient::stopThread()
{

	this->running = false;
	Console::WriteLine("Shutting down thread");
	
	/*
	if (this->aThread != nullptr) {
		//delete objects before closing the thread?
		if (this->aThread && this->aThread->IsAlive) {
			System::TimeSpan waitTime = System::TimeSpan(0, 0, 1);
			if (this->aThread->Join(waitTime) != true) {
				this->aThread->Abort(); //if doesnt close through other means
			}
				
		}
	}
	*/
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