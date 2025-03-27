#include "enemy.h"
void Enemy::Move(sf::Vector2f direction) {
	pos = direction + pos;

}