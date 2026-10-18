#pragma once
#include "UI.h"
#include "Combat.h"
#include "Player.h"

class Game
{
private:
	UI ui_;
	bool running_ = true;
	Player player_;

public:
	
	void Start();
	void newGame();
	void handleMainMenu();
};

