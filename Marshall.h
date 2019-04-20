#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>

class Marshall : public Player {
public:
	Marshall();
	~Marshall();
	int getMovement();
	int getRange();
	void die();
	int getSymbol();
	void Move();

private:
	int movement;
	int range;
	int symbol;
};

