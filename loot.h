#pragma once
#include "Sprite.h"
#include "map"



enum LootType
{
	speed , damage
};

static  const std::map < LootType, float> multipliers = { { LootType::damage , 4} , {LootType::speed , 2} };
class Loot
{
public: 
	game::Sprite image;
	sf::Vector2f pos;


	Loot();
	Loot(LootType type);
	LootType type;
	float buff_time;
	void Spawn_loot(Loot a);
	void Step();
	void UpdateDrawPosLoot(sf::Vector2f shift);
};

