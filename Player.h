#pragma once
class Player {
public:
	Player();
	~Player();
	int getPositionX();
	int getPositionY();
	void setPositionX(int);
	void setPositionY(int);
	int getRadius();
	virtual void Move(int);
	void die();
private:
	int positionX, positionY;
};

