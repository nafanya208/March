#include "Hero.h"
#include "TimeManager.h"


void Hero::Move(sf::Vector2f direction) {
	pos = direction + pos;
	image.sprite.setPosition(pos);

	
}

//void Hero::SetField(Field* f) {
//	field = f;
//}

void Hero::Attack() {
	/*float time = TimeManager::get_cur_time();
	if (attackTime <= time) {
		for (int i = 0; i < field->enemies.size(); i++) {

		}

	}*/
		
	
}
void Hero::Step() {
	Move(direction);

}
Hero::Hero() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/hero.png";
	image.SetImage(a);
	image.sprite.setScale(0.35, 0.35);
	pos = sf::Vector2f(400, 400);
	direction = sf::Vector2f(0, 0);
	hp = 250;
}

void Hero::SetDirection(sf::Vector2f dir) {
	direction = dir;
}
