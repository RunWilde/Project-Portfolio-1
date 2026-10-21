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

	ui_.clearScreen();
	ui_.border();
	std::cout << "Configure Enemy Health/Armor" << std::endl;
	ui_.border();
	ui_.EnterToContinue();

	int health;
	int armor;

	while (true)
	{
		ui_.border();
		std::cout << "Enter a value for the Enemy's health.\n" << "Select a value between 0 - 10000:" <<std::endl;
		std::cin >> health;
		
		if (health <= 0 || health > 10000)
		{
			ui_.border();
			std::cout << "Please enter a value above 0 and below 10000." << std::endl;
			ui_.border();
			ui_.EnterToContinue();
			continue;
		}
		else
		{
			enemy.SetMaxHealth(health);
			enemy.SetHealth(health);
			break;
		}
	}

	ui_.clearScreen();
	while (true)
	{
		ui_.border();
		std::cout << "Enter a value for the Enemy's armor.\n" << "Select a value between 0 - 100:" << std::endl;
		std::cin >> armor;

		if (armor <= 0 || armor > 100)
		{
			ui_.border();
			std::cout << "Please enter a value above 0 and below 100." << std::endl;
			ui_.border();
			ui_.EnterToContinue();
			continue;
		}
		else
		{
			enemy.SetArmor(armor);
			break;
		}
	}

	ui_.clearScreen();
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
