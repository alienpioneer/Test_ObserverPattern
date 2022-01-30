#pragma once
#include "Clients.h"
#include <thread>
#include <chrono>

void ClientBase::onEvent(Event event)
{
	switch (event)
	{
		case Event::EventA:
			std::cout << "Client " + m_name + " received event A" << std::endl;
			break;
		case Event::EventB:
			std::cout << "Client " + m_name + " received event B" << std::endl;
			break;
		case Event::EventC:
			std::cout << "Client " + m_name + " received event C" << std::endl;
			break;
		case Event::EventD:
			std::cout << "Client " + m_name + " received event D" << std::endl;
			break;
		default:;
	}
}

void ClientBase::Subscribe(Event event)
{
	m_eventController->Subscribe(this, event);
}

void ClientBase::Unsubscribe(Event event)
{
	m_eventController->Unsubscribe(this, event);
}

void ClientBase::SendEvent(Event event)
{
	m_eventController->SendEvent(event);
}

void ClientBase::execute()
{
}


void ClientA::start()
{
	Subscribe(Event::EventB);
	std::cout << "Client " + m_name + " started!" << std::endl;
}

void ClientA::execute()
{
	std::this_thread::sleep_for(std::chrono::duration<int, std::milli>(2000));
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