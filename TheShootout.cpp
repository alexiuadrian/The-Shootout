#include <iostream>
#include "Simulation.h"
using namespace std;

int main() {
    srand(time(NULL));
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
