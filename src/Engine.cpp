#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "Engine.h"
#include "json.hpp"
#include "constants.hpp"

using json = nlohmann::json;


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

	// Load init from JSON file
	std::cout << "Loading configuration from " << constants::INIT_PATH << "\n";
	std::ifstream ifile(constants::INIT_PATH);
	if (!ifile.is_open())
	{
		std::cerr << "Error: Could not open configuration file at " << constants::INIT_PATH << "\n";
		std::exit(0);
	}
	std::string jsonText((std::istreambuf_iterator<char>(ifile)), std::istreambuf_iterator<char>());
	auto init = json::parse(jsonText);
	ifile.close();

	// Setup the scene from init JSON
	mSceneWidth = init["width"];
	mSceneHeight = init["height"];
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
	for (size_t i=0; i < mSceneWidth; ++i)
	{
		for (size_t j = 0; j < mSceneHeight; ++j)
		{
			std::cout << "#";
		}
		std::cout << "\n";
	}
}

void Engine::end()
{
	std::cout << "Ending engine\n";
}