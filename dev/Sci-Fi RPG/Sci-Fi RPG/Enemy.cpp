#include "Enemy.h"

Enemy::Enemy()
{
	maxHealth_ = 200;
	health_ = 200;
	armor_ = 10;
}

int Enemy::GetHealth() const { return health_; }
int Enemy::GetMaxHealth() const { return maxHealth_; }
int Enemy::GetArmor() const { return armor_; }

void Enemy::SetHealth(int value) { health_ = value; }

bool Enemy::isAlive() const
{
	bool living;

	if (health_ > 0) { living = true; }
	else { living = false; }

	return living;
}