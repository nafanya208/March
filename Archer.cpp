#include "Archer.h"
#include <cmath>
#include "TimeManager.h"
Archer::Archer() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/archer.png";
	image.SetImage(a);
	image.sprite.setScale(0.35, 0.35);
	attackSpeed = 20.0;
	attackTime = 0;
	damage = 37;
	hp = 120;
}

void Archer::Move(sf::Vector2f direction) {
	pos = direction + pos;
	image.sprite.setPosition(pos);


}

void Archer::Attack() {
	float time = TimeManager::get_cur_time();
	if (attackTime <= time) {
		hero->hp -= damage;
		attackTime = time + attackSpeed;
	}
}



void Archer::Step() {
	sf::Vector2f pos_hero = hero->pos;
	sf::Vector2f direction = pos_hero - pos; /*( - 3 , -2)*/
	
	int len = matfunc.length(direction);
	if (len > 300) {
		
		direction = matfunc.normalize(direction);
		Move(direction);
		return;
	}
	if (len < 200) {
		
		direction = matfunc.normalize(direction);
		direction.x = direction.x * -1;
		direction.y = direction.y * -1;
		

		Move(direction);
	}
	else {
		Archer::Attack();
	}




}