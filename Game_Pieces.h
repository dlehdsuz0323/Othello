#pragma once
/* 
	1 = Èæµ¹
	2 = ¹éµ¹ 
*/

#define HIGH  8
#define WIDTH 8

enum PIECES
{
	EMPTY,
	BLACKPIECES,
	WHITEPIECES
};

class Game_Pieces
{
private:
	int _Player_Turn_Check = 1;
	int Pieces_BlackPieces = 0;
	int Pieces_WhitePieces = 0;
	int Board_Empty = 0;

public :

	void Game_Number_Of_Pieces(int map[HIGH][WIDTH], int &Pieces_BlackPieces, int &Pieces_WhitePieces, int &Board_Empty);

	Game_Pieces();
	~Game_Pieces();
};