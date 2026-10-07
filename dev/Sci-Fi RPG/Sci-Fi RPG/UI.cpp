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

int UI::userChoice()
{
	int choice = 0;

	std::cin >> choice;

	return choice;
}

void UI::invalidChoice()
{
	std::cout << "Invalid choice.\n";
}

void UI::mainMenu()
{
	border();

	std::cout << "Main Menu: \n" << "[1] New Game\n" << "[2] Load Game\n" << "[3] Credits \n" << "[4] Exit \n\n" << "Choice: ";

}



// ====================
// Combat Section of UI
// ====================

void UI::combatStats(const Player& player, const Enemy& enemy, int actionPoints)
{
	border();

	std::cout << "Player HP: " << player.GetHealth() << "/" << player.GetMaxHealth() << "\n";
	std::cout << "Enemy HP: " << enemy.GetHealth() << "/" << enemy.GetMaxHealth() << "\n";
	std::cout << "\nAction Points Remaining: " << "\n";
}

void UI::combatMenu()
{
	border();

	std::cout << "Combat Menu: \n" << "[1] Attack: 1 AP\n" << "[2] Action 2\n" << "[3] Action 3\n" << "[4] Return to Main Menu \n";
}

