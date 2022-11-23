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
		receiveMsgThr = std::thread(&TCP::ReceiveMessage, tcp, tcp->listenSocket);
		sendMsgThr = std::thread(&TCP::SendMessage, tcp, tcp->listenSocket);

		receiveMsgThr.detach();
		sendMsgThr.join();
	}
	return false;
}

void App::ShutDown()
{
	tcp->ShutDown();
}
