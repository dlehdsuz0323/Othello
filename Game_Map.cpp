#include <iostream>
#include <conio.h>
#include <Windows.h>

#include "Game_Map.h"
#include "Game_Pieces.h"

using namespace std;

Game_Map::Game_Map()
{	
	IN_GAME_MAP_CURSOR.x = 0;
	IN_GAME_MAP_CURSOR.y = 0;

	map[HIGH / 2][WIDTH / 2] = WHITEPIECES;
	map[(HIGH / 2) - 1][(WIDTH / 2) - 1] = WHITEPIECES;
	map[HIGH / 2][(WIDTH / 2) - 1] = BLACKPIECES;
	map[(HIGH / 2) - 1][(WIDTH / 2)] = BLACKPIECES;
}

void Game_Map::Game_Map_Print(void)
{
	Game_Pieces _PIECES;

	for (int i = 0; i < HIGH; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{

			if (i == IN_GAME_MAP_CURSOR.y && j == IN_GAME_MAP_CURSOR.x)
			{
				cout << "¡Ù";
			}

			else if (map[i][j] == WHITEPIECES) 
			{
				cout << "¡Ü"; 
			}
			else if (map[i][j] == BLACKPIECES) 
			{
				cout << "¡Û";
			}

			else if (map[i][j] == EMPTY)
			{
				if (i == 0 && j == 0)
					cout << "¦£";
				else if (i == 0 && j == HIGH - 1)
					cout << "¦¤";
				else if (i == 0)
					cout << "¦¨";
				else if (i == WIDTH - 1 && j == 0)
					cout << "¦¦";
				else if (i == WIDTH - 1 && j == HIGH - 1)
					cout << "¦¥";
				else if (i == WIDTH - 1)
					cout << "¦ª";
				else if (j == 0)
					cout << "¦§";
				else if (j == HIGH - 1)
					cout << "¦©";
				else
					cout << "¦«";
					cout << " ";	
			}
		}
		cout << endl;
	}
	if (_Player_Turn_Check == BLACKPIECES)
	{
		cout << "BLACKPIECES Turn" << endl;

		_PIECES.Game_Number_Of_Pieces(map, Pieces_BlackPieces, Pieces_WhitePieces, Board_Empty);
	}
	else if (_Player_Turn_Check == WHITEPIECES)
	{
		cout << "WHILEPIECES Turn" << endl;

		_PIECES.Game_Number_Of_Pieces(map, Pieces_BlackPieces, Pieces_WhitePieces, Board_Empty);
	}
}

void Game_Map::_Map_Cursor(void)
{

	_Map_Cursor_Input_Position = getch();
	switch (_Map_Cursor_Input_Position)
	{
	case 'w':
		IN_GAME_MAP_CURSOR.y--;
		break;
	case 's':
		IN_GAME_MAP_CURSOR.y++;
		break;
	case 'a':
		IN_GAME_MAP_CURSOR.x--;
		break;
	case 'd':
		IN_GAME_MAP_CURSOR.x++;
		break;


	case 'k':	// pieces drop
	{
		for (int i = 0; i < HIGH; i++)
		{
			for (int j = 0; j < WIDTH; j++)
			{
				if (_Player_Turn_Check == BLACKPIECES)
				{

					if (i == IN_GAME_MAP_CURSOR.y && j == IN_GAME_MAP_CURSOR.x)
					{
						if (map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] == BLACKPIECES)
						{
							break;
						}
						else if (map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] == WHITEPIECES)
						{
							break;
						}

						else
						{
							X_Position_Value = IN_GAME_MAP_CURSOR.x;
							Y_Position_Value = IN_GAME_MAP_CURSOR.y;

							if (_Map_Pieces_Check(BLACKPIECES, WHITEPIECES) == 1)
							{
								Game_Othello_Rule();
							}
							else if (Check_Direction_Number == 8)
							{
								break;
							}
						}
					}
				}


				else if (_Player_Turn_Check == WHITEPIECES)
				{
					if (i == IN_GAME_MAP_CURSOR.y && j == IN_GAME_MAP_CURSOR.x)
					{
						if (map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] == BLACKPIECES)
						{
							break;
						}
						else if (map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] == WHITEPIECES)
						{
							break;
						}

						else
						{
							X_Position_Value = IN_GAME_MAP_CURSOR.x;
							Y_Position_Value = IN_GAME_MAP_CURSOR.y;

							if (_Map_Pieces_Check(WHITEPIECES, BLACKPIECES) == 1)
							{
								Game_Othello_Rule();
							}
							else if (Check_Direction_Number == 8)
							{
								break;
							}
						}
					}
				}
			}
		}
		break;
	}

	case 'l':

		if (_Player_Turn_Check == 1)
		{
			_Player_Turn_Check = 2;
		}
		else if (_Player_Turn_Check == 2)
		{
			_Player_Turn_Check = 1;
		}
	}
}


