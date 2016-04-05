#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include <cstdio>
#include <string>
#include "Boss.h"
#include "SIVConfig.h"



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

	static array<SIVConfig^>^ readDevices(System::String^);

};


