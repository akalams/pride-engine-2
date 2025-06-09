#pragma once
#include <vector>
#include "ComponentSet.hpp"


class Engine
{
public:
	Engine();
	void startGameLoop(); // Begins main game loop

private:
	bool mRunning;
	std::vector <char> mScene;
	ComponentSet<Transform> mTransforms;
	ComponentSet<View> mViews;
	size_t mSceneWidth;
	size_t mSceneHeight;
	void start();
	void readInput();
	void update();
	void end();
};