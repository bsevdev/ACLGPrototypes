#include <iostream>
#include <string>
#include <windows.h>
#include <thread>
#include <stdlib.h>
// --------------------------------------------------------------
// Location 1, 2, 3, 4, 
//			5, 6, 7, 8, 
//			9, A, B, C,
//			D, E, F, G, 
// --------------------------------------------------------------
//      Location: x
//	O ---- O ---- O ---- O
//	|	   | 	  |	     |
//  O ---- O      O ---- O
//		   |	  |    	 
//	O ---- H ---- O ---- O
//	|	   |	  |    	 
//	O ---- O      O ---- O
// --------------------------------------------------------------
// Location = O
// "Home" = H
// Player = Xd

// Finalise map design
// Get display working										[DONE]
// we can "move" the X player from location to location		
// we can check where we are, and display this at the top
// --------------------------------------------------------------

using namespace std;

string cmd = "";

string	location1 = "O", location2 = "O", location3 = "O", location4 = "O",
		location5 = "O", location6 = "O", location7 = "O", location8 = "O",
		location9 = "O", locationA = "H", locationB = "O", locationC = "O",
		locationD = "O", locationE = "O", locationF = "O", locationG = "O",
		player = "X";

string mapDraw[7][7] = {location1,	" --- ",	location2,	" --- ",	location3,	" --- ", location4,
							"|",	"     ",		"|",	"     ",		"|",	"     ",	"|",
						location5,	" --- ",	location6,	"     ",	location7,	" --- ", location8,
							" ",	"     ",		"|",	"     ",		"|",	"     ",	" ",
						location9,	" --- ",	locationA,	" --- ",	locationB,	" --- ", locationC,
							"|",	"     ",		"|",	"     ",		"|",	"     ",	"|",
						locationD,	" --- ",	locationE,	"     ",	locationF,	" --- ", locationG,
};

//	O ---- O ---- O ---- O
//	|	   | 	  |	     |
//  O ---- O      O ---- O
//		   |	  |    	 
//	O ---- H ---- O ---- O
//	|	   |	  |    	 
//	O ---- O      O ---- O

//						[0][0] ---- [0][2] ---- [0][4] ---- [0][6]
//						  |				|		  |		    |
//						[2][0] ---- [2][2] ---- [2][4] ---- [2][6]
//						  |				|		  |		    |
//						[4][0] ---- [4][2] ---- [4][4] ---- [4][6]
//						  |				|		  |		    |
//						[6][0] ---- [6][2] ---- [6][4] ---- [6][6]

HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);

string input;

// disable highlighting in console
void disableHighlighting() {
	DWORD prev_mode;
	GetConsoleMode(hInput, &prev_mode);
	SetConsoleMode(hInput, ENABLE_EXTENDED_FLAGS |
		(prev_mode & ~ENABLE_QUICK_EDIT_MODE));
}

// throw prompt
void alertUser() {

	// https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-flashwindowex
	// "If the window caption was drawn as active before the call -
	// - the return value is nonzero. Otherwise, the return value is zero."

	HWND yourHwnd = GetConsoleWindow();     // bad ?
	FLASHWINFO fi;
	fi.cbSize = sizeof(FLASHWINFO);
	fi.hwnd = yourHwnd;
	fi.dwFlags = FLASHW_ALL | FLASHW_TIMERNOFG;
	fi.uCount = 0;
	fi.dwTimeout = 0;
	FlashWindowEx(&fi);
}

// display map
void displayMap() {

	// cout << "\n\n\n";         // <--- for moving up and down
	
	for (int i = 0; i < 7; i++) {

		// cout << "         ";             // <--- use this area for moving the map

		for (int j = 0; j < 7; j++) {
			cout << mapDraw[i][j];
		}

		cout << '\n';
	}

}

void setDefaultPlayPos() {

	mapDraw[6][4] = player;
}

void directionFunc() {	// same as normal command input class
		
	if (cmd == "up") {
		
	}

	else if (cmd == "down") {
		
	}

	else if (cmd == "left") {
	
	}	

	else if (cmd == "right") {
	
	}

	else {
		
	}
}

#pragma region From Commands code
void displayUI() {
	cout << "-------------------------------------------------------------------------------------";
	cout << "-------------\n" << "command:  \n" << "-----------------------------------------------------";
	cout << "---------------------------------------------" << endl;
}
void pushSpace() {

	for (int i = 0; i < 36; i++) {

		cout << '\n';
	}
}

bool gameOver = false;
#pragma endregion

int main() {

	// Disables console Highlighting 
	disableHighlighting();
	//setDefaultPlayPos();

	while (gameOver == false) {

		pushSpace();
		displayMap();		// draws world map


		displayUI();
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (INVALID_HANDLE_VALUE != hConsole)
		{
			COORD pos = { 9, 44 };
			SetConsoleCursorPosition(hConsole, pos);

			getline(cin, cmd);		// user input
		}

		system("cls");
	}

	displayMap();

	system("pause");
}