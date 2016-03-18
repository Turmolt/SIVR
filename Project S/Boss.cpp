#include "Boss.h"

#include "MainWindow.h"


using namespace System::Windows::Forms;
using namespace System;
using namespace System::Runtime::InteropServices;
#define ARRAY_SIZE 15


Boss::Boss()
{
	curMax = 0;
	clientArray = gcnew cli::array<VRPNClient^>(ARRAY_SIZE);
}

VRPNClient ^ Boss::newClient(DevType t, String^ devName)
{
	if (t == DevType::Gamepad) {
		this->clientArray[curMax] = gcnew VRPNClient(t,devName);
	}
	return this->clientArray[curMax++];
}

VRPNClient ^ Boss::getClient(int n)
{
	return this->clientArray[n];
}


[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew ProjectS::MainWindow());
	
	return 0;
}