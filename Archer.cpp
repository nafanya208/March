#include "Archer.h"
Archer::Archer() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/archer.png";
	image.SetImage(a);

}

void Archer::Move(sf::Vector2f direction) {
	pos = direction + pos;

}

void Archer::Attack() {

}
void Archer::Step() {


}