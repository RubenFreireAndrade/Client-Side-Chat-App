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
	TCPsocket GetListenSocket();
	void SetConsoleTextColor(WORD c);
	void ShutDown();

private:
	IPaddress ip{};
	const int port = 1234;
	bool isListening = true;
	bool hasMsgRecv = false;
	std::string clientInput;
	TCPsocket listenSocket = nullptr;

	Uint32 GetIp(TCPsocket sock);
};