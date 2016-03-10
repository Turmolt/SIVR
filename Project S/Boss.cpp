#include "Boss.h"

#include "MainWindow.h"

using namespace System::Windows::Forms;
using namespace ProjectS;

Boss::Boss()
{

	
}


[STAThread]
int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainWindow());
	
	return 0;
}