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

void Game::newGame()
{
	Player player;
	Enemy enemy;
	Combat combat;

	combat.startBattle(player, enemy);
}

void Game::handleMainMenu()
{
	int choice = ui_.userChoice();

	switch (choice)
	{
	case 1:
		// Start new game
		newGame();
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
			// Attack type 2
			break;

		case 3:
			// Attack type 3
			break;

		case 4:
			// Stop main loop and return to menu
			Start();
			break;

		default:
			// Invalid user choice, display invalid choice message.
			ui_.invalidChoice();
			break;
		}
	}
}