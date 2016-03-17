#include "VRPNClient.h"

#include "Boss.h"
#include "DeviceNames.h"
#include "ProcWorker.h"
#include <time.h>

using namespace std;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;
DevType x;
std::string devName;

struct Mutex2 {
	bool taken = false;
};
Mutex2 m2;
//create a VRPNClient with a device type and a device name to use on the VRPN Server
VRPNClient::VRPNClient(DevType t,std::string dn)
{
	
	if (t == DevType::Gamepad) {
		printf("We did it! %s\n", dn.c_str());
		startThread();
	}
	s = gcnew System::String("");
	devName = dn;
}

//idk?
void VRPNClient::makeClient()
{

}

void VRPNClient::listen() {

	//device specific stuff here
	for (int i = 0; i < 100; i++) {
		//System::IO::StreamWriter sw = gcnew StreamWrit(s);
		while (m2.taken);
		System::Console::Write("0");
		m2.taken = true;
	}
}
void VRPNClient::listen2() {

	//device specific stuff here
	for (int i = 0; i < 100; i++) {
		//System::IO::StreamWriter sw = gcnew StreamWrit(s);
		while (!m2.taken);
		System::Console::Write("1");
		m2.taken = false;
	}
}

void VRPN_CALLBACK VRPNClient::gamepadCb(void* userData, const vrpn_BUTTONCB b, const vrpn_TRACKERCB t)
{
	cout << b.button << " : " << b.state << endl;
}

//ensure that the device type is enabled in the config file
void VRPNClient::enableDevice(DevType t, std::string devName) {
	
	const char* cfgPath = (const char*)Marshal::StringToHGlobalAnsi(ProcWorker::configDir()).ToPointer();
	if (t == DevType::Gamepad) {
		ofstream cfgStream(cfgPath, std::ofstream::binary);
		cfgStream << DeviceNames::xinput<< " " << devName << "\n";
		cfgStream.close();

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