#pragma once
#include "UI.h"
#include "Combat.h"

class Game
{
private:
	UI ui_;
	bool running_ = true;

public:
	
	void Start();
	void newGame();
	void handleMainMenu();

};

