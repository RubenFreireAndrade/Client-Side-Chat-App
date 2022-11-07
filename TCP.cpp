#include "TCP.h"

TCP::TCP()
{
}

TCP::~TCP()
{
}

bool TCP::SDLInitialize()
{
	std::cout << "This is Client" << std::endl;
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
}

bool TCP::EstablishConnection()
{
	if (SDLNet_ResolveHost(&ip, /*"127.0.0.1"*/"localhost", port) == -1)
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

	char message[100];
	if (SDLNet_TCP_Recv(socket, message, 100) <= 0)
	{
		std::cout << "Could not receive message" << std::endl;
	}
	else
	{
		std::cout << "Message received: " << message << std::endl;
	}
}
