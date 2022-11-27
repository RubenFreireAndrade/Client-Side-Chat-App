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
	while (isListening)
	{
		int serverId = tcp->ListenSocket();
		std::thread receiveMsgThr(&TCP::ReceiveMessage, tcp, serverId);
		receiveMsgThr.detach();
	}
	return true;
}

void App::ShutDown()
{
	tcp->ShutDown();
}
