#include "Hero.h"

void Hero::Move(sf::Vector2f direction) {
	pos = direction + pos;
	image.sprite.setPosition(pos);

	
}

void Hero::Attack() {
	
}
void Hero::Step() {
	Move(sf::Vector2f(0 , 0));

}
Hero::Hero() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/hero.png";
	image.SetImage(a);
	image.sprite.setScale(0.35, 0.35);
	pos = sf::Vector2f(400, 400);
}