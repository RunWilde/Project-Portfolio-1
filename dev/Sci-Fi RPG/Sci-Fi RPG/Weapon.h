#pragma once
#include <string>
#include <vector>

// This defines the actual firemodes possible for a weapon
enum class FireMode
{
	Semi,
	Burst,
	Auto
};
// This Defines the weapon's base, so what it is at it's core.
// Mainly using this to calculate a weapons accuracy threshold. Still WIP
enum class WeaponBase
{
	Pistol,
	Rifle
};

class Weapon
{

private:
	// Weapon Identity
	std::string wpnName_;
	WeaponBase wpnBase_;

	// Weapon Properties
	int dmg_;
	int armP_;
	int acc_;
	int wt_;
	int magCap_;
	int wpnRelCo_;
	std::vector<FireMode> frMode_;

	// Current Magazine amount, just to define how many bullets the weapon has at current
	int curMag_;


public:

	Weapon();

	std::string GetName() const;
	WeaponBase GetBase() const;

	int GetDamage() const;
	int GetArmorPen() const;
	int GetAccuracy() const;
	int GetWeight() const;
	int GetMagCap()  const;
	int GetReloadCost() const;
	int GetCurrentMag() const;

	std::vector<FireMode> GetFireModes() const;
};

