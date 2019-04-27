#include "Marshall.h"

Marshall::Marshall() {
	movement = 1;
	setPositionX(rand() % 25);
	setPositionY(rand() % 25);
	range = 2;
	symbol = 2;
	armor = true;
}

Marshall::~Marshall() {

}

Marshall::Marshall(const Marshall& a) {
    this->movement = a.movement;
    this->range = a.range;
    this->symbol= a.symbol;
    this->armor = a.armor;
}

int Marshall::getMovement() {
	return movement;
}

int Marshall::getRange() {
	return range;
}

void Marshall::die() {
    if(armor) {
        armor = false;
        movement++;
        int randomX = rand() % 25;
        int randomY = rand() % 25;
        this->setPositionX(randomX);
        this->setPositionY(randomY);
        std::cout << "Marshall is hit!\n";
    }
    else {
    movement = 0;
	setPositionX(25);
	range = 0;
	std::cout << "Marshall is dead!\n";
    }
}

int Marshall::getSymbol() {
	return symbol;
}

void Marshall::Move(int enemyPosX, int enemyPosY, bool isInFightArea) { //functie care misca agentul in directia playerului cel mai apropiat
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
    else {
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

Coordonata* Marshall::shoot(int& nr) {
/*  Codul comentat merge dar agentul trage doar 1 unitate in jurul lui
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
*/

    Coordonata* v = new Coordonata[(range + 1) * 8 + 1];
    int i, j, maxLeft, maxRight, maxUp, maxDown;

    if(this->getPositionX() - range >= 0) {
        maxUp = this->getPositionX() - range;
    }
    else {
        maxUp = 0;
    }

    if(this->getPositionX() + range <= 24) {
        maxDown = this->getPositionX() + range;
    }
    else {
        maxDown = 24;
    }

    if(this->getPositionY() - range >= 0) {
        maxLeft = this->getPositionY() - range;
    }
    else {
        maxLeft = 0;
    }

    if(this->getPositionY() + range <= 24) {
        maxRight = this->getPositionY() + range;
    }
    else {
        maxRight = 24;
    }

    nr = 0;
    for(i = maxUp; i <= maxDown; i++) {  //stochez in v de tip Coordonata toate locurile prin care poate trece glontul
        for(j = maxLeft; j <= maxRight; j++) {
            if(i != this->getPositionX() || j != this->getPositionY()) {
                v[nr].setX(i);
                v[nr++].setY(j);
            }
        }
    }

    return v;
}

bool Marshall::getArmor() {
    return armor;
}
