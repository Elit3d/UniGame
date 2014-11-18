#include "character.h"
#include <string>

using namespace std;

character::character()
{
	setHealth(100);
	setArmor(0);
	setDamage(5.0f);
	setDamageModifier(0.0f);
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
