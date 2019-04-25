#pragma once
#include "Player.h"
#include "Coordonata.h"

class Map {
public:
	Map();
	~Map();
	void show();
	void update(Player&, int);
	int check(Coordonata*, int nrEl);   //functie care returneaza primul agent in care agentul cu vectorul de coordonate v poate sa traga
    bool fightZone(Player&);     //functie care verifica daca doi agenti se afla in "fight zone" adica daca mutarile lor pot deveni random
    int closestEnemy(Player&);   //functie care returneaza cel mai apropiat agent de agentul din antet

private:
	int** m;

};
