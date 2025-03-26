#include "Observer.h"

Publisher::~Publisher()
{
	m_subscribers.clear();
}

void Publisher::Subscribe(ISubscriber* object, Event event)
{
	m_subscribers[event].push_back(object);
}

void Publisher::Unsubscribe(ISubscriber* object, Event event)
{
	auto it = std::find(m_subscribers[event].begin(), m_subscribers[event].end(), object);
	if(it != m_subscribers[event].end())
		m_subscribers[event].erase(it);
}

void Publisher::SendEvent(Event event)
{
	auto mapIt = m_subscribers.find(event);

	if (mapIt != m_subscribers.end())
	{
		std::vector<ISubscriber*> subscribers = mapIt->second;
		for (auto& subscriber : subscribers)
		{
			subscriber->onEvent(event);
		}
	}
}

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
