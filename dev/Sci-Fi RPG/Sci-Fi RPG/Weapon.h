#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "UI.h"

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

enum class Caliber
{
	c9x19mm, c45ACP, c357, c44, c545x39, c556x45, c762x39, c762x51
};

enum class Sight
{
	irons, reddot, magreddot, midrange, longrange
};

class Weapon
{

private:
	// Weapon Identity
	std::string wpnName_;
	WeaponBase wpnBase_;

	//Weapon Parts
	Barrel wpnBarrel_;
	Caliber wpnCaliber_;
	Sight wpnSight_;
	

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
	void SelectWpnBase();
	void SelectBarrel();
	void SelectCaliber();
	void SelectSight();
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
	void SetWpnBase(WeaponBase newBase_);
	void SetBarrel(Barrel newBarrel_);
	void SetCaliber(Caliber newCaliber_);
	void SetSight(Sight newSight_);

	// Weapon Action Functions
	void useBoolet();
	void reload();
	std::vector<FireMode> GetFireModes() const;

	// Weapon Customizer Function here
	bool Customize();
};

