#pragma once
#include "Weapon.h"

class Player
{
private:

	int maxHealth_;
	int health_;
	int armor_;

	Weapon weapon_;

public:
	Player();

	int GetHealth() const;
	int GetMaxHealth() const;
	int GetArmor() const;

	void SetHealth(int value);

	bool isAlive() const;

	Weapon& GetWeapon();

};

