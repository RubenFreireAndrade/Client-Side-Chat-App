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
		/*TCPsocket tempSock = nullptr;
		tempSock = SDLNet_TCP_Accept(listenSocket);*/
		if (!listenSocket)
		{
			std::cout << "Trying to connect. . ." << std::endl;
			SDL_Delay(1000);
		}
		else
		{
			/*serverIp = SDLNet_TCP_GetPeerAddress(listenSocket);
			hostSocket = listenSocket;*/
			SetConsoleTextColor(2);
			std::cout << "Connected to Server: " << /*SDLNet_Read32(&serverIp->host) <<*/ std::endl;
			SetConsoleTextColor(7);
			SDL_Delay(500);
			return true;
		}
	}
}

bool TCP::SendMessage(TCPsocket sock)
{
	std::cout << "Type Your Message: " << std::endl;
	SetConsoleTextColor(3);
	std::getline(std::cin, clientInput);
	SetConsoleTextColor(7);

	int length = clientInput.length() + 1;
	if (SDLNet_TCP_Send(sock, clientInput.c_str(), length))
	{
		SetConsoleTextColor(6);
		std::cout << "Message sent successfully!" << std::endl;
		SetConsoleTextColor(7);
		return true;
	}
	std::cout << "Could not send message" << std::endl;
	return false;
}

bool TCP::ReceiveMessage(TCPsocket sock)
{
	char message[100];
	while (SDLNet_TCP_Recv(sock, message, 100))
	{
		SetConsoleTextColor(3);
		std::cout << "Message Received: " << message << std::endl;
		SetConsoleTextColor(7);
		hasMsgRecv = true;
		return true;
	}
	std::cout << "Could not receive message" << std::endl;
	return false;
}

bool TCP::GetMsgRecvFlag()
{
	return hasMsgRecv;
}

void TCP::SetConsoleTextColor(WORD c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void TCP::ShutDown()
{
	SDLNet_Quit();
	SDL_Quit();
}
