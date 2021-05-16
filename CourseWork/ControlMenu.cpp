#include "ControlMenu.h"

void ControlMenu(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item, bool & stop, int & level_of_difficulty)
{
	bool stop_menu = false;
	int Key = 33, AMOUNT_OF_ITEMS = 3;
	enum KeY
	{
		KEY_ARROW_DOWN = 80,
		KEY_ARROW_UP = 72,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	enum Menu
	{
		SETTINGS = 0,
		INFO = 1,
		EXIT = 2
	};


	while (!stop_menu)
	{
		if (_kbhit())
		{
			Key = _getch();

			switch (Key)
			{
			case KEY_ARROW_DOWN:

				if (selected_item < AMOUNT_OF_ITEMS - 1)
				{
					selected_item++;
				}
				else selected_item = 0;

				DrawMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ARROW_UP:

				if (selected_item > 0)
				{
					selected_item--;
				}
				else selected_item = AMOUNT_OF_ITEMS - 1;

				DrawMenu(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ENTER:

				switch (selected_item)
				{

				case SETTINGS:

					DrawSettings(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
					ControlSettings(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0, DrawMenu, level_of_difficulty);
					break;

				case INFO:
					Info(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 1, DrawMenu);
					break;

				case EXIT:

					ExitFromNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, stop, ACTIVE_COLOUR);
					stop_menu = stop;
					break;
				}
				break;
			case KEY_ESC:
				stop_menu = true;
				break;
			}
		}
		fflush(stdin);
	}
	/*if (stop)
	{
		DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
	}
	else
	{
		DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, 0, 1);
		DrawAlreadySetShips(output_handle, CSBufInf, your_field, already_set_pos);
		if (if_from_start)
		{
			DrawAlreadySetShips(output_handle, CSBufInf, enemy_useful, enemy_already_set_pos);
			DrawAlreadySetShips(output_handle, CSBufInf, your_useful, already_set_pos);
		}
	}*/
}