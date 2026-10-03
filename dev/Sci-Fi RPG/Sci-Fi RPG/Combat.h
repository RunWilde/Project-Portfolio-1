#pragma once
#include "Player.h"
#include "Enemy.h"

class Combat
{
private:

public:

	void playerTakeDamage(Player& target, int damage);
	void enemyTakeDamage(Enemy& target, int damage);
};

