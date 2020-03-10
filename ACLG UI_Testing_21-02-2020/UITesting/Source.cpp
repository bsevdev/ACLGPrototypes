#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <stdlib.h>

using namespace std;

// <<<<<<<<<<<<< TDL >>>>>>>>>>>>>
// why doesn't screen res change??
// consider ncurses?

// Tip: Move cursor before printing text

#pragma region
HWND console = GetConsoleWindow();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int ResX = 8300, ResY = 500, ResXFixed = 0, ResYFixed = 0, PosX = 550, PosY = 300;


void setDefConsoleSize() {

	// default size of 830 x 500
	MoveWindow(console, PosX, PosY, ResX, ResY, TRUE);
}
#pragma endregion Screen Stuff

const string drawCommandArea[1][2] = {	"----------------------------------------------------------------------------------------------------",
										"----------------------------------------------------------------------------------------------------"};

const string drawExtendedCommandArea[1][28] = {	"|","|", "|", "|", "|", "|", "|", "|", "|", 
												"|", "|", "|", "|", "|", "|", "|", "|","|",
												"|", "|", "|", "|", "|", "|", "|", "|", "|",	
												 "|",};

// will print the drawCommandArea
void displayCommandArea() {
	
	cout << "\n\n\n\n\n\n\n\n\n\n";         // <--- for moving up and down
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\n\n\n\n\n\n";

	for (int i = 0; i < 2; i++) {

		// cout << "         ";             // <--- use this area for moving the map
		cout << "\n";

		for (int j = 0; j < 1; j++) {
			cout << drawCommandArea[j][i];
		}

		cout << '\n';
	}
}

void commandLineUI() {
	cout << "\n\n\n\n\n\n\n\n\n\n";         // <--- for moving up and down
	cout << "\n\n\n\n\n\n\n\n\n\n";
	cout << "\n\n\n\n\n";
	cout << "----------------------------------------------------------------------------------------------------";
	//cout << "____________________________________________________________________________________________________";
}

void commandLineUIForExtended() {
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 0, 26 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "-----------------------------------------------------------------";

	}
	//cout << "----------------------------------------------------------------------------------------------------";
	//cout << "____________________________________________________________________________________________________";
}

void predictionSpace() {

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 1, 27 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "Command Suggestion: ";

	}

}

void commandLineUIForSuggestion() {

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 0, 24 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "-----------------------------------------------------------------";

	}

	
	
	//cout << "----------------------------------------------------------------------------------------------------";
	//cout << "____________________________________________________________________________________________________";
}

// displays the last Pipe character at the bottom of the screen
void lastPipe() {

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 30, 28 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "								|";

	}

}

void displayExtendedCommandArea() {

	commandLineUIForExtended();

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

void displaySkillsTitle() {

	// Display Intelligence Skill
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 78, 1 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Skills";

	}

	// Display Intelligence Skill
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 75, 2 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "------------";

	}
}

void displayIntelligence() {
#pragma region Intelligence Skills
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
#pragma endregion 
}

void displayAttacking() {

#pragma region Attack Skill

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
#pragma endregion 
}

void displayNetworking() {
#pragma region Networking Skill

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
#pragma endregion 
}
 
void displaySecurity() {
#pragma region Security Skill 

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
#pragma endregion 

}

void displayVul() {
#pragma region Vulnerability Skill

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
#pragma endregion 
}

void displayFunctionality() {
#pragma region Functionality Skill

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
#pragma endregion 
}

int main() {

	#pragma region
	setDefConsoleSize();
	system("screenBuffer.bat");
	#pragma endregion 

	string input;

	//commandLineUI();
	predictionSpace();
	commandLineUIForSuggestion();
	displayExtendedCommandArea();
	lastPipe();
	displaySkillsTitle();
	//displayIntelligence();
	displayAttacking();
	displayNetworking();
	displaySecurity();
	displayVul();
	displayFunctionality();
	

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 1, 24 };
		SetConsoleCursorPosition(hConsole, pos);
		cout << "C:\\Some\\Shitty\\User> ";
		getline(cin, input);		// user input
		
	}

	system("pause");
}