#include "YourMove.h"

void YourMove(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int your_field[10][10], int enemy_field[10][10], int your_useful[10][10], int enemy_useful[10][10], bool & stop, int & level_of_difficulty)
{
	enum KeY
	{
		KEY_ARROW_DOWN = 80,
		KEY_ARROW_UP = 72,
		KEY_ARROW_LEFT = 75,
		KEY_ARROW_RIGHT = 77,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};
	bool test1 = 0;
	int Key = 33, Vcounter_enemy = 0, Gcounter_enemy = 0;
	COORD your_already_set_pos{ (CSBufInf.srWindow.Right / 2) - 31, (CSBufInf.srWindow.Bottom / 2) - 4 }, enemy_field_position{ (CSBufInf.srWindow.Right / 2) - 2, (CSBufInf.srWindow.Bottom / 2) - 4 }, enemy_already_set_pos{ (CSBufInf.srWindow.Right / 2) - 2, (CSBufInf.srWindow.Bottom / 2) - 4 };
	DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, 0, 0, 0, 0, 0);
	DrawAlreadySetShips(output_handle, CSBufInf, your_field, your_already_set_pos);
	DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
	DrawAlreadySetShips(output_handle, CSBufInf, your_useful, your_already_set_pos);
	ControlIfDestroyed(output_handle, CSBufInf, enemy_field, enemy_useful);
	DrawV(CSBufInf, output_handle, enemy_field_position, 68, 1);

	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{
			case KEY_ARROW_DOWN:
				if (Vcounter_enemy < 9)
				{
					++Vcounter_enemy;
					++enemy_field_position.Y;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, 0, 0, 0, 0, 0);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, your_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, your_useful, your_already_set_pos);
				ControlIfDestroyed(output_handle, CSBufInf, enemy_field, enemy_useful);
				DrawV(CSBufInf, output_handle, enemy_field_position, 68, 1);
				break;

			case KEY_ARROW_UP:
				if (Vcounter_enemy > 0)
				{
					--Vcounter_enemy;
					--enemy_field_position.Y;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, 0, 0, 0, 0, 0);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, your_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, your_useful, your_already_set_pos);
				ControlIfDestroyed(output_handle, CSBufInf, enemy_field, enemy_useful);
				DrawV(CSBufInf, output_handle, enemy_field_position, 68, 1);
				break;

			case KEY_ARROW_RIGHT:
				if (Gcounter_enemy < 9)
				{
					++Gcounter_enemy;
					enemy_field_position.X += 2;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, 0, 0, 0, 0, 0);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, your_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, your_useful, your_already_set_pos);
				ControlIfDestroyed(output_handle, CSBufInf, enemy_field, enemy_useful);
				DrawV(CSBufInf, output_handle, enemy_field_position, 68, 1);
				break;

			case KEY_ARROW_LEFT:
				if (Gcounter_enemy > 0)
				{
					--Gcounter_enemy;
					enemy_field_position.X -= 2;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, 0, 0, 0, 0, 0);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, your_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, your_useful, your_already_set_pos);
				ControlIfDestroyed(output_handle, CSBufInf, enemy_field, enemy_useful);
				DrawV(CSBufInf, output_handle, enemy_field_position, 68, 1);
				break;

			case KEY_ENTER:
				if (enemy_field[Vcounter_enemy][Gcounter_enemy])
				{
					enemy_useful[Vcounter_enemy][Gcounter_enemy] = 3;
				}
				else
				{
					enemy_useful[Vcounter_enemy][Gcounter_enemy] = 2;
				}

				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, 0, 0, 0, 0, 0);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, your_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
				DrawAlreadySetShips(output_handle, CSBufInf, your_useful, your_already_set_pos);
				ControlIfDestroyed(output_handle, CSBufInf, enemy_field, enemy_useful);
				return;

			case KEY_ESC:
				DrawMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
				ControlMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, stop, level_of_difficulty);
				if (stop)
				{
					DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
				}
				else
				{
					DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, 0, 0, 0, 0, 0);
					DrawAlreadySetShips(output_handle, CSBufInf, your_field, your_already_set_pos);
					DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
					DrawAlreadySetShips(output_handle, CSBufInf, your_useful, your_already_set_pos);
					ControlIfDestroyed(output_handle, CSBufInf, enemy_field, enemy_useful);
					DrawV(CSBufInf, output_handle, enemy_field_position, 68, 1);
				}
			}
		}
	}
}
