#pragma once
#include<SDL.h>
#include<string>
#include<iostream>
#include<SDL_net.h>

#include"TCP.h"

class App
{
public:
	App();
	~App();
	int DisplayChatBox();
	void SendMessage();

private:
	std::string clientInput;
	TCP tcp;
};

