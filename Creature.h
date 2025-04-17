#pragma once
#include <SFML/Graphics.hpp>
#include "Sprite.h"
#include "MatFunc.h"

class Creature
{
public:
	sf::Text hp_text;	
	sf::Font font;
	
	MatFunc matfunc;
	int hp;
	int damage;
	int armor;
	sf::Vector2f pos;
	game::Sprite image;
	float attackTime;
	float attackSpeed;

	virtual void Move(sf::Vector2f direction) = 0;
	Creature();
	virtual void Attack() = 0;
	virtual void Step() = 0;
	virtual void UpdateDrawPos(sf::Vector2f shift);
};

