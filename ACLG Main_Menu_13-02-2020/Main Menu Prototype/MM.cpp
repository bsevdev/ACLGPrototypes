#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <mmsystem.h>
#include <cstdlib>
#include <thread>

// Add to define
#define std_con_out GetStdHandle(STD_OUTPUT_HANDLE)	// for adding colours to text


// Already added, ignore.
#define KEY_UP 72		// Key defines & codes
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESCAPE 27

using namespace std;

#pragma region
//NOT GLOBAL
bool gameOver = false;					// checks gameOver state
bool inMainMenu = true;					// triggers when user is on page: Main Menu
bool inOptionMenu = false;				// triggers when user is on page: Options Menu
bool inMiscMenu = false;				// triggers when user is on page: Misc Menu
bool inSoundMenu = false;				// triggers when user is on page: Audio Menu
bool inPrefMenu = false;				// triggers when user is on page: Preference Menu
bool inGraphicsMenu = false;			// triggers when user is on page: Graphics Menu
bool inHowToPushMenu = false;			// triggers when user is on page: "How To Push" Menu
bool inTextOMaticMenu = false;			// triggers when user is on page: Text-OMatic
#pragma endregion bools?

// menu max [NOTES] this will changes is there's another option(s) added.
int endIndex = 5;

#pragma region
// Handles, global variables
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#pragma endregion Iggy

#pragma region
string gameVersion = "1.0.0";					// version 
string wholeString = "A Command Line Game";		// full ACLG string

// default pos of random 0's and 1's
short int angusX = 42;
// how many loops it takes to finish each line of numbers
int angusDone = 17;
// current loop count
int angusLoopCount = 0;
// our random number to print
int oneOrZero;
#pragma endregion Carry from Text-O-Matic

// current option in the above (bool) menus
int option = 0;

// colour selection
enum concol
{
	// we are able to pick between 16 colours to text or background
	black = 0,
	dark_blue = 1,
	dark_green = 2,
	dark_aqua, dark_cyan = 3,
	dark_red = 4,
	dark_purple = 5, dark_pink = 5, dark_magenta = 5,
	dark_yellow = 6,
	dark_white = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
};

// setting colour
void setcolor(concol textcol, concol backcol)
{
	// we set the colour here
	int textColour = (int)textcol;
	int backColour = (int)backcol;
	textColour = textColour % 16;
	backColour = backColour % 16;
	unsigned short wAttributes = ((unsigned)backColour << 4) | (unsigned)textColour;
	SetConsoleTextAttribute(std_con_out, wAttributes);
}

// moving text t the middle
void moveToMiddle() {
	
	cout << "\n\n\n\n\n\n\n\n\n";
}

#pragma region
string mainMenuItems[6] = { "Play",		"Tutorial",		"How To Push",		"Name Change",		"Options",		"Quit", };	// list for main menu
string optionsMenuItems[5] = { "Graphics",	"Preferences" , "Audio" , "Misc", "Back"};										// list for options menu
string miscMenuItems[3] = { "Text-O-Matic", "Credits" , "Back" };															// list of misc menu
string soundMenuItems[3] = { "Mute Music","Mute SFX", "Back"};																// list of sound options 
string prefMenuItems[3] = { "Text Cursor", "Alerts", "Back"};																// list of preferences options
string graphicMenuItems[3] = {"Screen Size", "Screen Buffer", "Back"};														// graphics options
string howToPushItems[1] = {"< Back to Main Menu"};																			// "How to push" instructions with < back button
string textOMaticItems[1] = { "< Back" };																					// textOMatic with < back button
string titleItem[1] = {""};		// changes value depending on what title we are on.
#pragma endregion Arrays 


//NOT GLOBAL
// music booleans (music)
bool muteMusicEnabled = true;
bool muteSoundEffectsEnabled = true;

// preference booleans
bool textCursorEnabled = true;
bool alertsEnabled = true;

// graphics booleans
bool screenSizeEnabled = true;
bool screenBufferEnabled = true;

