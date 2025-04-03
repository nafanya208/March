#include "Knight.h"
Knight::Knight() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/knight.png";
	image.SetImage(a);
	image.sprite.setScale(sf::Vector2f(0.35, 0.35));

}

void Knight::Move(sf::Vector2f direction) {
	pos = direction + pos;
	image.sprite.setPosition(pos);

}

void Knight::Attack() {

}

sf::Vector2f normalize2(const sf::Vector2f& vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	if (length != 0) {
		return sf::Vector2f(vector.x / length , vector.y / length);
	}
	else {
		return sf::Vector2f(0, 0);
	}
}


void Knight::Step() { 
	sf::Vector2f pos_hero = hero->pos;
	sf::Vector2f direction = pos_hero - pos; /*( - 3 , -2)*/
	direction = normalize2(direction);
	Move(direction);
	

}