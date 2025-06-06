#pragma once


class Engine
{
public:
	Engine();
	void startGameLoop(); // Begins main game loop

private:
	bool mRunning;
	void start();
	void readInput();
	void update();
	void end();
};