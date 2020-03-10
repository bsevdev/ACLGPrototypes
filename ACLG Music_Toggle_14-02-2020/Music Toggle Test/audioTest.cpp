#include <windows.h>
#include <mmsystem.h>
#include <thread>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <iostream>

// Build -> properties -> Linker -> Input -> Additional Dep -> Add: "Winmm.lib"
// https://stackoverflow.com/questions/2302841/win32-playsound-how-to-control-the-volume

using namespace std;

// make song loop
// check if song is already playing

class audioManager {

public:

	bool musicToggle = false;
	bool musicIsPlaying = false;

	DWORD dwFileSize;
	BYTE* pFileBytes;

	void playSong() {

		if (musicToggle == true) {

			audioVolumeController();
			musicIsPlaying = true;
			PlaySound((LPCSTR)pFileBytes, NULL, SND_MEMORY | SND_LOOP | SND_FILENAME | SND_ASYNC);
			//PlaySound("song1.wav", NULL, SND_LOOP | SND_FILENAME | SND_ASYNC);

		}
		
		else if(musicToggle == false) {

			audioVolumeController();
			musicIsPlaying = false;
			PlaySound((LPCSTR)pFileBytes, NULL, SND_MEMORY | SND_LOOP | SND_FILENAME | SND_ASYNC);
			//PlaySound("song1.wav", NULL, SND_ASYNC | SND_FILENAME);
			std::this_thread::sleep_for(chrono::milliseconds(1));
			PlaySound(NULL, 0, 0);

		}

		// PlaySound(NULL, 0, 0);
	}

	void ReadWavFileIntoMemory(string fname, BYTE** pb, DWORD* fsize) {

		ifstream f(fname, ios::binary);

		f.seekg(0, ios::end);
		int lim = f.tellg();
		*fsize = lim;

		*pb = new BYTE[lim];
		f.seekg(0, ios::beg);

		f.read((char*)* pb, lim);

		f.close();
	}

	// must be called to set volume 

	void audioVolumeController() {

		ReadWavFileIntoMemory("song1.wav", &pFileBytes, &dwFileSize);

		BYTE* pDataOffset = (pFileBytes + 40);

		//cout << "Length: " << dwFileSize << endl;

		float fVolume = 0.05;		// volume controller

		__int16* p = (__int16*)(pDataOffset + 8);

		//cout << sizeof(*p) << endl;

		for (int i = 80 / sizeof(*p); i < dwFileSize / sizeof(*p); i++) {
			p[i] = (float)p[i] * fVolume;
		}

		//cout << "PlaySound" << endl;

		//PlaySound((LPCSTR)pFileBytes, NULL, SND_MEMORY);

	}

private:

	

};