#pragma once
#include "Player.h"
#include <time.h>
#include <stdlib.h>
#include "Coordonata.h"

class Cooper : public Player {
public:
	Cooper();
	~Cooper();
	Cooper(const Cooper&);
	int getMovement();
	void die();
	int getRange();
	int getSymbol();
	Coordonata* shoot(int&);
	void Move(int, int, bool);
	bool getArmor();

private:
	int movement;
	int range;
	int symbol;
	bool armor;
};