int Game_Map::_Map_Pieces_Check(int type, int not_type)
{
	// Up,Down,Right,Left Check_Variavle
	int y = Y_Position_Value;
	int x = X_Position_Value;

	// Cross Check_Variable 
	int x_EMPTY_Check = x = 0;
	int y_EMPTY_Check = y = 0;

	int First_Pieces_arr_x = 0;
	int First_Pieces_arr_y = 0;

	int Second_Pieces_arr_x = 0;
	int Second_Pieces_arr_y = 0;

	Check_Direction_Number = 0;

	{
		//Width_Right_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;
			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			for (int i = x; i < WIDTH; i++)
			{
				if (Check_Direction == false)
				{
					if (map[y][i] == type)
					{
						if (map[y][++x] == EMPTY)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}

						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[y][--i] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
						}
					}
				}
			}
		}

		//Width_Left_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;
			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			for (int i = x; i >= (WIDTH - WIDTH); i--)
			{
				if (Check_Direction != true)
				{
					if (map[y][i] == type)
					{
						if (map[y][--x] == EMPTY)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}

						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[y][++i] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
						}
					}
				}
			}
		}

		//High_Up_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;
			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			for (int i = y; i >= 0; i--)
			{
				if (Check_Direction != true)
				{
					if (map[i][x] == type)
					{
						if (map[--y][x] == EMPTY)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}

						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[++i][x] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
						}
					}
				}
			}
		}

		//High_Down_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;
			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			for (int i = y; i < WIDTH; i++)
			{
				if (Check_Direction != true)
				{
					if (map[i][x] == type)
					{
						if (map[++y][x] == EMPTY)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}

						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[--i][x] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
						}
					}
				}
			}
		}

		//RightCross_Up_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;

			x_EMPTY_Check = x;
			y_EMPTY_Check = y;

			First_Pieces_arr_x = 0;
			First_Pieces_arr_y = 0;

			Second_Pieces_arr_x = 0;
			Second_Pieces_arr_y = 0;

			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			while (true)
			{
				if (Check_Direction != true)
				{
					if (map[y_EMPTY_Check++][x_EMPTY_Check--] == EMPTY)
					{
						if (x > WIDTH || y < 0)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}
						else
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
						break;
					}

					if (map[y][x] == type)
					{
						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[y_EMPTY_Check - 2][x_EMPTY_Check + 2] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
							if (x < 0 || y > HIGH)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
								Check_Direction_Number += 1;
								break;
							}
						}
					}
					--x;
					++y;
				}
			}
		}
		// LeftCross_Down_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;

			x_EMPTY_Check = x;
			y_EMPTY_Check = y;

			First_Pieces_arr_x = 0;
			First_Pieces_arr_y = 0;

			Second_Pieces_arr_x = 0;
			Second_Pieces_arr_y = 0;

			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			while (true)
			{
				if (Check_Direction != true)
				{
					if (map[y_EMPTY_Check--][x_EMPTY_Check++] == EMPTY)
					{
						if (x < 0 || y > HIGH)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}
						else
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
						break;
					}
					if (map[y][x] == type)
					{
						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[y_EMPTY_Check + 2][x_EMPTY_Check - 2] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
							if (x > WIDTH || y < 0)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
								Check_Direction_Number += 1;
								break;
							}
						}
					}
					++x;
					--y;
				}
			}
		}

		//LeftCross_Up_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;

			x_EMPTY_Check = x;
			y_EMPTY_Check = y;

			First_Pieces_arr_x = 0;
			First_Pieces_arr_y = 0;

			Second_Pieces_arr_x = 0;
			Second_Pieces_arr_y = 0;

			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			while (true)
			{
				if (Check_Direction != true)
				{
					if (map[y_EMPTY_Check++][x_EMPTY_Check++] == EMPTY)
					{
						if (x < 0 || y < 0)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}
						else
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
						break;
					}
					if (map[y][x] == type)
					{
						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[y_EMPTY_Check - 2][x_EMPTY_Check - 2] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
						}
						if (y > HIGH || x > WIDTH)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}
					}
					++x;
					++y;
				}
			}
		}
		//RightCross_Down_Win_Check
		{
			y = Y_Position_Value;
			x = X_Position_Value;

			x_EMPTY_Check = x;
			y_EMPTY_Check = y;

			First_Pieces_arr_x = 0;
			First_Pieces_arr_y = 0;

			Second_Pieces_arr_x = 0;
			Second_Pieces_arr_y = 0;

			Check_Pieces = 0;
			map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;

			while (true)
			{
				if (Check_Direction != true)
				{
					if (map[y_EMPTY_Check--][x_EMPTY_Check--] == EMPTY)
					{
						if (y > HIGH || x > WIDTH)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}
						else
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
						break;
					}
					if (map[y][x] == type)
					{
						Check_Pieces += 1;

						if (Check_Pieces == 2)
						{
							if (map[y_EMPTY_Check + 2][x_EMPTY_Check + 2] == not_type)
							{
								map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = type;
								Check_Direction = true;
								_Player_Turn_Check = not_type;
								return 1;
							}
						}
						if (x < 0 || y < 0)
						{
							map[IN_GAME_MAP_CURSOR.y][IN_GAME_MAP_CURSOR.x] = EMPTY;
							Check_Direction_Number += 1;
							break;
						}
					}
					--x;
					--y;
				}
			}
		}
	}
}

