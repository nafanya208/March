#pragma once
#include "Creature.h"
#include "Hero.h"
class Enemy : public Creature
{
public:

	virtual void Move(sf::Vector2f direction) override;
	
	Hero* hero;


	void SetHero(Hero* h);
};

