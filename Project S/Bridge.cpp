#include <string>
#include <iostream>
#include <vrpn_Button.h>
#include <vrpn_Tracker.h>
#include <vrpn_Analog.h>
#include "Bridge.h"

using namespace std;

int butState = 0;
int butNumber = -1;




VrpnBridge::VrpnBridge(DevType x)
	:buttonState(butState),buttonNumber(butNumber)
{
	//ex = external;
	this->deviceType = x;
	this->running = true;
	
}

//The Button Handler for the device. Sets butState and butNumber to identify the buttons pressed
void VRPN_CALLBACK ButtonHandler(void* userData, const vrpn_BUTTONCB b) {
	butState = b.state;
	butNumber = b.button;
}

void VrpnBridge::StartButtonHandler(int* external) {
	//set to true, external class sets to false when thread should (hopefully) stop

	//external = &ext;
	vrpn_Button_Remote* vrpnButton = new vrpn_Button_Remote("Mouse0@localhost");
	
	vrpnButton->register_change_handler(0,ButtonHandler);
	while (this->running!=NULL) {
		vrpnButton->mainloop();
		Sleep(50.0);
		try {
			if (this->running == false)
				break;
		}
		catch (System::NullReferenceException^){
			cout << "damnit" << endl;
		}
	}
}