void Game_Map::Game_Othello_Rule(void)
{

	if(_Player_Turn_Check == WHITEPIECES)	// BLACK
	{ 
			Width_Right_Win_Check(BLACKPIECES);
			Width_Left_Win_Check(BLACKPIECES);
	
			High_Up_Win_Check(BLACKPIECES);
			High_Down_Win_Check(BLACKPIECES);
			
			RightCross_Up_Win_Check(BLACKPIECES);
			LeftCross_Down_Win_Check(BLACKPIECES);
			
			LeftCross_Up_Win_Check(BLACKPIECES);
			RightCross_Down_Win_Check(BLACKPIECES);

	if (Pieces_BlackPieces == 0)
	{
		cout << "White Win" << endl;
		exit(0);
	}
	else if (Pieces_WhitePieces == 0)
	{
		cout << "Black Win" << endl;
		exit(0);
	}

	else if (Board_Empty == 1) //Board FUll
	{
		if (Pieces_BlackPieces > Pieces_WhitePieces)
		{
			cout << "Black WIn" << endl;
		}
		else if (Pieces_BlackPieces < Pieces_WhitePieces)
		{
			cout << "White Win" << endl;
		}
		exit(0);
	}
	}

	else if (_Player_Turn_Check == BLACKPIECES)		//WHITE
	{
		Width_Right_Win_Check(WHITEPIECES);
		Width_Left_Win_Check(WHITEPIECES);
		
		High_Up_Win_Check(WHITEPIECES);
		High_Down_Win_Check(WHITEPIECES);
		
		RightCross_Up_Win_Check(WHITEPIECES);
		LeftCross_Down_Win_Check(WHITEPIECES);
		
		LeftCross_Up_Win_Check(WHITEPIECES);
		RightCross_Down_Win_Check(WHITEPIECES);	

		if (Pieces_BlackPieces == 0)
		{
			cout << "White Win" << endl;
			exit(0);
		}
		else if (Pieces_WhitePieces == 0)
		{
			cout << "Black Win" << endl;
			exit(0);
		}

		else if (Board_Empty == 1)	//Board FUll
		{
			if (Pieces_BlackPieces > Pieces_WhitePieces)
			{
				cout << "Black WIn" << endl;
			}
			else if (Pieces_BlackPieces < Pieces_WhitePieces)
			{
				cout << "White Win" << endl;
			}
			exit(0);
		}
	}
}


