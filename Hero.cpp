#include "Hero.h"

void Hero::Move(sf::Vector2f direction) {
	pos = direction + pos;
	
}

void Hero::Attack() {
	
}
void Hero::Step() {


}
Hero::Hero() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/hero.png";
	image.SetImage(a);
}