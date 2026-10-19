#include "Weapon.h"


Weapon::Weapon()
{
	// Weapon identity
	wpnName_ = "AK-47";
	wpnBase_ = WeaponBase::Rifle;

	// Weapon Parts
	wpnBarrel_ = Barrel::Rifle;

	// Weapon stats
	dmg_ = 35;
	armP_ = 55;
	acc_ = 76;
	wt_ = 20;
	magCap_ = 30;
	wpnRelCo_ = 1;
	frMode_ = { FireMode::Semi, FireMode::Auto };

	curMag_ = 30;
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

// Weapon Part Setters
void Weapon::SetBarrel(Barrel newBarrel_)
{
	wpnBarrel_ = newBarrel_;

	RecalculateStats();
}

// Weapon functions
void Weapon::RecalculateStats()
{
	dmg_ = 25;
	acc_ = 94;
	armP_ = 45;
	wt_ = 17;

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

	SelectBarrel();

	std::vector<std::string> options = 
	{ "Change Base", "Change Barrel", "Change caliber", "Change sight", "Change muzzle", "Change stock", "Change Fire Selector", "Change Magazine", "Confirm", "Cancel"};

	while (true)
	{
		ui_.clearScreen();
		ui_.border();
		int accPercent = 101 - acc_;

		std::cout << "Weapon: " << wpnName_ << std::endl;
		std::cout << "Damage: " << dmg_ << std::endl;
		std::cout << "Base Hit Chance: " << accPercent << "%" << std::endl;
		std::cout << "Armor Pen: " << armP_ << std::endl;
		std::cout << "Weight: " << wt_ << std::endl;
		std::cout << "Mag size: " << magCap_ << std::endl;
		std::cout << "Reload Cost: " << wpnRelCo_ << " AP" << std::endl;

		int choice = ui_.menuHandler("             Weapon Review", options);

		switch (choice)
		{
			// Base
		case 1:
			
			break;
			// Barrel
		case 2:
			SelectBarrel();
			break;
			// Caliber
		case 3:
			
			break;
			// Sight
		case 4:
			
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