void Game_Map::Width_Right_Win_Check(int type)
{
	Check_Pieces = 0;
	Check_Direction = false;

	int y = Y_Position_Value;
	int x = X_Position_Value;

	int First_Pieces_arr = 0;
	int Second_Pieces_arr = 0;

	for (int i = x; i < WIDTH; i++)
	{
		if (map[y][i] == EMPTY)
		{
			break;
		}
		if (map[y][i] == type)
		{
			Check_Pieces += 1;

			if (Check_Pieces == 1)
			{
				First_Pieces_arr = i;
			}
			if (Check_Pieces == 2)
			{
				Second_Pieces_arr = i;
				break;
			}
		}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = ++First_Pieces_arr; i < Second_Pieces_arr; i++)
			{
				map[y][i] = type;
			}
		}
	}
}
void Game_Map::Width_Left_Win_Check(int type)
{
	Check_Pieces = 0;
	int y = Y_Position_Value;
	int x = X_Position_Value;

	int First_Pieces_arr = 0;
	int Second_Pieces_arr = 0;

	for (int i = x; i >= (WIDTH - WIDTH); i--)
	{
		if (map[y][i] == EMPTY)
		{
			break;
		}
		if (map[y][i] == type)
		{
			Check_Pieces += 1;

			if (Check_Pieces == 1)
			{
				First_Pieces_arr = i;
			}
			if (Check_Pieces == 2)
			{
				Second_Pieces_arr = i;
				break;
			}
		}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = ++Second_Pieces_arr; i < First_Pieces_arr; i++)
			{
				map[y][i] = type;
			}
		}
	}
}

void Game_Map::High_Up_Win_Check(int type)
{
	Check_Pieces = 0;
	int y = Y_Position_Value;
	int x = X_Position_Value;

	int First_Pieces_arr = 0;
	int Second_Pieces_arr = 0;

	for (int i = y; i >= 0; i--)
	{
		if (map[i][x] == EMPTY)
		{
			break;
		}
		if (map[i][x] == type)
		{
			Check_Pieces += 1;

			if (Check_Pieces == 1)
			{
				First_Pieces_arr = i;
			}
			if (Check_Pieces == 2)
			{
				Second_Pieces_arr = i;
				break;
			}
		}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = ++Second_Pieces_arr; i < First_Pieces_arr; i++)
			{
				map[i][x] = type;
			}
		}
	}
}
void Game_Map::High_Down_Win_Check(int type)
{
	Check_Pieces = 0;
	int y = Y_Position_Value;
	int x = X_Position_Value;

	int First_Pieces_arr = 0;
	int Second_Pieces_arr = 0;

	for (int i = y; i < WIDTH; i++)
	{
		if (map[i][x] == EMPTY)
		{
			break;
		}
		 if (map[i][x] == type)
		{
			 Check_Pieces += 1;
			
			if (Check_Pieces == 1)
			{
				First_Pieces_arr = i;
			}
			if (Check_Pieces == 2)
			{
				Second_Pieces_arr = i;
				break;
			}
		}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = ++First_Pieces_arr; i < Second_Pieces_arr; i++)
			{
				map[i][x] = type;
			}
		}
	}
}


