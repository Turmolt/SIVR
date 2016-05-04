#pragma once

#include <windows.h>
#include "VRPNClient.h"
#include <vcclr.h>
#include "SIVConfig.h"
#include "SIVRServer.h"


ref class Boss
{
public:
	Boss();
	void newClient(DevType t, System::String^,SIVConfig^ cfg);
	VRPNClient^ getClient(DevType type);
	void killClient(DevType t);
	//cli::array<VRPNClient^>^ clientArray;
	void killServer();

	//SERVER FUNCTIONS
	SIVRServer^ getServer();
	SIVRServer^ makeServer();
	void startServer();
	void stopServer();

	//The Server
	SIVRServer^ server;

	//Client references
	VRPNClient^ Hands;
	VRPNClient^ Head;
	VRPNClient^ Spatial;
	VRPNClient^ Misc;
	VRPNClient^ Mouse;

	SIVConfig^ headCfg;
	SIVConfig^ handCfg;
	SIVConfig^ spatialCfg;
	SIVConfig^ miscCfg;

	bool hands;
	bool head;
	bool tracker;
	bool misc;
	bool mouse;


	int curMax;
	int curKill;

};
