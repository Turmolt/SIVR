#include "SIVRServer.h"

using namespace std;
using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

/*
Input:
	Port = Port number
	
	head, hands, spatial, misc 
*/
SIVRServer::SIVRServer(int port, String^ head, String^ hands, String^ spatial, String^ misc)
{
	this->port = port;
	this->activePurposes = 0;
	this->activePos = 0;
	this->activeRot = 0;
	
	//values of purposes can be n for none, r for rot, p for pos, b for both
	if (!head->Equals("n")) {
		this->headData.tracking = true;

		if (head->Equals("p") || head->Equals("b")) {
			this->activePos++;
			this->headData.pos = true;
		}
		if (head->Equals("r") || head->Equals("b")) {
			this->activeRot++;
			this->headData.rot = true;
		}

		this->activePurposes++;
	}
	if (!hands->Equals("n")) {
		this->handData.tracking = true;

		if (hands->Equals("p") || hands->Equals("b")) {
			this->activePos++;
			this->handData.pos = true;
		}
		if (hands->Equals("r") || hands->Equals("b")) {
			this->activeRot++;
			this->handData.rot = true;
		}

		this->activePurposes++;
	}
	if (!spatial->Equals("n")) {
		this->spatialData.tracking = true;

		if (spatial->Equals("p") || spatial->Equals("b")) {
			this->activePos++;
			this->spatialData.pos = true;
		}
		if (spatial->Equals("r") || spatial->Equals("b")) {
			this->activeRot++;
			this->spatialData.rot = true;
		}

		this->activePurposes++;
	}
	if (!misc->Equals("n")) {

		this->miscData.tracking = true;

		if (misc->Equals("p") || misc->Equals("b")) {
			this->activePos++;
			this->miscData.pos = true;
		}
		if (misc->Equals("r") || misc->Equals("b")) {
			this->activeRot++;
			this->miscData.rot = true;
		}

		this->activePurposes++;
	}
	
	/*TcpListener^ listener = gcnew TcpListener(IPAddress::Loopback, this->port);

	listener->Start();

*/
}

SIVRServer::~SIVRServer() {

}

char* SIVRServer::MakeMsg()
{
	int posIndex = 0;
	int rotIndex = 0;

	int psize = (sizeof(float)) * 3;
	int rsize = (sizeof(float)) * 4;
	int hsize = 3 + 4;

	int size = (rsize*this->activeRot) + (psize* this->activePos);
	//System::Console::WriteLine(size);
	char* newbuffer = new char[size];




	if (this->headData.tracking) {
		if (this->headData.pos) {
			memcpy(newbuffer+(posIndex*psize) + (rotIndex*rsize), (this->headData.positionArray), (int)sizeof(float)*3);
			posIndex++;
		}
		if (this->headData.rot) {
			memcpy(newbuffer + (rotIndex*rsize) + (posIndex * psize), (this->headData.rotationArray), (int)sizeof(float) * 4);
			rotIndex++;
		}
	}
	if (this->handData.tracking) {
		if (this->handData.pos) {
			memcpy(newbuffer + (posIndex*psize)+(rotIndex*rsize), (this->handData.positionArray), (int)sizeof(float) * 3);
			posIndex++;
		}
		if (this->handData.rot) {
			memcpy(newbuffer + (rotIndex*rsize) + (posIndex * psize), (this->handData.rotationArray), (int)sizeof(float) * 4);
			rotIndex++;
		}
	}
	if (this->spatialData.tracking) {
		if (this->spatialData.pos) {
			memcpy(newbuffer + (posIndex*psize) + (rotIndex*rsize), (this->spatialData.positionArray), (int)sizeof(float) * 3);
			posIndex++;
		}
		if (this->spatialData.rot) {
			memcpy(newbuffer + (rotIndex*rsize) + (posIndex * psize), (this->spatialData.rotationArray), (int)sizeof(float) * 4);
			rotIndex++;
		}
	}
	if (this->miscData.tracking) {
		if (this->miscData.pos) {
			memcpy(newbuffer + (posIndex*psize) + (rotIndex*rsize), (this->miscData.positionArray), (int)sizeof(float) * 3);
			posIndex++;
		}
		if (this->miscData.rot) {
			memcpy(newbuffer + (rotIndex*rsize)+(posIndex*psize), (this->miscData.rotationArray), (int)sizeof(float) * 4);
			rotIndex++;
		}
	}

	
	return newbuffer;
}

