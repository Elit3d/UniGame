#pragma once

#include "gamebase.h"
#include "character.h"

class GhostHunter :	public GameBase
{
public:
	GhostHunter(void);
	~GhostHunter(void);

	void setup();
	void logic();
	void draw();

	void onKeyReleased();
	void onMouseMoved();
	void onKeyDown();

	// Our method declarations will go here
	const float gravity = 1.5f;
	const float jumpForce = 5.0f;
	float currentJumpForce = 0.0f;

	character mainChar;
	character enemys[3];

private:
	
};

