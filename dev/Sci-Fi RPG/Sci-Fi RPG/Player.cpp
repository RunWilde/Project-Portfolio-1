#include "Player.h"

Player::Player()
{
	maxHealth_ = 200;
	health_ = 200;
	armor_ = 10;
}

int Player::GetHealth() const{ return health_; }
int Player::GetMaxHealth() const { return maxHealth_; }
int Player::GetArmor() const{ return armor_; }

int Player::GetMight() const{ return Mig_; }
int Player::GetAgility() const{ return Agi_; }
int Player::GetEndurance() const{ return End_; }
int Player::GetIntelligence() const{ return Int_; }
int Player::GetCharisma() const{ return Cha_; }


void Player::SetHealth(int value) { health_ = value; }

bool Player::isAlive() const
{
	bool living;

	if (health_ > 0)
	{ living = true; }
	else { living = false; }

	return living;
}

Weapon& Player::GetWeapon()
{
	return weapon_;
}

const Weapon& Player::GetWeapon() const
{
	return weapon_;
}


