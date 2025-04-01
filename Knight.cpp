#include "Knight.h"
Knight::Knight() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/knight.png";
	image.SetImage(a);
	image.sprite.setScale(sf::Vector2f(0.5, 0.5));

}

void Knight::Move(sf::Vector2f direction) {
	pos = direction + pos;

}

void Knight::Attack() {

}
void Knight::Step() {


}