#pragma once

#include "string.h"


static char *xinput = "vrpn_XInputGamepad XInput0 0";

static char *ffjoystick = "vrpn_DirectXFFJoystick	Joystick0	60	0";

static char *serialmouse = "vrpn_Button_SerialMouse	Button0 COM1 3button";

static char *mouse = "vrpn_Mouse	Mouse0";

static char *wiimote = "vrpn_WiiMote		WiiMote0 1 0 0 1";

static char *phasespace = strcat("#vrpn_Tracker_PhaseSpace Tracker0 localhost 480.0 1 0\n#<owl>\n#0 :     pt      0      #to sensor 0 assign led 0\n",
	"#1 :     pt      1      #to sensor 1 assign led 1\n#2 :     pt      2      #to sensor 2 assign led 2\n#3 :     pt      3      #to sensor 3 assign led 3\n#</owl>");

static char *zsight = "vrpn_Tracker_zSight zSight";

static char *yei3space = "vrpn_YEI_3Space_Sensor_Wireless	YEI0	0	120004F9	COM9	115200	0	0	50.0 1 0 0 1";

static char *threespace = "vrpn_Tracker_3Space	Tracker0 / dev / ttyS0	19200";

static char *intersense = "vrpn_Tracker_InterSense Tracker0 AUTO IS900time";