#ifndef TEST_OBSERVERPATTERN_H
#define TEST_OBSERVERPATTERN_H

#include <map>
#include <vector>

enum class Event
{
	EventA,
	EventB,
	EventC,
	EventD
};

//The subscriber must implement this interface
class ISubscriber
{
public:
	ISubscriber();
	virtual ~ISubscriber();
	virtual void onEvent(Event event) = 0;
};


//To be passed as an argument to the object that derives from the subscriber
class Publisher
{
public:
	Publisher() :
		m_subscribers() {};
	~Publisher();
	void Subscribe(ISubscriber* object, Event event);
	void Unsubscribe(ISubscriber* object, Event event);
	void SendEvent(Event event); // this will call the onEvent from the subscriber

private:
	std::map<Event, std::vector<ISubscriber*>> m_subscribers;
};

#endif // !TEST_OBSERVERPATTERN_H

