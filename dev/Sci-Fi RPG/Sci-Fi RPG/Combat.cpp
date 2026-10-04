#include "Combat.h"

void Combat::playerTakeDamage(Player& target, int damage)
{
	int hp = target.GetHealth();

	hp -= damage;

	target.SetHealth(hp);
}

void Combat::enemyTakeDamage(Enemy& target, int damage)
{
	int hp = target.GetHealth();

	hp -= damage;

	target.SetHealth(hp);
}

void Combat::startBattle(Player& player, Enemy& enemy)
{
	while (inCombat_) {
		ui_.clearScreen();
		ui_.combatStats(player, enemy);
		ui_.combatMenu();
		int choice = ui_.userChoice();

		if (!enemy.isAlive())
		{
			inCombat_ = false;
		}

		switch (choice)
		{
		case 1:
			// Attack type 1
			enemyTakeDamage(enemy, 30);
			break;

		case 2:
			// Attack type 2
			break;

		case 3:
			// Attack type 3
			break;

		case 4:
			// Stop main loop and return to menu
			return;

		default:
			// Invalid user choice, display invalid choice message.
			ui_.invalidChoice();
			break;
		}
	}
}