int  SIVRServer::startListening() {
	//Init program to call winsock2.dll
	//WORD wVersionRequested;
	//WSADATA wsaData;
	//int wsaerr;

	//wVersionRequested = MAKEWORD(2, 2);
	//wsaerr = WSAStartup(wVersionRequested, &wsaData);

	//if (wsaerr != 0) {
	//	printf("Server: Winsock DLL not found!\n");
	//	WSACleanup();
	//	return 0;
	//}
	//else {
	//	printf("Server: Winsock DLL found\n");
	//}

	//this->sSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//if (this->sSock = INVALID_SOCKET) {
	//	printf("Server: Error initializing the socket\n");
	//	WSACleanup();
	//	return 0;
	//}


	////SOCKADDR_IN is used by sockets to specify an endpoint address
	////to which the socket connects
	//sockaddr_in service;
	//service.sin_family = AF_INET;
	//service.sin_port = htons(port);
	//service.sin_addr.s_addr = inet_addr("127.0.0.1");

	////bind links the socket with sockaddr_in we just made
	//if (bind(this->sSock, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
	//	printf("Server: Error binding socket to port\n");
	//	WSACleanup();
	//	return 0;
	//}

	////wait for the incoming connections!
	//if (listen(this->sSock, 10) == SOCKET_ERROR)
	//	printf("Error listening on socket %d\n", WSAGetLastError());
	//else
	//{
	//	printf("waiting for incoming connection...\n");
	//}

	//printf("Server waiting for client...\n");
	//acceptConns();
	return 0;
}


//the code that is executed when a client is accepted
int SIVRServer::acceptConns() {


	//sockaddr_in from;
	//int fromlen = sizeof(from);

	//
	////infinite loop to send data from this to client
	//while (true) {

	//	
	//	cSock = accept(this->sSock, (SOCKADDR*)&from, &fromlen);

	//	MakeMsg();

	//	char* sendBuffer;

	//	int iResult;

	//	char* temp = MakeMsg();
	//	printf(temp);
	//	iResult = send(cSock, temp, (int)sizeof(temp), 0);

	//	if (iResult == SOCKET_ERROR) {
	//		printf("send failed %d\n", WSAGetLastError());
	//		closesocket(cSock);
	//		WSACleanup();
	//		return -1;
	//	}

	//	printf("Bytes Sent: %ld\n", iResult);
	//	
	//}

	//closesocket(this->sSock);
	//WSACleanup();
	return 0;
}