void Game_Map::RightCross_Up_Win_Check(int type)
{
	Check_Pieces = 0;
	int y = Y_Position_Value;
	int x = X_Position_Value;

	int x_EMPTY_Check = x;
	int y_EMPTY_Check = y;

	int First_Pieces_arr_x = 0;
	int First_Pieces_arr_y = 0;

	int Second_Pieces_arr_x = 0;
	int Second_Pieces_arr_y = 0;

	while (true)
	{
		if (map[y_EMPTY_Check ++][x_EMPTY_Check --] == EMPTY)
		{
			if (x > WIDTH || y < 0)
			{
				break;
			}
			else
				break;
		}
		if (map[y][x] == type)
		{
			Check_Pieces += 1;
			if (Check_Pieces == 1)
			{
				First_Pieces_arr_x = x;
				First_Pieces_arr_y = y;
			}
		}


		if (Check_Pieces == 2)
		{
			Second_Pieces_arr_x = x;
			Second_Pieces_arr_y = y;
			break;
		}
		--x;
		++y;
		if (x < 0 || y > HIGH)
		{
			break;
		}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = ++Second_Pieces_arr_x; i < First_Pieces_arr_x; i++)
			{
				y--;
				map[y][i] = type;
			}
		}
	}
}
void Game_Map::LeftCross_Down_Win_Check(int type)
{
	Check_Pieces = 0;
	int y = Y_Position_Value;
	int x = X_Position_Value;

	int x_EMPTY_Check = x;
	int y_EMPTY_Check = y;

	int First_Pieces_arr_x = 0;
	int First_Pieces_arr_y = 0;

	int Second_Pieces_arr_x = 0;
	int Second_Pieces_arr_y = 0;

	while (true)
	{
		if (map[y_EMPTY_Check --][x_EMPTY_Check ++] == EMPTY)
		{
			if (x < 0 || y > HIGH)
			{
				break;
			}
			else
				break;
		}
		if (map[y][x] == type)
		{
			Check_Pieces += 1;
			if (Check_Pieces == 1)
			{
				First_Pieces_arr_x = x;
				First_Pieces_arr_y = y;
			}
		}


		if (Check_Pieces == 2)
		{
			Second_Pieces_arr_x = x;
			Second_Pieces_arr_y = y;
			break;
		}
		++x;
		--y;
		if (x > WIDTH || y < 0)
		{
			break;
		}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = --Second_Pieces_arr_x; i > First_Pieces_arr_x; i--)
			{
				y++;
				map[y][i] = type;
			}
		}
	}
}

void Game_Map::LeftCross_Up_Win_Check(int type) 
{
	Check_Pieces = 0;
	int y = Y_Position_Value;
	int x = X_Position_Value;

	int x_EMPTY_Check = x;
	int y_EMPTY_Check = y;

	int First_Pieces_arr_x = 0;
	int First_Pieces_arr_y = 0;

 	int Second_Pieces_arr_x = 0;
	int Second_Pieces_arr_y = 0;

	while (true)
	{
		if (map[y_EMPTY_Check ++][x_EMPTY_Check ++] == EMPTY)
		{
			if (x < 0 || y < 0)
			{
				break;
			}
			else
				break;
		}
		if (map[y][x] == type)
		{
			Check_Pieces += 1;
			if (Check_Pieces == 1)
			{
				First_Pieces_arr_x = x;
				First_Pieces_arr_y = y;
			}
		}


		if (Check_Pieces == 2)
		{
			Second_Pieces_arr_x = x;
			Second_Pieces_arr_y = y;
			break;
		}
		++x;
		++y;
		if (y > HIGH || x > WIDTH)
		{
			break;
		}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = --Second_Pieces_arr_x; i > First_Pieces_arr_x; i--)
			{
				y--;
				map[y][i] = type;
			}
		}
	}
}
void Game_Map::RightCross_Down_Win_Check(int type)
{ 
	Check_Pieces = 0;
	int y = Y_Position_Value;
	int x = X_Position_Value;

	int x_EMPTY_Check = x;
	int y_EMPTY_Check = y;

	int First_Pieces_arr_x = 0;
	int First_Pieces_arr_y = 0;

	int Second_Pieces_arr_x = 0;
	int Second_Pieces_arr_y = 0;

	while (true)
	{
		if (map[y_EMPTY_Check --][x_EMPTY_Check --] == EMPTY)
		{
			if (y > HIGH || x > WIDTH)
			{
				break;
			}
			else
				break;
		}
			if (map[y][x] == type)
			{
				Check_Pieces += 1;
				if (Check_Pieces == 1)
				{
					First_Pieces_arr_x = x;
					First_Pieces_arr_y = y;
				}

				if (Check_Pieces == 2)
				{
					Second_Pieces_arr_x = x;
					Second_Pieces_arr_y = y;
					break;
				}
			}
			--x;
			--y;
			if (x < 0 || y < 0)
			{
				break;
			}
	}

	if (Check_Pieces > 1)
	{
		{
			for (int i = ++Second_Pieces_arr_x; i < First_Pieces_arr_x; i++)
			{
				y++;
				map[y][i] = type;
			}
		}
	}
}   //RIGHT DOWN //RIGHT DOWN


Game_Map::~Game_Map()
{
}