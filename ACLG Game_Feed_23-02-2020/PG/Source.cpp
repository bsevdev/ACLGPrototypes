#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <cstring>

// only throw prompt is window is closed
// disable console disable highlight
// int to LPCTSTR
// music loop -- toggle on/off							[DONE]
// tidy up code
// move over to LIVE game planning
// move to LIVE
// gameplay planning


using namespace std;

bool gameOver = false;
bool updateDone = false;
bool setGameFeedPos = false;

				  // 0      1       2        3      4        5       6       7        8         9
string text[22] = { "","","","", "","", "","", "","", "","", "","", "","", "","", "","", "","", };
string cmd = "";
string typedYesString = "You typed yes";
string typedNoString = "You typed no";
string lastString = "";
string badInput = "That is not a command!";
string hintString = "[TIP]: Try growing up a little bit, it helps.";
string hintString2 = "[TIP]: Type \"stats\" to display your basic player statistics.";
//--------------
string skillText1 = "We're testing text...";
string skillText2 = "We're still testing text...";
string skillText3 = "Nearly there...";
string skillText4 = "Done."; // <--- windows alert here.

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int iSecret;

void pushSpace() {
	
	for (int i = 0; i < 26; i++) {

		cout << '\n';
	}
}

// will UPDATE the Game Feed
void updateGameFeed() {

	// we make this false to enter the loop
	updateDone = false;

	while (updateDone == false) {
		
		#pragma region Index 0 Look
		if (text[0] == "")
		{
			// do nothing

		}

		else {
			text[0] = "";
		}
		#pragma endregion 

		#pragma region Index 1 Look
		if (text[1] == "") {
			
			// do nothing
		}

		else {
			
			text[0] = text[1];
		}
		#pragma endregion 

		#pragma region Index 2 Look
		if (text[2] == "") {

			// do nothing
		}

		else {

			text[1] = text[2];
		}
		#pragma endregion 

		#pragma region Index 3 Look
		if (text[3] == "") {

			// do nothing
		}

		else {

			text[2] = text[3];
		}
		#pragma endregion  
	
		#pragma region Index 4 Look
			if (text[4] == "") {

				// do nothing
			}

			else {

				text[3] = text[4];
			}
		#pragma endregion  
	
		#pragma region Index 5 Look
		if (text[5] == "") {

			// do nothing
		}

		else {

			text[4] = text[5];
		}
		#pragma endregion 
	
		#pragma region Index 6 Look
		if (text[6] == "") {

			// do nothing
		}

		else {

			text[5] = text[6];
		}
		#pragma endregion 
			
		#pragma region Index 7 Look
		if (text[7] == "") {

			// do nothing
		}

		else {

			text[6] = text[7];
		}
		#pragma endregion  
	
		#pragma region Index 8 Look
		if (text[8] == "") {

			// do nothing
		}

		else {

			text[7] = text[8];
		}
		#pragma endregion 

		#pragma region Index 9 Look
		if (text[9] == "") {

			// do nothing
		}

		else {

			text[8] = text[9];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[10] == "") {

			// do nothing
		}

		else {

			text[9] = text[10];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[11] == "") {

			// do nothing
		}

		else {

			text[10] = text[11];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[12] == "") {

			// do nothing
		}

		else {

			text[11] = text[12];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[13] == "") {

			// do nothing
		}

		else {

			text[12] = text[13];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[14] == "") {

			// do nothing
		}

		else {

			text[13] = text[14];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[15] == "") {

			// do nothing
		}

		else {

			text[14] = text[15];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[16] == "") {

			// do nothing
		}

		else {

			text[15] = text[16];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[17] == "") {

			// do nothing
		}

		else {

			text[16] = text[17];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[18] == "") {

			// do nothing
		}

		else {

			text[17] = text[18];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[19] == "") {

			// do nothing
		}

		else {

			text[18] = text[19];
		}
#pragma endregion 
		
		#pragma region Index 9 Look
		if (text[20] == "") {

			// do nothing
		}

		else {

			text[19] = text[20];
		}
#pragma endregion 
	
		#pragma region Index 9 Look
			if (text[21] == "") {

				text[21] = lastString;
			}

			else {

				text[20] = text[21];
				text[21] = lastString;
			}
		#pragma endregion 

		lastString = "";
		updateDone = true;
		
	}
	
}

// will DISPLAY the Game Feed
void displayGameFeed() {

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 0, 35 };
		SetConsoleCursorPosition(hConsole, pos);

	}

	// displays the current array
	for (int i = 0; i < 22; i++) {

		cout << text[i] << '\n';
	}
}

// will GENERATE RANDOM NUMBER for hints (uses updateGameFeed())
void TipGenerator() {

	/* initialize random seed: */
	/* generate secret number between 1 and 200: */

	// Re-implementation to Switch case if causing issues

	iSecret = rand() % 10 + 1;

	// "hint" test
	if (iSecret == 5) {
		lastString = hintString;
		updateGameFeed();
	}

	else {
		
	}

	if (iSecret == 10) {
		lastString = hintString2;
		updateGameFeed();
	}

	else {
	
	}
	
}

// shows "command" section NOTE: This will be the UI function
void displayUI() {
	
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 0, 25 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "-------------------------------------------------------------------------------------";
		cout << "-------------\n";
		cout << "command:  ";

	}
}

// Skill Mechanic Functionality
void SkillMechanicTest() {

	// Come up with a way to place these into a loop (numbered)
	// 1 
	system("cls");
	pushSpace();
	lastString = skillText1;
	updateGameFeed();
	displayGameFeed();
	displayUI();
	std::this_thread::sleep_for(chrono::seconds(1));


	// 2
	system("cls");
	pushSpace();
	lastString = skillText2;
	updateGameFeed();
	displayGameFeed();
	displayUI();
	std::this_thread::sleep_for(chrono::seconds(1));

	// 3
	system("cls");
	pushSpace();
	lastString = skillText3;
	updateGameFeed();
	displayGameFeed();
	displayUI();
	std::this_thread::sleep_for(chrono::seconds(1));


	system("cls");
	pushSpace();
	lastString = skillText4;
	updateGameFeed();
	displayGameFeed();

}

// checking all GameInput here
void GameFeedInput() {

	// for testing, if we type yes, no
	if (cmd == "yes") {

		lastString = typedYesString;
		// updates game feed
		updateGameFeed();
	}

	else if (cmd == "no") {

		lastString = typedNoString;
		// updates game feed
		updateGameFeed();
	}

	else if (cmd == "run") {

		SkillMechanicTest();
	}

	// otherwise, it was not a command (acts as "default") for switch-case
	else {

		// [**************IMPLEMENT RANDOM ERROR MESSAGES**************]
		lastString = badInput;
		updateGameFeed();
		
	}

	// Switch case implementation

}

int main() {

	system("mode 100,28");

	// begin random seed
	unsigned srand((int)time(NULL));

	pushSpace();

	while (gameOver == false) {

		pushSpace();
		displayGameFeed();
		displayUI();


		if (INVALID_HANDLE_VALUE != hConsole)
		{
			COORD pos = { 9, 37 };
			SetConsoleCursorPosition(hConsole, pos);
			
			getline(cin, cmd);		// user input
		}

		// checks what you type
		GameFeedInput();

		// generates random number for hint
		TipGenerator();

		system("cls");
	}

	system("pause");
}