#pragma once
#include <string>
#include <vector>

// This define the actual firemodes possible for a weapon
enum class FireMode
{
	Semi,
	Burst,
	Auto
};

class Weapon
{

private:
	// Weapon Identity
	std::string WpnName_;
	int WpnBaseType_;

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

};

