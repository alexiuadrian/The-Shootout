#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>

class Cooper : public Player {
public:
	Cooper();
	~Cooper();
	int getMovement();
	void die();
	int getRange();
	int getSymbol();
	void shoot(int&, int&, int&, int&);
	void Move();

private:
	int movement;
	int range;
	int symbol;
};

