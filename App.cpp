#include "App.h"

App::App()
{
}

App::~App()
{
}

int App::DisplayChatBox()
{
	tcp.SDLInitialize();
	tcp.EstablishConnection();
	if (!tcp.socket)
	{
		return 0;
	}
	else
	{
		std::cout << "|||||||||||||||||||||||||||||||||||" << std::endl;
		std::cout << "Type Your Message: ";
		std::getline(std::cin, clientInput);
		SendMessage();
	}
}

void App::SendMessage()
{
	int length = clientInput.length() + 1;
	if (SDLNet_TCP_Send(tcp.socket, clientInput.c_str(), length) < length)
	{
		std::cout << "Could not send message" << std::endl;
	}
	else
	{
		std::cout << "Message sent successfully! " << std::endl;
	}
}
