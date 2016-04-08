//author - sam gates
#include "ProcWorker.h"

//max number of configs we can read in per purpose


/*
The class used to start and check if a process is running
*/
ref class Globals {
public:
	static System::String^ ServDir = "";
	static System::String^ ConfigDir = "C:/Users/Sam/Desktop/Coding/C++/SIVR/Project S/vrpn.cfg";
	static Boss^ boss;
	static array<SIVConfig^>^ sivc = gcnew array<SIVConfig^>(4);
};

ProcWorker::ProcWorker()
{

}

//Returns server directory
System::String^ ProcWorker::servDir() {

	return Globals::ServDir;
}

System::String^ ProcWorker::configDir() {

	return Globals::ConfigDir;
}

//Set server directory
void ProcWorker::setServDir(System::String^ s) {
	Globals::ServDir = s;
}

void ProcWorker::setConfigDir(System::String^ s) {
	Globals::ConfigDir = s;
}

Boss ^ ProcWorker::getBoss()
{
	return Globals::boss;
}

void ProcWorker::setBoss(Boss^ b)
{
	Globals::boss = b;
}

SIVConfig^ ProcWorker::GetCfg(System::String ^ c)
{
	if (c->Equals("Misc")) {
		return Globals::sivc[3];
	}

	return Globals::sivc[3];
}

array<System::String^>^ ProcWorker::readDevices(System::String^ purpose)
{
	
	System::String^ folder = System::IO::Directory::GetCurrentDirectory()->ToString();
	if (purpose->ToString()->Equals("Head")) {
		folder += "/Devices/Head";
	}
	else if (purpose->ToString()->Equals("Misc")){
		folder += "/Devices/Misc Devices";
	}
	else if (purpose->ToString()->Equals("Hands")) {
		folder += "/Devices/Hands";
	}
	else if (purpose->ToString()->Equals("Spatial")) {
		folder += "/Devices/Spatial Tracking";
	}

	array<System::String^>^ file = System::IO::Directory::GetFiles(folder);
	array<System::String^>^ configArray = gcnew array<System::String^>(file->Length);

	//System::Console::WriteLine("--== Files inside '{0}' ==--", folder);
	folder += "\\";
	for (int i = 0; i < file->Length; i++) {
		System::String^ filename = file[i]->Replace(folder, "");
		configArray[i] = filename->Split('.')[0];
	}

	return configArray;
}

SIVConfig^ ProcWorker::readConfig(DevType t, System::String^ devName)
{
	System::String^ folder = System::IO::Directory::GetCurrentDirectory()->ToString();
	if (t==DevType::HeadTracker) {
		folder += "/Devices/Head";
	}
	else if (t == DevType::Spatial) {
		folder += "/Devices/Spatial Tracking";
	}
	else if (t == DevType::HandTracker) {
		folder += "/Devices/Hands";
	}
	else{
		folder += "/Devices/Misc Devices";
	}

	//array<System::String^>^ file = System::IO::Directory::GetFiles(folder);

	//System::Console::WriteLine("--== Files inside '{0}' ==--", folder);
	folder += "\\";

	System::String^ filename = folder + devName + ".sivc";
	//okay time to read the file
	
	System::IO::StreamReader^ reader = System::IO::File::OpenText(filename);

	SIVConfig^ newConfig = gcnew SIVConfig();

	//array<System::String^>^ cfgString = gcnew array<System::String^>(6);
	System::String^ cfgLine = "";

	for (int i = 0; i < 6; i++) {

		//read in the line of text
		//cfgString[i] = reader->ReadLine();
		//System::Console::WriteLine(cfgString[i]->ToString());
		//cfgString[i]->Split(' ');

		//read in the line of text 
		cfgLine = reader->ReadLine();

		//grab the data we want
		cfgLine = cfgLine->Split(' ')[1];

		switch (i) {
		case 0:
			//VRPN Device Name
			newConfig->VRPNname = cfgLine;
			break;
		case 1:
			//number of analog channels
			newConfig->channels = System::Int32::Parse(cfgLine);
			break;
		case 2:
			//what type of data the device returns
			newConfig->dataTypes = cfgLine;
			break;
		case 3:
			//number of buttons associated with it
			newConfig->buttons = System::Int32::Parse(cfgLine);
			break;
		case 4:
			//rotation channels (X,Y,Z,W) if quaternion
			if (newConfig->dataTypes->Equals("Rotation") || newConfig->dataTypes->Equals("Both"))
			{
				cfgLine = cfgLine->Replace("(", "");
				cfgLine = cfgLine->Replace(")", "");
				array<System::String^>^ parseMe = cfgLine->Split(',');

				newConfig->XRot = System::Int32::Parse(parseMe[0]);
				newConfig->YRot = System::Int32::Parse(parseMe[1]);
				newConfig->ZRot = System::Int32::Parse(parseMe[2]);
				newConfig->WRot = System::Int32::Parse(parseMe[3]);
			}
			break;
		case 5:
			//position channels (X,Y,Z,Scale)
			if (newConfig->dataTypes->Equals("Position") || newConfig->dataTypes->Equals("Both")) {
				cfgLine = cfgLine->Replace("(", "");
				cfgLine = cfgLine->Replace(")", "");
				array<System::String^>^ parseMe = cfgLine->Split(',');
				newConfig->XPos = System::Int32::Parse(parseMe[0]);
				newConfig->YPos = System::Int32::Parse(parseMe[1]);
				newConfig->ZPos = System::Int32::Parse(parseMe[2]);
				newConfig->Scale = System::Double::Parse(parseMe[3]);
			}
			break;

		}
	}
	
	reader->Close();

	return newConfig;
	


}

//startProc starts a .exe file, lpApp is the path of the .exe to start
void ProcWorker::startProc(LPCTSTR lpApp) {

	//additional information
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	//set size of structures
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	//start the program
	if(CreateProcess(lpApp,
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi))
	std::printf("Started\n");

	//Close the process handle
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

}

//end the speccified process
void ProcWorker::endProc(char *procName) {
	
	//Get process ID, assign desired access (TERMINATION) and then if
	//the process is currently open, kill that sucka
	DWORD id = checkProc(procName);
	DWORD dwDesiredAccess = PROCESS_TERMINATE;
	BOOL bInheritHandle = FALSE;
	HANDLE h = OpenProcess(dwDesiredAccess, bInheritHandle, id);
	if (h == NULL)
		std::printf("Server not open\n");
	else
	{
		BOOL result = TerminateProcess(h, 0);
		std::printf("Server terminated\n");
		CloseHandle(h);
	}
}

//checks to see if a process is running
DWORD ProcWorker::checkProc(char *procName) {

	//add \\ to end of process name
	char* p = strrchr(procName, '\\');
	if (p)
		procName = p + 1;
	
	PROCESSENTRY32 entry;
	entry.dwSize = sizeof(PROCESSENTRY32);

	//get a snapshot of the current running processes, then iterate through them and check
	//each one against the name that was provided. 'vrpn_server.exe' is an example
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	if (snap == INVALID_HANDLE_VALUE)
		return false;

	Process32First(snap, &entry);
	if (!strcmp(procName, entry.szExeFile)) {
		CloseHandle(snap);
		return entry.th32ProcessID;
	}

	while (Process32Next(snap, &entry))
	{
		if (!strcmp(procName, entry.szExeFile)) {
			CloseHandle(snap);
			return entry.th32ProcessID;
		}
	}
	
	CloseHandle(snap);
	return 0;
}
