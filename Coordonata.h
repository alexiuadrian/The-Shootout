#pragma once

class Coordonata {
public:
    Coordonata();
    ~Coordonata();
    Coordonata(const Coordonata&);
    int getX();
    int getY();
    void setX(int);
    void setY(int);

private:
    int X, Y;
};
