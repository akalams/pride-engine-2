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

	// Render properties
	int mCameraX;
	int mCameraY;
	size_t mCameraWidth;
	size_t mCameraHeight;

	// Game loop functions
	void start();
	void readInput();
	void update();
	void render();
	void end();
};