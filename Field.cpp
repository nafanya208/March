#include "Field.h"
 
Field::Field(sf::Vector2f size) : size(size) {

	Generate();
};
void Field::Spawn(int archer_amount , int knight_amount) {
	for (int i = 0; i < archer_amount; i++) {
		enemies.push_back(new Archer());
		int archer_x = rand() % 2000 - 1000;
		int archer_y = rand() % 2000 - 1000;
		enemies[i]->pos = sf::Vector2f(archer_x, archer_y);
	}

	for (int i = enemies.size(); i < knight_amount + archer_amount; i++) {
		enemies.push_back(new Knight());
		int knight_x = rand() % 2000 - 1000;
		int knight_y = rand() % 2000 - 1000;

		enemies[i]->pos = sf::Vector2f(knight_x, knight_y);
	}

}
void Field::Generate() {
	field_shape = sf::RectangleShape(size);
	field_shape.setFillColor(sf::Color(51, 153, 0, 255));
	field_shape.setPosition(sf::Vector2f(0, 0));
	srand(time(0));
	int archer_amount = rand() % 7 + 5;
	int knight_amount = rand() % 10 + 5;

	Spawn(archer_amount, knight_amount);

	/*for (int i = 0; i < archer_amount; i++) {
		enemies.push_back(new Archer());
		int archer_x = rand() % 1000;
		int archer_y = rand() % 1000;
		enemies[i]->pos = sf::Vector2f(archer_x , archer_y); 
	}

	for (int i = enemies.size(); i < knight_amount; i++) {
		enemies.push_back(new Knight());
		int knight_x = rand() % 1000;
		int knight_y = rand() % 1000;
		
		enemies[i]->pos = sf::Vector2f(knight_x, knight_y);
	}*/
	
	
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->SetHero(&hero);
		
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
	
	hero.image.Draw(window);
	window.draw(hero.hp_text);
	
}

void Field::Step() {
	
	for (auto i = enemies.begin(); i != enemies.end();) {
		if ((*i)->hp <= 0) {
			auto save = *i; 
			
			enemies.erase(i);
			i = enemies.begin();
			continue;
		}

		(*i)->Step();
		i++;
	}
	
	hero.Step();

}