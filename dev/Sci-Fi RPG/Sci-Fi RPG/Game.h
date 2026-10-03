#pragma once
#include "UI.h"

class Game
{
private:
	UI ui_;
	bool running_ = true;

public:
	
	void Start();
	void handleMainMenu();
};

