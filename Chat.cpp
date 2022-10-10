#include "Chat.h"

Chat::Chat()
{
}

Chat::~Chat()
{
}

int Chat::DisplayChatBox()
{
	tcp.EstablishConnection();
	if (!tcp.socket)
	{
		return 0;
	}
	else
	{
		std::cout << "|||||||||||||||||||||||||||||||||||" << std::endl;
		std::cout << "Type Your Message: ";
		std::cin >> clientInput;
	}
}
