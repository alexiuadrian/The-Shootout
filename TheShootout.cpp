#include <iostream>
#include "Map.cpp"
#include "Player.cpp"
#include "Cooper.cpp"
#include "Marshall.cpp"
using namespace std;


int main() {
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

	return 0;
}