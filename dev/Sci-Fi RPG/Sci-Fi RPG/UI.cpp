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

void UI::combatMenu()
{
	border();

	std::cout << "Combat Menu: \n" << "[1] Fire Semi Shot\n" << "[2] Return to Main Menu \n";
}

