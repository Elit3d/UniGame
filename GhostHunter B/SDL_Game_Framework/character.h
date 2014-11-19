#pragma once
#include "GameBase.h"
#include <string>

class character :
	public GameBase
{
public:
	character();
	~character();

	AWSprite getSpriteImage(); //return the sprite
	int getHealth(); //return the health of the player
	int getArmor(); //return the armor of the player
	float getDamage(); //return the base damage of the player (how much damage they do)
	float getDamageModifier(); //return the damage modifier of the player
	bool getJumping(); //return is the player jumping
	bool getFalling(); //return is the player falling
	bool getJumpedLast(); //return if player jumped at last opportunity

	void setSpriteImage(char imagePath[]); //set the image for the sprite
	void setHealth(int health); //set the health of the player
	void setArmor(int armor); //set the armor level of the player
	void setDamage(float damage); //set the base damage of the player
	void setDamageModifier(float damageModifier); //set the damage modifier of the player
	void setJumping(bool jumping); //set if the player is jumping
	void setFalling(bool falling); //set if the player is falling
	void setJumpedLast(bool jumped); //set if player jumped at last opportunity

	AWSprite m_spriteImage; //image to represent sprite

private:
	int m_health; //character health
	int m_armor; //character armor
	float m_damage; //base level of damage
	float m_damageModifier; //any modifier positive or negative
	bool m_jumping; //is character jumping
	bool m_falling; //is character on the way down
	bool m_jumpedLast; //did the player jump at the last opportunity
};

