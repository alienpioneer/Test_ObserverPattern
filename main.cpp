#pragma once
#include "Clients.h"

int main()
{	
	std::shared_ptr<Publisher> eventController = std::make_shared<Publisher>(Publisher());
	
	ClientA clientA(eventController, "A");
	ClientB clientB(eventController, "B");

	clientA.start();
	clientB.start();
	clientA.execute();
	clientB.execute();

	std::cout << "End" << std::endl;

	return 0;
}