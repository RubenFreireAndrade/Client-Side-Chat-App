#include<SDL.h>
#include<string>
#include<iostream>
#include<SDL_net.h>

#include"Chat.h"

int main(int argc, char* argv[])
{
	Chat chat;
	chat.DisplayChatBox();

	SDLNet_Quit();
	SDL_Quit();
	return 0;
}