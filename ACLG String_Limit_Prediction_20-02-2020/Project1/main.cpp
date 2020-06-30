#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>

using namespace std;

// 6. Optomisation 

#pragma region
// https://stackoverflow.com/questions/60299958/stop-input-once-10-characters-are-inside-a-string
// TESING CMMANDS

// IF WE TYPE THE FIRST 2 LETTERS OF COMMAND, THROW HINT
// if the typed hint is the full word, clear predictive hint

// [[[[[[ONLY HAVE PREDICTURE TEXT FOR EASY FORGETTABLE COMMANDS]]]]]]]

// music-on/off (it will check the status of the music to pick correct suggestion) ---------
// cls ---- (for now)-----------------------------------------------------------------------
// attack-angus ----------------------------------------------------------------------------
// ping-angus ------------------------------------------------------------------------------
// help ------------------------------------------------------------------------------------
// menu ------------------------------------------------------------------------------------
// run-secure ------------------------------------------------------------------------------
// run-vul	--------------------------------------------------------------------------------
#pragma endregion Some Notes

#pragma region
bool attackAngusPredict = false;
bool pingAngusPredict = false;
bool secureAngusPredict = false;
bool vulAngusPredict = false;
bool musicPredict = false;
bool helpPredict = false;
bool runMultiSuggestion = false;
bool menuPredict = false;
#pragma endregion Prediction Bools

#pragma region 

// Special Keys
#define BACKSPACE 8
#define HYPHEN 45
#define ESC 27
#define TAB 9
#define SPACE 32
#define ENTER 13

// Lowercase Letters
#define KEY_A_Lowercase 97
#define KEY_B_Lowercase 98
#define KEY_C_Lowercase 99
#define KEY_D_Lowercase 100
#define KEY_E_Lowercase 101
#define KEY_F_Lowercase 102
#define KEY_G_Lowercase 103
#define KEY_H_Lowercase 104
#define KEY_I_Lowercase 105
#define KEY_J_Lowercase 106
#define KEY_K_Lowercase 107
#define KEY_L_Lowercase 108
#define KEY_M_Lowercase 109
#define KEY_N_Lowercase 110
#define KEY_O_Lowercase 111
#define KEY_P_Lowercase 112
#define KEY_Q_Lowercase 113
#define KEY_R_Lowercase 114
#define KEY_S_Lowercase 115
#define KEY_T_Lowercase 116
#define KEY_U_Lowercase 117
#define KEY_V_Lowercase 118
#define KEY_W_Lowercase 119
#define KEY_X_Lowercase 120
#define KEY_Y_Lowercase 121
#define KEY_Z_Lowercase 122

// Numbers
#define KEY_0 48
#define KEY_1 49
#define KEY_2 50
#define KEY_3 51
#define KEY_4 52
#define KEY_5 53 
#define KEY_6 54
#define KEY_7 55
#define KEY_8 56
#define KEY_9 57

// Capital Letters
#define KEY_A_Capital 65
#define KEY_B_Capital 66
#define KEY_C_Capital 67
#define KEY_D_Capital 68
#define KEY_E_Capital 69
#define KEY_F_Capital 70
#define KEY_G_Capital 71
#define KEY_H_Capital 72
#define KEY_I_Capital 73
#define KEY_J_Capital 74
#define KEY_K_Capital 75
#define KEY_L_Capital 76
#define KEY_M_Capital 77
#define KEY_N_Capital 78
#define KEY_O_Capital 79
#define KEY_P_Capital 80
#define KEY_Q_Capital 81
#define KEY_R_Capital 82
#define KEY_S_Capital 83
#define KEY_T_Capital 84
#define KEY_U_Capital 85
#define KEY_V_Capital 86
#define KEY_W_Capital 87
#define KEY_X_Capital 88
#define KEY_Y_Capital 89
#define KEY_Z_Capital 90

#pragma endregion Defines

#pragma region 
std::string lastfullNameValue;
std::string fullusername;
std::string prevString;
std::string predictString;
#pragma endregion String Saving

#pragma region
int charlimit = 0;
bool hitLimit = false;
#pragma endregion Key Checks

#pragma region 
std::string letter;
std::string a = "a";
std::string b = "b";
std::string c = "c";
std::string d = "d";
std::string e = "e";
std::string f = "f";
std::string g = "g";
std::string h = "h";
std::string i = "i";
std::string j = "j";
std::string k = "k";
std::string l = "l";
std::string m = "m";
std::string n = "n";
std::string o = "o";
std::string p = "p";
std::string q = "q";
std::string r = "r";
std::string s = "s";
std::string t = "t";
std::string u = "u";
std::string v = "v";
std::string w = "w";
std::string x = "x";
std::string y = "y";
std::string z = "z";
#pragma endregion Key Strings

