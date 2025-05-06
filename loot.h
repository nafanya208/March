#pragma once
#include "Sprite.h"

enum LootType
{
	speed , damage
};
class Loot
{
public: 
	int damage_multiplier;
	int speed_multiplier; 
	game::Sprite image;
	sf::Vector2f pos;


	Loot();
	Loot(LootType type);
	LootType type;

	void Spawn_loot(Loot a);
	void Step();
	void UpdateDrawPosLoot(sf::Vector2f shift);
};

