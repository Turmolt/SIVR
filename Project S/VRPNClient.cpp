#include "VRPNClient.h"

#include "Boss.h"
#include "DeviceNames.h"
#include "ProcWorker.h"

using namespace std;
using namespace System::Runtime::InteropServices;
DevType x;
std::string devName;




VRPNClient::VRPNClient(DevType t,std::string dn)
{
	if (t == DevType::Gamepad) {
		printf("We did it! %s\n", dn.c_str());
	}
	devName = dn;
}

void VRPNClient::makeClient()
{

}

void VRPNClient::enableDevice(DevType t, std::string devName) {
	
	const char* cfgPath = (const char*)Marshal::StringToHGlobalAnsi(ProcWorker::configDir()).ToPointer();
	if (t == DevType::Gamepad) {
		ofstream cfgStream(cfgPath, std::ofstream::binary);
		cfgStream << DeviceNames::xinput<< " " << devName << "\n";
		cfgStream.close();

	}

}

