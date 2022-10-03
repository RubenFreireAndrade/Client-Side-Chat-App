#include<iostream>
#include<string>
#include<SDL.h>
#include<SDL_net.h>

int main(int argc, char* argv[])
{
	IPaddress ip;
	TCPsocket socket = nullptr;
	//std::string ipAddress = "127.0.0.1";
	const int port = 1234;
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "SDL2 is not initialize properly" << std::endl;
		return 0;
	}
	else if (SDLNet_Init() == -1)
	{
		std::cout << "SDL_net is not initialize properly" << std::endl;
		return 0;
	}

	///////////////////////////////////////////////////////////////
	if (SDLNet_ResolveHost(&ip, "127.0.0.1", port) == -1)
	{
		std::cout << "Could not connect to server" << std::endl;
		return 0;
	}
	
	socket = SDLNet_TCP_Open(&ip);
	if (!socket)
	{
		std::cout << "Could not open socket" << std::endl;
		return 0;
	}


	std::cout << "This is Client" << std::endl;
	system("pause");
	
	SDLNet_Quit();
	SDL_Quit();
	return 0;
}