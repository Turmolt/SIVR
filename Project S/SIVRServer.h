
#include "Glob.h"
#include <array>
#include "VRPNClient.h"



//#include <stdio.h>
//
//#include <conio.h>
//#include <iostream>
//
//#include <string>
//#include <WinSock2.h>


ref struct PurposeData {
	bool tracking = false;
	bool rot = false;
	bool pos = false;
	float* positionArray = new float[3];
	float* rotationArray = new float[4];


};

ref class SIVRServer
{
public:
	SIVRServer(int port, System::String^ head, System::String^ hands, System::String^ spatial, System::String^ misc);

	virtual ~SIVRServer();

	//float message[28];

	char* MakeMsg();
	
	int startListening();

	void SetData(DevType);
	void StartServer();

	System::Threading::Thread^ serverThread;

	bool running;

	//float* MarshalData(cli::array < cli::interior_ptr<float>>^);

	bool headTracking;
	bool handTracking;
	bool spatialTracking;
	bool miscTracking;

	int activePurposes;

	int activeRot;
	int activePos;

	int* buttonNum;
	int buttonVal;

	PurposeData headData;
	PurposeData handData;
	PurposeData spatialData;
	PurposeData miscData;

	



protected:
	int port;
//	SOCKET sSock;
//	SOCKET cSock;

private:
	int acceptConns();

	void ServerLoop();

};

