#pragma once
#include "Map.h"
#include "Player.h"
#include "Cooper.h"
#include "Marshall.h"

class Simulation {

public:
	Simulation();
	~Simulation();
	void NextRound();
	void show();

private:
	Map _MAP;
	Cooper _C;
	Marshall _M;

};