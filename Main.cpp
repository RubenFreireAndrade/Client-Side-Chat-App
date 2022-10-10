#include<SDL.h>
#include<string>
#include<iostream>
#include<SDL_net.h>

#include"TCP.h"

int main(int argc, char* argv[])
{
	TCP tcp;
	tcp.EstablishConnection();
	system("pause");
	
	SDLNet_TCP_Close(tcp.socket);
	SDLNet_Quit();
	SDL_Quit();
	return 0;
}