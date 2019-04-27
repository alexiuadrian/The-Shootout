#pragma once
#include "Map.h"
#include "Player.h"
#include "Cooper.h"
#include "Marshall.h"
#include "Chris.h"
#include "Coordonata.h"

class Simulation {

public:
	Simulation(int);
	~Simulation();
	Simulation(const Simulation&);
	void show();
	bool check(int); //functia verifica daca moare un agent
	bool NextRound(int);

private:
	Map _MAP;
	Cooper _C;
	Marshall _M;
    Chris _CH;
};
