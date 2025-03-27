#pragma once
#include "enemy.h"
class Archer : public Enemy 
{
	virtual void Attack() override;

	virtual void Step() override;
};

