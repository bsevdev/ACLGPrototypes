#include <iostream>
#include "audioTest.cpp"
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

audioManager getAudio;

string cmd;


void dump() {
	while (1) {


		cout << "command: ";
		cin >> cmd;

		if (cmd == "music-on") {

			if (getAudio.musicIsPlaying == true) {

				cout << "Music is already playing!" << '\n';
			}
			else {

				getAudio.musicToggle = true;
				getAudio.playSong();
			}

		}

		if (cmd == "music-off") {

			if (getAudio.musicIsPlaying == false) {

				cout << "Music is already off!" << '\n';
			}
			else {

				getAudio.musicToggle = false;
				getAudio.playSong();
			}

		}

		//system("cls");
	}
}


int main() {

	dump();

	system("pause");
}