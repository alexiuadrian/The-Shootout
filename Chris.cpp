#include "Chris.h"

Chris::Chris() {
	movement = 1;
	setPositionX(24);
	setPositionY(0);
	range = 4;
	symbol = 3;
	armor = true;
}

Chris::~Chris() {

}

int Chris::getMovement() {
	return movement;
}

int Chris::getRange() {
	return range;
}

void Chris::die() {
    if(armor) {
        armor = false;
        movement++;
        int randomX = rand() % 25;
        int randomY = rand() % 25;
        this->setPositionX(randomX);
        this->setPositionY(randomY);
    }
    else {
    movement = 0;
	setPositionX(25);
	range = 0;
	symbol = 0;
	std::cout << "Chris is dead!\n";
    }
}

int Chris::getSymbol() {
	return symbol;
}

void Chris::Move(int enemyPosX, int enemyPosY, bool isInFightArea) { //functie care misca agentul in directia playerului cel mai apropiat
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

Coordonata* Chris::shoot(int& nr) {
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
    //impart in trei bucati stocarea traiectoriei
    //Partea de sus:
    for(i = maxUp; i <= this->getPositionX() - range / 2; i++) {  //stochez in v de tip Coordonata toate locurile prin care poate trece glontul
        for(j = maxLeft; j <= maxRight; j++) {
                v[nr].setX(i);
                v[nr++].setY(j);
        }
    }

    //Partea de la mijloc:
    for(i = this->getPositionX() - range / 2 + 1; i <= this->getPositionX() + range / 2; i++) {
        for(j = maxLeft; j <= this->getPositionY() - range / 2; j++) {
            v[nr].setX(i);
            v[nr++].setY(j);
        }

        for(j = this->getPositionY() + range / 2 + 1; j <= maxRight; j++) {
            v[nr].setX(i);
            v[nr++].setY(j);
        }
    }

    //Partea de sus:
    for(i = this->getPositionX() + range / 2 + 1; i <= maxDown; i++) {
        for(j = maxLeft; j <= maxRight; j++) {
                v[nr].setX(i);
                v[nr++].setY(j);
        }
    }

    return v;
}

bool Chris::getArmor() {
    return armor;
}

