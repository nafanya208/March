#pragma once
#include "Creature.h"
class Hero : public Creature
{
public:
	virtual void Move(sf::Vector2f direction) override;

	virtual void Attack() override;

	virtual void Step() override;

	Hero();
};

