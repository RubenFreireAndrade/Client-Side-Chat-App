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
		return false;
	}
	else if (SDLNet_Init() == -1)
	{
		std::cout << "SDL_net is not initialize properly" << std::endl;
		return false;
	}
	return true;
}

bool TCP::OpenSocket()
{
	if (SDLNet_ResolveHost(&ip, "localhost", port) == -1) // Change localhost to user input. So user has to input an address.
	{
		std::cout << "Could not connect to server" << std::endl;
		return false;
	}

	listenSocket = SDLNet_TCP_Open(&ip);
	if (!listenSocket)
	{
		std::cout << "Could not find socket" << std::endl;
		return false;
	}
	return true;
}

bool TCP::ListenSocket()
{
	while (isListening)
	{
		if (!listenSocket)
		{
			std::cout << "Trying to connect. . ." << std::endl;
			// Need to keep Socket Open when there is no server to connect.
			//OpenSocket();
			SDL_Delay(1000);
		}
		else
		{
			std::cout << "Connected to Server" << std::endl;
			return true;
		}
	}
}

bool TCP::SendMessage(TCPsocket sock)
{
	std::cout << "Type Your Message: " << std::endl;
	std::getline(std::cin, clientInput);

	int length = clientInput.length() + 1;
	if (SDLNet_TCP_Send(sock, clientInput.c_str(), length))
	{
		std::cout << "Message sent successfully!" << std::endl;
		return true;
	}
	std::cout << "Could not send message" << std::endl;
	return false;
}

bool TCP::ReceiveMessage(TCPsocket sock)
{
	char message[100];
	if (SDLNet_TCP_Recv(sock, message, 100))
	{
		std::cout << "Message Received: " << message << std::endl;
		return true;
	}
	std::cout << "Could not receive message" << std::endl;
	return false;
}

void TCP::ShutDown()
{
	SDLNet_Quit();
	SDL_Quit();
}
