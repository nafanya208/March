#pragma once
#include "Creature.h"
class Field;

class Hero : public Creature
{
public:
	virtual void Move(sf::Vector2f direction) override;

	virtual void Attack() override;

	virtual void Step() override;
	
	Field* field;
	
	float rangeAttack;

	void SetField(Field* f);
	Hero();
	sf::Vector2f direction;
	void SetDirection(sf::Vector2f dir);
};

