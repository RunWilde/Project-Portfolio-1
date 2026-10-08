#include "Game.h"
#include <string>
#include <vector>

void Game::Start()
{
	while (running_) 
	{
		handleMainMenu();
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
	std::vector<std::string> options = { "New Game", "Load Game", "Credits", "Exit" };

	int choice = ui_.menuHandler("Main Menu", options);

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
		break;
	}
}