#pragma once
#include "enemy.h"
#include "Sprite.h"
class Archer : public Enemy 
{
public:
	virtual void Attack() override;

	virtual void Step() override;

	virtual void Move(sf::Vector2f direction) override;
	Archer();
};

