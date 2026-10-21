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
	void SetMaxHealth(int value);
	void SetArmor(int value);

	bool isAlive() const;
};

