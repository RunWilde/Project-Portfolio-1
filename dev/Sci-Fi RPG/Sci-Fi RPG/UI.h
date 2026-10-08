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

	int menuHandler(const std::string& menuTitle, const std::vector<std::string>& menuOptions);
	void mainMenu();
	void combatStats(const Player& player, const Enemy& enemy, int actionPoints);
	void combatMenu();
	
};

