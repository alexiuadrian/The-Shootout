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

int Map::check(Coordonata* v, int nrEl) {   //functie care returneaza primul agent in care agentul cu vectorul de coordonate v poate sa traga
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
/*
bool Map::fightZone(Coordonata a, Coordonata b) {
    if((a.getX() - b.getX() <= 7 && a.getX() >= b.getX()) || (b.getX() - a.getX() <= 7 && b.getX() >= a.getX()) || (a.getY() - b.getY() <= 7 && a.getY() >= b.getY()) || (b.getY() - a.getY() <= 7 && b.getY() >= a.getY())) {
        return true;
    }
    return false;
}
*/

bool Map::fightZone(Player& a) {
    int i, j, maxLeft, maxRight, maxUp, maxDown;

    if(a.getPositionX() - 7 >= 0) {
        maxUp = a.getPositionX() - 7;
    }
    else {
        maxUp = 0;
    }

    if(a.getPositionX() + 7 <= 24) {
        maxDown = a.getPositionX() + 7;
    }
    else {
        maxDown = 24;
    }

    if(a.getPositionY() - 7 >= 0) {
        maxLeft = a.getPositionY() - 7;
    }
    else {
        maxLeft = 0;
    }

    if(a.getPositionY() + 7 <= 24) {
        maxRight = a.getPositionY() + 7;
    }
    else {
        maxRight = 24;
    }

    for(i = maxUp; i <= maxDown; i++) {
        for(j = maxLeft; j <= maxRight; j++) {
            if(m[i][j] != 0 && m[i][j] != a.getSymbol()) {
                return true;
            }
        }
    }

    return false;
}

int Map::closestEnemy(Player& a) {
    int i, j, sym1 = -1, sym2 = -1, nr1 = 0, nr2 = 0;   //in nr1 numar distanta pana la agentul cautat dupa a si in nr2 pe cel cautat inainte
    bool ok = true;                           //in sym1 salvez simbolul primului agent gasit dupa si in sym2 cel gasit inainte

    for(i = a.getPositionX(); i <= 24 && ok; i++) {     //caut primul agent dupa agentul a si ii salvez simbolul
        for(j = a.getPositionY(); j <= 24 && ok; j++) {
                nr1++;
            if(m[i][j] != 0 && m[i][j] != a.getSymbol()) {
                sym1 = m[i][j];
                ok = false;
            }
        }
    }

    ok = true;
    for(i = a.getPositionX(); i >= 0 && ok; i--) {         //caut primul agent inainte de agentul a si ii salvez simbolul
        for(j = a.getPositionY(); j >= 0 && ok; j--) {
            nr2++;
            if(m[i][j] != 0 && m[i][j] != a.getSymbol()) {
                sym2 = m[i][j];
                ok = false;
            }
        }
    }

    if(nr1 < nr2) {         //compar distanta dintre cei doi agenti gasiti si agentul a
        if(sym1 != -1) {
            return sym1;
        }
        else {
            if(sym2 != -1) {
                return sym2;
            }
        }
    }
    else {
        if(sym2 != -1) {
            return sym2;
        }
        else {
            if(sym1 != -1) {
                return sym1;
            }
        }
    }

}
