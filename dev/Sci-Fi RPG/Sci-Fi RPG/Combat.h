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

public:

	void playerAttack(Player& player, Enemy& target, int accBonus);
	void enemyAttack(Enemy& enemy, Player& target);

	void startBattle(Player& player, Enemy& enemy);
	void weaponActions(Player& player, Enemy& enemy, int& actionPoints);
	void enemyTurn(Player& player, Enemy& enemy);
	void combatStats(const Player& player, const Enemy& enemy, int actionPoints);

};

