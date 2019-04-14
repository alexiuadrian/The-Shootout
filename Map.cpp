#include "Map.h"
#include <iostream>
using namespace std;

Map::Map() {
	m = new int*[26];
	for (int i = 0; i <= 25; i++) {
		m[i] = new int[25];
	}

	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			m[i][j] = 0;
		}
	}

	_C = new Cooper[1];
	_M = new Marshall[1];

	m[_C[0].getPositionX()][_C[0].getPositionY()] = 1;
	m[_M[0].getPositionX()][_M[0].getPositionY()] = 2;

}


Map::~Map() {
	for (int i = 0; i < 25; i++) {
		delete m[i];
	}
	delete[] m;

	delete[] _C;
	delete[] _M;
}

void Map::show() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 25; j++) {
			cout << m[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Map::Update() {
	for (int i = 0; i <= 25; i++) {
		for (int j = 0; j < 25; j++) {
			m[i][j] = 0;
		}
	}

	_C[0].Move(_C[0].getMovement());
	m[_C[0].getPositionX()][_C[0].getPositionY()] = 1;

	_M[0].Move(_M[0].getMovement());
	m[_M[0].getPositionX()][_M[0].getPositionY()] = 2;

	int i, j;
	bool isInAttackRadius = false;

	for(i=_C[0].getPositionX()-_C[0].getRadius(); i<=_C[0].getPositionX()+_C[0].getRadius(); i++) {
		for(j=_C[0].getPositionY()-_C[0].getRadius(); j<=_C[0].getPositionY()+_C[0].getRadius(); j++) {
			if(_M[0].getPositionX() == i && _M[0].getPositionY() == j) {
				isInAttackRadius = true;
			}
		}
	}

	if(isInAttackRadius == true) {
		cout << "1 Attacks 2\n";
		m[_M[0].getPositionX()][_M[0].getPositionY()] = 0;
		_M[0].die();
	}

	isInAttackRadius = false;

	for(i=_M[0].getPositionX()-_M[0].getRadius(); i<=_M[0].getPositionX()+_M[0].getRadius(); i++) {
		for(j=_M[0].getPositionY()-_M[0].getRadius(); j<=_M[0].getPositionY()+_M[0].getRadius(); j++) {
			if(_C[0].getPositionX() == i && _C[0].getPositionY() == j) {
				isInAttackRadius = true;
			}
		}
	}	

	if(isInAttackRadius == true) {
		cout << "2 Attacks 1\n";
		m[_C[0].getPositionX()][_C[0].getPositionY()] = 0;
		_C[0].die();
	}

}

void Map::Move() {

}