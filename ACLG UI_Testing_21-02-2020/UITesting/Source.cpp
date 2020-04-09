#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <stdlib.h>

using namespace std;

// ALL SKILL VALUES
int AL_value = 0, AR_value = 0, AX_value = 0;
int FL_value = 0, FR_value = 0, FX_value = 0;
int NL_value = 0, NR_value = 0, NX_value = 0;
int SL_value = 0, SR_value = 0, SX_value = 0;
int VL_value = 0, VR_value = 0, VX_value = 0;
int TX_value = 0;

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

	// we can call extended
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

// function displaying the SKILLS  title
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

// display ATTACK skill and all stats
void DisplayAttacking() {


	// Display Attack level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 4 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Attacking level: " << AL_value << "/120";

	}

	// Display Attack XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 5 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Attacking XP: " << AX_value << "";

	}

	// Display Attack Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 6 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: " << AR_value << "";

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

// display NETWORKING skill and all stats
void DisplayNetworking() {

	// Display Networking Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 8 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Networking level: " << NL_value << "/120";

	}

	// Display Networking XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 9 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Networking XP: " << NX_value << "";

	}

	// Display Networking Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 10 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: " << NR_value << "";

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
 
// display SECURITY skill and all stats
void DisplaySecurity() {

	// Display Security Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 12 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Security level: " << SL_value << "/120";

	}

	// Display Security XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 13 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Security XP: " << SX_value << "";

	}

	// Display Security Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 14 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: " << SR_value << "";

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

// display VULNERABILITY skill and all stats
void DisplayVul() {

	// Display Vulnerability Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 16 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Vulnerability level: " << VL_value << "/120";

	}

	// Display Vulnerability XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 17 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Vulnerability XP: " << VX_value << "";

	}

	// Display Vulnerability Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 18 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: " << VR_value << "";

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

// display FUNCTIONALITY skill and all stats
void DisplayFunctionality() {

	// Display Functionality Level
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 20 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Functionality level: " << FL_value << "/120";

	}

	// Display Functionality XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 21 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Functionality XP: " << FX_value << "";

	}

	// Display Functionality Remaining XP
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 67, 22 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << "Remaining XP: " << FR_value << "";

	}
}

void UseUI() {
	string command_Input;

	//CommandLineUI();					// WILL BE USED AT START OF TUTORIAL (MINUS LastPipe())
	PredictionText();					// IGNORE OF TUTOIRAL 
	UIForSuggestion();					// IGNORE FOR TUTORIAL
	DisplayExtendedCommandArea();		// When introducing skills, use this + LastPipe()
	LastPipe();							// LastPipe. 

	DisplaySkillsTitle();
	DisplayAttacking();
	DisplayNetworking();
	DisplaySecurity();
	DisplayVul();
	DisplayFunctionality();

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 1, 24 };		// tutorial = 1,26.   GAME = 1,24
		SetConsoleCursorPosition(hConsole, pos);
		cout << "C:\\Some\\Shitty\\User> ";
		getline(cin, command_Input);		// user input

	}
}

int main() {

	system("mode 100, 28");

	UseUI();

	system("pause");
}