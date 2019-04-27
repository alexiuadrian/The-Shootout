#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "Coordonata.h"

class Chris : public Player {
public:
	Chris();
	~Chris();
	Chris(const Chris&);
	int getMovement();
	int getRange();
	void die();
	int getSymbol();
	void Move(int, int, bool);
	Coordonata* shoot(int&);
	bool getArmor();

private:
	int movement;
	int range;
	int symbol;
	bool armor;
};