// Function for displaying all credits. To be edited.
void rollCredits() {
	
	system("cls");
	std::this_thread::sleep_for(chrono::seconds(2));
	moveToMiddle();
	cout << "				    ";
	cout << "A Command Line Game\n";
	std::this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	std::this_thread::sleep_for(chrono::seconds(2));
	moveToMiddle();
	cout << "				    ";
	cout << "Developer: @toadflax.\n";
	std::this_thread::sleep_for(chrono::seconds(3));
	system("cls");
	std::this_thread::sleep_for(chrono::seconds(2));
	moveToMiddle();
	cout << "				    ";
	cout << "Audio: @musicvsartstuff.\n";
	std::this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	std::this_thread::sleep_for(chrono::seconds(2));
	moveToMiddle();
	cout << "				    ";
	cout << "Live updates: @playcmd.\n";
	std::this_thread::sleep_for(chrono::seconds(3));
	system("cls");
	std::this_thread::sleep_for(chrono::seconds(2));
	moveToMiddle();
	cout << "				    ";
	cout << "Testers: Lewis Crawley, ";
	std::this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	std::this_thread::sleep_for(chrono::seconds(2));
	moveToMiddle();
	cout << "				    ";
	cout << "Thank you for playing!";
	std::this_thread::sleep_for(chrono::seconds(2));
	system("cls");
	std::this_thread::sleep_for(chrono::seconds(1));

}

// Displays our game menu. 
void MainMenuList() {

	// ONCE WE FIND NEW COLOURS, REMOVE
	setcolor(white, black);

	// Menu here (Play, Settings, Credits, Exit)
	// by default, option "Play will be highlighted

	moveToMiddle();

	// Option Play
	if (option == 0) {

		#pragma region 
		cout << "				         ";
		titleItem[0] = "[A Command Line Game]";
		cout << titleItem[0] << "\n\n";
		#pragma endregion Main Menu Title
	
		// changes appearahcne of these options whilst on others
		mainMenuItems[2] = "How To Push";
		mainMenuItems[3] = "Name Change";
		mainMenuItems[4] = "Options";

		cout << "				          ";
		setcolor(black, white);
		cout << mainMenuItems[option] << endl;	// highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << mainMenuItems[1] << endl;	
		cout << "				          ";
		cout << mainMenuItems[2] << endl;
		cout << "				          ";
		cout << mainMenuItems[3] << endl;
		cout << "				          ";
		cout << mainMenuItems[4] << endl;
		cout << "				          ";
		cout << mainMenuItems[5] << endl;
	}

	// Option Tutorial
	if (option == 1) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[A Command Line Game]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		mainMenuItems[2] = "How To Push";
		mainMenuItems[3] = "Name Change";
		mainMenuItems[4] = "Options";

		cout << "				          ";
		cout << mainMenuItems[0] << endl;	
		cout << "				          ";
		setcolor(black, white);
		cout << mainMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << mainMenuItems[2] << endl;
		cout << "				          ";
		cout << mainMenuItems[3] << endl;
		cout << "				          ";
		cout << mainMenuItems[4] << endl;
		cout << "				          ";
		cout << mainMenuItems[5] << endl;
	}

	// Push Help
	if (option == 2) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[A Command Line Game]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		mainMenuItems[option] = "How To Push >";
		mainMenuItems[3] = "Name Change";
		mainMenuItems[4] = "Options";

		cout << "				          ";
		cout << mainMenuItems[0] << endl;	
		cout << "				          ";
		cout << mainMenuItems[1] << endl; 
		cout << "				          ";
		setcolor(black, white);
		cout << mainMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << mainMenuItems[3] << endl;
		cout << "				          ";
		cout << mainMenuItems[4] << endl;
		cout << "				          ";
		cout << mainMenuItems[5] << endl;
	}

	// Change Name
	if (option == 3) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[A Command Line Game]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		mainMenuItems[option] = "Change Name >";
		mainMenuItems[2] = "How To Push";
		mainMenuItems[4] = "Options";

		cout << "				          ";
		cout << mainMenuItems[0] << endl;
		cout << "				          ";
		cout << mainMenuItems[1] << endl;
		cout << "				          ";
		cout << mainMenuItems[2] << endl; // highlight selected option
		cout << "				          ";
		setcolor(black, white);
		cout << mainMenuItems[option] << endl;
		setcolor(white, black);
		cout << "				          ";
		cout << mainMenuItems[4] << endl;
		cout << "				          ";
		cout << mainMenuItems[5] << endl;
	}

	// Options
	if (option == 4) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[A Command Line Game]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		mainMenuItems[option] = "Options >";
		mainMenuItems[2] = "How To Push";
		mainMenuItems[3] = "Name Change";

		cout << "				          ";
		cout << mainMenuItems[0] << endl;
		cout << "				          ";
		cout << mainMenuItems[1] << endl;
		cout << "				          ";
		cout << mainMenuItems[2] << endl; // highlight selected option
		cout << "				          ";
		cout << mainMenuItems[3] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << mainMenuItems[option] << endl;
		setcolor(white, black);
		cout << "				          ";
		cout << mainMenuItems[5] << endl;
	}

	// Quit
	if (option == 5) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[A Command Line Game]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		mainMenuItems[2] = "How To Push";
		mainMenuItems[3] = "Name Change";
		mainMenuItems[4] = "Options";

		cout << "				          ";
		cout << mainMenuItems[0] << endl;
		cout << "				          ";
		cout << mainMenuItems[1] << endl;
		cout << "				          ";
		cout << mainMenuItems[2] << endl; // highlight selected option
		cout << "				          ";
		cout << mainMenuItems[3] << endl;
		cout << "				          ";
		cout << mainMenuItems[4] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << mainMenuItems[option] << endl;
		setcolor(white, black);
	}

	//cout << option;
}

