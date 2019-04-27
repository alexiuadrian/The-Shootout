#include <iostream>
#include "Simulation.h"
using namespace std;

int main() {
    srand(time(NULL));
	int option;

    cout << "THE SHOOTOUT\n\n";
    cout << "1) Start Game\n";
    cout << "2) Exit\n\n";
    cin >> option;

    switch(option) {
        case 1: {
            cout << "COOPER - Pistol\nMoves 2 units and has a range of 4 units\nHe shoots up, down, left and right in a straight line\n\n";
            cout << "MARSHALL - Shotgun\nMoves 1 unit and has a range of 2 units\nHe shoots in any direction, 3 bullets at a time\n\n";
            cout << "CHRIS - Grenade Launcher\nMoves 1 unit and has a range of 5 units\nHe shoots in any direction, but 2 units away from him\n\n";
            cout << "WHO WILL FIGHT?\n\n";
            cout << "1) COOPER vs MARSHALL\n\n";
            cout << "2) COOPER vs CHRIS\n\n";
            cout << "3) MARSHALL vs CHRIS\n\n";
            int opt2;
            cin >> opt2;
            Simulation S(opt2);
            S.show();
            cout << "1 = Next Round! ";
            cin >> option;

            while(option == 1) {
            S.NextRound(opt2);
            cout << "1 = Next Round! ";
            cin >> option;
            }
            break;
        }
        case 2: {
            return 0;
        }
    }

	return 0;
}
