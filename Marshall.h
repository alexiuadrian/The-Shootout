#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Coordonata.h"

class Marshall : public Player {
public:
	Marshall();
	~Marshall();
	int getMovement();
	int getRange();
	void die();
	int getSymbol();
	void Move(int, int, bool);
	Coordonata* shoot(int&);

private:
	int movement;
	int range;
	int symbol;
};

