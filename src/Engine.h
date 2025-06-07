#pragma once
#include <vector>


class Engine
{
public:
	Engine();
	void startGameLoop(); // Begins main game loop

private:
	bool mRunning;
	std::vector <char> mScene;
	size_t mSceneWidth;
	size_t mSceneHeight;
	void start();
	void readInput();
	void update();
	void end();
};