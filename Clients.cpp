#include "Clients.h"
#include <string>
#include <thread>
#include <chrono>

void ClientA::start()
{
	Subscribe(Event::EventB);
	std::cout << "Client " + m_name + " started!" << std::endl;
}

void ClientA::execute()
{
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(2000));
	SendEvent(Event::EventA);
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(1000));
	SendEvent(Event::EventA);
}

void ClientB::start()
{
	Subscribe(Event::EventA);
	std::cout << "Client " + m_name + " started!" << std::endl;
}

void ClientB::execute()
{
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(2000));
	SendEvent(Event::EventB);
}

void ClientA::onEvent(Event event)
{
	switch (event)
	{
	case Event::EventA:
		std::cout << "Client " + m_name + " received EventA!" << std::endl;
		break;
	case Event::EventB:
		std::cout << "Client " + m_name + " received EventB!" << std::endl;
		break;
	default:;
	}
}

void ClientB::onEvent(Event event)
{
	switch (event)
	{
	case Event::EventA:
		std::cout << "Client " + m_name + " received EventA!" << std::endl;
		break;
	case Event::EventB:
		std::cout << "Client " + m_name + " received EventB!" << std::endl;
		break;
	default:;
	}
}