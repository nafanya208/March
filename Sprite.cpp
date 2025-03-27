#include "Sprite.h"
void game::Sprite::Draw(sf::RenderWindow& window) {
	window.draw(image);
}

game::Sprite::Sprite(std::string path) {

	texture.loadFromFile(path);
	image.setTexture(texture);
	image.setPosition(sf::Vector2f(0, 0));
}

