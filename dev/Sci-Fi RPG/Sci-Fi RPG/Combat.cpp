#include "Combat.h"

void Combat::playerAttack(Player& player, Enemy& target, int accBonus)
{

	int hp = target.GetHealth();
	int gunDamage = player.GetWeapon().GetDamage();
	int armor = target.GetArmor();
	/*int accPlay = player.GetAgility();*/
	int accGun = player.GetWeapon().GetAccuracy();
	int apGun = player.GetWeapon().GetArmorPen();

	int hit = Math::dice(1, 100) + accBonus;

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
			combatStats(player, enemy, actionPoints);
			int choice = ui_.menuHandler("             Combat Menu", options);

			switch (choice)
			{
			case 1:
				weaponActions(player, enemy, actionPoints);

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

void Combat::weaponActions(Player& player, Enemy& enemy, int& actionPoints)
{
	std::vector<FireMode> fireModes = player.GetWeapon().GetFireModes();
	std::vector<std::string> options;

	for (int i = 0; i < fireModes.size(); i++)
	{
		switch (fireModes[i])
		{
		case FireMode::Semi:
			options.push_back("Semi: 1 AP (+10 Accuracy)");
			break;

		case FireMode::Burst:
			options.push_back("Burst: 2 AP");
			break;

		case FireMode::Auto:
			options.push_back("Full Auto: 3 AP (-10 Accuracy)");
			break;
		}
	}

	// Back to menu option here.
	options.push_back("Back");

	int choice = ui_.menuHandler("Attack Options", options);

	// Invalid input or Back returns to the combat menu.
	if (choice == 0 || choice == static_cast<int>(options.size()))
	{
		return;
	}

	FireMode selectedMode = fireModes[choice - 1];

	int apCost = 0;
	int shots = 0;
	int accBonus = 0;

	switch (selectedMode)
	{
	case FireMode::Semi:
		apCost = 1;
		shots = 1;
		accBonus = 10;
		break;

	case FireMode::Burst:
		apCost = 2;
		shots = 3;
		accBonus = 0;
		break;

	case FireMode::Auto:
		apCost = 3;
		shots = 10;
		accBonus = -10;
		break;
	}

	if (actionPoints < apCost)
	{
		std::cout << "Not enough action points left!" << std::endl;
		ui_.EnterToContinue();
		return;
	}

	actionPoints -= apCost;

	for (int shot = 0; shot < shots && enemy.isAlive(); shot++)
	{
		std::cout << "Shot " << shot + 1 << ": ";
		playerAttack(player, enemy, accBonus);
	}

	ui_.EnterToContinue();
}

void Combat::enemyTurn(Player& player, Enemy& enemy)
{
	/*playerTakeDamage(player, 30);*/

	if (!player.isAlive())
	{
		inCombat_ = false;
	}
}

void Combat::combatStats(const Player& player, const Enemy& enemy, int actionPoints)
{
	ui_.border();

	std::cout << "Player HP: " << player.GetHealth() << "/" << player.GetMaxHealth() << "\n";
	std::cout << "Enemy HP: " << enemy.GetHealth() << "/" << enemy.GetMaxHealth() << "\n";
	std::cout << "\nAction Points Remaining: " << actionPoints << "\n";
}
