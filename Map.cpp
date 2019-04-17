#include "Map.h"
#include <iostream>
using namespace std;

Map::Map() {
	m = new int*[26];
	for(int i=0; i<=25; i++) {
		m[i] = new int[25];
	}

	for(int i=0; i<=25; i++) {
		for(int j=0; j<25; j++) {
			m[i][j] = 0;
		}
	}

}

Map::~Map() {
	for(int i=0; i<=25; i++) {
		delete[] m[i];
	}
	delete[] m;
}

void Map::show() {
	for(int i=0; i<25; i++) {
		for(int j=0; j<25; j++) {
			cout << m[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void Map::update(Player& a, int sym) {
	for(int i=0; i<25; i++) {
		for(int j=0; j<25; j++) {
			if(m[i][j] == sym) {
				m[i][j] = 0;
			}
		}
	}

	m[a.getPositionX()][a.getPositionY()] = sym;
}