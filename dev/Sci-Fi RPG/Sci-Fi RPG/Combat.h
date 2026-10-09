#pragma once
#include "Player.h"
#include "Enemy.h"
#include "UI.h"


class Combat
{
private:
	UI ui_;
	bool inCombat_;



public:

	void playerTakeDamage(Player& target, int damage);
	void enemyTakeDamage(Player& player, Enemy& target);

	void startBattle(Player& player, Enemy& enemy);
	void enemyTurn(Player& player, Enemy& enemy);
};