#pragma region 
bool keyPressed = false;
bool backSpacePressed = false;
#pragma endregion Key Bools

void predictionCheckFunction() {

	// command attack-angus
	if (lastfullNameValue == "att" || lastfullNameValue == "atta" ||
		lastfullNameValue == "attac" || lastfullNameValue == "attack" ||
		lastfullNameValue == "attack-" || lastfullNameValue == "attack-a" ||
		lastfullNameValue == "attack-an" || lastfullNameValue == "attack-ang" ||
		lastfullNameValue == "attack-angu") {

		attackAngusPredict = true;

		// false
		pingAngusPredict = false;
		secureAngusPredict = false;
		vulAngusPredict = false;
		musicPredict = false;
		helpPredict = false;
		runMultiSuggestion = false;
		menuPredict = false;

		predictString = "attack-angus?";
	}


	// command ping-angus
	else if (lastfullNameValue == "pin" || lastfullNameValue == "ping" ||
		lastfullNameValue == "ping-" || lastfullNameValue == "ping-a" ||
		lastfullNameValue == "ping-an" || lastfullNameValue == "ping-ang" ||
		lastfullNameValue == "ping-angu") {

		pingAngusPredict = true;


		// false
		attackAngusPredict = false;
		secureAngusPredict = false;
		vulAngusPredict = false;
		musicPredict = false;
		helpPredict = false;
		runMultiSuggestion = false;
		menuPredict = false;

		predictString = "ping-angus?";
	}

	// command run- (multi suggest)
	else if (lastfullNameValue == "run" || lastfullNameValue == "run-") {

		runMultiSuggestion = true;


		// false
		attackAngusPredict = false;
		pingAngusPredict = false;
		vulAngusPredict = false;
		musicPredict = false;
		helpPredict = false;
		menuPredict = false;

		predictString = "run-secure, run-vul?";
	}

	// command run-secure
	else if (lastfullNameValue == "run-s" || lastfullNameValue == "run-se" ||
		lastfullNameValue == "run-sec" || lastfullNameValue == "run-secu" ||
		lastfullNameValue == "run-secur") {

		secureAngusPredict = true;


		// false
		attackAngusPredict = false;
		pingAngusPredict = false;
		vulAngusPredict = false; 
		musicPredict = false; 
		helpPredict = false;
		runMultiSuggestion = false;
		menuPredict = false;

		predictString = "run-secure?";
	}

	// command run-vul
	else if (lastfullNameValue == "run-v" || lastfullNameValue == "run-vu") {

		vulAngusPredict = true;


		// false
		attackAngusPredict = false;
		pingAngusPredict = false;
		secureAngusPredict = false;
		musicPredict = false;
		helpPredict = false;
		runMultiSuggestion = false;
		menuPredict = false;

		predictString = "run-vul?";
	}

	// command music-on/off
	else if (lastfullNameValue == "mus" || lastfullNameValue == "musi" ||
		lastfullNameValue == "music" || lastfullNameValue == "music-" ||
		lastfullNameValue == "music-o") {

		musicPredict = true;


		// false
		attackAngusPredict = false;
		pingAngusPredict = false;
		secureAngusPredict = false;
		vulAngusPredict = false;
		helpPredict = false; 
		runMultiSuggestion = false;
		menuPredict = false;

		predictString = "music-on/off?";
	}

	// command help
	else if (lastfullNameValue == "h" || lastfullNameValue == "he" || lastfullNameValue == "hel" ) {

		helpPredict = true;


		// false
		attackAngusPredict = false;
		pingAngusPredict = false;
		secureAngusPredict = false;
		vulAngusPredict = false;
		musicPredict = false;
		runMultiSuggestion = false;
		menuPredict = false;

		predictString = "help?";
	}

	// command menu
	else if (lastfullNameValue == "m" || lastfullNameValue == "me" || lastfullNameValue == "men") {

		menuPredict = true;


		// false
		attackAngusPredict = false;
		pingAngusPredict = false;
		secureAngusPredict = false;
		vulAngusPredict = false;
		musicPredict = false;
		runMultiSuggestion = false;
		helpPredict = false;

		predictString = "menu? (also hit \"ESC\" key)";
	}


	// otherwise, we "clear" the string 
	else{

		// all false
		attackAngusPredict = false;
		pingAngusPredict = false;
		helpPredict = false;
		secureAngusPredict = false;
		vulAngusPredict = false;
		musicPredict = false;
		runMultiSuggestion = false;

		// reset preditct text string
		predictString = "";
	}

}

