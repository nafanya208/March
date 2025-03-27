#include "Field.h"
Field::Field(sf::Vector2f size) : size(size) {

	Generate();
};

void Field::Generate() {
	field_shape = sf::RectangleShape(size);
	field_shape.setFillColor(sf::Color(51, 153, 0, 255));
	field_shape.setPosition(sf::Vector2f(0, 0));
};

void Field::Draw(sf::RenderWindow& window ) {
	window.draw(field_shape);
}