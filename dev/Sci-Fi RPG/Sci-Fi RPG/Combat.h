#pragma once
#include "Player.h"
#include "Enemy.h"
#include "UI.h"


class Combat
{
private:
	UI ui_;

public:

	void playerTakeDamage(Player& target, int damage);
	void enemyTakeDamage(Enemy& target, int damage);

	void startBattle(Player& player, Enemy& enemy);
};

