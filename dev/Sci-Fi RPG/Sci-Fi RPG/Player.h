#pragma once
#include "Weapon.h"

class Player
{
private:

	int maxHealth_;
	int health_;
	int armor_;

	int Mig_;
	int Agi_;
	int End_;
	int Int_;
	int Cha_;

	Weapon weapon_;

public:
	Player();

	int GetHealth() const;
	int GetMaxHealth() const;
	int GetArmor() const;

	int GetMight() const;
	int GetAgility() const;
	int GetEndurance() const;
	int GetIntelligence() const;
	int GetCharisma() const;

	void SetHealth(int value);

	bool isAlive() const;

	Weapon& GetWeapon();

};

