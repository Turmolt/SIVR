#include "VRPNClient.h"

#include "Boss.h"
#include "DeviceNames.h"
#include "ProcWorker.h"
#include <time.h>
#include <msclr\marshal_cppstd.h>
#include "Bridge.h"
#include <string>
#include <array>
#include <subscriptionservices.h>

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
using namespace System::IO;
//using namespace System::ServiceModel;

VrpnBridge* b;

struct Mutex2 {
	int taken = 0;
};
Mutex2 m2;
//create a VRPNClient with a device type and a device name to use on the VRPN Server
VRPNClient::VRPNClient(DevType t, String^ dev,SIVConfig^ cfg)
{


	this->Rotation = gcnew cli::array<float>(4);
	this->Position = gcnew cli::array<float>(3);

	//VrpnBridge* b = new VrpnBridge(external);

	this->config = cfg;

	//Console::WriteLine(this->config->buttons);

	//Console::WriteLine(this->config->dataTypes);
	//Console::WriteLine(this->config->VRPNname);
	this->config->deviceName = dev;
	s = gcnew String("");
	this->dName = dev;

	b = new VrpnBridge(t, this->config);
	this->deviceType = t;


	Console::WriteLine("End VRPN Construct");

	

	//startAnalogThread();

	
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
			if (b->changed) {
				Console::WriteLine(b->buttonNumber + " : " + b->buttonState);
				b->changed = false;
			}
		}
		else
		{
			Console::Write("No Bridge");
			b = new VrpnBridge(this->deviceType, this->config);
		}
		
		
		Sleep(5.0);
	}

	b->running = false;
}

//Listen is the function in which the thread runs, when this ends the thread ends.
//TODO: Create a "listen" func for each device
void VRPNClient::analogListen() {
	b->StartGamepadHandler();
}

void VRPNClient::analogListen2() {
	this->running = true;
	//device specific stuff here
	Console::WriteLine("Analog Listen");
	switch (this->deviceType) {

		//write to head if device type is head
	case DevType::HeadTracker:
		while (this->running) {
			if (b != NULL) {
				if (b->changed) {
					if (this->config->rot) {
						server->headData.rotationArray[0] = b->analogArray[b->XRot];
						server->headData.rotationArray[1] = b->analogArray[b->YRot];
						server->headData.rotationArray[2] = b->analogArray[b->ZRot];
						server->headData.rotationArray[3] = b->analogArray[b->WRot];
					}
					if (this->config->pos) {
						server->headData.positionArray[0] = b->analogArray[b->XPos];
						server->headData.positionArray[1] = b->analogArray[b->YPos];
						server->headData.positionArray[2] = b->analogArray[b->ZPos];
					}
					b->changed = false;
				}
			}
			else
			{
				Console::Write("Oops");
				b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;

		//if the device is hand then write to hand
	case DevType::HandTracker:
		while (this->running) {
			if (b != NULL) {
				if (b->changed) {
					if (this->config->rot) {
						this->server->handData.rotationArray[0] = b->analogArray[b->XRot];
						this->server->handData.rotationArray[1] = b->analogArray[b->YRot];
						this->server->handData.rotationArray[2] = b->analogArray[b->ZRot];
						this->server->handData.rotationArray[3] = b->analogArray[b->WRot];
					}
					if (this->config->pos) {
						this->server->handData.positionArray[0] = b->analogArray[b->XPos];
						this->server->handData.positionArray[1] = b->analogArray[b->YPos];
						this->server->handData.positionArray[2] = b->analogArray[b->ZPos];
					}
					b->changed = false;
				}
				//Console::WriteLine(b->buttonNumber);
			}
			else
			{
				Console::Write("Oops");
				b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;
	case DevType::Spatial:
		while (this->running) {
			if (b != NULL) {
				if (b->changed) {
					if (this->config->rot) {
						this->server->spatialData.rotationArray[0] = b->analogArray[b->XRot];
						this->server->spatialData.rotationArray[1] = b->analogArray[b->YRot];
						this->server->spatialData.rotationArray[2] = b->analogArray[b->ZRot];
						this->server->spatialData.rotationArray[3] = b->analogArray[b->WRot];
					}
					if (this->config->pos) {
						this->server->spatialData.positionArray[0] = b->analogArray[b->XPos];
						this->server->spatialData.positionArray[1] = b->analogArray[b->YPos];
						this->server->spatialData.positionArray[2] = b->analogArray[b->ZPos];
					}
					b->changed = false;
				}
				//Console::WriteLine(b->buttonNumber);
			}
			else
			{
				Console::Write("Oops");
				b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;
	case DevType::Misc:
		while (this->running) {
			if (b != NULL) {
				if (b->changed) {
					if (this->server->miscData.rot) {
						this->server->miscData.rotationArray[0] = b->Rotation[0];
						this->server->miscData.rotationArray[1] = b->Rotation[1];
						this->server->miscData.rotationArray[2] = b->Rotation[2];
						this->server->miscData.rotationArray[3] = b->Rotation[3];
					}
					if (this->server->miscData.pos) {
						this->server->miscData.positionArray[0] = b->Position[0];
						this->server->miscData.positionArray[1] = b->Position[1];
						this->server->miscData.positionArray[2] = b->Position[2];
					}
					b->changed = false;
				}
				//Console::WriteLine(b->buttonNumber);
			}
			else
			{
				Console::Write("Oops");
				b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;
	}
	

	b->running = false;
}

//ensure that the device type is enabled in the config file
void VRPNClient::enableDevice(DevType t, System::String^ devName) {
	
	//const char* cfgPath = (const char*)Marshal::StringToHGlobalAnsi(ProcWorker::configDir()).ToPointer();
	String^ cfgPath = ProcWorker::configDir();
	if (t == DevType::Misc) {
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
	this->server = ProcWorker::getBoss()->server;
	Console::WriteLine(this->server->miscData.pos + "O boy");
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