#pragma once
#include<string>
#include<iostream>
#include<Windows.h>
#include<SDL.h>
#include<SDL_net.h>

class TCP
{
public:
	TCP();
	~TCP();
	bool SDLInitialize();
	bool OpenSocket();
	bool ListenSocket();
	bool SendMessage(TCPsocket sock);
	bool ReceiveMessage(TCPsocket sock);
	bool GetMsgRecvFlag();
	void SetConsoleTextColor(WORD c);
	void ShutDown();

	IPaddress ip;
	IPaddress* serverIp;
	TCPsocket listenSocket = nullptr;
	TCPsocket hostSocket = nullptr;
	const int port = 1234;
	std::string clientInput;
	std::string name = "Ruben";
private:
	bool isListening = true;
	bool hasMsgRecv = false;
};