// Displays our option menu.
void OptionsMenu() {

	moveToMiddle();
	// Graphics 
	if (option == 0) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Options]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		optionsMenuItems[0] = "Graphics >";
		optionsMenuItems[1] = "Preferences";
		optionsMenuItems[2] = "Sound";
		optionsMenuItems[3] = "Misc";
		optionsMenuItems[4] = "Back";

		cout << "				          ";
		setcolor(black, white);
		cout << optionsMenuItems[option] << endl;	// highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << optionsMenuItems[1] << endl;
		cout << "				          ";
		cout << optionsMenuItems[2] << endl;
		cout << "				          ";
		cout << optionsMenuItems[3] << endl;
		cout << "\n";
		cout << "				          ";
		cout << optionsMenuItems[4] << endl;
	}

	// Preferences
	if (option == 1) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Options]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		optionsMenuItems[0] = "Graphics";
		optionsMenuItems[1] = "Preferences >";
		optionsMenuItems[2] = "Sound";
		optionsMenuItems[3] = "Misc";
		optionsMenuItems[4] = "Back";

		cout << "				          ";
		cout << optionsMenuItems[0] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << optionsMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << optionsMenuItems[2] << endl;
		cout << "				          ";
		cout << optionsMenuItems[3] << endl;
		cout << "\n";
		cout << "				          ";
		cout << optionsMenuItems[4] << endl;
	}

	// Sound
	if (option == 2) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Options]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		optionsMenuItems[0] = "Graphics";
		optionsMenuItems[1] = "Preferences";
		optionsMenuItems[2] = "Sound >";
		optionsMenuItems[3] = "Misc";
		optionsMenuItems[4] = "Back";

		cout << "				          ";
		cout << optionsMenuItems[0] << endl;
		cout << "				          ";
		cout << optionsMenuItems[1] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << optionsMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << optionsMenuItems[3] << endl;
		cout << "\n";
		cout << "				          ";
		cout << optionsMenuItems[4] << endl;
	}

	// Misc
	if (option == 3) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Options]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		optionsMenuItems[0] = "Graphics";
		optionsMenuItems[1] = "Preferences";
		optionsMenuItems[2] = "Sound";
		optionsMenuItems[3] = "Misc >";
		optionsMenuItems[4] = "Back";

		cout << "				          ";
		cout << optionsMenuItems[0] << endl;
		cout << "				          ";
		cout << optionsMenuItems[1] << endl;
		cout << "				          ";
		cout << optionsMenuItems[2] << endl; // highlight selected option
		cout << "				          ";
		setcolor(black, white);
		cout << optionsMenuItems[option] << endl;
		setcolor(white, black);
		cout << "\n";
		cout << "				          ";
		cout << optionsMenuItems[4] << endl;
	}

	// Back
	if (option == 4) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Options]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		optionsMenuItems[0] = "Graphics";
		optionsMenuItems[1] = "Preferences";
		optionsMenuItems[2] = "Sound";
		optionsMenuItems[3] = "Misc";
		optionsMenuItems[4] = "< Back";

		cout << "				          ";
		cout << optionsMenuItems[0] << endl;
		cout << "				          ";
		cout << optionsMenuItems[1] << endl;
		cout << "				          ";
		cout << optionsMenuItems[2] << endl; // highlight selected option
		cout << "				          ";
		cout << optionsMenuItems[3] << endl;
		cout << "\n";
		cout << "				          ";
		setcolor(black, white);
		cout << optionsMenuItems[option] << endl;
		setcolor(white, black);
	}
	
}

