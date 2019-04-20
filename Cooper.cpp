#include "Cooper.h"
#include <iostream>

Cooper::Cooper() {
	movement = 2;
	setPositionX(0);
	setPositionY(0);
	range = 5;
	symbol = 1;
}

Cooper::~Cooper() {

}

int Cooper::getMovement() {
	return movement;
}

int Cooper::getRange() {
	return range;
}

void Cooper::die() {
	setPositionX(25);
	movement = 0;
	range = 0;
}

int Cooper::getSymbol() {
	return symbol;
}

void Cooper::Move() {
	srand(time(NULL));
	int pos = rand() % 9;

	bool ok = false;

	while (!ok) {

		int pos = rand() % 9;

		switch (pos) {
		case 0: {

		}
			break;
		case 1: {
			if (this->getPositionX() - movement >= 0 && this->getPositionY() - movement >= 0) {
				this->setPositionX(this->getPositionX() - movement);
				this->setPositionY(this->getPositionY() - movement);
				ok = true;
			}
		}
				break;
		case 2: {
			if (this->getPositionX() - movement >= 0) {
				this->setPositionX(this->getPositionX() - movement);
				ok = true;
			}
		}
				break;
		case 3: {
			if (this->getPositionX() - movement >= 0 && this->getPositionY() + movement < 25) {
				this->setPositionX(this->getPositionX() - movement);
				this->setPositionY(this->getPositionY() + movement);
				ok = true;
			}
		}
				break;
		case 4: {
			if (this->getPositionY() + movement < 25) {
				this->setPositionY(this->getPositionY() + movement);
				ok = true;
			}
		}
				break;
		case 5: {
			if (this->getPositionX() + movement < 25 && this->getPositionY() + movement < 25) {
				this->setPositionX(this->getPositionX() + movement);
				this->setPositionY(this->getPositionY() + movement);
				ok = true;
			}
		}
				break;
		case 6: {
			if (this->getPositionX() + movement < 25) {
				this->setPositionX(this->getPositionX() + movement);
				ok = true;
			}
		}
				break;
		case 7: {
			if (this->getPositionX() + movement < 25 && this->getPositionY() - movement >= 0) {
				this->setPositionX(this->getPositionX() + movement);
				this->setPositionY(this->getPositionY() - movement);
				ok = true;
			}
		}
				break;
		case 8: {
			if (this->getPositionY() - movement >= 0) {
				this->setPositionY(this->getPositionY() - movement);
				ok = true;
			}
		}
				break;
		}
	}
}

void Cooper::shoot(int& left, int& right, int& up, int& down) { //returneaza folosind parametrii pozitia maxima in care poate trage in functie de directie
	if(range - this->getPositionY() < 0) {
		left = 0;
	}
	else {
		left = range - this->getPositionY();
	}

	if(range + this->getPositionY() > 24) {
		right = 24;
	}
	 else {
	 	right = range + this->getPositionY();
	 }

	 if(range + this->getPositionX() > 24) {
	 	down = 24;
	 }
	 else {
	 	down = range + this->getPositionX();
	 }	

	 if(range - this->getPositionX() < 0) {
	 	up = 0;
	 }
	 else {
	 	up = range - this->getPositionX();
	 }

}