#pragma once
#include "Creature.h"
class Enemy : public Creature
{
	virtual void Move(sf::Vector2f direction) override;

};

