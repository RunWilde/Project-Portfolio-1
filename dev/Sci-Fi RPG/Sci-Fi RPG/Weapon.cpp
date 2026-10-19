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
	return false;
}
