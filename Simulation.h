#pragma once
#include "Map.h"
#include "Player.h"
#include "Cooper.h"
#include "Marshall.h"
#include "Coordonata.h"

class Simulation {

public:
	Simulation();
	~Simulation();
	void show();
	void check();
	void NextRound();

private:
	Map _MAP;
	Cooper _C;
	Marshall _M;

};
