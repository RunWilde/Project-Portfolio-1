#pragma once
#include "Player.h"
#include "Enemy.h"

class UI
{

private:

public:

	void border();
	void clearScreen();
	int userChoice();
	void invalidChoice();

	void mainMenu();
	void combatStats(const Player& player, const Enemy& enemy, int actionPoints);
	void combatMenu();

};

