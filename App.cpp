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
		std::thread receiveMsgThr(&TCP::ReceiveMessage, tcp, tcp->GetListenSocket());
		receiveMsgThr.detach();
		if (tcp->GetMsgRecvFlag())
		{
			std::thread sendMsgThr(&TCP::SendMessage, tcp, tcp->GetListenSocket());
			sendMsgThr.join();
		}
	}
	return true;
}

void App::ShutDown()
{
	tcp->ShutDown();
}