// Displays our Misc menu.
void miscMenu() {

	moveToMiddle();
	// Text-O-Matic
	if (option == 0) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[Miscellaneous]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		miscMenuItems[2] = "Back";

		cout << "				          ";
		setcolor(black, white);
		cout << miscMenuItems[option] << endl;	// highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << miscMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		cout << miscMenuItems[2] << endl;
	}

	// Credits
	if (option == 1) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[Miscellaneous]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		miscMenuItems[2] = "Back";

		cout << "				          ";
		cout << miscMenuItems[0] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << miscMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "\n";
		cout << "				          ";
		cout << miscMenuItems[2] << endl;
	}

	// Back
	if (option == 2) {

#pragma region 
		cout << "				         ";
		titleItem[0] = "[Miscellaneous]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		miscMenuItems[2] = "< Back";

		cout << "				          ";
		cout << miscMenuItems[0] << endl;
		cout << "				          ";
		cout << miscMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		setcolor(black, white);
		cout << miscMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
	}

	
}

// Displays our Audio menu.
void soundMenu() {
	moveToMiddle();

	// Mute Music
	if (option == 0) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Sound]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		// status checks
		if (muteMusicEnabled == true) {
			soundMenuItems[0] = "Mute Music:On";
		}

		else if (muteMusicEnabled == false) {
			soundMenuItems[0] = "Mute Music:Off";
		}
		
		// resets
		soundMenuItems[2] = "Back";
		soundMenuItems[1] = "Mute SFX";

		cout << "				          ";
		setcolor(black, white);
		cout << soundMenuItems[option] << endl;	// highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << soundMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		cout << soundMenuItems[2] << endl;
	}

	// Mute Sfx
	if (option == 1) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Sound]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		// status checks
		if (muteSoundEffectsEnabled == true) {
			soundMenuItems[1] = "Mute SFX:On";
		}

		else if (muteSoundEffectsEnabled == false) {
			soundMenuItems[1] = "Mute SFX:Off";
		}

		// resets
		soundMenuItems[2] = "Back";
		soundMenuItems[0] = "Mute Music";

		cout << "				          ";
		cout << soundMenuItems[0] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << soundMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "\n";
		cout << "				          ";
		cout << soundMenuItems[2] << endl;
	}

	// Back
	if (option == 2) {

#pragma region 
		cout << "				            ";
		titleItem[0] = "[Sound]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		soundMenuItems[0] = "Mute Music";
		soundMenuItems[1] = "Mute SFX";
		soundMenuItems[2] = "< Back";

		cout << "				          ";
		cout << soundMenuItems[0] << endl;
		cout << "				          ";
		cout << soundMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		setcolor(black, white);
		cout << soundMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
	}
	
}

// Displays our Preference menu.
void prefMenu() {
	moveToMiddle();

	// Show Cursor
	if (option == 0) {

#pragma region 
		cout << "				          ";
		titleItem[0] = "[Preferences]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		// status checks
		if (textCursorEnabled == true) {
			prefMenuItems[0] = "Text Cursor:On";
		}

		else if (textCursorEnabled == false) {
			prefMenuItems[0] = "Text Cursor:Off";
		}

		// resets
		prefMenuItems[2] = "Back";
		prefMenuItems[1] = "Alerts";

		cout << "				          ";
		setcolor(black, white);
		cout << prefMenuItems[option] << endl;	// highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << prefMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		cout << prefMenuItems[2] << endl;
	}

	// Alerts
	if (option == 1) {

#pragma region 
		cout << "				          ";
		titleItem[0] = "[Preferences]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		// status checks
		if (alertsEnabled == true) {
			prefMenuItems[1] = "Alerts:On";
		}

		else if (alertsEnabled == false) {
			prefMenuItems[1] = "Alerts:Off";
		}

		// resets
		prefMenuItems[2] = "Back";
		prefMenuItems[0] = "Text Cursor";

		cout << "				          ";
		cout << prefMenuItems[0] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << prefMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "\n";
		cout << "				          ";
		cout << prefMenuItems[2] << endl;
	}

	// Back
	if (option == 2) {

#pragma region 
		cout << "				          ";
		titleItem[0] = "[Preferences]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		prefMenuItems[0] = "Text Cursor";
		prefMenuItems[1] = "Alerts";
		prefMenuItems[2] = "< Back";

		cout << "				          ";
		cout << prefMenuItems[0] << endl;
		cout << "				          ";
		cout << prefMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		setcolor(black, white);
		cout << prefMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
	}
}

