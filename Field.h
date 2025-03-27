#pragma once
#include <SFML/Graphics.hpp>
class Field
{

	sf::RectangleShape field_shape;

public:
	sf::Vector2f size;

	Field(sf::Vector2f size);

	

	void Generate();

	void Draw(sf::RenderWindow& window);
};

