#include "Game.h"
#include <string>
#include <vector>
#include <random>

void Game::Start()
{
	while (running_) 
	{
		handleMainMenu();
	}
}

void Game::newGame()
{
	Enemy enemy;
	Combat combat;

	combat.startBattle(player_, enemy);
}

void Game::handleMainMenu()
{
	std::vector<std::string> options = { "Customize Weapon", "Load Weapon", "Enter Firing Range", "Exit" };

	int choice = ui_.menuHandler("             Main Menu", options);

	switch (choice)
	{
	case 1:
	{
		// Customize weapon
		Weapon customWeapon = player_.GetWeapon();

		// Add weapon to the player once customization is done.
		if (customWeapon.Customize())
		{
			player_.GetWeapon() = customWeapon;
		}

		break;
	}
	case 2:
		// Load saved Weapon
		break;

	case 3:
		// Enter the firing range
		newGame();
		break;

	case 4:
		// Stop main loop and exit application
		running_ = false;
		break;

	default:
		break;
	}


}
