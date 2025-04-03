#include "enemy.h"
void Enemy::Move(sf::Vector2f direction) {
	pos = direction + pos;

}

void Enemy::SetHero(Hero* h) {
	hero = h;
}