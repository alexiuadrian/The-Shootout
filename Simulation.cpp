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

}

void Simulation::NextRound() {
	//_C.Move(_C.getMovement());
	//_M.Move(_M.getMovement());
	_C.Move();
	_M.Move();
	_MAP.update(_M, _M.getSymbol());
	_MAP.update(_C, _C.getSymbol());
	_MAP.show();
	check();
}