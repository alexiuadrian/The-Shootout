#include "Marshall.h"

Marshall::Marshall() {
	movement = 1;
	setPositionX(16);
	setPositionY(8);
	range = 5;
	symbol = 2;
}

Marshall::~Marshall() {

}

int Marshall::getMovement() {
	return movement;
}

int Marshall::getRange() {
	return range;
}

void Marshall::die() {
	movement = 0;
	setPositionX(25);
	range = 0;
	std::cout << "Marshall is dead!\n";
}

int Marshall::getSymbol() {
	return symbol;
}

void Marshall::Move(int enemyPosX, int enemyPosY) { //functie care misca agentul in directia playerului cel mai apropiat
	/*
	srand(time(NULL));
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
	*/

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

Coordonata* Marshall::shoot(int& nr) {
    Coordonata* v = new Coordonata[8*range];
    nr = 0;

    if(this->getPositionX() - 1 >= 0) {
        if(this->getPositionY() - 1 >= 0) {
            v[nr].setX(this->getPositionX() - 1);
            v[nr++].setY(this->getPositionY() - 1);
        }
        v[nr].setX(this->getPositionX() - 1);
        v[nr++].setY(this->getPositionY());
        if(this->getPositionY() + 1 <= 24) {
            v[nr].setX(this->getPositionX() - 1);
            v[nr++].setY(this->getPositionY() + 1);
        }
    }

    if(this->getPositionY() - 1 >= 0) {
        v[nr].setX(this->getPositionX());
        v[nr++].setY(this->getPositionY() - 1);
    }

    if(this->getPositionY() + 1 <= 24) {
        v[nr].setX(this->getPositionX());
        v[nr++].setY(this->getPositionY() + 1);
    }

    if(this->getPositionX() + 1 <= 24) {
        if(this->getPositionY() - 1 >= 0) {
            v[nr].setX(this->getPositionX() + 1);
            v[nr++].setY(this->getPositionY() - 1);
        }
        v[nr].setX(this->getPositionX() + 1);
        v[nr++].setY(this->getPositionY());
        if(this->getPositionY() + 1 <= 24) {
            v[nr].setX(this->getPositionX() + 1);
            v[nr++].setY(this->getPositionY() + 1);
        }
    }
    return v;
}

