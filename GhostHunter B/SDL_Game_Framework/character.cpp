#include "character.h"
#include <string>

using namespace std;

character::character()
{
	setHealth(100);
	setArmor(0);
	setDamage(5.0f);
	setDamageModifier(0.0f);
	setJumping(false);
	setFalling(false);
	setJumpedLast(false);
}


character::~character()
{
}

void character::setSpriteImage(char imagePath[])
{
	m_spriteImage.setImage(imagePath, 1);
}

void character::setHealth(int health)
{
	m_health = health;
}

void character::setArmor(int armor)
{
	m_armor = armor;
}

void character::setDamage(float damage)
{
	m_damage = damage;
}

void character::setDamageModifier(float damageModifier)
{
	m_damageModifier = damageModifier;
}

void character::setJumping(bool jumping)
{
	m_jumping = jumping;
}

void character::setFalling(bool falling)
{
	m_falling = falling;
}

void character::setJumpedLast(bool jumped)
{
	m_jumpedLast = jumped;
}


int character::getHealth()
{
	return m_health;
}

int character::getArmor()
{
	return m_armor;
}

float character::getDamage()
{
	return m_damage;
}

float character::getDamageModifier()
{
	return m_damageModifier;
}

bool character::getJumping()
{
	return m_jumping;
}

bool character::getFalling()
{
	return m_falling;
}

bool character::getJumpedLast()
{
	return m_jumpedLast;
}