#include "Cooper.h"
#include <iostream>

Cooper::Cooper() {
	movement = 2;
	setPositionX(0);
	setPositionY(0);
	range = 4;
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
	std::cout << "Cooper is dead!\n";
}

int Cooper::getSymbol() {
	return symbol;
}

void Cooper::Move(int enemyPosX, int enemyPosY, bool isInFightArea) { //daca agentul se afla in fight area atunci se misca random, altfel se misca in directia celui mai apropiat agent
    if(isInFightArea) {
	int pos = rand() % 9;

	bool ok = false;

	while (!ok) {

		pos = rand() % 9;

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
    else {   //agentul cauta cel mai apropiat inamic si merge spre el
    if((this->getPositionX() - this->getMovement() != enemyPosX || this->getPositionX() + this->getMovement() != enemyPosX) && (this->getPositionY() - this->getMovement() != enemyPosY || this->getPositionY() + this->getMovement() != enemyPosY)) {
    if(this->getPositionX() > enemyPosX && this->getPositionX() - this->getMovement() >= 0) {
        this->setPositionX(this->getPositionX() - this->getMovement());
    }
    else if(this->getPositionX() < enemyPosX && this->getPositionX() + this->getMovement() <= 24) {
        this->setPositionX(this->getPositionX() + this->getMovement());
    }

    if(this->getPositionY() > enemyPosY && this->getPositionY() - this->getMovement() >= 0) {
        this->setPositionY(this->getPositionY() - this->getMovement());
    }
    else if(this->getPositionY() < enemyPosY && this->getPositionY() + this->getMovement() <= 24) {
        this->setPositionY(this->getPositionY() + this->getMovement());
    }
    }
    }
}

Coordonata* Cooper::shoot(int& nr) { //returneaza un vector ce contine elemente reprezentand pozitiile pe unde poate trece glontul
    int i;
    nr = 0;
    Coordonata* v = new Coordonata[(range + 1) * 4 + 1];  //in vectorul de tip coordonata stochez toate coordonatele prin care trece glontul

    if(this->getPositionY() - range >= 0) {
        for(i = this->getPositionY() - 1; i >= this->getPositionY() - range; i--) { //vad cat poate sa mearga glontul in stanga
            v[nr].setY(i);
            v[nr++].setX(this->getPositionX());
    }
    }
    else {
        for(i = this->getPositionY() - 1; i >= 0; i--) { //aici e in caz ca peretele e la o distanta mai mica decat range
            v[nr].setY(i);
            v[nr++].setX(this->getPositionX());
    }
    }

    if(this->getPositionY() + range <= 24) {
        for(i = this->getPositionY() + 1; i <= this->getPositionY() + range; i++) {  // -||- in dreapta
            v[nr].setY(i);
            v[nr++].setX(this->getPositionX());
    }
    }
    else {
        for(i = this->getPositionY() + 1; i <= 24; i++) {
            v[nr].setY(i);
            v[nr++].setX(getPositionX());
    }
    }

    if(this->getPositionX() - range >= 0) {
        for(i = this->getPositionX() - 1; i >= this->getPositionX() - range; i--) {  // -||- in sus
            v[nr].setY(this->getPositionY());
            v[nr++].setX(i);
    }
    }
    else {
        for(i = this->getPositionX() - 1; i >= 0; i--) {
            v[nr].setY(this->getPositionY());
            v[nr++].setX(i);
    }
    }

    if(this->getPositionX() + range <= 24) {
        for(i = this->getPositionX() + 1; i <= this->getPositionX() + range; i++) { // -||- in jos
            v[nr].setY(this->getPositionY());
            v[nr++].setX(i);
    }
    }
    else {
        for(i = this->getPositionX() + 1; i <= 24; i++) {
            v[nr].setY(this->getPositionY());
            v[nr++].setX(i);
    }
    }

    return v;
}
