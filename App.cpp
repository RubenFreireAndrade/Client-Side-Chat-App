#include "App.h"

App::App()
{
	tcp = new TCP();
}

App::~App()
{
}

bool App::InitApp()
{
	if (!tcp->SDLInitialize())
	{
		return false;
	}

	if (!tcp->OpenSocket())
	{
		return false;
	}
	return true;
}

bool App::RunApp()
{
	while (tcp->ListenSocket())
	{
		std::thread receiveMsgThr(&TCP::ReceiveMessage, tcp, tcp->listenSocket);
		receiveMsgThr.detach();
		if (tcp->GetMsgSentFlag())
		{
			std::thread sendMsgThr(&TCP::SendMessage, tcp, tcp->listenSocket);
			sendMsgThr.join();
		}
	}
	return true;
}

void App::ShutDown()
{
	tcp->ShutDown();
}
