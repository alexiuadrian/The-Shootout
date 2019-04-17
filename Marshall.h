#pragma once
#include "Player.h"

class Marshall : public Player {
public:
	Marshall();
	~Marshall();
	int getMovement();
	int getRadius();
	void die();
	int getSymbol();
private:
	int movement;
	int radius;
	int symbol;
};

