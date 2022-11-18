#include "App.h"

App::App()
{
	tcp = new TCP();
}

App::~App()
{
}

bool App::RunApp()
{
	bool isAppRunning = true;

	tcp->SDLInitialize();
	tcp->OpenSocket();
	while (isAppRunning)
	{
		if (tcp->listenSocket)
		{
			/*std::thread receiveMsgThread(&TCP::ReceiveMessage, tcp, tcp->listenSocket);
			receiveMsgThread.join();*/
			/*std::thread sendMsgThread(&TCP::SendMessage, tcp, tcp->listenSocket);
			sendMsgThread.join();*/
			tcp->ReceiveMessage(tcp->listenSocket);
			
			//tcp->SendMessage(tcp->listenSocket, clientInput);
		}
		else
		{
			return isAppRunning = false;
		}
	}
}

void App::ShutDown()
{
	tcp->ShutDown();
}
