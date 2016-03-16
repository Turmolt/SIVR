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


//create a VRPNClient with a device type and a device name to use on the VRPN Server
VRPNClient::VRPNClient(DevType t,std::string dn)
{
	if (t == DevType::Gamepad) {
		printf("We did it! %s\n", dn.c_str());
	}
	devName = dn;
}

//idk?
void VRPNClient::makeClient()
{

}

void VRPNClient::listen() {

	//device specific stuff here


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
	aThread = gcnew Thread(gcnew ThreadStart(this, &VRPNClient::listen));
	aThread->Start();
	while (!aThread->IsAlive); //waiting for the thread to start
	Thread::Sleep(100);
}


//call when ending device listening
void VRPNClient::stopThread()
{
	if (aThread != nullptr) {
		//delete objects before closing the thread?
		if (aThread && aThread->IsAlive) {
			System::TimeSpan waitTime = System::TimeSpan(0, 0, 1);
			if (aThread->Join(waitTime) != true) {
				aThread->Abort(); //if doesnt close through other means
			}
				
		}
	}
}

