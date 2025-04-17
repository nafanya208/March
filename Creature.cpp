#include "Creature.h"
 Creature::Creature() {
	 font.loadFromFile("Arial.ttf");
	 hp_text.setFont(font); // Устанавливаем шрифт
	hp_text.setCharacterSize(24); // Устанавливаем размер символов
	hp_text.setFillColor(sf::Color::White); // Устанавливаем цвет текста
	hp_text.setPosition(100, 100); // Устанавливаем позицию текста

}
