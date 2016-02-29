#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include <cstdio>
#include <string>




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
};


