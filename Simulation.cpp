#include "Simulation.h"
#include <iostream>

Simulation::Simulation() {
	_MAP.update(_C, _C.getSymbol());
	_MAP.update(_M, _M.getSymbol());
	//_MAP.update(_CH, _CH.getSymbol());
}

Simulation::~Simulation() {

}

void Simulation::show() {
	_MAP.show();
}

void Simulation::check() {
    Coordonata* C = new Coordonata[_C.getRange()*4];
    Coordonata* M = new Coordonata[_M.getRange()*8];
    Coordonata* CH = new Coordonata[(_CH.getRange()+1)*8 + 1];
    int nrC = 0, nrM = 0, nrCH = 0;
    C = _C.shoot(nrC);
    M = _M.shoot(nrM);
    CH = _CH.shoot(nrCH);

    switch(_MAP.check(C, nrC)) {
        case 2: {
            _M.die();
            break;
        }
        //break;
        case 3: {
            _CH.die();
        }
        break;
    }

    switch(_MAP.check(M, nrM)) {
        case 1: {
            _C.die();
            break;
        }
        //break;
        case 3: {
            _CH.die();
        }
        break;
    }
    /*
    switch(_MAP.check(CH, nrCH)) {
        case 1: {
            _C.die();
            break;
        }
        case 2: {
            _M.die();
        }
        break;
    }
*/
    /*
    for(int i = 0; i <= nrCH; i++) {
        std::cout << CH[i].getX() << " " << CH[i].getY() << '\n';
    }
    */

    delete[] C;
    delete[] M;
    delete[] CH;
    nrC = 0;
    nrM = 0;
    nrCH = 0;
}

void Simulation::NextRound() {
    //mut fiecare agent in directia celui mai apropiat agent
    switch(_MAP.closestEnemy(_C)) {
        case 2: {
            _C.Move(_M.getPositionX(), _M.getPositionY(), _MAP.fightZone(_C));
            break;
        }
        case 3: {
            _C.Move(_CH.getPositionX(), _CH.getPositionY(), _MAP.fightZone(_C));
        }
        break;
    }

    switch(_MAP.closestEnemy(_M)) {
        case 1: {
            _M.Move(_C.getPositionX(), _C.getPositionY(), _MAP.fightZone(_M));
            break;
        }
        case 3: {
            _M.Move(_CH.getPositionX(), _CH.getPositionY(), _MAP.fightZone(_M));
        }
        break;
    }
/*
    switch(_MAP.closestEnemy(_CH)) {
        case 1: {
            _CH.Move(_C.getPositionX(), _C.getPositionY(), _MAP.fightZone(_CH));
            break;
        }
        case 2: {
            _CH.Move(_M.getPositionX(), _M.getPositionY(), _MAP.fightZone(_CH));
        }
        break;
    }
*/
    _MAP.update(_C, _C.getSymbol());
	_MAP.update(_M, _M.getSymbol());
	//_MAP.update(_CH, _CH.getSymbol());
	check();
	_MAP.show();
}
