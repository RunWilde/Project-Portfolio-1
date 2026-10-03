#include "Game.h"

void Game::Start()
{
	ui_.mainMenu();
	handleMainMenu();
}

void Game::handleMainMenu()
{
	int choice = ui_.userChoice();

	switch (choice)
	{
	case 1:
		// Start new game
		break;

	case 2:
		// Load saved game
		break;

	case 3:
		// Display credits and then return to main menu
		break;

	case 4:
		// Stop main loop and exit application
		running_ = false;
		break;

	default:
		// Invalid user choice, display invalid choice message.
		break;
	}
}
