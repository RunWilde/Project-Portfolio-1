#pragma once
#include <string>
#include <vector>

// This defines the actual firemodes possible for a weapon
enum class FireMode
{
	Semi,Burst,Auto
};
// This Defines the weapon's base, so what it is at it's core.
// Mainly using this to calculate a weapons accuracy threshold/starting numbers. Still WIP
enum class WeaponBase
{
	Pistol,Rifle
};

enum class Barrel
{
	CompactSMG, SMG, CompactCarbine, Carbine, Rifle, LongRifle
};

class Weapon
{

private:
	// Weapon Identity
	std::string wpnName_;
	WeaponBase wpnBase_;

	//Weapon Parts
	Barrel wpnBarrel_;

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

	void RecalculateStats();
public:

	Weapon();

	std::string GetName() const;
	WeaponBase GetBase() const;

	// Weapon Stat getters
	int GetDamage() const;
	int GetArmorPen() const;
	int GetAccuracy() const;
	int GetWeight() const;
	int GetMagCap()  const;
	int GetReloadCost() const;
	int GetCurrentMag() const;

	// Weapon part getters/setters

	void SetBarrel(Barrel wpnBarrel_);

	void useBoolet();
	void reload();
	std::vector<FireMode> GetFireModes() const;
};

