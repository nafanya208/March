#pragma once
#include "Sprite.h"
class loot
{
public: 
	int speed_multiplier; 
	game::Sprite image;
	sf::Vector2f pos;


	loot();

	void Spawn_loot(loot a);
	void Step();
	void UpdateDrawPosLoot(sf::Vector2f shift);
};

