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

	//platform.sprite.setImage("images/platform.png");
	//platform.sprite.set_world_position(10.0f, 400.0f);

	//create an array of platforms with position

	float coordinates[NBR_PLATFORMS] = {};

	for (int i = 0; i < 2; i++)
	{
		
		platform[i].sprite.setImage("images/platform.png");
		platform[i].sprite.set_world_position((float)i * 20.0f, (float)i*i*10.0f);
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
	
	/*if (mainChar.m_spriteImage.bb_collision(platform.sprite))
	{
		//if in contact with platform set jumping and falling to false (will eventually need to be a for loop for all platforms)
		mainChar.m_spriteImage.set_world_position_y((float)platform.sprite.get_y() - mainChar.m_spriteImage.get_height());
		mainChar.setJumping(false);
		mainChar.setFalling(false);
	}*/

	for (int i = 0; i < 2; i++)
	{
		if (mainChar.m_spriteImage.bb_collision(platform[i].sprite))
		{
			mainChar.m_spriteImage.set_world_position_y((float)platform[i].sprite.get_y() - mainChar.m_spriteImage.get_height());
			mainChar.setJumping(false);
			mainChar.setFalling(false);
			break;
		}
		else
		{
			//if not collided then falling is true
			mainChar.setFalling(true);
			currentFallGravity = fallGravity;
		}
	}



	if (mainChar.m_spriteImage.get_y() >= height - mainChar.m_spriteImage.get_height())
	{
		//if character tries to go off screen at the bottom it will be set at 0 and falling set to false to prevent further attempts
		mainChar.setJumping(false);
		
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

void GhostHunter::onKeyReleased()
{

}

void GhostHunter::onKeyPressed()
{ 
	Uint8 *keystates = SDL_GetKeyState(NULL); //bypass event queue for keystrokes


	if (keystates[SDLK_a] && mainChar.m_spriteImage.get_x() > 0)
	{
		mainChar.m_spriteImage.set_world_position_x(mainChar.m_spriteImage.get_x() - 5);
	}
	if (keystates[SDLK_d] && mainChar.m_spriteImage.get_x() < width - mainChar.m_spriteImage.get_width())
	{
		mainChar.m_spriteImage.set_world_position_x(mainChar.m_spriteImage.get_x() + 5);
	}

	if (keystates[SDLK_SPACE] && mainChar.getJumping() == false && mainChar.getFalling() == false ||
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
	//draw items from array (KYLE)
	for (int i = 0; i < 2; i++)
	{
		platform[i].sprite.update_everything();
	}
	//platform.sprite.update_everything();
}
