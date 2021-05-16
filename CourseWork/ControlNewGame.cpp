#include "ControlNewGame.h"

void ControlNewGame(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int & Sh4, int & Sh3, int & Sh2, int & Sh1, int & active, int your_field[10][10], int AMOUNT_OF_ITEMS_G, int enemy_field[10][10], bool & if_ready, int& level_of_difficulty)
{
	int Key = 33, selected_item = 0, AMOUNT_OF_ITEMS_V = 2, active_v = 1;
	bool stop = false, stop_keys = false;
	COORD position{ (CSBufInf.srWindow.Right / 2) - 31, (CSBufInf.srWindow.Bottom / 2) - 4 };

	enum KeY
	{
		KEY_ARROW_DOWN = 80,
		KEY_ARROW_UP = 72,
		KEY_ARROW_LEFT = 75,
		KEY_ARROW_RIGHT = 77,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	std::thread computer(ComputerSet, enemy_field);
	computer.detach();

	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{
			case KEY_ARROW_LEFT:

				if (Sh1 || Sh2 || Sh3 || Sh4)
				{
					stop_keys = false;

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

				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
				break;

			case KEY_ARROW_RIGHT:

				if (Sh1 || Sh2 || Sh3 || Sh4)
				{
					stop_keys = false;
					while (!stop_keys)
					{
						if (active < AMOUNT_OF_ITEMS_G)
						{
							active++;
						}
						else active = 1;

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

				DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0);
				DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
				break;

			case KEY_ARROW_UP:
				if (active_v > 0)
				{
					--active_v;
					DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, 0, 1);
					DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
				}
				else
				{
					active_v = 1;
					DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0);
					DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
				}
				break;

			case KEY_ARROW_DOWN:
				if (active_v == 0)
				{
					++active_v;
					DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0);
					DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
				}
				else 
				{
					active_v = 0;
					DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, 0, 1);
					DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
				}
				break;

			case KEY_ENTER:

				if (active_v == 1)
				{
					if (Sh1 || Sh2 || Sh3 || Sh4)
					{
						switch (active)
						{
						case 4:
							SetSh1(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0, your_field);
							break;

						case 3:
							SetSh2(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0, your_field);
							break;

						case 2:
							SetSh3(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0, your_field);
							break;

						case 1:
							SetSh4(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, 0, your_field);
							break;
						}
					}
				}
				else
				{
					DrawMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
					ControlMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, stop, level_of_difficulty);
					if (stop)
					{
						DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
					}
					else
					{
						DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, 0, 1);
						DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
					}
				}
				break;

			case KEY_ESC:
				DrawMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
				ControlMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, stop, level_of_difficulty);
				if (stop)
				{
					DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
				}
				else
				{
					DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, 0, 1);
					DrawAlreadySetShips(output_handle, CSBufInf, your_field, position);
				}
				break;
			}						
		}
		if (!(Sh1 || Sh2 || Sh3 || Sh4))
		{
			if_ready = true;
			stop = true;
		}
		fflush(stdin);
	}
}