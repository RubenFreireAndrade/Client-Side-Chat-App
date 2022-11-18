#include<SDL.h>
#include<string>
#include<iostream>
#include<SDL_net.h>

#include"App.h"

int main(int argc, char* argv[])
{
	App app;
	bool isAppRunning = true;
	while (isAppRunning)
	{
		if (!app.RunApp())
		{
			app.ShutDown();
			return isAppRunning = false;
		}
	}
	return 0;
}