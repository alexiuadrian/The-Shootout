#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Cooper.h"
#include "Marshall.h"
#include "Simulation.h"
using namespace std;

int main() {

/*
	int option;
	Map M;
	M.show();

	cout << "1 = NEXT ROUND! ";
	cin >> option;

	while (option == 1) {
		M.Update();
		M.show();
		cout << "1 = NEXT ROUND! ";
		cin >> option;
	}
*/

	int option = 1;
	Simulation S;
	S.show();
	cout << "1 = Next Round! ";
	cin >> option;

	while(option == 1) {
		S.NextRound();
		cout << "1 = Next Round! ";
		cin >> option;
	}

	return 0;
}