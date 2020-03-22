#pragma once
/*
	1 = Èæµ¹
	2 = ¹éµ¹
*/

#define HIGH  8
#define WIDTH 8

struct POSITION
{
	int y;
	int x;
};

class Game_Map
{
private:
	POSITION IN_GAME_MAP_CURSOR;
	char _Map_Cursor_Input_Position;

	int map[HIGH][WIDTH] = { 0 };

	int _Player_Turn_Check = 1; //Èæµ¹
	int Check_Pieces = 0;
	bool Check_Direction = false;
	int Check_Direction_Number = 0;

	int X_Position_Value = 0;
	int Y_Position_Value = 0;


	int Pieces_BlackPieces = 0;
	int Pieces_WhitePieces = 0;
	int Board_Empty = 0;
public:

	void Game_Map_Print(void);
	void Game_Othello_Rule(void);
	void _Map_Cursor(void);
	int _Map_Pieces_Check(int type, int not_type);

	void Width_Right_Win_Check(int type);
	void Width_Left_Win_Check(int type);

	void High_Up_Win_Check(int type);
	void High_Down_Win_Check(int type);

	void RightCross_Up_Win_Check(int type);
	void RightCross_Down_Win_Check(int type);

	void LeftCross_Up_Win_Check(int type);
	void LeftCross_Down_Win_Check(int type);


	Game_Map();
	~Game_Map();
};