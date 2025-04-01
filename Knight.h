#pragma once
#include "enemy.h"

class Knight : public Enemy 
{
public:
	virtual void Move(sf::Vector2f direction) override;
	virtual void Attack() override;

	virtual void Step() override;

	Knight();
};

