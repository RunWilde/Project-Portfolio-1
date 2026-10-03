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

void UI::mainMenu()
{
	border();

	std::cout << "Main Menu: \n" << "[1] New Game\n" << "[2] Load Game\n" << "[3] Credits \n" << "[4] Exit \n\n" << "Choice: ";

}

void UI::invalidChoice()
{
	std::cout << "Invalid choice.\n";
}

int UI::userChoice()
{
	int choice = 0;

	std::cin >> choice;

	return choice;
}

int UI::getMainMenuChoice()
{
	return 0;
}