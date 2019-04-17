#pragma once
#include "Player.h"

class Cooper : public Player {
public:
	Cooper();
	~Cooper();
	int getMovement();
	void die();
	int getRadius();
	int getSymbol();
private:
	int movement;
	int radius;
	int symbol;
};

