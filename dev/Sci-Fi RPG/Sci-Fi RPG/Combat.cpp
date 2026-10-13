#include "Combat.h"

void Combat::playerAttack(Player& player, Enemy& target)
{

	unsigned int hp = target.GetHealth();
	unsigned int damage = player.GetWeapon().GetDamage();
	unsigned int armor = target.GetArmor();
	unsigned int accPlay = player.GetAgility();
	unsigned int accGun = player.GetWeapon().GetAccuracy();
	unsigned int apGun = player.GetWeapon().GetArmorPen();

	
	int hit = d100_ + accPlay;

	if (hit > accGun)
	{
		// Damage calculation: 
		// Health - ((Armor pen - Armor) - Damage) = new Health
		hp -= ((apGun - armor) - damage);

		target.SetHealth(hp);

		// Display to console enemy hit for x amount of damage
		std::cout << "Enemy hit for" 
		// if damage == 0, Display to console, enemy armor is too high
	}
	else{ // Display to console, miss}
	


	//int hp = target.GetHealth();

	//hp -= damage;

	//target.SetHealth(hp);
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
