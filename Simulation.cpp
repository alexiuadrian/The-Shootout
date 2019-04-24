#include "Simulation.h"
#include <iostream>

Simulation::Simulation() {
	_MAP.update(_M, _M.getSymbol());
	_MAP.update(_C, _C.getSymbol());
}

Simulation::~Simulation() {

}

void Simulation::show() {
	_MAP.show();
}

void Simulation::check() {
    Coordonata* C = new Coordonata[_C.getRange()*4];
    Coordonata* M = new Coordonata[8];
    int nrC = 0, nrM = 0;
    C = _C.shoot(nrC);
    M = _M.shoot(nrM);

    switch(_MAP.check(C, nrC)) {
        case 2: {
            _M.die();
        }
        break;
    }

    switch(_MAP.check(M, nrM)) {
        case 1: {
            _C.die();
        }
        break;
    }

    delete[] C;
    nrC = 0;
}

void Simulation::NextRound() {

	_C.Move(_M.getPositionX(), _M.getPositionY(), _MAP.fightZone(_C));
	_M.Move(_C.getPositionX(), _C.getPositionY(), _MAP.fightZone(_M));
	_MAP.update(_M, _M.getSymbol());
	_MAP.update(_C, _C.getSymbol());
	check();
	_MAP.show();
}
