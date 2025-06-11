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
	mCameraX = 0;
	mCameraY = 0;
}

void Engine::startGameLoop()
{
	start();
	while (mRunning)
	{
		readInput();
		update();
		render();
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
	mCameraWidth = init["width"];
	mCameraHeight = init["height"];

	// Initialize scene with some characters
	mTransforms = ComponentSet<Transform>();
	mTransforms.addComponent({2, 2});
	mTransforms.addComponent({0, 0});
	mTransforms.addComponent({-2, -2});
	mViews = ComponentSet<View>();
	mViews.addComponent({'P'});
	mViews.addComponent({'#'});
	mViews.addComponent({'#'});
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

void Engine::render()
{
	int rowStart = mCameraY-mCameraHeight/2;
	int columnStart = mCameraX-mCameraWidth/2;
	for (int r=rowStart; r < rowStart+(int)mCameraHeight; ++r)
	{
		for (int c=columnStart; c < columnStart+(int)mCameraWidth; ++c)
		{
			bool found = false;
			for (size_t k = 0; k < mTransforms.size(); ++k)
			{
				if (mTransforms.getComponent(k).x == c && mTransforms.getComponent(k).y == r)
				{
					std::cout << mViews.getComponent(k).symbol;
					found = true;
					break;
				}
			}
			if (!found)
			{
				std::cout << ' ';
			}
		}
		std::cout << "\n";
	}
}

void Engine::end()
{
	std::cout << "Ending engine\n";
}