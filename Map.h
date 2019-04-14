#pragma once
#include "Cooper.h"
#include "Marshall.h"


class Map : public Player
{
public:
	Map();
	~Map();
	void show();
	void Update();
	void Move();
private:
	int** m;
	Cooper* _C;
	Marshall* _M;
};