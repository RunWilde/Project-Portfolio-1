#include "Combat.h"

void Combat::playerAttack(Player& player, Enemy& target)
{

	int hp = target.GetHealth();
	int gunDamage = player.GetWeapon().GetDamage();
	int armor = target.GetArmor();
	int accPlay = player.GetAgility();
	int accGun = player.GetWeapon().GetAccuracy();
	int apGun = player.GetWeapon().GetArmorPen();

	// Don't forget to add player accuracy when implemented
	int hit = Math::dice(1, 100);

	if (hit >= accGun)
	{
		// Armor Pen removes armor, but excess pen doesn't add damage
		int effectiveArmor = armor - apGun;

		if (effectiveArmor < 0)
		{
			effectiveArmor = 0;
		}

		// Remaining armor reduces the weapon's damage
		int recievedDamage = gunDamage - effectiveArmor;

		if (recievedDamage < 0)
		{
			recievedDamage = 0;
		}

		// If armor blocks all damage, display to console
		if (recievedDamage == 0)
		{
			std::cout << "Your shot hit, but the enemy's armor blocked all damage!" << std::endl;
		}
		else 
		{
			hp -= recievedDamage;

			target.SetHealth(hp);

			std::cout << "Enemy hit for " << recievedDamage << " damage!" << std::endl;
		}
	}
	else { std::cout << "You missed!" << std::endl; } // Display to console, miss
}

void Combat::enemyAttack(Enemy& enemy, Player& target)
{
	//int hp = target.GetHealth();
	//int damage = player.GetWeapon().GetDamage();

	//hp -= damage;

	//target.SetHealth(hp);
}

void Combat::startBattle(Player& player, Enemy& enemy)
{
	// Combat encounter is active
	inCombat_ = true;

	// Outter Combat Loop
	while (inCombat_)
	{
		std::vector<std::string> options = { "Attack", "Action 2", "Action 3", "End Turn" };
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
				playerAttack(player, enemy);
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
	/*playerTakeDamage(player, 30);*/

	if (!player.isAlive())
	{
		inCombat_ = false;
	}
}
