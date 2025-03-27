#pragma once
#include "Creature.h"
class Hero : public Creature
{
	virtual void Move(sf::Vector2f direction) override;

	virtual void Attack() override;

};

