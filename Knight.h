#pragma once
#include "enemy.h"
class Knight : public Enemy 
{
	virtual void Attack() override;

	virtual void Step() override;
};

