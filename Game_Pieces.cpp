#include <iostream>

#include "Game_Pieces.h"

using namespace std;

Game_Pieces::Game_Pieces()
{
}

void Game_Pieces::Game_Number_Of_Pieces(int map[HIGH][WIDTH],int &Pieces_BlackPieces, int &Pieces_WhitePieces,int &Board_Empty)
{
	Pieces_BlackPieces = 0;
	Pieces_WhitePieces = 0;
	Board_Empty = 0;

	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if (map[i][j] == BLACKPIECES)
			{
				Pieces_BlackPieces += 1;
			}
			if (map[i][j] == WHITEPIECES)
			{
				Pieces_WhitePieces += 1;
			}
			if (map[i][j] == EMPTY)
			{
				Board_Empty += 1;
			}
		}
	}
				cout << "Pieces_BlackPieces :  " << Pieces_BlackPieces << endl;
				cout << "Pieces_WhitePieces :  " << Pieces_WhitePieces << endl;
				cout << "Board_Empty :  " << Board_Empty << endl;
}

Game_Pieces::~Game_Pieces()
{
}
