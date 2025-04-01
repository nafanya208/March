#pragma once
#include <SFML/Graphics.hpp>
#include "Sprite.h"

class Creature
{
public:
	int hp;
	int damage;
	int armor;
	sf::Vector2f pos;
	game::Sprite image;

	virtual void Move(sf::Vector2f direction) = 0;
	virtual void Attack() = 0;
	virtual void Step() = 0;
};

