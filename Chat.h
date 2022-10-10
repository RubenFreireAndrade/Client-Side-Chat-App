#pragma once
#include<SDL.h>
#include<string>
#include<iostream>
#include<SDL_net.h>

#include"TCP.h"

class Chat
{
public:
	Chat();
	~Chat();
	int DisplayChatBox();

private:
	std::string clientInput;
	TCP tcp;
};

