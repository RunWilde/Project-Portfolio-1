#include "UI.h"
#include <iostream>

void UI::border()
{
	std::cout << "==================================================" << std::endl;
}

void UI::clearScreen()
{
	system("cls");
}

void UI::EnterToContinue()
{
	std::cout << "Press enter to continue...";
	std::cin.get();
	clearScreen();
}

int UI::menuHandler(const std::string& menuTitle, const std::vector<std::string>& menuOptions)
{
	int choice = 0;
	std::string tempChoice;

	border();
	std::cout << menuTitle << std::endl;
	border();

	for (int i = 0; i < menuOptions.size(); i++)
	{
		std::cout << "[" << i + 1 << "] " << menuOptions[i] << std::endl;
	}

	
	std::cout << "Choice: ";
	std::getline(std::cin, tempChoice);

	// Checking user input for if it's a valid digit or out of range
	bool isValidNumber = !tempChoice.empty() && tempChoice.size() <= 2;

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
		choice = std::stoi(tempChoice);
		if (choice >= 1 && choice <= menuOptions.size())
		{
			clearScreen();
			return choice;
		}
	}
	// Invalid Choice
	std::cout << "Invalid Choice, try again." << std::endl;
	EnterToContinue();
	return 0;

}

// ====================
// Combat Section of UI
// ====================

void UI::combatStats(const Player& player, const Enemy& enemy, int actionPoints)
{
	border();

	std::cout << "Player HP: " << player.GetHealth() << "/" << player.GetMaxHealth() << "\n";
	std::cout << "Enemy HP: " << enemy.GetHealth() << "/" << enemy.GetMaxHealth() << "\n";
	std::cout << "\nAction Points Remaining: " << actionPoints << "\n";
}

