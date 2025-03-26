#ifndef CLIENTS_H
#define CLIENTS_H

#include "Observer.h"

class ClientA : ClientBase
{
	public:
		ClientA(std::shared_ptr<Publisher> eventController, std::string name) 
			:ClientBase(eventController, name) {};
		~ClientA() {};
		void start();
		void execute();
		void onEvent(Event event) override;
};
	
class ClientB : ClientBase
{
public:
	ClientB(std::shared_ptr<Publisher> eventController, std::string name)
		:ClientBase(eventController, name) {};
	~ClientB() {};
	void start();
	void execute();
	void onEvent(Event event) override;
};

	
#endif CLIENTS_H
