#include <iostream>
#include <string>
#include "Engine.h"
#include "json.hpp"


Engine::Engine() 
{
	mRunning = true;
}

void Engine::startGameLoop()
{
	start();
	while (mRunning)
	{
		readInput();
		update();
	}
	end();
}

void Engine::start()
{
	std::cout << "Starting engine\n";
}

void Engine::readInput()
{
	std::cout << "Enter input (type 'q' to quit): ";
	std::string input;
	std::cin >> input;
	if (input == "q")
	{
		mRunning = false;
	}
}

void Engine::update()
{
}

void Engine::end()
{
	std::cout << "Ending engine\n";
}

