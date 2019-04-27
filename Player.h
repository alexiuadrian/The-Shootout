#pragma once

class Player {
public:
	Player();
	~Player();
    Player(const Player&);
	int getPositionX();
	int getPositionY();
	void setPositionX(int);
	void setPositionY(int);
	virtual int getMovement();
	virtual int getRange();
	virtual void Move();
	virtual void die();
	virtual int getSymbol();
	virtual void shoot(int*, int*, int&, int&);

private:
	int positionX;
	int positionY;
	int symbol;
};

