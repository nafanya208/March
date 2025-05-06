#include "loot.h"

Loot::Loot() {
	std::string a = "C:/IT/SFML-2.6.2/March/March/March/potion.png";
	image.SetImage(a);
	speed_multiplier = 2;
	int loot_x = rand() % 2000 - 1000;
	int loot_y = rand() % 2000 - 1000;
	pos = sf::Vector2f(loot_x, loot_y);
	image.sprite.setScale(sf::Vector2f(0.1, 0.1));

}

void Loot::Step() {



}

void Loot::UpdateDrawPosLoot(sf::Vector2f shift) {
	image.sprite.setPosition(shift + pos);
	
}

 Loot::Loot(LootType type) {
	 this->type = type;
	if (type == LootType::speed) {
		std::string a = "C:/IT/SFML-2.6.2/March/March/March/potion.png";
		image.SetImage(a);
		damage_multiplier = 1;
		
		speed_multiplier = 2;
		int loot_x = rand() % 2000 - 1000;
		int loot_y = rand() % 2000 - 1000;
		pos = sf::Vector2f(loot_x, loot_y);
		image.sprite.setScale(sf::Vector2f(0.1, 0.1));

	}
	else {
		std::string a = "C:/IT/SFML-2.6.2/March/March/March/damage.png";
		image.SetImage(a);
		damage_multiplier = 2;
		speed_multiplier = 1;
		int loot_x = rand() % 2000 - 1000;
		int loot_y = rand() % 2000 - 1000;
		pos = sf::Vector2f(loot_x, loot_y);
		image.sprite.setScale(sf::Vector2f(0.5, 0.5));
	}

}
