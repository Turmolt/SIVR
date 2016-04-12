#include "SIVRServer.h"


#include <stdio.h>

#include <conio.h>
#include <iostream>

#include <string>
#include <WinSock2.h>

using namespace std;
SIVRServer::SIVRServer(int port, bool head, bool hands, bool spatial, bool misc)
{
	this->port = port;
	
	if (head) {
		this->headData.tracking = true;
		this->activePurposes++;
	}
	if (hands) {
		this->handData.tracking = true;
		this->activePurposes++;
	}
	if (head) {
		this->spatialData.tracking = true;
		this->activePurposes++;
	}
	if (head) {
		this->miscData.tracking = true;
		this->activePurposes++;
	}

	

}

SIVRServer::~SIVRServer() {

}

char* SIVRServer::MakeMsg()
{
	
	int size = (((int)sizeof(float)*4)+ ((int)sizeof(float) * 3)) * activePurposes;
	char* newbuffer = new char[size];

	if (this->headTracking) {
		if (this->headData.pos) {
			memcpy(newbuffer, this->headData.positionArray, (int)sizeof(float)*3);
		}
		if (this->headData.rot) {
			for (int i = 0; i < 4; i++)
				memcpy(newbuffer, this->headData.rotationArray, (int)sizeof(float) * 4);
		}
	}
	else if (this->handTracking) {
		if (this->handData.pos) {
			for (int i = 0; i < 3; i++)
				memcpy(newbuffer, this->handData.positionArray, (int)sizeof(float) * 3);
		}
		if (this->handData.rot) {
			for (int i = 0; i < 4; i++)
				memcpy(newbuffer, this->handData.rotationArray, (int)sizeof(float) * 4);
		}
	}
	else if (this->spatialTracking) {
		if (this->spatialData.pos) {
			for (int i = 0; i < 3; i++)
				memcpy(newbuffer, this->spatialData.positionArray, (int)sizeof(float) * 3);
		}
		if (this->spatialData.rot) {
			for (int i = 0; i < 4; i++)
				memcpy(newbuffer, this->spatialData.rotationArray, (int)sizeof(float) * 4);
		}
	}
	else if (this->miscTracking) {
		if (this->miscData.pos) {
			for (int i = 0; i < 3; i++)
				memcpy(newbuffer, this->miscData.positionArray, (int)sizeof(float) * 3);
		}
		if (this->miscData.rot) {
			for (int i = 0; i < 4; i++)
				memcpy(newbuffer, this->miscData.rotationArray, (int)sizeof(float) * 4);
		}
	}

	
	return newbuffer;
}

int  SIVRServer::startListening() {
	//Init program to call winsock2.dll
	WORD wVersionRequested;
	WSADATA wsaData;
	int wsaerr;

	wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);

	if (wsaerr != 0) {
		printf("Server: Winsock DLL not found!\n");
		WSACleanup();
		return 0;
	}
	else {
		printf("Server: Winsock DLL found\n");
	}

	this->sSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (this->sSock = INVALID_SOCKET) {
		printf("Server: Error initializing the socket\n");
		WSACleanup();
		return 0;
	}


	//SOCKADDR_IN is used by sockets to specify an endpoint address
	//to which the socket connects
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_port = htons(port);
	service.sin_addr.s_addr = inet_addr("127.0.0.1");

	//bind links the socket with sockaddr_in we just made
	if (bind(this->sSock, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) {
		printf("Server: Error binding socket to port\n");
		WSACleanup();
		return 0;
	}

	//wait for the incoming connections!
	if (listen(this->sSock, 10) == SOCKET_ERROR)
		printf("Error listening on socket %d\n", WSAGetLastError());
	else
	{
		printf("waiting for incoming connection...\n");
	}

	printf("Server waiting for client...\n");
	acceptConns();
	return 0;
}


//the code that is executed when a client is accepted
int SIVRServer::acceptConns() {
	sockaddr_in from;
	int fromlen = sizeof(from);

	
	//infinite loop to send data from this to client
	while (true) {

		
		cSock = accept(this->sSock, (SOCKADDR*)&from, &fromlen);

		MakeMsg();

		char* sendBuffer;

		int iResult;

		char* temp = MakeMsg();
		printf(temp);
		iResult = send(cSock, temp, (int)sizeof(temp), 0);

		if (iResult == SOCKET_ERROR) {
			printf("send failed %d\n", WSAGetLastError());
			closesocket(cSock);
			WSACleanup();
			return -1;
		}

		printf("Bytes Sent: %ld\n", iResult);
		
	}

	closesocket(this->sSock);
	WSACleanup();
	return 0;
}

void SIVRServer::SetData(DevType)
{

}

void SIVRServer::StartServer()
{

}



