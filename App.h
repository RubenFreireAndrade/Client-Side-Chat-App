#pragma once
#include<string>
#include<SDL.h>
#include<thread>
#include<iostream>
#include<SDL_net.h>

#include"TCP.h"

class App
{
public:
	App();
	~App();
	bool RunApp();
	void ShutDown();

private:
	TCP* tcp;
	std::string clientInput;
};

