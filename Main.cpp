#include<SDL.h>
#include<string>
#include<iostream>
#include<SDL_net.h>

#include"App.h"

int main(int argc, char* argv[])
{
	App App;
	bool isAppRunning = true;
	while (isAppRunning)
	{
		App.DisplayChatBox();
	}

	SDLNet_Quit();
	SDL_Quit();
	return 0;
}