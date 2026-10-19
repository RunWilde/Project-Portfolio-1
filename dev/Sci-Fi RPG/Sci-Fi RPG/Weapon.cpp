#include "Weapon.h"


Weapon::Weapon()
{
	// Weapon identity
	wpnName_ = "AK-47";
	wpnBase_ = WeaponBase::Rifle;

	// Weapon Parts
	wpnBarrel_ = Barrel::Rifle;
	wpnCaliber_ = Caliber::c762x39;

	// Weapon stats
	magCap_ = 30;
	wpnRelCo_ = 1;
	frMode_ = { FireMode::Semi, FireMode::Auto };

	curMag_ = 30;

	RecalculateStats();
}

// Weapon Identity Getters
std::string Weapon::GetName() const
{
	return wpnName_;
}

WeaponBase Weapon::GetBase() const
{
	return wpnBase_;
}

// Weapon Stat Getters
int Weapon::GetDamage() const
{
	return dmg_;
}

int Weapon::GetArmorPen() const
{
	return armP_;
}

int Weapon::GetAccuracy() const
{
	return acc_;
}

int Weapon::GetWeight() const
{
	return wt_;
}

int Weapon::GetMagCap() const
{
	return magCap_;
}

int Weapon::GetReloadCost() const
{
	return wpnRelCo_;
}

int Weapon::GetCurrentMag() const
{
	return curMag_;
}

void Weapon::SetWpnBase(WeaponBase newBase_)
{
	wpnBase_ = newBase_;

	RecalculateStats();
}

// Weapon Part Setters
void Weapon::SetBarrel(Barrel newBarrel_)
{
	wpnBarrel_ = newBarrel_;

	RecalculateStats();
}

void Weapon::SetCaliber(Caliber newCaliber_)
{
	wpnCaliber_ = newCaliber_;

	RecalculateStats();
}

void Weapon::SetSight(Sight newSight_)
{
	wpnSight_ = newSight_;

	RecalculateStats();
}

// Weapon functions
void Weapon::RecalculateStats()
{
	// Temporary Values to make up for missing attatcments and to reset values to default
	dmg_ = 0;
	armP_ = 0;
	wt_ = 15;
	// Stock stats standin here
	acc_ -= 6;

	// Weapon Base here, Starting accuracy threshold
	switch (wpnBase_)
	{
	case WeaponBase::Pistol:
		acc_ = 55;
		break;

	case WeaponBase::Rifle:
		acc_ = 100;
		break;

	}

	// CompactSMG, SMG, CompactCarbine, Carbine, Rifle, LongRifle
	switch (wpnBarrel_)
	{
	case Barrel::CompactSMG:
		dmg_ += 5;
		acc_ -= 5;
		armP_ += 0;
		wt_ += 1;
		break;

	case Barrel::SMG:
		dmg_ += 5;
		acc_ -= 8;
		armP_ += 1;
		wt_ += 1;
		break;

	case Barrel::CompactCarbine:
		dmg_ += 10;
		acc_ -= 10;
		armP_ += 5;
		wt_ += 2;
		break;

	case Barrel::Carbine:
		dmg_ += 10;
		acc_ -= 15;
		armP_ += 2;
		wt_ += 2;
		break;

	case Barrel::Rifle:
		dmg_ += 10;
		acc_ -= 18;
		armP_ += 10;
		wt_ += 3;
		break;

	case Barrel::LongRifle:
		dmg_ += 15;
		acc_ -= 20;
		armP_ += 5;
		wt_ += 4;
		break;

	}

	// Caliber here
	switch (wpnCaliber_)
	{
	case Caliber::c9x19mm:
		dmg_ += 30;
		armP_ += 0;
		wt_ += 1;
		break;
	case Caliber::c45ACP:
		dmg_ += 35;
		armP_ += 0;
		wt_ += 1;
		break;
	case Caliber::c357:
		dmg_ += 40;
		armP_ += 5;
		wt_ += 1;
		break;
	case Caliber::c44:
		dmg_ += 45;
		armP_ += 10;
		wt_ += 2;
		break;
	case Caliber::c545x39:
		dmg_ += 30;
		armP_ += 20;
		wt_ += 2;
		break;
	case Caliber::c556x45:
		dmg_ += 35;
		armP_ += 30;
		wt_ += 2;
		break;
	case Caliber::c762x39:
		dmg_ += 25;
		armP_ += 45;
		wt_ += 2;
		break;
	case Caliber::c762x51:
		dmg_ += 30;
		armP_ += 50;
		wt_ += 3;
		break;
	}

	// Sight here                
	switch (wpnSight_)
	{
	case Sight::irons:
		acc_ -= 0;
		wt_ += 0;
		break;
	case Sight::reddot:
		acc_ -= 3;
		wt_ += 1;
		break;
	case Sight::magreddot:
		acc_ -= 5;
		wt_ += 2;
		break;
	case Sight::midrange:
		acc_ -= 7;
		wt_ += 3;
		break;
	case Sight::longrange:
		acc_ -= 10;
		wt_ += 4;
		break;
	}
}

