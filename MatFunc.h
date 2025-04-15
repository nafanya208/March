#pragma once
#include <SFML/Graphics.hpp>
class MatFunc
{
public:
	static float length(const sf::Vector2f& vector) {
		return std::sqrt(vector.x * vector.x + vector.y * vector.y);
	}

	static sf::Vector2f normalize(const sf::Vector2f& vector) {
		float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

		if (length != 0) {
			return sf::Vector2f(vector.x / length, vector.y / length);
		}
		else {
			return sf::Vector2f(0, 0);
		}
	}

	
};

 
 