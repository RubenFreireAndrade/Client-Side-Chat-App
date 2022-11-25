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
			SDL_Delay(1000);
		}
		else
		{
			return true;
		}
	}
}

bool TCP::SendMessage(TCPsocket sock)
{
	SDL_Delay(100);
	std::cout << "Type Your Message: " << std::endl;
	this->SetConsoleTextColor(3);
	std::getline(std::cin, clientInput);
	this->SetConsoleTextColor(7);
	SDL_Delay(100);

	if (SDLNet_TCP_Send(sock, clientInput.c_str(), clientInput.length() + 1))
	{
		SDL_Delay(100);
		this->SetConsoleTextColor(6);
		std::cout << "Message sent successfully!" << std::endl;
		this->SetConsoleTextColor(7);
		SDL_Delay(100);
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
		SDL_Delay(100);
		std::cout << "/ / / / / / / / / / / 'Funny Looking Chat Box' / / / / / / / / / / /" << std::endl;
		this->SetConsoleTextColor(3);
		std::cout << this->GetIp(sock) << " Sent: " << message << "			|" << std::endl;
		this->SetConsoleTextColor(7);
		hasMsgRecv = true;
		std::cout << "/ / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / / /" << std::endl;
		SDL_Delay(100);
	}
	std::cout << "Could not receive message" << std::endl;
	return false;
}

bool TCP::GetMsgRecvFlag()
{
	return hasMsgRecv;
}

TCPsocket TCP::GetListenSocket()
{
	return listenSocket;
}

void TCP::SetConsoleTextColor(WORD c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

Uint32 TCP::GetIp(TCPsocket sock)
{
	IPaddress* clientIp = SDLNet_TCP_GetPeerAddress(sock);
	return SDLNet_Read32(&clientIp->host);
}

void TCP::ShutDown()
{
	SDLNet_Quit();
	SDL_Quit();
}

