#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include <cstdio>
#include <string>
#include "Boss.h"
#include "SIVConfig.h"

#define MAX_CONFIG 5
#define HEAD_N 0
#define HAND_N 1
#define SPATIAL_N 2
#define MISC_N 3

static class ProcWorker
{
public:
	ProcWorker();
	static void startProc(LPCTSTR);
	static void endProc(char *);
	static DWORD checkProc(char *);
	static System::String^ servDir();
	static System::String^ configDir();
	static void setServDir(System::String^);
	static void setConfigDir(System::String^);
	static Boss^ getBoss();
	static void setBoss(Boss^ b);

	static SIVConfig^ GetCfg(System::String^);

	static array<SIVConfig^>^ readDevices(System::String^);

	static void readConfig(DevType, System::String^);

};


