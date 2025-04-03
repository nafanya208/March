#include "Archer.h"
#include <cmath>
Archer::Archer() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/archer.png";
	image.SetImage(a);
	image.sprite.setScale(0.35, 0.35);


}

void Archer::Move(sf::Vector2f direction) {
	pos = direction + pos;
	image.sprite.setPosition(pos);


}

void Archer::Attack() {

}

float length(const sf::Vector2f& vector) {

	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	
}

sf::Vector2f normalize(const sf::Vector2f& vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

	if (length != 0) {
		return sf::Vector2f(vector.x / length, vector.y / length);
	}
	else {
		return sf::Vector2f(0, 0);
	}
}

void Archer::Step() {
	sf::Vector2f pos_hero = hero->pos;
	sf::Vector2f direction = pos_hero - pos; /*( - 3 , -2)*/
	int len = length(direction);
	if (len > 300) {
		direction = normalize(direction);
		Move(direction);
		return;
	}
	if (len < 200) {
		direction = normalize(direction);
		direction.x = direction.x * -1;
		direction.y = direction.y * -1;
		

		Move(direction);
	}
	else {
		Archer::Attack();
	}




}