//This is the loop that the server runs
//TODO: Launch listener, spit out data to listener when the time is right
void SIVRServer::ServerLoop() {
	

	while (this->running) {
		TcpListener^ listener = gcnew TcpListener(IPAddress::Loopback, this->port);

		Console::Write("Waiting for client...");
		listener->Start();

		TcpClient^ client = listener->AcceptTcpClient();
		Console::WriteLine(" Client connected!");
		NetworkStream^ stream = client->GetStream();
		StreamWriter^ writer = gcnew StreamWriter(stream, Encoding::ASCII);
		try{
			while (this->running) {

				/*Sleep(5.0);
				char* st = MakeMsg();
				Sleep(5.0);

				float headRotation[4];
				float headPosition[3];

				float handRotation[4];
				float handPosition[3];

				float spatialRotation[4];
				float spatialPosition[3];

				float miscRotation[4];
				float miscPosition[3];

				int psize = (sizeof(float)) * 3;
				int rsize = (sizeof(float)) * 4;

				int ps = 0;
				int rs = 0;

				String^ strng = "";

				if (this->headData.tracking) {
					if (this->headData.pos) {
						memcpy(headPosition, st + (ps++*psize) + (rsize*rs), psize);
						for (int i = 0; i < 3; i++)
							strng += headPosition[i].ToString() + "  ";
					}
					if (this->headData.rot){
						memcpy(headRotation, st + (ps*psize) + (rsize*rs++), rsize);
						for (int i = 0; i < 4; i++)
							strng += headRotation[i].ToString() + "  ";
					}
				}
				if (this->handData.tracking) {
					if (this->handData.pos){
						memcpy(handPosition, st + (ps++*psize) + (rsize*rs), psize);
						for (int i = 0; i < 3; i++)
							strng += handPosition[i].ToString() + "  ";
					}
					if (this->handData.rot) {
						memcpy(handRotation, st + (ps*psize) + (rsize*rs++), rsize);
						for (int i = 0; i < 4; i++)
							strng += handRotation[i].ToString() + "  ";
					}
				}
				if (this->spatialData.tracking) {
					if (this->spatialData.pos){
						memcpy(spatialPosition, st + (ps++*psize) + (rsize*rs), psize);
						for (int i = 0; i < 3; i++)
							strng += spatialPosition[i].ToString() + "  ";
					}
					if (this->spatialData.rot) {
						memcpy(spatialRotation, st + (ps*psize) + (rsize*rs++), rsize);
						for (int i = 0; i < 4; i++)
							strng += spatialRotation[i].ToString() + "  ";
					}
				}
				if (this->miscData.tracking) {
					if (this->miscData.pos) {
						memcpy(miscPosition, st + (ps++*psize) + (rsize*rs), psize);
						for (int i = 0; i < 3; i++)
							strng += miscPosition[i].ToString() + "  ";
					}
					if (this->miscData.rot) {
						memcpy(miscRotation, st + (ps*psize) + (rsize*rs++), rsize);
						for (int i = 0; i < 4; i++)
							strng += miscRotation[i].ToString() + "  ";
					}
				}



				*/
				String^ strng = "";

				if (this->headData.tracking) {
					if (this->headData.pos)
						for (int i = 0; i < 3; i++)
							strng += this->headData.positionArray[i] + " ";

					if (this->headData.rot)
						for (int i = 0; i < 4; i++)
							strng += this->headData.rotationArray[i] + " ";

					strng += "#";
				}
				if (this->handData.tracking) {
					if (this->handData.pos)
						for (int i = 0; i < 3; i++)
							strng += this->handData.positionArray[i] + " ";

					if (this->handData.rot)
						for (int i = 0; i < 4; i++)
							strng += this->handData.rotationArray[i] + " ";

					strng += "#";
				}
				if (this->spatialData.tracking) {
					if (this->spatialData.pos)
						for (int i = 0; i < 3; i++)
							strng += this->spatialData.positionArray[i] + " ";
					
					if (this->spatialData.rot)
						for (int i = 0; i < 4; i++)
							strng += this->spatialData.rotationArray[i] + " ";

					strng += "#";
					
				}
				if (this->miscData.tracking) {
					if (this->miscData.pos)
						for (int i = 0; i < 3; i++)
							strng += this->miscData.positionArray[i] + " ";

					if (this->miscData.rot)
						for (int i = 0; i < 4; i++)
							strng += this->miscData.rotationArray[i] + " ";

					strng += "#";
				}
				//strng += "\0";
				Sleep(5);
				writer->WriteLine(strng);
				writer->Flush();
			}
		}
		catch (Exception^ e) {
			Console::WriteLine("Client Quit.");
			listener->Stop();
			
		}
	}
}

void SIVRServer::SetData(DevType)
{

}

//Spawn thread to run the server toop
void SIVRServer::StartServer()
{
	//System::Console::WriteLine("Server!");

	this->serverThread = gcnew Thread(gcnew ThreadStart(this, &SIVRServer::ServerLoop));
	this->serverThread->Start();
	this->running = true;
	while (!this->serverThread->IsAlive);

	Sleep(100);
	
	/*
	while (1) {
		Sleep(1000.0);
		char* st = MakeMsg();
		Sleep(1000.0);
		float pos1[3];
		float rotation[4];
		float position[3];

		int psize = (sizeof(float)) * 3;
		int rsize = (sizeof(float)) * 4;

		memcpy(position, st, psize);
		memcpy(rotation, st + psize, rsize);
		String^ strng = "";
		for (int i = 0; i < 3; i++)
			strng += position[i].ToString() + " p ";
		for (int i = 0; i < 4; i++)
			strng += rotation[i].ToString() + " r ";

		Console::WriteLine(strng);
	}*/
}



