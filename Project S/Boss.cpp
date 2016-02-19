#include "Boss.h"


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