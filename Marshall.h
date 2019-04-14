#pragma once
#include "Player.h"

class Marshall : public Player {
public:
	Marshall();
	~Marshall();
	virtual int getMovement();
	virtual int getRadius();
	virtual void die();
private:
	int movement;
	int radius;
};

