#pragma once
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Enemy.h"
#include "Knight.h"
#include "Archer.h"
#include "Sprite.h"

class Field
{

	sf::RectangleShape field_shape;

public:
	sf::Vector2f size;

	Field(sf::Vector2f size);
	sf::Vector2f map_shift;
	const sf::Vector2f map_shift_start = { -1000 , -1000 };;
	Hero hero;

	game::Sprite map_photo;
	std::vector <Enemy*> enemies;

	Archer archer;
	
	

	void Generate();

	void Draw(sf::RenderWindow& window);

	void Step(); 
	
	void Spawn(int archer_amount, int knight_amount);
};

