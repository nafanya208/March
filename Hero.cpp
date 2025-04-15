#include "Hero.h"
#include "TimeManager.h"
#include "Field.h"

sf::Vector2f operator-(const sf::Vector2f& vec1, const sf::Vector2f& vec2) {
	return sf::Vector2f(vec1.x - vec2.x, vec1.y - vec2.y);
}

void Hero::Move(sf::Vector2f direction) {
	pos = direction + pos;
	image.sprite.setPosition(pos);

	
}

void Hero::SetField(Field* f) {
	field = f;
}

void Hero::Attack() {
	float time = TimeManager::get_cur_time();
	if (attackTime <= time) {
		for (int i = 0; i < field->enemies.size(); i++) {
			sf::Vector2f vec = pos - field->enemies[i]->pos;
			float length = MatFunc::length(vec);
			if (length <= rangeAttack) {
				field->enemies[i]->hp -= damage;
				attackTime = time + attackSpeed;
			}
		}

	}
		
	
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
	rangeAttack = 150;
}

void Hero::SetDirection(sf::Vector2f dir) {
	direction = dir;
}
