#pragma once



#include <windows.h>
#include "VRPNClient.h"
#include <vcclr.h>

ref class Boss
{
public:
	Boss();
	VRPNClient^ newClient(DevType t, System::String^);
	VRPNClient^ getClient(int n);
	cli::array<VRPNClient^>^ clientArray;
	int curMax;
};
