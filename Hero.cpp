#include "Hero.h"
#include "TimeManager.h"
#include "Field.h"

sf::Vector2f operator-(const sf::Vector2f& vec1, const sf::Vector2f& vec2) {
	return sf::Vector2f(vec1.x - vec2.x, vec1.y - vec2.y);
}


void Hero::Move(sf::Vector2f direction) {
	sf::Vector2f better = sf::Vector2f(direction.x * speed, direction.y * speed); // todo: fix speed
	pos = better   + pos;
	/*image.sprite.setPosition(pos);*/
	/*hp_text.setPosition(pos);*/
	
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
	hp_text.setString(std::to_string(hp));

}
Hero::Hero() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/hero2.png";
	image.SetImage(a);
	image.sprite.setScale(0.35, 0.35);
	pos = sf::Vector2f(400, 400);
	direction = sf::Vector2f(0, 0);
	hp = 250;
	rangeAttack = 1000;
	attackSpeed = 0.05;
	attackTime = 0;
	damage = 10;
	hp = 200;
	image.sprite.setPosition(pos);
	hp_text.setPosition(pos - sf::Vector2f(20,20));
	speed = 2;
}

void Hero::SetDirection(sf::Vector2f dir) {
	direction = dir;
}
