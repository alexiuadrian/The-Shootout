#pragma once
#include "Player.h"

class Cooper : public Player {
public:
	Cooper();
	~Cooper();
	virtual int getMovement();
	virtual void die();
	virtual int getRadius();
private:
	int movement;
	int radius;
};

