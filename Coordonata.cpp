#include "Coordonata.h"

Coordonata::Coordonata() {
    X = 0;
    Y = 0;
}

Coordonata::~Coordonata() {
    X = 0;
    Y = 0;
}

int Coordonata::getX() {
    return X;
}

int Coordonata::getY() {
    return Y;
}

void Coordonata::setX(int x) {
    X = x;
}

void Coordonata::setY(int y) {
    Y = y;
}

