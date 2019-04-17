#pragma once
class Player {
public:
	Player();
	~Player();
	int getPositionX();
	int getPositionY();
	void setPositionX(int);
	void setPositionY(int);
	virtual int getMovement();
	virtual int getRadius();
	virtual void Move(int);
	virtual void die();
	virtual int getSymbol();
	//int setSymbol(int);
private:
	int positionX;
	int positionY;
	int symbol;
};