// Displays our Graphics menu.
void graphicsMenu() {
	moveToMiddle();

	// Screen Size
	if (option == 0) {

#pragma region 
		cout << "				             ";
		titleItem[0] = "[Graphics]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		// status checks
		if (screenSizeEnabled == true) {
			graphicMenuItems[0] = "Screen Size:(TBA)";
		}

		else if (screenSizeEnabled == false) {
			graphicMenuItems[0] = "Screen Size:(TBA)";
		}

		// resets
		graphicMenuItems[2] = "Back";
		graphicMenuItems[1] = "Screen Buffer";

		cout << "				          ";
		setcolor(black, white);
		cout << graphicMenuItems[option] << endl;	// highlight selected option
		setcolor(white, black);
		cout << "				          ";
		cout << graphicMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		cout << graphicMenuItems[2] << endl;
	}

	// Screen Buffer
	if (option == 1) {

#pragma region 
		cout << "				             ";
		titleItem[0] = "[Graphics]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		// status checks
		if (screenBufferEnabled == true) {
			graphicMenuItems[1] = "Screen Buffer:(TBA)";
		}

		else if (screenBufferEnabled == false) {
			graphicMenuItems[1] = "Screen Buffer:(TBA)";
		}

		// resets
		graphicMenuItems[2] = "Back";
		graphicMenuItems[0] = "Screen Size";

		cout << "				          ";
		cout << graphicMenuItems[0] << endl;
		cout << "				          ";
		setcolor(black, white);
		cout << graphicMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
		cout << "\n";
		cout << "				          ";
		cout << graphicMenuItems[2] << endl;
	}

	// Back
	if (option == 2) {

#pragma region 
		cout << "				             ";
		titleItem[0] = "[Graphics]";
		cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

		graphicMenuItems[0] = "Screen Size";
		graphicMenuItems[1] = "Screen Buffer";
		graphicMenuItems[2] = "< Back";

		cout << "				          ";
		cout << graphicMenuItems[0] << endl;
		cout << "				          ";
		cout << graphicMenuItems[1] << endl;
		cout << "\n";
		cout << "				          ";
		setcolor(black, white);
		cout << graphicMenuItems[option] << endl; // highlight selected option
		setcolor(white, black);
	}
}

// IGNORE
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

// Displays How to push instructions and BACK
void displayBackFromHowToPush() {

	system("cls");
	// short delay before start 
	std::this_thread::sleep_for(chrono::seconds(1));
	// "move to middle"
	cout << "\n\n\n\n";

#pragma region 
	cout << "				           ";
	titleItem[0] = "[How To Push]";
	cout << titleItem[0] << "\n\n";
#pragma endregion Main Menu Title

	std::this_thread::sleep_for(chrono::seconds(1));
	cout << "				       ";
	cout << "1. Save your progress.";
	cout << "\n\n";

	std::this_thread::sleep_for(chrono::seconds(2));
	cout << "				 ";
	cout << "2. Head over to (www.playcmd.net).";
	cout << "\n\n";

	std::this_thread::sleep_for(chrono::seconds(2));
	cout << "	     ";
	cout << "3. Copy and past contents from c:\\ACLG\\User\\username\\Data\\HN.txt to HN Data.";
	cout << "\n\n";

	std::this_thread::sleep_for(chrono::seconds(2));
	cout << "	       ";
	cout << "4. Copy and past contents from c:\\ACLG\\User\\usermae\\SS\\TX.txt to TX Data.";
	cout << "\n\n";

	std::this_thread::sleep_for(chrono::seconds(2));
	cout << "	         ";
	cout << "5. Copy and past contents from c:\\ACLG\\User\\PC\\ID.txt to UniqueID.";
	cout << "\n\n";

	std::this_thread::sleep_for(chrono::seconds(2));
	cout << "					      ";
	cout << "6. Push!";
	cout << "\n\n";

	if (option == 0) {
		std::this_thread::sleep_for(chrono::seconds(4));
		cout << "\n\n";
		cout << "				         ";
		setcolor(black, white);
		cout << howToPushItems[option] << endl;
		setcolor(white, black);
	}

}

