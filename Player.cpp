#include "Player.h"
#include <time.h>
#include <stdlib.h>

Player::Player() {
	positionX = 0;
	positionY = 0;
}

Player::~Player() {

}

int Player::getPositionX() {
	return positionX;
}

int Player::getPositionY() {
	return positionY;
}

void Player::setPositionX(int x) {
	positionX = x;
}

void Player::setPositionY(int y) {
	positionY = y;
}

void Player::Move(int val) {
	srand(time(NULL));

	bool ok = false;

	while (!ok) {

		int pos = rand() % 9;

		switch (pos) {
		case 0: {

		}
			break;
		case 1: {
			if (positionX - val >= 0 && positionY - val >= 0) {
				positionX -= val;
				positionY -= val;
				ok = true;
			}
		}
				break;
		case 2: {
			if (positionX - val >= 0) {
				positionX -= val;
				ok = true;
			}
		}
				break;
		case 3: {
			if (positionX - val >= 0 && positionY + val < 25) {
				positionX -= val;
				positionY += val;
				ok = true;
			}
		}
				break;
		case 4: {
			if (positionY + val < 25) {
				positionY += val;
				ok = true;
			}
		}
				break;
		case 5: {
			if (positionX + val < 25 && positionY + val < 25) {
				positionX += val;
				positionY += val;
				ok = true;
			}
		}
				break;
		case 6: {
			if (positionX + val < 25) {
				positionX += val;
				ok = true;
			}
		}
				break;
		case 7: {
			if (positionX + val < 25 && positionY - val >= 0) {
				positionX += val;
				positionY -= val;
				ok = true;
			}
		}
				break;
		case 8: {
			if (positionY - val >= 0) {
				positionY -= val;
				ok = true;
			}
		}
				break;
		}
	}
}

int Player::getRadius() {
	return 0;
}

void Player::die() {
	
}

int Player::getSymbol() {
	return 0;
}

int Player::getMovement() {
	return 0;
}