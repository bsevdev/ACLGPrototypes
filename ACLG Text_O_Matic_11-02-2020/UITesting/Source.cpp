#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <stdlib.h>

using namespace std;

#pragma region
HWND console = GetConsoleWindow();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int ResX = 8300, ResY = 500, ResXFixed = 0, ResYFixed = 0, PosX = 550, PosY = 300;


void setDefConsoleSize() {

	// default size of 830 x 500
	MoveWindow(console, PosX, PosY, ResX, ResY, TRUE);
}
#pragma endregion Screen Stuff

string gameVersion = "1.0.0";
string wholeString = "A Command Line Game";

int angusX = 42;
int angusDone = 17;
int angusLoopCount = 0;
int oneOrZero;

/*
	this_thread::sleep_for(chrono::	seconds(1));
									microseconds
									milliseconds
									minutes
									hours
*/

/*
Versions: 
The left most number is called the major version
The middle is called the minor version
The right most is called the revision, point release or subminor release
*/

void pushDown() {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
}


void runTextOMatic() {

	#pragma region Display ACLG Version
	system("cls");
	pushDown();
	cout << "					ACLG [Version " << gameVersion << "]\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "			       2020 Toadflax Games. All rights deserved.";
	this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	this_thread::sleep_for(chrono::seconds(2));

	/*
	Microsoft Windows [Version 10.0.18362.592]
	(c) 2019 Microsoft Corporation. All rights reserved.
	*/
	#pragma endregion
	
	#pragma region Display title
	system("cls");
	pushDown();
	cout << "				  \"This takes ages!\" - Work Colleague" << "\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "				        Developer: @toadflax";
	this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	this_thread::sleep_for(chrono::seconds(2));
	#pragma endregion 

	#pragma region Display Quote
	system("cls");
	pushDown();
	cout << "				    \"This Game's boring\" - Mother\n";
	this_thread::sleep_for(chrono::seconds(2));
	cout << "				       Sound: @musicsartstuff";
	this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	#pragma endregion 

	// Here we print ACLG in the middle of the screen

	pushDown();
	//cout << "						ACLG";
	

	// 1. At 1 frame, we will print "A Command Line Game"
	// 2. At the frame afterwards, this is replaced and made to look exactly the same, by the 
	// variables (a, cmd, line, game)
	// 3. We then begin to move "Game" downwards until it hits a certain point.
	// 4. Then to the right until it hits a certain point
	// 5. We do this until our values are back to original.
	// 6. We then check to see if the words are all back at their starting point
	// 7. If they are, we go away. 
	// 8. This will continue to loop until the user hits a "key"

	//animation();
	
}

void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int random(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void startPause() {
	this_thread::sleep_for(chrono::seconds(1));
}

void AngusTypes() {

	srand(time(0));
	
	angusX = 42; // reset to default value

	#pragma region 
	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			
			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x

			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	system("cls");
	angusX = 42;

		// last char space
		while (angusX != 61) {

			oneOrZero = random(0, 1);

			// Position of entire string text (42, 12)
			if (INVALID_HANDLE_VALUE != hConsole)
			{

				//    pos = {across, up/down}
				COORD pos = { 43, 13 };

				SetConsoleCursorPosition(hConsole, pos);

				cout << "Angus is typing...";

			}

			// Position of entire string text (42, 12)
			if (INVALID_HANDLE_VALUE != hConsole)
			{
				if (angusX == 43) { // on first loop, make an extra space
					angusX++;
				}

				if (angusX == 51) { // on 10th loop, make extra 
					angusX++;
				}

				if (angusX == 56) {	// make extra 
					angusX++;
				}

				//    pos = {across, up/down}
				COORD pos = { angusX, 11 };

				SetConsoleCursorPosition(hConsole, pos);

				cout << oneOrZero;		// we print random 1 or 0 generated 

				//angusLoopCount++;		// we keep counting the loops
				angusX++; // we move along the x

				this_thread::sleep_for(chrono::milliseconds(50));
			}
		}

	system("cls");
	angusX = 42;

		// last char space
		while (angusX != 61) {

			oneOrZero = random(0, 1);

			// Position of entire string text (42, 12)
			if (INVALID_HANDLE_VALUE != hConsole)
			{

				//    pos = {across, up/down}
				COORD pos = { 43, 13 };

				SetConsoleCursorPosition(hConsole, pos);

				cout << "Angus is typing...";

			}

			// Position of entire string text (42, 12)
			if (INVALID_HANDLE_VALUE != hConsole)
			{
				if (angusX == 43) { // on first loop, make an extra space
					angusX++;
				}

				if (angusX == 51) { // on 10th loop, make extra 
					angusX++;
				}

				if (angusX == 56) {	// make extra 
					angusX++;
				}

				//    pos = {across, up/down}
				COORD pos = { angusX, 11 };

				SetConsoleCursorPosition(hConsole, pos);

				cout << oneOrZero;		// we print random 1 or 0 generated 

				//angusLoopCount++;		// we keep counting the loops
				angusX++; // we move along the x

				this_thread::sleep_for(chrono::milliseconds(50));
			}
		}

	system("cls");
	angusX = 42;

	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{

			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x

			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	system("cls");
	angusX = 42;

	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{

			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x

			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	system("cls");
	angusX = 42;

	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{

			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x

			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	system("cls");
	angusX = 42;

	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{

			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x

			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	system("cls");
	angusX = 42;

	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{

			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x

			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	system("cls");
	angusX = 42;

	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{

			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x

			this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	system("cls");
	angusX = 42;

	// last char space
	while (angusX != 61) {

		oneOrZero = random(0, 1);

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{

			//    pos = {across, up/down}
			COORD pos = { 43, 13 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << "Angus is typing...";

		}

		// Position of entire string text (42, 12)
		if (INVALID_HANDLE_VALUE != hConsole)
		{
			if (angusX == 43) { // on first loop, make an extra space
				angusX++;
			}

			if (angusX == 51) { // on 10th loop, make extra 
				angusX++;
			}

			if (angusX == 56) {	// make extra 
				angusX++;
			}

			//    pos = {across, up/down}
			COORD pos = { angusX, 11 };

			SetConsoleCursorPosition(hConsole, pos);

			cout << oneOrZero;		// we print random 1 or 0 generated 

			//angusLoopCount++;		// we keep counting the loops
			angusX++; // we move along the x
			

			//this_thread::sleep_for(chrono::milliseconds(50));
		}
	}

	/*system("cls");
	angusX = 42;

	this_thread::sleep_for(chrono::seconds(2));
	system("cls");*/
	system("cls");

	// Position of entire string text (42, 12)
	if (INVALID_HANDLE_VALUE != hConsole)
	{
		//         pos = {across, up/down}
		COORD pos = { 42, 11 };

		SetConsoleCursorPosition(hConsole, pos);

		cout << wholeString;
	}

#pragma endregion Entire Animation 



}

void moveTitleShowBack() {

	// set up < Back button
	this_thread::sleep_for(chrono::seconds(2));


}

int main() {

	#pragma region
	setDefConsoleSize();
	hidecursor();
	system("screenBuffer.bat");
	#pragma endregion 


	runTextOMatic();
	startPause();
	AngusTypes();
	moveTitleShowBack();
	

	system("pause");
}