void Weapon::SelectWpnBase()
{
	UI ui_;

	std::vector<std::string> options = { "Pistol", "Rifle", "Back"};

	while (true)
	{
		int choice = ui_.menuHandler("Weapon Base", options);

		switch (choice)
		{
		case 1:
			SetWpnBase(WeaponBase::Pistol);
			return;
		case 2:
			SetWpnBase(WeaponBase::Rifle);
			return;
		case 3:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectBarrel()
{
	UI ui_;

	std::vector<std::string> options = { "Compact SMG", "SMG", "Compact Carbine", "Carbine", "Rifle", "Long Rifle", "Back" };
	
	while (true)
	{
		int choice = ui_.menuHandler("             Barrel Type", options);

		switch (choice)
		{
		case 1:
			SetBarrel(Barrel::CompactSMG);
			return;

		case 2:
			SetBarrel(Barrel::SMG);
			return;

		case 3:
			SetBarrel(Barrel::CompactCarbine);
			return;

		case 4:
			SetBarrel(Barrel::Carbine);
			return;

		case 5:
			SetBarrel(Barrel::Rifle);
			return;

		case 6:
			SetBarrel(Barrel::LongRifle);
			return;

		case 7:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectCaliber()
{
	UI ui_;

	std::vector<std::string> options = { "9x19mm", ".45 ACP", ".357", ".44", "5.45x39mm", "5.56x45mm", "7.62x39mm", "7.62x51mm", "Back" };

	while (true)
	{
		int choice = ui_.menuHandler("             Caliber", options);

		switch (choice)
		{
		case 1:
			SetCaliber(Caliber::c9x19mm);
			return;

		case 2:
			SetCaliber(Caliber::c45ACP);
			return;

		case 3:
			SetCaliber(Caliber::c357);
			return;

		case 4:
			SetCaliber(Caliber::c44);
			return;

		case 5:
			SetCaliber(Caliber::c545x39);
			return;

		case 6:
			SetCaliber(Caliber::c556x45);
			return;

		case 7:
			SetCaliber(Caliber::c762x39);
			return;

		case 8:
			SetCaliber(Caliber::c762x51);
			return;

		case 9:
			return;

		default:
			break;
		}
	}
}

void Weapon::SelectSight()
{
	UI ui_;

	std::vector<std::string> options = { "Irons", "Red Dot", "Magnified Red Dot", "Mid Range Optic", "Long Range Optic", "Back" };

	while (true)
	{
		int choice = ui_.menuHandler("             Sight Type", options);

		switch (choice)
		{
		case 1:
			SetSight(Sight::irons);
			return;

		case 2:
			SetSight(Sight::reddot);
			return;

		case 3:
			SetSight(Sight::magreddot);
			return;

		case 4:
			SetSight(Sight::midrange);
			return;

		case 5:
			SetSight(Sight::longrange);
			return;

		case 6:
			return;

		default:
			break;
		}
	}
}

void Weapon::useBoolet()
{
	if (curMag_ > 0)
	{
		curMag_--;
	}
}

void Weapon::reload()
{
	curMag_ = magCap_;
}

std::vector<FireMode> Weapon::GetFireModes() const
{
	return frMode_;
}

bool Weapon::Customize()
{
	UI ui_;

	std::vector<std::string> options = 
	{ "Change Base", "Change Barrel", "Change caliber", "Change sight", "Change muzzle", "Change stock", "Change Fire Selector", "Change Magazine", "Confirm", "Cancel"};

	while (true)
	{
		ui_.clearScreen();
		ui_.border();
		std::cout << "            Weapon Stats" << std::endl;
		ui_.border();
		int accPercent = 101 - acc_;

		std::cout << "Weapon: " << wpnName_ << std::endl;
		std::cout << "Damage: " << dmg_ << std::endl;
		std::cout << "Base Hit Chance: " << accPercent << "%" << std::endl;
		std::cout << "Armor Pen: " << armP_ << std::endl;
		std::cout << "Weight: " << wt_ << std::endl;
		std::cout << "Mag size: " << magCap_ << std::endl;
		std::cout << "Reload Cost: " << wpnRelCo_ << " AP" << std::endl;

		int choice = ui_.menuHandler("         Weapon Parts List", options);

		switch (choice)
		{
			// Base
		case 1:
			SelectWpnBase();
			break;
			// Barrel
		case 2:
			SelectBarrel();
			break;
			// Caliber
		case 3:
			SelectCaliber();
			break;
			// Sight
		case 4:
			SelectSight();
			break;
			// Muzzle
		case 5:

			break;
			// stock
		case 6:

			break;
			// Fire Selector
		case 7:

			break;
			// Magazine
		case 8:
			
			break;

		case 9:
			return true;

		case 10:
			return false;

		default:
			break;
		}
	}
}
