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
	// Reload to set the Weapons Ammo to MaxMag at start of combat
	player.GetWeapon().reload();

	// Combat encounter is active
	inCombat_ = true;

	// Turn counter
	int turnCount = 1;

	// Outter Combat Loop
	while (inCombat_)
	{
		Weapon& weapon = player.GetWeapon();
		int reloadCost = weapon.GetReloadCost();

		std::vector<std::string> options = 
		{ 
			"Attack", 
			"Reload: " + std::to_string(reloadCost) + " AP",
			"End Turn", 
			"Leave Range" };

		int actionPoints = 4;
		bool turnEnded = false;

		// Players turn
		while (!turnEnded && inCombat_)
		{
			combatStats(player, enemy, actionPoints, turnCount);
			int choice = ui_.menuHandler("          Combat Actions", options);

			switch (choice)
			{
			case 1:
				weaponActions(player, enemy, actionPoints);

				if (!enemy.isAlive())
				{
					ui_.border();
					std::cout << "Target destroyed on turn " << turnCount << std::endl;
					ui_.border();
					ui_.EnterToContinue();
					inCombat_ = false;
				}
				break;

			case 2:
				// Reload action
				if (weapon.GetCurrentMag() >= weapon.GetMagCap())
				{
					ui_.border();
					std::cout << "Magazine is already full of ammo." << std::endl;
					ui_.border();
				}
				else if (actionPoints < reloadCost)
				{
					ui_.border();
					std::cout << "Not enough action points left to reload." << std::endl;
					ui_.border();
				}
				else
				{
					weapon.reload();
					actionPoints -= reloadCost;

					ui_.border();
					std::cout << "You eject the current magazine of \nyour " << weapon.GetName() << " and insert a new one." << std::endl;
					ui_.border();
				}

				ui_.EnterToContinue();
				break;

			case 3:
				// End turn.
				turnEnded = true;
				break;

			case 4:
				// Leave the Range
				inCombat_ = false;
				break;

			default:
			break;
			}
		}

		// Add one to turn count
		if (inCombat_)
		{
			ui_.border();
			std::cout << "End of turn " << turnCount << "." << std::endl;
			ui_.border();
			ui_.EnterToContinue();

			turnCount += 1;
		}
		else
		{
			ui_.border();
			std::cout << "Combat Practice Over." << std::endl;
			ui_.border();
			ui_.EnterToContinue();
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
	std::string wepName = player.GetWeapon().GetName();

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

	if (player.GetWeapon().GetCurrentMag() <= 0)
	{
		std::cout << "You clench the trigger- Click!\n" << "Your magazine appears to be empty." << std::endl;
		ui_.EnterToContinue();
		return;
	}

	actionPoints -= apCost;

	for (int shot = 0; shot < shots && enemy.isAlive(); shot++)
	{
		if (player.GetWeapon().GetCurrentMag() <= 0)
		{
			std::cout << "Your " << wepName << " has stopped firing\n" << "It ran out of boolets." << std::endl;
			break;
		}

		player.GetWeapon().useBoolet();

		std::cout << "Shot " << shot + 1 << ": ";
		playerAttack(player, enemy, accBonus);
	}

	ui_.EnterToContinue();
}

//void Combat::enemyTurn(Player& player, Enemy& enemy)
//{
//	/*playerTakeDamage(player, 30);*/
//
//	if (!player.isAlive())
//	{
//		inCombat_ = false;
//	}
//}

void Combat::combatStats(const Player& player, const Enemy& enemy, int actionPoints, int turnCount)
{
	ui_.border();

	/*std::cout << "Player HP: " << player.GetHealth() << "/" << player.GetMaxHealth() << "\n";*/

	const Weapon& weapon = player.GetWeapon();
	std::cout << "Weapon: " << weapon.GetName() << "  |  ";
	std::cout << "Ammo: " << weapon.GetCurrentMag() << "/" << weapon.GetMagCap() << "\n";
	std::cout << "Enemy HP: " << enemy.GetHealth() << "/" << enemy.GetMaxHealth() << "  |  ";
	std::cout << "Enemy Armor:" << enemy.GetArmor() << "\n";
	std::cout << "\nAction Points Remaining: " << actionPoints << "\n";
	std::cout << "Turn: " << turnCount << "\n";
}
