#ifndef TEST_OBSERVERPATTERN_H
#define TEST_OBSERVERPATTERN_H

#include <iostream>
#include <map>
#include <vector>

// Each subscriber (client) can subscribe to the events from this list
enum class Event
{
	EventA,
	EventB,
	EventC,
	EventD
};


// Common subscriber interface - the client subscriber class must implement this interface
class ISubscriber
{
public:
	ISubscriber(){};
	virtual ~ISubscriber(){};
	virtual void onEvent(Event event) = 0;
};


// This is the main observer object - controls the subscribers mapping to events
class Publisher
{
public:
	Publisher() : m_subscribers() {};
	~Publisher();

	void Subscribe(ISubscriber* object, Event event);
	void Unsubscribe(ISubscriber* object, Event event);

	// this will call the onEvent from the subscriber
	void SendEvent(Event event); 

private:
	std::map<Event, std::vector<ISubscriber*>> m_subscribers;
};


// The general client base - all the client objects must inherit from this base
class ClientBase : ISubscriber
{
public:
	ClientBase(std::shared_ptr<Publisher> eventController, std::string name) :
		ISubscriber(), m_name(name), m_eventController(eventController) {};

	virtual ~ClientBase() {};

	void Subscribe(Event event);
	void Unsubscribe(Event event);
	void SendEvent(Event event);

	virtual void onEvent(Event event);

protected:
	std::string m_name;
	std::shared_ptr<Publisher> m_eventController;
};

#endif // TEST_OBSERVERPATTERN_H

