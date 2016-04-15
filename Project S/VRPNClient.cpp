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



struct Mutex2 {
	int taken = 0;
};
Mutex2 m2;
//create a VRPNClient with a device type and a device name to use on the VRPN Server
VRPNClient::VRPNClient(DevType t, String^ dev,SIVConfig^ cfg)
{


	this->Rotation = gcnew cli::array<float>(4);
	this->Position = gcnew cli::array<float>(3);

	this->config = cfg;

	this->config->deviceName = dev;
	s = gcnew String("");
	this->dName = dev;
	Console::WriteLine("Start Bridge");
	this->b = new VrpnBridge(t, this->config);
	this->deviceType = t;


	//Console::WriteLine("End VRPN Construct");
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
		if (this->b != NULL) {
			if (this->b->changed) {
				//Console::WriteLine(b->buttonNumber + " : " + b->buttonState);
				this->b->changed = false;
			}
		}
		else
		{
			Console::Write("No Bridge");
			this->b = new VrpnBridge(this->deviceType, this->config);
		}
		
		
		Sleep(5.0);
	}

	this->b->running = false;
}

//Listen is the function in which the thread runs, when this ends the thread ends.
//TODO: Create a "listen" func for each device
void VRPNClient::analogListen() {
	this->b->StartGamepadHandler();
}

void VRPNClient::analogListen2() {
	this->running = true;
	//device specific stuff here
	//Console::WriteLine("Analog Listen");
	switch (this->deviceType) {

		//write to head if device type is head
	case DevType::HeadTracker:
		Console::WriteLine(this->config->dataTypes + " is the type");
		//set data ahead of being changed
		for (int k = 0; k <= 3; k++) {
			if(k!=3)
				server->headData.positionArray[k] = b->Position[k];
			server->headData.rotationArray[k] = b->Rotation[k];
		}
		while (this->running) {
			if (this->b != NULL) {
				//if (this->b->changed) {
					if (this->server->headData.rot) {
						server->headData.rotationArray[0] = this->b->Rotation[0];
						server->headData.rotationArray[1] = this->b->Rotation[1];
						server->headData.rotationArray[2] = this->b->Rotation[2];
						server->headData.rotationArray[3] = this->b->Rotation[3];
					}
					if (this->server->headData.pos) {
						server->headData.positionArray[0] = this->b->Position[0];
						server->headData.positionArray[1] = this->b->Position[1];
						server->headData.positionArray[2] = this->b->Position[2];
					}
					//this->b->changed = false;
				//}
			}
			else
			{
				Console::Write("Oops");
				this->b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;

		//if the device is hand then write to hand
	case DevType::HandTracker:
		//set data ahead of being changed
		Console::WriteLine("hand data logging started\n");
		for (int k = 0; k <= 3; k++) {
			if (k != 3)
				server->handData.positionArray[k] = this->b->Position[k];
			server->handData.rotationArray[k] = this->b->Rotation[k];
		}
		while (this->running) {
			if (this->b != NULL) {
				//if (b->changed) {
					if (this->server->handData.rot) {
						this->server->handData.rotationArray[0] = this->b->Rotation[0];
						this->server->handData.rotationArray[1] = this->b->Rotation[1];
						this->server->handData.rotationArray[2] = this->b->Rotation[2];
						this->server->handData.rotationArray[3] = this->b->Rotation[3];
					}
					if (this->server->handData.pos) {
						this->server->handData.positionArray[0] = this->b->Position[0];
						this->server->handData.positionArray[1] = this->b->Position[1];
						this->server->handData.positionArray[2] = this->b->Position[2];
					}
					//b->changed = false;
				//}
				//Console::WriteLine(b->buttonNumber);
			}
			else
			{
				Console::Write("Oops");
				this->b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;
	case DevType::Spatial:
		//set data ahead of being changed
		for (int k = 0; k <= 3; k++) {
			if (k != 3)
				server->spatialData.positionArray[k] = this->b->Position[k];
			server->spatialData.rotationArray[k] = this->b->Rotation[k];
		}
		while (this->running) {
			if (this->b != NULL) {
				//if (b->changed) {
					if (this->server->spatialData.rot) {
						this->server->spatialData.rotationArray[0] = this->b->Rotation[0];
						this->server->spatialData.rotationArray[1] = this->b->Rotation[1];
						this->server->spatialData.rotationArray[2] = this->b->Rotation[2];
						this->server->spatialData.rotationArray[3] = this->b->Rotation[3];
					}
					if (this->server->spatialData.pos) {
						this->server->spatialData.positionArray[0] = this->b->Position[0];
						this->server->spatialData.positionArray[1] = this->b->Position[1];
						this->server->spatialData.positionArray[2] = this->b->Position[2];
					}
					//b->changed = false;
				//}
				//Console::WriteLine(b->buttonNumber);
			}
			else
			{
				Console::Write("Oops");
				this->b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;
	case DevType::Misc:
		//set data amisc of being changed
		for (int k = 0; k <= 3; k++) {
			if (k != 3)
				server->miscData.positionArray[k] = this->b->Position[k];
			server->miscData.rotationArray[k] = this->b->Rotation[k];
		}
		while (this->running) {
			if (b != NULL) {
				//if (b->changed) {
					if (this->server->miscData.rot) {
						this->server->miscData.rotationArray[0] = this->b->Rotation[0];
						this->server->miscData.rotationArray[1] = this->b->Rotation[1];
						this->server->miscData.rotationArray[2] = this->b->Rotation[2];
						this->server->miscData.rotationArray[3] = this->b->Rotation[3];
					}
					if (this->server->miscData.pos) {
						this->server->miscData.positionArray[0] = this->b->Position[0];
						this->server->miscData.positionArray[1] = this->b->Position[1];
						this->server->miscData.positionArray[2] = this->b->Position[2];
					}
					//b->changed = false;
				//}
				//Console::WriteLine(b->buttonNumber);
			}
			else
			{
				Console::Write("Oops");
				this->b = new VrpnBridge(this->deviceType, this->config);
			}


			Sleep(5.0);
		}
		break;
	}
	

	this->b->running = false;
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
	//Console::WriteLine(this->server->miscData.pos + "O boy");
	this->running = true;
	this->aThread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::analogListen));
	this->a2Thread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::analogListen2));
	this->aThread->Start();
	this->a2Thread->Start();
	while (!this->aThread->IsAlive); //waiting for the thread to start
	Thread::Sleep(100);
	Console::WriteLine("Running");
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

