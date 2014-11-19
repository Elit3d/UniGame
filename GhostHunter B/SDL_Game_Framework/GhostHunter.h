#pragma once

#include "gamebase.h"
#include "character.h"
#include "terrain.h"

const int NBR_PLATFORMS = 10;

class GhostHunter :	public GameBase
{
public:
	GhostHunter(void);
	~GhostHunter(void);

	void setup();
	void logic();
	void draw();

	void onKeyReleased();
	void onKeyPressed();
	void onMouseMoved();

	Uint8 *lastKeyState = SDL_GetKeyState(NULL);
	
	// Our method declarations will go here
	const float gravity = 0.5f;
	const float fallGravity = 0.5f;
	float currentFallGravity = 0.0f;
	const float jumpForce = 13.0f;
	float currentJumpForce = 0.0f;

	character mainChar;
	character enemys[3];

	//terrain platform;
	//array to hold platforms
	terrain platform[NBR_PLATFORMS];
	

private:
	
};

