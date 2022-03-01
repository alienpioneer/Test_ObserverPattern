#pragma once
#include "Clients.h"
#include <thread>
#include <functional>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include "CsvTest.cpp"


int main()
{	
	std::shared_ptr<Publisher> eventController = std::make_shared<Publisher>(Publisher());
	
	ClientA clientA(eventController, "A");
	ClientB clientB(eventController, "B");

	clientA.start();
	clientB.start();

	std::thread threadA(&ClientA::execute, &clientA);
	std::thread threadB(&ClientB::execute, &clientB);
	//clientA.execute();
	//clientB.execute();

	threadA.join();
	threadB.join();

	std::cout << "End" << std::endl;

	return 0;
}