
#include "GhostHunter.h"

int main(int argc, char *argv[])
{
	GameBase::initSDL(800,750);
	GhostHunter gh;	// Create the game object
	gh.setup();		// Perform any game initialisation
	gh.start();		// Start the game
	return 0;
}