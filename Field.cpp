#include "Field.h"
 
Field::Field(sf::Vector2f size) : size(size) {

	Generate();
};

void Field::Generate() {
	field_shape = sf::RectangleShape(size);
	field_shape.setFillColor(sf::Color(51, 153, 0, 255));
	field_shape.setPosition(sf::Vector2f(0, 0));
	
	enemies.push_back( new Archer());
	enemies.push_back(new Knight());
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->SetHero(&hero);
		
	}
	hero.SetField(this);
};

 

void Field::Draw(sf::RenderWindow& window ) {
	window.draw(field_shape);
	//archer.image.Draw(window);
	//window.draw(enemies[0]->image.sprite);
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->image.Draw(window);
	}
	hero.image.Draw(window);
}

void Field::Step() {
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->Step();
	}
	
	hero.Step();

}