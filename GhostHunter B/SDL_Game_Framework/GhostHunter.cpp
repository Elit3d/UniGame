#include "GhostHunter.h"
#include "random.h"
#include "character.h"

GhostHunter::GhostHunter(void)
{
}

GhostHunter::~GhostHunter(void)
{
}

void GhostHunter::setup()
{
	setBackground("images/haunted-house.jpg");
	mainChar.setSpriteImage("images/ghost.png");
	enableKeyRepeat();
}

void GhostHunter::logic()
{
	onKeyDown();
	onMouseMoved();
}

void GhostHunter::onKeyReleased()
{

}

void GhostHunter::onKeyDown()
{
	
	
}

void GhostHunter::onMouseMoved()
{
	
}

void GhostHunter::draw(){
	mainChar.getSpriteImage().update_everything();
}
