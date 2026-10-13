#pragma once
#include "Player.h"
#include "Enemy.h"
#include "UI.h"
#include "Math.h"
#include <iostream>

class Combat
{
private:
	UI ui_;
	bool inCombat_;
	int d100_ = Math::dice(1,100);

public:

	void playerAttack(Player& player, Enemy& target);
	void enemyAttack(Enemy& enemy, Player& target);

	void startBattle(Player& player, Enemy& enemy);
	void enemyTurn(Player& player, Enemy& enemy);
};