void updateStringForward() {

	if (keyPressed == true) {
		keyPressed = false;

		++charlimit;								// increment the limit 

		prevString = lastfullNameValue;				// save the previous string so we can stop 

		fullusername = lastfullNameValue + letter;		// "letter" value is changed depending on what key was typed 

		lastfullNameValue = fullusername;			// save last interval
	}
}

void compeletePrediction() {

	// complete predictive text for angus
	if (attackAngusPredict == true) {

		lastfullNameValue = "attack-angus";		// make input = to the command
		predictString = "";							// empty prediction
		attackAngusPredict = false;

		// we need to count how many characters the command has, and apply
		charlimit = 12;
	}

	// complete predictive text for angus
	if (pingAngusPredict == true) {

		lastfullNameValue = "ping-angus";		// make input = to the command
		predictString = "";							// empty prediction
		pingAngusPredict = false;

		// we need to count how many characters the command has, and apply
		charlimit = 10;
	}

	// complete predictive text for angus
	if (secureAngusPredict == true) {

		lastfullNameValue = "run-secure";		// make input = to the command
		predictString = "";							// empty prediction
		secureAngusPredict = false;

		// we need to count how many characters the command has, and apply
		charlimit = 10;
	}

	// complete predictive text for angus
	if (vulAngusPredict == true) {

		lastfullNameValue = "run-vul";		// make input = to the command
		predictString = "";							// empty prediction
		vulAngusPredict = false;

		// we need to count how many characters the command has, and apply
		charlimit = 7;
	}

	// complete predictive text for angus
	if (helpPredict == true) {

		lastfullNameValue = "help";		// make input = to the command
		predictString = "";							// empty prediction
		helpPredict = false;

		// we need to count how many characters the command has, and apply
		charlimit = 4;
	}

	// complete predictive text for angus
	if (menuPredict == true) {

		lastfullNameValue = "menu";		// make input = to the command
		predictString = "";							// empty prediction
		menuPredict = false;

		// we need to count how many characters the command has, and apply
		charlimit = 4;
	}

	// MUSIC HINT WILL DEPEND ON IF MUSIC IS ON OR NOT


}

void updateStringBackwards() {
	
	// we need to GET the last string on the interval
	// we then need to remove the last char of that string
	// the display again

	--charlimit;	// minus the charlimit
	lastfullNameValue = lastfullNameValue.substr(0,
						lastfullNameValue.size() - 1);

}

