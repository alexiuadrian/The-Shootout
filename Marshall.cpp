#include "Marshall.h"

Marshall::Marshall() {
	movement = 1;
	setPositionX(24);
	setPositionY(24);
	radius = 5;
	symbol = 2;
}

Marshall::~Marshall() {

}

int Marshall::getMovement() {
	return movement;
}

int Marshall::getRadius() {
	return radius;
}

void Marshall::die() {
	movement = 0;
	setPositionX(25);
	radius = 0;
}

int Marshall::getSymbol() {
	return symbol;
}