#include "Player.h"

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

void Player::Move() {
	
}

int Player::getRange() {
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

void Player::shoot(int* posX, int* posY, int& nrOfPosX, int& nrOfPosY) {  //rng = range-ul armei, *posX, *posY sunt vectori in care vor fi salvate coordonatele traiectoriei gloantelor, nrOfPos nr de elemente din cei doi vectori

}