int main() {

	int c = 0;

	while (1) {

		c = 0;

		#pragma region
		// We check if the user has typed more than 10 characters, 
		// if they have, we stop the input.

		// limit here is 10
		if (charlimit >= 20) {
			cout << "\n\n";
			hitLimit = true;
			//std::cout << "Too many characters (for testing)";
			std::cout << " C:\\Some\\Shitty\\User> " << lastfullNameValue;
			cout << "\n";
			cout << " Command Suggestion: " << predictString;
			cout << "\n";
			cout << " -----------------";
			cout << "\n";
			cout << " Char count: " << charlimit;
			
		}

		// otherwise we continue until they have
		else {
			cout << "\n\n";
			hitLimit = false;
			std::cout << " C:\\Some\\Shitty\\User> " << lastfullNameValue;
			cout << "\n";
			cout << " Command Suggestion: " << predictString;
			cout << "\n";
			cout << " -----------------";
			cout << "\n";
			cout << " Char count: " << charlimit;
		}
		#pragma endregion Display 

		switch ((c = _getch())) {

			// we check if the user has hit a limit before allowing them to process the press
			// we then trigger the respected boolean to the letter, and call 
			// our function to update our string var

			#pragma region 
			case KEY_A_Lowercase:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "a";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}

			break;

			case KEY_B_Lowercase:
				if (hitLimit == false) {
					letter = "b";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
			break;

			case KEY_C_Lowercase:
				if (hitLimit == false) {
					letter = "c";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_D_Lowercase:
				if (hitLimit == false) {
					letter = "d";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_E_Lowercase:
				if (hitLimit == false) {
					letter = "e";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_F_Lowercase:
				if (hitLimit == false) {
					letter = "f";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_G_Lowercase:
				if (hitLimit == false) {
					letter = "g";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_H_Lowercase:
				if (hitLimit == false) {
					letter = "h";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_I_Lowercase:
				if (hitLimit == false) {
					letter = "i";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_J_Lowercase:
				if (hitLimit == false) {
					letter = "j";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_K_Lowercase:
				if (hitLimit == false) {
					letter = "k";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_L_Lowercase:
				if (hitLimit == false) {
					letter = "l";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_M_Lowercase:
				if (hitLimit == false) {
					letter = "m";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_N_Lowercase:
				if (hitLimit == false) {
					letter = "n";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_O_Lowercase:
				if (hitLimit == false) {
					letter = "o";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_P_Lowercase:
				if (hitLimit == false) {
					letter = "p";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_Q_Lowercase:
				if (hitLimit == false) {
					letter = "q";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_R_Lowercase:
				if (hitLimit == false) {
					letter = "r";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_S_Lowercase:
				if (hitLimit == false) {
					letter = "s";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_T_Lowercase:
				if (hitLimit == false) {
					letter = "t";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_U_Lowercase:
				if (hitLimit == false) {
					letter = "u";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_V_Lowercase:
				if (hitLimit == false) {
					letter = "v";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_W_Lowercase:
				if (hitLimit == false) {
					letter = "w";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_X_Lowercase:
				if (hitLimit == false) {
					letter = "x";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_Y_Lowercase:
				if (hitLimit == false) {
					letter = "y";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_Z_Lowercase:
				if (hitLimit == false) {
					letter = "z";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;
			case HYPHEN:
				if (hitLimit == false) {
					letter = "-";
					keyPressed = true;
					updateStringForward();
				}
				break;

			case ESC:	// will pull up the game menu
				exit(0);
				break;

			case TAB:
				compeletePrediction();
				break;

			case SPACE:
				break;

			// the enter key would take current string
			// and do whatever command, if not a command, we display prompt as normal.

			case ENTER:	// will execute all commands
				exit(0);
				break;

			case BACKSPACE:
				if (charlimit > 0) {
					updateStringBackwards();
				}

				// if the user has triggered a predictive suggestion, and hits backspace, 
				// we clear the suggestion

				if (attackAngusPredict == true) {
					predictString = "";
				}

				else if (secureAngusPredict == true) {
					predictString = "";
				}

				else if (pingAngusPredict == true) {
					predictString = "";
				}

				else if (vulAngusPredict == true) {
					predictString = "";
				}

				else if (musicPredict == true) {
					predictString = "";
				}

				else if (helpPredict == true) {
					predictString = "";
				}

				else if (menuPredict == true) {
					predictString = "";
				}

				else if (runMultiSuggestion == true) {
					predictString = "";
				}

			break;
			#pragma endregion Lowercase Letters & Special Keys

			#pragma region [Note: Update these if Lowecase input changes]
			case KEY_A_Capital:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "a";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}

				break;

			case KEY_B_Capital:
				if (hitLimit == false) {
					letter = "b";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_C_Capital:
				if (hitLimit == false) {
					letter = "c";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_D_Capital:
				if (hitLimit == false) {
					letter = "d";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_E_Capital:
				if (hitLimit == false) {
					letter = "e";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_F_Capital:
				if (hitLimit == false) {
					letter = "f";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_G_Capital:
				if (hitLimit == false) {
					letter = "g";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_H_Capital:
				if (hitLimit == false) {
					letter = "h";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_I_Capital:
				if (hitLimit == false) {
					letter = "i";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_J_Capital:
				if (hitLimit == false) {
					letter = "j";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_K_Capital:
				if (hitLimit == false) {
					letter = "k";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_L_Capital:
				if (hitLimit == false) {
					letter = "l";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_M_Capital:
				if (hitLimit == false) {
					letter = "m";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_N_Capital:
				if (hitLimit == false) {
					letter = "n";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_O_Capital:
				if (hitLimit == false) {
					letter = "o";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_P_Capital:
				if (hitLimit == false) {
					letter = "p";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_Q_Capital:
				if (hitLimit == false) {
					letter = "q";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_R_Capital:
				if (hitLimit == false) {
					letter = "r";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_S_Capital:
				if (hitLimit == false) {
					letter = "s";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_T_Capital:
				if (hitLimit == false) {
					letter = "t";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_U_Capital:
				if (hitLimit == false) {
					letter = "u";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_V_Capital:
				if (hitLimit == false) {
					letter = "v";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_W_Capital:
				if (hitLimit == false) {
					letter = "w";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_X_Capital:
				if (hitLimit == false) {
					letter = "x";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_Y_Capital:
				if (hitLimit == false) {
					letter = "y";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
				break;

			case KEY_Z_Capital:
				if (hitLimit == false) {
					letter = "z";
					keyPressed = true;
					updateStringForward();
					predictionCheckFunction();
				}
			#pragma endregion Capital Letters

			#pragma region
			case KEY_0:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "0";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_1:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "1";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_2:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "2";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_3:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "3";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_4:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "4";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_5:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "5";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_6:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "6";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_7:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "7";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_8:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "8";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			case KEY_9:
				if (hitLimit == false) {		// we check if the user has hit the limit
					letter = "9";				// we change the value of letter
					keyPressed = true;			// we check the key was pressed
					updateStringForward();		// we call our string update function
					predictionCheckFunction();
				}
				break;
			#pragma endregion Numbers
			
		}
		
		system("cls");
	}

	system("pause");
}
