#include "Test_ObserverPattern.h"

ISubscriber::ISubscriber()
{
}

ISubscriber::~ISubscriber()
{
}

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
