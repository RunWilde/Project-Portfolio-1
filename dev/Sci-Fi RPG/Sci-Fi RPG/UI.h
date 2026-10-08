#pragma once
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <string>

class UI
{

private:

public:

	void border();
	void clearScreen();
	void invalidChoice();
	void EnterToContinue();

	int menuHandler(const std::string& menuTitle, const std::vector<std::string>& menuOptions);
	void combatStats(const Player& player, const Enemy& enemy, int actionPoints);
};

