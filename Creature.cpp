#include "Creature.h"
 Creature::Creature() {
	 font.loadFromFile("Arial.ttf");
	 hp_text.setFont(font); // ������������� �����
	hp_text.setCharacterSize(24); // ������������� ������ ��������
	hp_text.setFillColor(sf::Color::White); // ������������� ���� ������
	hp_text.setPosition(100, 100); // ������������� ������� ������

}
