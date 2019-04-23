#pragma once
#include "Player.h"
#include "Coordonata.h"

class Map {
public:
	Map();
	~Map();
	void show();
	void update(Player&, int);
	int check(Coordonata*, int nrEl);

private:
	int** m;

};
