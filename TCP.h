#pragma once
#include<string>
#include<vector>
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
	int ListenSocket();
	bool SendMessage(int clientId);
	bool ReceiveMessage(int sock);
	void SetConsoleTextColor(WORD c);
	TCPsocket GetListenSocket();
	void ShutDown();

private:
	IPaddress ip{};
	const int port = 1234;
	bool isListening = true;
	bool hasMsgRecv = false;
	std::string clientInput;

	std::vector<TCPsocket> clients;
	TCPsocket listenSocket = nullptr;

	Uint32 GetIp(TCPsocket sock);
};