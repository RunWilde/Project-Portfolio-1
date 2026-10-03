#pragma once
class Enemy
{
private:

	int maxHealth_;
	int health_;
	int armor_;

public:
	Enemy();

	int GetHealth() const;
	int GetMaxHealth() const;
	int GetArmor() const;

	void SetHealth(int value);

	bool isAlive() const;
};

