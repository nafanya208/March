#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace game {

	class Sprite
	{
	public:
		void Draw(sf::RenderWindow& window);

		//Sprite(std::string path);
		Sprite();

		sf::Sprite& operator=(const sf::Sprite&) = delete;
		sf::Sprite(const sf::Sprite&) = delete;
		sf::Sprite sprite;
		sf::Texture texture;

		void SetImage(std::string path);
	};
}