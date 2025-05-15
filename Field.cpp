#include "Field.h"

Field::Field() {


}
 
Field::Field(sf::Vector2f size) : size(size) {

	Generate();
};
void Field::Spawn(int archer_amount , int knight_amount) {
	int size = enemies.size();
	for (int i = enemies.size(); i < archer_amount+size; i++) {
		enemies.emplace_back(new Archer());
		int archer_x = rand() % 2000 - 1000;
		int archer_y = rand() % 2000 - 1000;
		enemies[i]->pos = sf::Vector2f(archer_x, archer_y);
	}
	size = enemies.size();
	for (int i = enemies.size(); i < knight_amount + size; i++) {
		enemies.emplace_back(new Knight());
		int knight_x = rand() % 2000 - 1000;
		int knight_y = rand() % 2000 - 1000;

		enemies[i]->pos = sf::Vector2f(knight_x, knight_y);
	}

	for (int i = 0; i < enemies.size(); i++) {
		/*enemies[i]->SetHero(std::make_shared < Hero> (hero));*/
		enemies[i]->SetHero(&hero);

	}
}
void Field::Generate() {
	
	field_shape = sf::RectangleShape(size);
	field_shape.setFillColor(sf::Color(51, 153, 0, 255));
	field_shape.setPosition(sf::Vector2f(0, 0));
	/*Hero = new Hero();
	hero = std::shared_ptr <Hero> (hero_ptr);*/
	srand(time(0));
	int archer_amount = rand() % 7 + 5;
	int knight_amount = rand() % 10 + 5;

	

	Spawn(archer_amount, knight_amount);

	/*loots.reserve(20);*/
	for (int i = 0; i < 30; i++) {
		int j = rand() % 2;
		if (j == 1) {
			loots.emplace_back(LootType::speed);
		}
		if (j == 0) {
			loots.emplace_back(LootType::damage);
		}
		
	}
	
	
	
	
	hero.SetField(this);
	map_photo.SetImage("map.png");
};

 

void Field::Draw(sf::RenderWindow& window ) {

	
	//window.draw(field_shape);
	map_photo.sprite.setPosition(map_shift + map_shift_start);
	map_photo.Draw(window);
	//archer.image.Draw(window);
	//window.draw(enemies[0]->image.sprite);

	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->UpdateDrawPos(map_shift);
		enemies[i]->image.Draw(window);
		window.draw(enemies[i]->hp_text);
	}
	for (auto i = loots.begin(); i != loots.end(); i++) {
		(*i).UpdateDrawPosLoot(map_shift);
		(*i).image.Draw(window);
	}
	
	hero.image.Draw(window);
	window.draw(hero.hp_text);
	

	
}

void Field::Step() {
	
	for (auto i = enemies.begin(); i != enemies.end();) {
		if ((*i)->hp <= 0) {
			
			i = enemies.erase(i); // Удаляем элемент и получаем новый итератор
			continue; // Переходим к следующему элементу
		}
		
		(*i)->Step();
		++i; // Переходим к следующему элементу
	}
	
	if (enemies.size() <= 5) {
		Spawn(rand() % 7 + 5, rand() % 10 + 5);
	}
	hero.Step();
	

}