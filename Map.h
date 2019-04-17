#pragma once
#include "Player.h"


class Map {
public:
	Map();
	~Map();
	void show();
	void update(Player&, int);
private:
	int** m;
	
};