#include "ControlSettings.h"

void ControlSettings(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int from_where_item, void (*FromWhere)(HANDLE, CONSOLE_SCREEN_BUFFER_INFO&, int, int, int), int& level_of_difficulty)
{
	int Key = 33, selected_item = 0, AMOUNT_OF_ITEMS = 4;
	bool stop = false;
	enum KeY
	{
		KEY_ARROW_DOWN = 80,
		KEY_ARROW_UP = 72,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	enum Settings
	{
		EASY = 0,
		MEDIUM = 1,
		HARD = 2,
		RETURN_TO_MENU = 3
	};

	while (!stop)
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

				DrawSettings(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ARROW_UP:

				if (selected_item > 0)
				{
					selected_item--;
				}
				else selected_item = AMOUNT_OF_ITEMS - 1;

				DrawSettings(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ENTER:

				switch (selected_item)
				{

				case EASY:

					level_of_difficulty = 0;
					break;

				case MEDIUM:

					level_of_difficulty = 1;
					break;

				case HARD:

					level_of_difficulty = 2;
					break;

				case RETURN_TO_MENU:
					stop = true;
					break;
				}
				break;

			case KEY_ESC:
				stop = true;
				break;
			}
		}
		fflush(stdin);
	}
	FromWhere(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, from_where_item);
}
