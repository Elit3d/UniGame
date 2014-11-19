#include "character.h"
#include <string>

using namespace std;

character::character()
{
	setHealth(100); //player health
	setArmor(0); //player armor
	setDamage(5.0f); //player damage
	setDamageModifier(0.0f); //damage modifier
	setJumping(false); 
	setFalling(false);
	setPoints(0); //player points
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

void character::setPoints(int points) //player points
{
	m_points = points;
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

int character::getHealth()
{
	return m_health;
}

int character::getPoints() //player points
{
	return m_points;
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