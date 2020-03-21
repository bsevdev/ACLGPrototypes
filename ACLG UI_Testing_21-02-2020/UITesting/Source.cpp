#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <stdlib.h>

using namespace std;

// Tip: Move cursor before printing text

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// displays bars going across
const string drawCommandArea[1][2] = {	"----------------------------------------------------------------------------------------------------",
										"----------------------------------------------------------------------------------------------------"};

// displays bars going downwards
const string drawExtendedCommandArea[1][28] = {	"|","|", "|", "|", "|", "|", "|", "|", "|", 
												"|", "|", "|", "|", "|", "|", "|", "|","|",
												"|", "|", "|", "|", "|", "|", "|", "|", "|",	
												 "|",
};

// This function prints a long line across the screen
void CommandLineUI() {
	cout << "\n\n\n\n\n\n\n\n\n\n";         // <--- for moving up and down
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\n\n\n\n";
	cout << "----------------------------------------------------------------------------------------------------";
}

// Used with DisplayExtendedCommandArea() for full GAME UI
void UIForExtended() {
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 0, 26 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "-----------------------------------------------------------------";

	}
}

// Predictive text for GAME
void PredictionText() {

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 1, 27 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "Command Suggestion: ";

	}

}

// Displays cut-off version of CommandLineUI();	
void UIForSuggestion() {

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 0, 24 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "-----------------------------------------------------------------";

	}
}

// displays the last Pipe character at the bottom of the screen
void LastPipe() {

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 30, 28 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "								|";

	}
}

// This function will display FULL Ui that includes area for skills
void DisplayExtendedCommandArea() {

	UIForExtended();

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 0, 0 };

		SetConsoleCursorPosition(hConsole, pos);

		for (int i = 0; i < 1; i++) {

			for (int j = 0; j < 28; j++) {

				cout << "								";				// <--- move parrallel UI line forwards

				cout << drawExtendedCommandArea[i][j];
				cout << "\n";
			}
		}
	}
}

void DisplaySkillsTitle() {

	// Display Skill Title
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 78, 1 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Skills";

	}

	// Display Skill Line
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 75, 2 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "------------";

	}
}

void DisplayIntelligence() {
	// Display Intelligence Skill
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 3 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Intelligence level: 0/120";

	}

	// Display Intelligence EXP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 4 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Intelligence XP: 0";

	}

	// Display Intelligence Remaining EXP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 5 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: 0";

	}

	// Bars under intelligence
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 66, 6 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "-----------------------------";

	}
}	  

void DisplayAttacking() {


	// Display Attack level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 4 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Attacking level: 0/120";

	}

	// Display Attack XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 5 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Attacking XP: 0";

	}

	// Display Attack Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 6 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: 0";

	}

	// Bar under Attack 
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 66, 7 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "-----------------------------";

	}
}

void DisplayNetworking() {

	// Display Networking Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 8 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Networking level: 0/120";

	}

	// Display Networking XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 9 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Networking XP: 0";

	}

	// Display Networking Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 10 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: 0";

	}

	// Bar under Networking
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 66, 11 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "-----------------------------";

	}
}
 
void DisplaySecurity() {

	// Display Security Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 12 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Security level: 0/120";

	}

	// Display Security XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 13 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Security XP: 0";

	}

	// Display Security Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 14 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: 0";

	}

	// Bar under Security
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 66, 15 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "-----------------------------";

	}

}

void DisplayVul() {

	// Display Vulnerability Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 16 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Vulnerability level: 0/120";

	}

	// Display Vulnerability XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 17 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Vulnerability XP: 0";

	}

	// Display Vulnerability Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 18 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: 0";

	}

	// Bar under Vulnerability
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 66, 19 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "-----------------------------";
	}
}

void DisplayFunctionality() {

	// Display Functionality Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 20 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Functionality level: 0/120";

	}

	// Display Functionality XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 21 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Functionality XP: 0";

	}

	// Display Functionality Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 22 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: 0";

	}
}

int main() {

	system("mode 100, 28");

	string input;

	//CommandLineUI();					// WILL BE USED AT START OF TUTORIAL (MINUS LastPipe())
	PredictionText();					// IGNORE OF TUTOIRAL 
	UIForSuggestion();				// IGNORE FOR TUTORIAL
	DisplayExtendedCommandArea();		// When introducing skills, use this + LastPipe()
	LastPipe();						// LastPipe. 


	//DisplaySkillsTitle();
	//DisplayAttacking();
	//DisplayNetworking();
	//DisplaySecurity();
	//DisplayVul();
	//DisplayFunctionality();
	

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 1, 24 };		// tutorial = 1,26.   GAME = 1,24
		SetConsoleCursorPosition(hConsole, pos);
		cout << "C:\\Some\\Shitty\\User> ";
		getline(cin, input);		// user input
		
	}

	system("pause");
}