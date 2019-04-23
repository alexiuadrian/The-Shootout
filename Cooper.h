#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include "Coordonata.h"

class Cooper : public Player {
public:
	Cooper();
	~Cooper();
	int getMovement();
	void die();
	int getRange();
	int getSymbol();
	Coordonata* shoot(int&);
	void Move(int, int);

private:
	int movement;
	int range;
	int symbol;
};

