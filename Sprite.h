#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace game {

	class Sprite
	{
	public:
		void Draw(sf::RenderWindow& window);

		Sprite(std::string path);


		sf::Sprite image;
		sf::Texture texture;
	};

}