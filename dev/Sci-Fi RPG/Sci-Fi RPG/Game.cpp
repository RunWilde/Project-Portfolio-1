#include "Game.h"

void Game::Start()
{
	while (running_) 
	{
		ui_.mainMenu();
		handleMainMenu();
		ui_.clearScreen();
	}
}

void Game::Combat()
{
	while (running_)
	{
		ui_.combatMenu();
		handleCombatMenu();
		ui_.clearScreen();
	}
}

void Game::handleMainMenu()
{
	int choice = ui_.userChoice();

	switch (choice)
	{
	case 1:
		// Start new game
		Combat();
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
		ui_.invalidChoice();
		break;
	}
}

void Game::handleCombatMenu()
{
	int choice = ui_.userChoice();
	{
		int choice = ui_.userChoice();

		switch (choice)
		{
		case 1:
			// Attack type 1
			break;

		case 2:
			// Stop loop and exit back to main menu
			Start();
			break;

		default:
			// Invalid user choice, display invalid choice message.
			ui_.invalidChoice();
			break;
		}
	}
}
