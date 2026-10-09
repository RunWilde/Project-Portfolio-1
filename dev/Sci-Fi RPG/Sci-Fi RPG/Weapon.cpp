#include "Weapon.h"

Weapon::Weapon()
{
	wpnName_ = "AK-47";
	wpnBase_ = WeaponBase::Rifle;

	dmg_ = 35;
	armP_ = 55;
	acc_ = 76;
	wt_ = 20;
	magCap_ = 30;
	wpnRelCo_ = 1;
	frMode_ = { FireMode::Semi, FireMode::Auto };

	curMag_ = 30;
}

std::string Weapon::GetName() const
{
	return wpnName_;
}

WeaponBase Weapon::GetBase() const
{
	return wpnBase_;
}

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

std::vector<FireMode> Weapon::GetFireModes() const
{
	return frMode_;
}
