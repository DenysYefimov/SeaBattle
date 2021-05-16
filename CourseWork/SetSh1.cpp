#include "SetSh1.h"

void SetSh1(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int & Sh4, int & Sh3, int & Sh2, int & Sh1, int & active, bool active_menu, int your_field[10][10])
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
	int Key = 33, Vcounter = 0, Gcounter = 0;
	bool stop_keys = false;

	DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, active_menu);
	COORD position{ (CSBufInf.srWindow.Right / 2) - 31, (CSBufInf.srWindow.Bottom / 2) - 4 }, already_set_pos{ (CSBufInf.srWindow.Right / 2) - 31, (CSBufInf.srWindow.Bottom / 2) - 4 };
	DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
	DrawV(CSBufInf, output_handle, position, 187, 1);

	while (true)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{
			case KEY_ARROW_DOWN:
				if (Vcounter < 9)
				{
					++Vcounter;
					++position.Y;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, active_menu);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
				DrawV(CSBufInf, output_handle, position, 187, 1);
				break;

			case KEY_ARROW_UP:
				if (Vcounter > 0)
				{
					--Vcounter;
					--position.Y;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, active_menu);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
				DrawV(CSBufInf, output_handle, position, 187, 1);
				break;

			case KEY_ARROW_RIGHT:
				if (Gcounter < 9)
				{
					++Gcounter;
					position.X += 2;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, active_menu);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
				DrawV(CSBufInf, output_handle, position, 187, 1);
				break;

			case KEY_ARROW_LEFT:
				if (Gcounter > 0)
				{
					--Gcounter;
					position.X -= 2;
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, active_menu);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
				DrawV(CSBufInf, output_handle, position, 187, 1);
				break;

			case KEY_ENTER:
				your_field[Vcounter][Gcounter] = 1;
				--Sh1;
				if (Sh1 || Sh2 || Sh3 || Sh4)
				{
					if (Sh1);
					else
					{
						while (!stop_keys)
						{
							if (active > 1)
							{
								--active;
							}
							else active = 4;

							switch (active)
							{
							case 1:
								if (!Sh4);
								else stop_keys = true;
								break;

							case 2:
								if (!Sh3);
								else stop_keys = true;
								break;

							case 3:
								if (!Sh2);
								else stop_keys = true;
								break;

							case 4:
								if (!Sh1);
								else stop_keys = true;
								break;
							}
						}
					}
				}
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, active_menu);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
				return;

			case KEY_ESC:
				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, active_menu);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
				return;

			}
		}
	}
}