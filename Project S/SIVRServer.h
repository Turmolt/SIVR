
#include "Glob.h"
#include <array>

struct PurposeData {
	bool tracking = false;
	bool rot = false;
	bool pos = false;
	float* positionArray = new float[3];
	float* rotationArray = new float[4];
};

class SIVRServer
{
public:
	SIVRServer(int port, bool head, bool hands, bool spatial, bool misc);

	virtual ~SIVRServer();

	float message[28];

	char* MakeMsg();
	
	int startListening();

	void SetData(DevType);
	void StartServer();

	bool headTracking;
	bool handTracking;
	bool spatialTracking;
	bool miscTracking;

	int activePurposes = 0;

	int* buttonNum;
	int buttonVal;

	PurposeData headData;
	PurposeData handData;
	PurposeData spatialData;
	PurposeData miscData;
	int port;

	SOCKET sSock;
	SOCKET cSock;

private:
	int acceptConns();

};

