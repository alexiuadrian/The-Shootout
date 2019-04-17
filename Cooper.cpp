#include "Cooper.h"
#include <iostream>

Cooper::Cooper() {
	movement = 2;
	setPositionX(0);
	setPositionY(0);
	radius = 2;
	symbol = 1;
}

Cooper::~Cooper() {

}

int Cooper::getMovement() {
	return movement;
}

int Cooper::getRadius() {
	return radius;
}

void Cooper::die() {
	setPositionX(25);
	movement = 0;
	radius = 0;
}

int Cooper::getSymbol() {
	return symbol;
}