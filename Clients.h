#ifndef CLIENTS_H
#define CLIENTS_H

#include <iostream>
#include <string>
#include "Observer.h"

//The general client base - all the client objects must inherit from this base
class ClientBase : ISubscriber
{
public:
	ClientBase(std::shared_ptr<Publisher> eventController, std::string name) :
		ISubscriber(), m_name(name), m_eventController(eventController) {};
	virtual ~ClientBase() { m_eventController = nullptr; m_name = ""; };
	void Subscribe(Event event);
	void Unsubscribe(Event event);
	void SendEvent(Event event);
	virtual void onEvent(Event event);
	virtual void start() = 0;
	virtual void execute() = 0;
protected:
	std::string m_name;
	std::shared_ptr<Publisher> m_eventController;
};


class ClientA : ClientBase
{
	public:
		ClientA(std::shared_ptr<Publisher> eventController, std::string name) 
			:ClientBase(eventController, name) {};
		~ClientA() {};
		void start() override;
		void execute() override;
		void onEvent(Event event) override;
};
	
class ClientB : ClientBase
{
public:
	ClientB(std::shared_ptr<Publisher> eventController, std::string name)
		:ClientBase(eventController, name) {};
	~ClientB() {};
	void start() override;
	void execute() override;
	void onEvent(Event event) override;
};

	
#endif CLIENTS_H
