#pragma once
#include <SFML/Graphics.hpp>
class Creature
{
public:
	int hp;
	int damage;
	int armor;
	sf::Vector2f pos;


	virtual void Move(sf::Vector2f direction) = 0;
	virtual void Attack() = 0;
	virtual void Step() = 0;
};

