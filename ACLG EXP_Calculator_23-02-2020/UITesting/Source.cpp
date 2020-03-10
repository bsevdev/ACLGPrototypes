#include <iostream>
#include <string>
#include <Windows.h>
#include <thread>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <locale>
#include <ctime>
#include "comma.cpp"

using namespace std;

#pragma region
HWND console = GetConsoleWindow();
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
int ResX = 830, ResY = 500, ResXFixed = 0, ResYFixed = 0, PosX = 550, PosY = 300;


void setDefConsoleSize() {

	// default size of 830 x 500
	MoveWindow(console, PosX, PosY, ResX, ResY, TRUE);
}
#pragma endregion Screen Stuff

// TDL: random exp

long double currentLevel = 0;				// This stores the current Skill Level
long double overalExp = 0;					// this stores the overal Skill exp
long double expLeft = 0;					// expLeft = Difference - expGain
long double currentDifference = 0;			// this is the difference, gap between current exp and next level, calcualted: currentDifference = nextLevel - overalExp;
long double expRate = 0;					// your current exp rate

long double multi = 1.28;					// the multipler, from 1-20 is 28%, from 20-120 is 10%
long double lastLevelHit = 100;				// this stores the LAST level you had
long double finalMultiplyer = 0;			// this is your final multipler value			
long double expCap = 174612457;				// this is the maximum amount of experience you can gain in any skill.
long double twentryVal = 20;
int random_integer;							// our random number var

bool weLeveled = false;						// this checks if we have leveled up --- TESTING 
bool hitLimit = false;						// this checks if player has maxed. -> MUST BE STORED LOCALLY IF HIT

comma_numpunct useComma;					// Calling comma function	



// we generate a random number from the highest and lowest
int generateExp(int from, int to) {
	 
	return rand() % (to - from + 1) + from;

}

// we increase the multiplyer each time we level up
void multiplyer() {

	finalMultiplyer = lastLevelHit * multi;		// multiply last lvl * multipler, store this, and save it.
	lastLevelHit = finalMultiplyer;

	if (currentLevel >= twentryVal) {					// once player hits level 20, multipler = 10%
		multi = 1.1;
	}

}

// called after level up
void calcRemaining() {

	// once we level up, we calculate the difference
	
	currentDifference = lastLevelHit - overalExp;

}

// generate random exp here
void addExp() {

	// [NOTE] for the start, 10-50 exp does not hit negative numbers!
	// we only dish out exp whilst hitLimit is FALSE
	// random exp to be planned and written here: 

	if (hitLimit == false) {

		// [LEVEL SKIPPING TESTING]

		/*if (currentLevel != 9999) {
			random_integer = generateExp(55465542, 654566557);
			expRate = random_integer;
		}*/

		// 1-4, 52-67
		if (currentLevel >= 1 && currentLevel <= 4) {

			// 1. generate random number from said range
			// 2. put this number into an expRate
			random_integer = generateExp(52, 67);
			expRate = random_integer;
		}
		// 5-10 88-104
		if (currentLevel >= 5 && currentLevel <= 10) {

			random_integer = generateExp(88, 104);
			expRate = random_integer;
		}
		// 11-20 280-345
		if (currentLevel >= 11 && currentLevel <= 20) {

			random_integer = generateExp(280, 345);
			expRate = random_integer;
		}
		// 21-40, 503-659
		if (currentLevel >= 21 && currentLevel <= 40) {

			random_integer = generateExp(503, 659);
			expRate = random_integer;
		}
		// 41-60, 959-1193
		if (currentLevel >= 41 && currentLevel <= 60) {

			random_integer = generateExp(959, 1193);
			expRate = random_integer;
		}
		// 61-80, 1780-2147
		if (currentLevel >= 61 && currentLevel <= 80) {

			random_integer = generateExp(1780, 2147);
			expRate = random_integer;
		}
		// 81-100, 3258-3864
		if (currentLevel >= 81 && currentLevel <= 100) {

			random_integer = generateExp(3258, 3864);
			expRate = random_integer;
		}
		// 101-110, 5864-6954
		if (currentLevel >= 101 && currentLevel <= 110) {

			random_integer = generateExp(5864, 6954);
			expRate = random_integer;
		}
		// 111-120,  10970-12517
		if (currentLevel >= 111 && currentLevel <= 120) {

			random_integer = generateExp(10970, 12517);
			expRate = random_integer;
		}
	}

	// if we have hit our limit, expRate = 0

	else {
		expRate = 0;
	}
}

