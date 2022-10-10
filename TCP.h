#pragma once
#include<iostream>
#include<SDL.h>
#include<SDL_net.h>

class TCP
{
public:
	TCP();
	~TCP();
	int EstablishConnection();

	IPaddress ip;
	TCPsocket socket = nullptr;
	const int port = 1234;
private:
	//std::string ipAddress = "127.0.0.1";
};