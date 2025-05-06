#pragma once
#include "Creature.h"
#include "loot.h"

class Field;

class Hero : public Creature
{
public:
	virtual void Move(sf::Vector2f direction) override;

	virtual void Attack() override;

	virtual void Step() override;
	
	Field* field;
	std::vector <std::pair < LootType, float > > buffs;
	float rangeAttack;
	float speed;
	float rangePick;
	void SetField(Field* f);
	Hero();
	sf::Vector2f direction;
	void SetDirection(sf::Vector2f dir);
	void PickUpLoot();
	void AddBuff(Loot a);
};

