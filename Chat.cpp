#include "Chat.h"

Chat::Chat()
{
}

Chat::~Chat()
{
}

int Chat::DisplayChatBox()
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
		//std::cin >> clientInput;
		std::getline(std::cin, clientInput);
		SendMessage();
	}
}

void Chat::SendMessage()
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
