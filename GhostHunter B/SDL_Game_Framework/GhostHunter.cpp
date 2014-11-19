#include "GhostHunter.h"
#include "random.h"
#include "character.h"
#include <math.h>

GhostHunter::GhostHunter(void)
{
}

GhostHunter::~GhostHunter(void)
{
}

void GhostHunter::setup()
{
	setBackground("images/background_blank.png");

	mainChar.setSpriteImage("images/ghost.png");
	mainChar.m_spriteImage.set_transparent_colour(255, 0, 255);
	mainChar.m_spriteImage.set_world_position(0.0f,(float)height - mainChar.m_spriteImage.get_height());

	float coordinates[NBR_PLATFORMS][2] = { { 50, 600 }, { 50, 450 }, { 600, 600 }, { 600, 450 }, { (width / 2) - 75, 300 },
											{ 50, 150 }, { 600, 150 } };

	for (int i = 0; i < NBR_PLATFORMS; i++)
	{
		
		platform[i].sprite.setImage("images/platform.png");
		platform[i].sprite.set_world_position((float)coordinates[i][0], (float)coordinates[i][1]); //get coordinates from array
	}

	enableKeyRepeat();
}

void GhostHunter::logic()
{
	//refactor all this shit, place different parts into different functions, too messy

	onKeyPressed();//get keyboard input

	if (mainChar.getJumping() == true)
	{
		mainChar.m_spriteImage.set_world_position_y(mainChar.m_spriteImage.get_y() - currentJumpForce + gravity); // location = force of jump - gravity
		currentJumpForce -= gravity; // force of the jump is lessened untit it becomes negative, not how it should be done but it works
	}
	
	for (int i = 0; i < NBR_PLATFORMS; i++)
	{
		if (mainChar.m_spriteImage.bb_collision(platform[i].sprite))
		{
			mainChar.m_spriteImage.set_world_position_y((float)platform[i].sprite.get_y() - mainChar.m_spriteImage.get_height());
			mainChar.setJumping(false);
			mainChar.setFalling(false);
			currentJumpForce = 0.0f;
			break;
		}
		else
		{
			//if not collided then falling is true
			mainChar.setFalling(true);
		}
	}

	if (mainChar.m_spriteImage.get_y() >= height - mainChar.m_spriteImage.get_height())
	{
		//if character tries to go off screen at the bottom it will be set at 0 and falling set to false to prevent further attempts
		mainChar.setJumping(false);
		currentJumpForce = 0.0f;
		
		mainChar.m_spriteImage.set_world_position_y((float)height - mainChar.m_spriteImage.get_height());
		mainChar.setFalling(false);
	}

	if (mainChar.getJumping() == false && mainChar.getFalling() == true)
	{
		//the same as the jumping section but without the original jump, so the currentJumpForce starts at 0, for when you walk off a platform
		mainChar.m_spriteImage.set_world_position_y(mainChar.m_spriteImage.get_y() - currentJumpForce + gravity);
		
		currentJumpForce -= gravity;
	}	
}

void GhostHunter::onKeyPressed()
{ 
	Uint8 *keystates = SDL_GetKeyState(NULL); //bypass event queue for keystrokes


	if (keystates[SDLK_a] && mainChar.m_spriteImage.get_x() > 0)
	{
		mainChar.m_spriteImage.set_world_position_x(mainChar.m_spriteImage.get_x() - 5); //move left
	}
	if (keystates[SDLK_d] && mainChar.m_spriteImage.get_x() < width - mainChar.m_spriteImage.get_width()) //move right
	{
		mainChar.m_spriteImage.set_world_position_x(mainChar.m_spriteImage.get_x() + 5);
	}

	if (keystates[SDLK_SPACE] && mainChar.getJumping() == false && mainChar.getFalling() == false  && mainChar.jum|| // jump
		keystates[SDLK_w] && mainChar.getJumping() == false && mainChar.getFalling() == false)
	{
		mainChar.setJumping(true);
		currentJumpForce = jumpForce;
	}

	if (keystates[SDLK_ESCAPE]) //replaces the frameworks inbuilt quit which wasn't working for some reason
	{
		gameover = true;
	}
}

void GhostHunter::onMouseMoved()
{
	
}

void GhostHunter::draw(){
	mainChar.m_spriteImage.update_everything();
	for (int i = 0; i < NBR_PLATFORMS; i++)
	{
		platform[i].sprite.update_everything();
	}
}
