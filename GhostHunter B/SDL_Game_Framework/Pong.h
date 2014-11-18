#pragma once

#include "gamebase.h"
#include "random.h"

using namespace random;

const float BAT_MOVE = 5.0f;

class Pong :
	public GameBase
{
public:
	Pong(void);
	~Pong(void);

	void setup();
	void draw();
	void logic();

	void resetBall();
	void onKeyReleased();
	void onKeyPressed();


private:
	AWSprite topWall, bottomWall, leftWall;
	AWSprite bat, ball;

	// 0 = waiting to start 1 = in play
	int state;

	int rallyLength;
	int maxRallyLength;
};

