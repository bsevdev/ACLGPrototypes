#include <iostream>

using namespace std;

string values[3][3] = {" * ", " * ", " * " ," * ", " * ", " * " ," * ", " * ", " * " };

string playerX = " x ";
string playerO = "o";

int spot;

bool playerXTurn = true;
bool playerOTurn = true;

void printGrid() {

	cout << "\n\n";

	for (int i = 0; i < 3; i++) {

		for (int j = 0; j < 3; j++) {

			cout << values[i][j];

		}

		cout << endl;
	}

}

void playerTurn() {

	if (playerXTurn == true) {
		playerOTurn = false;
		cout << "Player X turn: ";
		cin >> spot;
	}
	else {
		playerXTurn = false;
		cout << "Player O turn: ";
		cin >> spot;
		playerOTurn = true;

	}
}

void Moves() {

	if (spot == 5) {

		values[1][1] = playerX;
		
	}
	
}

void playerTurnCheck() {
	
	if (playerXTurn == true) {
		playerXTurn = false;
	}

	else if (playerOTurn == true) {
		playerOTurn = false;
	}
}

int main() {

	while (1) {
		printGrid();
		playerTurn();
		Moves();

		system("cls");
		playerTurnCheck();
	}

	system("pause");
}

