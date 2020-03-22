#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "Game_Map.h"

using namespace std;

void printMenu(void);

int main(void)
{
	Game_Map _MAP;
	while (true)
	{
		_MAP._Map_Cursor();
		system("cls"); 
		_MAP.Game_Map_Print();
	}
}

void printMenu(void)
{
	cout << endl;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
	cout << endl;
}