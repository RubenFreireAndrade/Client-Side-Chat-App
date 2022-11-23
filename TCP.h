#pragma once
#include<string>
#include<iostream>
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
	bool GetMsgSentFlag();
	void ShutDown();

	IPaddress ip;
	TCPsocket listenSocket = nullptr;
	const int port = 1234;
	std::string clientInput;
private:
	bool isListening = true;
	bool hasSentMsg = false;
};