// Pushes our text
void pushDown() {

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
}

// IGNORE
int random(int from, int to) {
	return rand() % (to - from + 1) + from;
}

// [FIRST] function for Textomatic
void runTextOMatic() {

	system("cls");
	std::this_thread::sleep_for(chrono::seconds(1));

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

// [SECOND] function for textomatic
void AngusTypes() {

	srand((unsigned int)time(0));

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

// [THIRD] function for textomatic
void moveTitleShowBack() {

	// set up < Back button

	if (option == 0) {
		std::this_thread::sleep_for(chrono::seconds(2));
		cout << "\n\n";
		cout << "				                ";
		setcolor(black, white);
		cout << textOMaticItems[option] << endl;
		setcolor(white, black);
	}

}

// This function carries out usage of the Main Menu
void MM(){

	// we set main menu as true and load as this was the request
	// menu set to true by default.
	if (inMainMenu == true) {
		inOptionMenu = false;
		MainMenuList();				// call menu. 
	}

	do {

		int c = 0;

		while (1)
		{
			c = 0;

			// menu "hit" variables#
			// (endHit) main = 5, options = 3

			switch ((c = _getch())) {
			case KEY_UP:

#pragma region 
				// option does nothing if it is smaller than 0
				if (option <= 0) {

				}

				// moves UP in every named menu list
				else if (inMainMenu == true) {
					system("cls");
					--option;
					MainMenuList();
				}

				else if (inOptionMenu == true) {
					system("cls");
					--option;
					OptionsMenu();
				}

				else if (inMiscMenu == true) {
					system("cls");
					--option;
					miscMenu();
				}

				else if (inSoundMenu == true) {
					--option;
					system("cls");
					soundMenu();
				}

				else if (inPrefMenu == true) {
					--option;
					system("cls");
					prefMenu();
				}

				else if (inGraphicsMenu == true) {
					--option;
					system("cls");
					graphicsMenu();
				}

#pragma endregion Key Up Actions 

				break;
			case KEY_DOWN:

#pragma region 
				// option is never larger than the last index
				if (option >= endIndex) {

				}

				// go DOWN on each menu list mentioned
				else if (inMainMenu == true) {
					system("cls");
					++option;
					MainMenuList();
				}

				else if (inOptionMenu == true) {
					system("cls");
					++option;
					OptionsMenu();
				}

				else if (inMiscMenu == true) {
					system("cls");
					++option;
					miscMenu();
				}

				else if (inSoundMenu == true) {
					system("cls");
					++option;
					soundMenu();
				}

				else if (inPrefMenu == true) {
					system("cls");
					++option;
					prefMenu();
				}

				else if (inGraphicsMenu == true) {
					system("cls");
					++option;
					graphicsMenu();
				}
#pragma endregion Key Down Actions

				break;

			case KEY_LEFT:

#pragma region 
				// head BACK to main menu
				if (option == 4 && inOptionMenu == true) {

					system("cls");
					option = 0;	// reset pos
					endIndex = 5;
					inOptionMenu = false;
					inMainMenu = true;
					MainMenuList();
				}

				// head BACK TO [OPTIONS] FROM MISC
				else if (option == 2 && inMiscMenu == true) {
					system("cls");
					option = 3;	// keep that previous pos
					endIndex = 4;
					inOptionMenu = true;
					inMiscMenu = false;
					OptionsMenu();
				}

				// head BACK TO [OPTIONS] FROM SOUND
				else if (option == 2 && inSoundMenu == true) {
					system("cls");
					option = 2;	// keep that previous pos
					endIndex = 4;
					inOptionMenu = true;
					inSoundMenu = false;
					OptionsMenu();
				}

				// head BACK TO [OPTIONS] FROM PREF
				else if (option == 2 && inPrefMenu == true) {
					system("cls");
					option = 1;	// keep that previous pos
					endIndex = 4;
					inOptionMenu = true;
					inPrefMenu = false;
					OptionsMenu();
				}

				// head BACK TO [OPTIONS] FROM GRAPHICS
				else if (option == 2 && inGraphicsMenu == true) {
					system("cls");
					option = 0;	// reset pos
					endIndex = 4;
					inOptionMenu = true;
					inGraphicsMenu = false;
					OptionsMenu();
				}

				// head BACK TO [MENU] FROM HOW TO GUIDE
				else if (option == 0 && inHowToPushMenu == true) {
					system("cls");
					this_thread::sleep_for(chrono::seconds(1));
					option = 2;	// reset pos
					endIndex = 5;
					inMainMenu = true;
					inHowToPushMenu = false;
					MainMenuList();
				}

				// head BACK TO [MISC] FROM TEXT
				else if (option == 0 && inTextOMaticMenu == true) {
					system("cls");
					option = 0;	// reset pos
					endIndex = 2;
					inMiscMenu = true;
					inTextOMaticMenu = false;
					miscMenu();
				}
#pragma endregion Key Left Actions 

				break;
			case KEY_RIGHT:

#pragma region 
				// LOAD OPTIONS MENU
				if (option == 4 && inMainMenu == true) {
					// load options menu

					inOptionMenu = true;
					inMainMenu = false;

					system("cls");
					option = 0; // options is now 14
					endIndex = 4;	// how far we can go down on options menu
					OptionsMenu();

					//cout << "Load options!";
				}

				// LOAD CHANGE NAME MENU
				else if (option == 3 && inMainMenu == true) {
					// load change name

					cout << "Change name!";
				}

				else if (option == 2 && inMainMenu == true) {
					// load push name
					// load options menu

					inHowToPushMenu = true;
					inMainMenu = false;

					system("cls");
					option = 0; // options is now 14
					endIndex = 0;	// how far we can go down on options menu
					displayBackFromHowToPush();
				}

				// LOAD MISC MENU
				else if (option == 3 && inOptionMenu == true) {

					inOptionMenu = false;
					inMiscMenu = true;

					system("cls");
					option = 0; // options is now 14
					endIndex = 2;	// how far we can go down on options menu
					miscMenu();

				}

				// LOAD SOUND MENU
				else if (option == 2 && inOptionMenu == true) {
					inOptionMenu = false;
					inSoundMenu = true;

					system("cls");
					option = 0; // options is now 14
					endIndex = 2;	// how far we can go down on options menu
					soundMenu();
				}

				// LOAD PREFERENCES MENU
				else if (option == 1 && inOptionMenu == true) {
					inOptionMenu = false;
					inPrefMenu = true;

					system("cls");
					option = 0; // options is now 14
					endIndex = 2;	// how far we can go down on options menu
					prefMenu();

				}

				// LOAD GRAPHICS MENU
				else if (option == 0 && inOptionMenu == true) {
					inOptionMenu = false;
					inGraphicsMenu = true;

					system("cls");
					option = 0; // options is now 14
					endIndex = 2;	// how far we can go down on options menu
					graphicsMenu();

				}

#pragma endregion Key Right Actions

				break;
			case KEY_ENTER:

#pragma region 
				// EXIT game
				if (option == 5 && inMainMenu == true) {
					exit(0);
				}

				// PLAYS THE GAME
				else if (option == 0 && inMainMenu == true) {
					cout << "Play the game!!";
				}

				// LOADS TUTORIAL
				else if (option == 1 && inMainMenu == true) {
					cout << "Load tutorial!";
				}

				// LOADS TEXT-O-MATIC
				else if (option == 0 && inMiscMenu == true) {
					inMiscMenu = false;
					inTextOMaticMenu = true;
					runTextOMatic();
					this_thread::sleep_for(chrono::seconds(1));
					AngusTypes();
					moveTitleShowBack();
					//option = 0;		// reset option
					//miscMenu();		// load previous menu
				}

				// LOADS CREDITS
				else if (option == 1 && inMiscMenu == true) {
					rollCredits();
					option = 0;
					miscMenu();
				}

				// MUTES MUSIC
				else if (option == 0 && inSoundMenu == true) {
					system("cls");

					// if it's off, turn it on, if it's on, turn it off
					if (muteMusicEnabled == true) {
						muteMusicEnabled = false;
					}

					else if (muteMusicEnabled == false) {
						muteMusicEnabled = true;
					}

					soundMenu();	// show sound menu
				}

				// MUTES MUSIC SOUND EFFECTS
				else if (option == 1 && inSoundMenu == true) {
					system("cls");

					// if it's off, turn it on, if it's on, turn it off
					if (muteSoundEffectsEnabled == true) {
						muteSoundEffectsEnabled = false;
					}

					else if (muteSoundEffectsEnabled == false) {
						muteSoundEffectsEnabled = true;
					}

					soundMenu();	// show sound menu
				}

				// TOGGLE CURSOR 
				else if (option == 0 && inPrefMenu == true) {
					system("cls");

					// if it's off, turn it on, if it's on, turn it off
					if (textCursorEnabled == true) {
						textCursorEnabled = false;
					}

					else if (textCursorEnabled == false) {
						textCursorEnabled = true;
					}

					prefMenu();	// show sound menu
				}

				// TOGGLE ALERTS 
				else if (option == 1 && inPrefMenu == true) {
					system("cls");

					// if it's off, turn it on, if it's on, turn it off
					if (alertsEnabled == true) {
						alertsEnabled = false;
					}

					else if (alertsEnabled == false) {
						alertsEnabled = true;
					}

					prefMenu();	// show sound menu
				}

				// TOGGLE Screen Size
				else if (option == 0 && inGraphicsMenu == true) {
					system("cls");

					// if it's off, turn it on, if it's on, turn it off
					if (screenSizeEnabled == true) {
						screenSizeEnabled = false;
					}

					else if (screenSizeEnabled == false) {
						screenSizeEnabled = true;
					}

					graphicsMenu();	// show sound menu
				}

				// TOGGLE Screen Buffer
				else if (option == 1 && inGraphicsMenu == true) {
					system("cls");

					// if it's off, turn it on, if it's on, turn it off
					if (screenBufferEnabled == true) {
						screenBufferEnabled = false;
					}

					else if (screenBufferEnabled == false) {
						screenBufferEnabled = true;
					}

					graphicsMenu();	// show sound menu
				}
#pragma endregion Key Enter Actions

				break;
			case KEY_ESCAPE:

#pragma region 
				/*
				MainMenu
				OptionMenu
				MiscMenu
				SoundMenu
				PrefMenu
				GraphicsMenu
				*/

				// From Graphics to Options Menu
				if (inGraphicsMenu == true) {
					std::this_thread::sleep_for(chrono::milliseconds(100));
					system("cls");
					option = 0;	// reset pos
					endIndex = 4;
					inOptionMenu = true;
					inGraphicsMenu = false;
					OptionsMenu();
				}

				// From Preference to Options
				else if (inPrefMenu == true) {
					std::this_thread::sleep_for(chrono::milliseconds(100));
					system("cls");
					option = 1;	// keep that previous pos
					endIndex = 4;
					inOptionMenu = true;
					inPrefMenu = false;
					OptionsMenu();
				}

				// From Sound to Options
				else if (inSoundMenu == true) {
					std::this_thread::sleep_for(chrono::milliseconds(100));
					system("cls");
					option = 2;
					endIndex = 4;
					inOptionMenu = true;
					inSoundMenu = false;
					OptionsMenu();
				}

				// From Misc to Options
				else if (inMiscMenu == true) {
					std::this_thread::sleep_for(chrono::milliseconds(100));
					system("cls");
					option = 3;
					endIndex = 4;
					inOptionMenu = true;
					inMiscMenu = false;
					OptionsMenu();
				}

				// From Options to Main Menu
				else if (inOptionMenu == true) {
					std::this_thread::sleep_for(chrono::milliseconds(100));
					system("cls");
					option = 0;
					endIndex = 5;
					inOptionMenu = false;
					inMainMenu = true;
					MainMenuList();
				}

				// From How To Push to Main Menu
				else if (inHowToPushMenu == true) {
					std::this_thread::sleep_for(chrono::milliseconds(100));
					system("cls");
					option = 2;
					endIndex = 5;
					inHowToPushMenu = false;
					inMainMenu = true;
					MainMenuList();
				}

				else if (inTextOMaticMenu == true) {
					std::this_thread::sleep_for(chrono::milliseconds(100));
					system("cls");
					option = 0;	// reset pos
					endIndex = 2;
					inMiscMenu = true;
					inTextOMaticMenu = false;
					miscMenu();
				}

#pragma endregion Esc Actions 

				break;
			default:	// default input not registered, does nothing 
				break;


			}

		}
	} while (gameOver == false);		// [for testing] , we loop until game is over

}

int main() {

	
	MM();
	system("pause");
	return 0;
}