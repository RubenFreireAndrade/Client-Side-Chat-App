#include<SDL.h>
#include<string>
#include<iostream>
#include<SDL_net.h>

//#include"TCP.h"
#include"Chat.h"

int main(int argc, char* argv[])
{
	Chat chat;
	/*TCP tcp;
	tcp.EstablishConnection();*/
	
	chat.DisplayChatBox();

	//SDLNet_TCP_Close(tcp.socket);
	SDLNet_Quit();
	SDL_Quit();
	return 0;
}