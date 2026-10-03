#include "UI.h"
#include <iostream>

void UI::border()
{
	std::cout << "==================================================" << std::endl;
}

void UI::mainMenu()
{
	border();

	std::cout << "Main Menu: \n" << "[1] New Game\n" << "[2] Load Game\n" << "[3] Credits \n" << "[4] Exit: \n\n" << "Choice: ";
}
