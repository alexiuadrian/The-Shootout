#include "Simulation.h"
#include <iostream>

Simulation::Simulation(int players) {

	switch(players) {
        case 1: {
            _MAP.update(_C, _C.getSymbol());
            _MAP.update(_M, _M.getSymbol());
            while(_C.getPositionX() == _M.getPositionX() && _C.getPositionY() == _M.getPositionY()) {
                _MAP.update(_C, _C.getSymbol());
                _MAP.update(_M, _M.getSymbol());
            }
            break;
        }
        case 2: {
            _MAP.update(_C, _C.getSymbol());
            _MAP.update(_CH, _CH.getSymbol());
            while(_C.getPositionX() == _CH.getPositionX() && _C.getPositionY() == _CH.getPositionY()) {
                _MAP.update(_C, _C.getSymbol());
                _MAP.update(_CH, _CH.getSymbol());
            }
            break;
        }
        case 3: {
            _MAP.update(_M, _M.getSymbol());
            _MAP.update(_CH, _CH.getSymbol());
            while(_M.getPositionX() == _CH.getPositionX() && _M.getPositionY() == _CH.getPositionY()) {
                _MAP.update(_M, _M.getSymbol());
                _MAP.update(_CH, _CH.getSymbol());
            }
            break;
        }
        break;
	}

}

Simulation::~Simulation() {

}

Simulation::Simulation(const Simulation& a) {
    this->_MAP = a._MAP;
    this->_C = a._C;
    this->_M = a._M;
    this->_CH = a._CH;
}

void Simulation::show() {
	_MAP.show();
}

bool Simulation::check(int players) {
    Coordonata* C = new Coordonata[_C.getRange()*4];
    Coordonata* M = new Coordonata[_M.getRange()*8];
    Coordonata* CH = new Coordonata[(_CH.getRange() + 1) * (_CH.getRange() + 1) * 4];
    bool ok = false;
    int nrC = 0, nrM = 0, nrCH = 0;

    switch(players) {
        case 1: {
            C = _C.shoot(nrC);
            M = _M.shoot(nrM);

            if(_MAP.check(C, nrC, _C) == 2) {
                _M.die();
                ok = true;
            }

            if(_MAP.check(M, nrM, _M) == 1) {
                _C.die();
                ok = true;
            }
            break;
        }
        case 2: {
            C = _C.shoot(nrC);
            CH = _CH.shoot(nrCH);

            if(_MAP.check(C, nrC, _C) == 3) {
                _CH.die();
                ok = true;
            }

            if(_MAP.check(CH, nrCH, _CH) == 1) {
                _C.die();
                ok = true;
            }

            break;
        }
        case 3: {
            M = _M.shoot(nrM);
            CH = _CH.shoot(nrCH);

            if(_MAP.check(M, nrM, _M) == 3) {
                _CH.die();
                ok = true;
            }

            if(_MAP.check(CH, nrCH, _CH) == 2) {
                _M.die();
                ok = true;
                }
            }
        break;
    }

    delete[] C;
    delete[] M;
    delete[] CH;
    nrC = 0;
    nrM = 0;
    nrCH = 0;
    return ok;
}

bool Simulation::NextRound(int players) {
//mut fiecare agent in directia celui mai apropiat agent
    switch(players) {
        case 1: {
        _C.Move(_M.getPositionX(), _M.getPositionY(), _MAP.fightZone(_C));  //player1 se misca spre player2 si invers
        _M.Move(_C.getPositionX(), _C.getPositionY(), _MAP.fightZone(_M));
        _MAP.update(_C, _C.getSymbol());    //se updateaza pozitiile celor 2 playeri in harta
        _MAP.update(_M, _M.getSymbol());
        _MAP.show();    //se afiseaza harta
        if(check(players)) {    //daca un player e lovit sau moare, se mai afiseaza odata harta cu mesajul corespunzator deasupra
            _MAP.update(_C, _C.getSymbol());
            _MAP.update(_M, _M.getSymbol());
            _MAP.show();
        }
        switch(_MAP.isGameOver()) {     //verific daca jocul s-a terminat si afisez cine a castigat
            case 1: {
                std::cout << "COOPER WON!\n";
                return false;
            }
            case 2: {
                std::cout << "MARSHALL WON!\n";
                return false;
            }
        }
        return true;
        break;
        }
        case 2: {
        _C.Move(_CH.getPositionX(), _CH.getPositionY(), _MAP.fightZone(_C));
        _CH.Move(_C.getPositionX(), _C.getPositionY(), _MAP.fightZone(_CH));
        _MAP.update(_C, _C.getSymbol());
        _MAP.update(_CH, _CH.getSymbol());
        _MAP.show();
        if(check(players)) {
            _MAP.update(_C, _C.getSymbol());
            _MAP.update(_CH, _CH.getSymbol());
            _MAP.show();
        }
        switch(_MAP.isGameOver()) {
            case 1: {
                std::cout << "COOPER WON!\n";
                return false;
            }
            case 3: {
                std::cout << "CHRIS WON!\n";
                return false;
            }
        }
        return true;
        break;
        }
        case 3: {
        _M.Move(_CH.getPositionX(), _CH.getPositionY(), _MAP.fightZone(_M));
        _CH.Move(_M.getPositionX(), _M.getPositionY(), _MAP.fightZone(_CH));
        _MAP.update(_M, _M.getSymbol());
        _MAP.update(_CH, _CH.getSymbol());
        _MAP.show();
        if(check(players)) {
            _MAP.update(_CH, _CH.getSymbol());
            _MAP.update(_M, _M.getSymbol());
            _MAP.show();
        }
        switch(_MAP.isGameOver()) {
            case 2: {
                std::cout << "MARSHALL WON!\n";
                return false;
            }
            case 3: {
                std::cout << "CHRIS WON!\n";
                return false;
            }
        }
        return true;
        break;
        }
    }
    return true;
}
