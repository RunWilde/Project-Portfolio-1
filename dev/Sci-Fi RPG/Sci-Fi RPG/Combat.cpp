#include "Combat.h"

void Combat::playerTakeDamage(Player& target, int damage)
{
	int hp = target.GetHealth();

	hp -= damage;

	target.SetHealth(hp);
}

void Combat::enemyTakeDamage(Player& player, Enemy& target)
{
	int hp = target.GetHealth();
	int damage = player.GetWeapon().GetDamage();

	hp -= damage;

	target.SetHealth(hp);
}

void Combat::startBattle(Player& player, Enemy& enemy)
{
	// Combat encounter is active
	inCombat_ = true;

	// Outter Combat Loop
	while (inCombat_)
	{
		std::vector<std::string> options = { "Semi Shot: 1 AP", "Attack 2", "Attack 3", "End Turn" };
		int actionPoints = 4;

		// Players turn
		while (actionPoints > 0 && inCombat_)
		{
			ui_.combatStats(player, enemy, actionPoints);
			int choice = ui_.menuHandler("Combat Menu", options);

			switch (choice)
			{
			case 1:
				// Attack costs 1 AP.
				enemyTakeDamage(player, enemy);
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
				break;

			default:
			break;
			}
		}

		// Enemy Turn
		if (inCombat_ && player.isAlive() && enemy.isAlive())
		{
				enemyTurn(player, enemy);
		}
	}
}

void Combat::enemyTurn(Player& player, Enemy& enemy)
{
	playerTakeDamage(player, 30);

	if (!player.isAlive())
	{
		inCombat_ = false;
	}
}
