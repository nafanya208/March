#include "Knight.h"
#include "TimeManager.h"

Knight::Knight() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/knight.png";
	image.SetImage(a);
	image.sprite.setScale(sf::Vector2f(0.35, 0.35));
	attackSpeed = 10.0;
	attackTime = 0;
	damage = 20;
	hp = 200;

}

void Knight::Move(sf::Vector2f direction) {
	pos = direction + pos;
	image.sprite.setPosition(pos);
	hp_text.setPosition(pos);
}

void Knight::Attack() {
	
	float time = TimeManager::get_cur_time();
	if (attackTime <= time) {
		hero->hp -= damage;
		attackTime = time + attackSpeed;
	}
	
}




void Knight::Step() { 
	sf::Vector2f pos_hero = hero->pos;
	sf::Vector2f direction = pos_hero - pos; /*( - 3 , -2)*/
	int len = matfunc.length(direction);
	
	direction = matfunc.normalize(direction);
	
	if (len > 100) {
		Move(direction);
	}
	else {
		
		Attack(); 
	}
	
	hp_text.setString(std::to_string(hp));

}