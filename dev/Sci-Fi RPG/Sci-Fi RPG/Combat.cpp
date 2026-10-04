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
	// Combat encounter is active
	inCombat_ = true;

	while (inCombat_)
	{
		int actionPoints = 4;

		while (actionPoints > 0 && inCombat_)
		{
			ui_.clearScreen();
			ui_.combatStats(player, enemy);
			ui_.combatMenu();
			int choice = ui_.userChoice();

			switch (choice)
			{
			case 1:
				// Attack costs 1 AP.
				enemyTakeDamage(enemy, 30);
				actionPoints -= 1;

				if (!enemy.isAlive())
				{
					inCombat_ = false;
				}
				break;

			case 2:
				// Attack type 2 - not implemented yet
				break;

			case 3:
				// Attack type 3 - not implemented yet
				break;

			case 4:
				// End turn.
				actionPoints = 0;
				return;

			default:
				ui_.invalidChoice();
				break;
			}
		}
	}
}
