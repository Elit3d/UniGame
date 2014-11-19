#pragma once
#include "GameBase.h"
#include <string>

class character :
	public GameBase
{
public:
	character();
	~character();
	AWSprite getSpriteImage();
	int getHealth();
	int getArmor();
	float getDamage();
	float getDamageModifier();
	bool getJumping();
	bool getFalling();

	void setSpriteImage(char imagePath[]);
	void setHealth(int health);
	void setArmor(int armor);
	void setDamage(float damage);
	void setDamageModifier(float damageModifier);
	void setJumping(bool jumping);
	void setFalling(bool falling);

	AWSprite m_spriteImage; //image to represent sprite

private:
	int m_health; //character health
	int m_armor; //character armor
	float m_damage; //base level of damage
	float m_damageModifier; //any modifier positive or negative
	bool m_jumping; //is character jumping
	bool m_falling; //is character on the way down
};

