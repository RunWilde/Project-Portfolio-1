#include "Combat.h"

void Combat::playerTakeDamage(Player& target, int damage)
{
	int hp = target.GetHealth();

	hp -= damage;

	target.SetHealth(hp);
}

void Combat::enemyTakeDamage(Enemy& target, int damage)
{
	int hp = target.GetHealth();

	hp -= damage;

	target.SetHealth(hp);
}