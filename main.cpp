#pragma once
#include "Clients.h"
#include <thread>
#include <future>

/*  Expected output
Client A started!
Client B started!
Client B received EventA!
Client B received EventA!
Client A received EventB!
End 
*/

int main()
{	
	std::shared_ptr<Publisher> eventController = std::make_shared<Publisher>(Publisher());
	
	ClientA clientA(eventController, "A");
	ClientB clientB(eventController, "B");

	clientA.start();
	clientB.start();

	std::async(&ClientA::execute, &clientA);
	std::async(&ClientB::execute, &clientB);

	/*std::thread threadA(&ClientA::execute, &clientA);
	std::thread threadB(&ClientB::execute, &clientB);*/
	//clientA.execute();
	//clientB.execute();

	/*threadA.join();
	threadB.join();*/

	std::cout << "End" << std::endl;

	return 0;
}