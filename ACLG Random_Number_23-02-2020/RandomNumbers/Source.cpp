#include <iostream>
#include <ctime>

using namespace std;

// random generation for XP
int random(int from, int to) {
	return rand() % (to - from + 1) + from;
}

int finalRandomNumber = 0;

// Random generaton for ID 
void playerIDGenerator() {

	int randomArray[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int randomNumber = 0;


	for (int j = 0; j < 9; j++) {

		int r = (rand() % 30) + 5;

		randomArray[j] = r;
		randomNumber *= 100;
		randomNumber += randomArray[j];

		if (randomNumber < 0) {
			randomNumber = randomNumber * -1;
			finalRandomNumber = randomNumber;
		}

		if (finalRandomNumber > 999999999) {	// if 10 digits

			finalRandomNumber = randomNumber / 10;
		}
		
	}
}

int main() {

	//unsigned srand((int)time(NULL));

	/*while (1) {
		
		cout << random(111111111, 999999999) << "\n";
		system("pause");
	}*/

	for (int i = 0; i < 20; i++) {
		playerIDGenerator();
		cout << "ID: #" << finalRandomNumber << ".\n\n";
	}

	system("pause");

}