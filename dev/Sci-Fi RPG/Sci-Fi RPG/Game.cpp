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

	int health = 0;
	int armor = 0;

	while (true)
	{
		ui_.border();
		std::cout << "Enter a value for the Enemy's health.\n" << "Select a value between 100 - 1000:" <<std::endl;
		
		std::string tempChoice;

		if (!std::getline(std::cin, tempChoice))
		{
			return;
		}

		bool isValidNumber = !tempChoice.empty() && tempChoice.size() <= 4;

		for (int i = 0; i < tempChoice.size(); i++)
		{
			if (tempChoice[i] < '0' || tempChoice[i] > '9')
			{
				isValidNumber = false;
				break;
			}
		}

		if (isValidNumber)
		{
			health = std::stoi(tempChoice);

			if (health >= 100 && health <= 1000)
			{
				enemy.SetMaxHealth(health);
				enemy.SetHealth(health);
				break;
			}
		}

		ui_.clearScreen();
		ui_.border();
		std::cout << "Please enter a number between 100 - 1000" << std::endl;
		ui_.border();
		ui_.EnterToContinue();
	}

	ui_.clearScreen();

	while (true)
	{
		ui_.border();
		std::cout << "Enter a value for the Enemy's armor.\n"
			<< "Select a value between 0 - 100:" << std::endl;

		std::string tempChoice;

		if (!std::getline(std::cin, tempChoice))
		{
			return;
		}

		bool isValidNumber =
			!tempChoice.empty() && tempChoice.size() <= 3;

		for (int i = 0; i < tempChoice.size(); i++)
		{
			if (tempChoice[i] < '0' || tempChoice[i] > '9')
			{
				isValidNumber = false;
				break;
			}
		}

		if (isValidNumber)
		{
			armor = std::stoi(tempChoice);

			if (armor >= 0 && armor <= 100)
			{
				enemy.SetArmor(armor);
				break;
			}
		}

		ui_.clearScreen();
		ui_.border();
		std::cout << "Please enter a whole number between 0 - 100."
			<< std::endl;
		ui_.border();
		ui_.EnterToContinue();
	}

	ui_.clearScreen();
	combat.startBattle(player_, enemy);
}

void Game::handleMainMenu()
{
	std::vector<std::string> options = { "Customize Weapon", "Enter Firing Range", "Exit" };

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
		// Enter the firing range
		newGame();
		break;

	case 3:
		// Stop main loop and exit application
		running_ = false;
		break;

	default:
		break;
	}


}
