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

	void setSpriteImage(char imagePath[]);
	void setHealth(int health);
	void setArmor(int armor);
	void setDamage(float damage);
	void setDamageModifier(float damageModifier);

private:
	AWSprite m_spriteImage; //image to represent sprite
	int m_health; //character health
	int m_armor; //character armor
	float m_damage; //base level of damage
	float m_damageModifier; //any modifier positive or negative
};

