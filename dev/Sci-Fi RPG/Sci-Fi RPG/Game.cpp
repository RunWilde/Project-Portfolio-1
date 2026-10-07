#include "Game.h"
// Dev Branch sheez

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