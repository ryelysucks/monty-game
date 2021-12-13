#include <iostream>
#include <stdlib.h>
#include <time.h>          //i hate this so much
#include <string>
#include "windows.h"
#include "mmsystem.h"
#pragma comment(lib, "Winmm.lib")

using std::cout;
using std::cin;
using std::string;

//function to pick between and play sound files

void playSound(string sound)
{
	if (sound == "win")
	{
		PlaySound(TEXT("Data\\winSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	else if (sound == "fail")
	{                                                                              
		PlaySound(TEXT("Data\\failSound.wav"), NULL, SND_FILENAME | SND_ASYNC); 
	}
	else if (sound == "reset")
	{
		PlaySound(NULL, 0, 0);  //stop previous sound from playing first
		PlaySound(TEXT("Data\\musicSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
}

//random seed and winning number generation

int randomize()
{
	srand(time(NULL));
	unsigned int winner = rand() % 3 + 1;   //also i stole this
	return (winner);
}

//main game function

int doorMain()
{
	int choice, winner = randomize();
	cout << "Which door will you pick?\n" << "One, two, or three?\n\n";
	cin >> choice;
	while (choice != winner)
	{
		playSound("fail");
		cout << "Awww. Loser. The correct door was actually " << winner << "\n";
		cin.clear();
		cin.ignore(256, '\n');
		winner = randomize();
		system("pause");
		playSound("reset");
		cout << "\n\nWhich door will you pick?\n" << "One, two, or three?\n\n";
		cin >> choice;
	}
	cout << "\nWINNER! " << winner << " was the correct answer!\n\n";
	playSound("win");
	system("pause");
	return 0;
}

// program start

int main()
{
	SetConsoleTitle(TEXT("MontyC++"));
	PlaySound(TEXT("Data\\musicSound.wav"), NULL, SND_FILENAME | SND_ASYNC);
	cout << "Welcome, in front of you are three doors!\n" << "If you pick the right door, you will be rewarded! Good luck.\n\n";
	Sleep(1100);
	doorMain();
}