void jumpLevel() {
	
	// this means you should have levelled up, but didn't
	// let's force it 

	// we check if we are lower than 0
	// we also check if the player is actually due a level up
	while (expLeft <= 0 && overalExp >= finalMultiplyer) {
		weLeveled = true;
		++currentLevel;
		multiplyer();
		calcRemaining();

	}
}

void ExpCap() {
	
	// Max exp = 174,612,457
	// test to make sure this will work after level = 120!

	// if our overal exp is large that our capped exp of 174,612,457

	if (overalExp >= expCap) {
		hitLimit = true;			// we turn out hitLimit bool true as we have hit our limit
		expRate = 0;				// we do not want anymore exp, so expRate = 0;
		overalExp = expCap;			// we make sure our overall experience is equal to our exp cap
		finalMultiplyer = 0;		// we make our multipler value = 0;
		expLeft = 0;				// there is no exp left as we have maxed
		currentLevel = 120;			// we display our final level of 120.
	}
}

// exp added onto total
void addToTotal() {
	
	// whenever we gain exp, add this to total experience

	overalExp += expRate;
}

void displayRemaining() {

	// this needs to loop.
	// our expLeft is the difference minus the exp rate.
	// this means we show the distance and subtract what we earn.
	expLeft = currentDifference -= expRate;
}

void expFunc() {

	// in actual game, this loop will not be (1)
	unsigned srand((int)time(NULL));

	while (1) {

		displayRemaining();			// we call display remaining 
		ExpCap();					// we make check to see if our player has CAPPED before giving more exp

		// check if you have levelled up
		// >= so it doesn't hit negatives
		if (overalExp >= lastLevelHit || expLeft <= 0) {			// if our overalExp larger that our Last level Hit, that means we have enough exp to level up
																// we also check if expLeft is smaller than 0

			// if we have not capped yet
			// increased level by 1
			// run the multipler to get next level
			// calculate the next remaining exp

			// store next difference
			if (hitLimit == false) {
				weLeveled = true;
				++currentLevel;
				multiplyer();
				calcRemaining();
				jumpLevel();

				expLeft = currentDifference;
			}

		}

		#pragma region 
		std::locale comma_locale(std::locale(), new comma_numpunct());
		// tell cout to use our new locale.
		std::cout.imbue(comma_locale);
		std::cout << std::setprecision(0) << std::fixed;
		#pragma endregion Unity, precision, perfection.

		// we update our exp addition
		addExp();

		#pragma region
		cout << "Current level: " << currentLevel << "/120" << '\n';
		cout << "Overall exp: " << overalExp << '\n';
		cout << "Remaining exp: " << expLeft << '\n';
		cout << "----------------------------\n";
		cout << "Current Exp Rate: " << expRate << '\n';
		cout << "Next Level: " << finalMultiplyer << '\n';
		cout << "Random Number: " << random_integer << '\n';
		#pragma endregion Display Stats

		// we add this total
		addToTotal();
		
		cout << "\n\n\n";
		system("pause");

		// everytime we level up, pause --------- FOR TESTING
		/*if (weLeveled == true) {
			weLeveled = false;
			system("pause");
		}*/

		if (hitLimit == true) {
			// the information on "this skill is maxed"
			// will need to be saved localled
			cout << "This skill is maxed.\n";
			system("pause");
		}

		system("cls");
	}
}

int main() {

	#pragma region
	setDefConsoleSize();
	//system("screenBuffer.bat");
	#pragma endregion 

	// call expFunc
	expFunc();

	cout << "\n\n\n";
	system("pause");

}




