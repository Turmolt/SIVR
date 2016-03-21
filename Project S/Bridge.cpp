#include <string>
#include <iostream>
#include <vrpn_Button.h>
#include <vrpn_Tracker.h>
#include <vrpn_Analog.h>
#include "Bridge.h"

using namespace std;

int ex;

VrpnBridge::VrpnBridge(float mine)
	:ext(ex)
{
	//ex = external;
}

void VRPN_CALLBACK ButtonHandler(void* userData, const vrpn_BUTTONCB b) {
	cout << b.button << ": " << b.state<<endl;
	ex = b.state;
	
}

void VrpnBridge::ButtonH() {
	
	
}

void VrpnBridge::StartHandler(int* external) {
	external = &ext;
	vrpn_Button_Remote* vrpnButton = new vrpn_Button_Remote("Mouse0@localhost");
	
	vrpnButton->register_change_handler(0,ButtonHandler);

	while (1) {
		vrpnButton->mainloop();

		//cout<<ex<<" hehe"<<endl;
		Sleep(50.0);
	}
}

void VrpnBridge::Param() {
	//external = mine;

}