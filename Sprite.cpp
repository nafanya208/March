#include "Sprite.h"
void game::Sprite::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

void game::Sprite::SetImage(std::string path) {
	texture.loadFromFile(path);
	sprite.setTexture(texture);
	sprite.setPosition(sf::Vector2f(200, 200));
	//sprite.setScale(sf::Vector2f(0.5, 0.5));
}



//game::Sprite::Sprite(std::string path) {
//	/*texture.loadFromFile(path);
//	sprite.setTexture(texture);
//	sprite.setPosition(sf::Vector2f(200, 200));
//	sprite.setScale(sf::Vector2f(0.5, 0.5));*/
//}

game::Sprite::Sprite() {};


