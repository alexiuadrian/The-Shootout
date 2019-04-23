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
	cout << "Player " << sym << " changed his position to: (" << a.getPositionX() << ", " << a.getPositionY() << ")\n";
	for(int i=0; i<25; i++) {
		for(int j=0; j<25; j++) {
			if(m[i][j] == sym) {
				m[i][j] = 0;
			}
		}
	}

	m[a.getPositionX()][a.getPositionY()] = sym;
}

int Map::check(Coordonata* v, int nrEl) {   //functie care returneaza primul agent in care agentul a poate sa traga
    int i;

    /*
    for(i = a.getPositionX() + 1; i <= posShoot[3]; i++) {
        if(m[i][a.getPositionY()] != 0) {
            return m[i][a.getPositionY()];
        }
    }

    for(i = a.getPositionX() - 1; i >= posShoot[2]; i--) {
        if(m[i][a.getPositionY()] != 0) {
            return m[i][a.getPositionY()];
        }
    }

    for(i = a.getPositionY() + 1; i <= posShoot[0]; i++) {
        if(m[a.getPositionX()][i] != 0) {
            return m[a.getPositionX()][i];
        }
    }

    for(i = a.getPositionY() - 1; i >= posShoot[1]; i--) {
        if(m[a.getPositionX()][i] != 0) {
            return m[a.getPositionX()][i];
        }
    }
*/

    for(i = 0; i < nrEl; i++) {
        if(m[v[i].getX()][v[i].getY()] != 0) {
            return m[v[i].getX()][v[i].getY()];
        }
    }

    return 0;
}
