#include "ControlInterface.h"

void ControlInterface(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO &CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int your_field[10][10], int enemy_field[10][10])
{
	int Key = 33, selected_item = 0, AMOUNT_OF_ITEMS = 4, Sh1 = 4, Sh2 = 3, Sh3 = 2, Sh4 = 1, active = 1, level_of_difficulty = 2;
	bool stop = false, if_ready = false;

	enum KeY
	{
		KEY_ARROW_DOWN = 80,
		KEY_ARROW_UP = 72,
		KEY_ENTER = 13,
		KEY_ESC = 27
	};

	enum Interface
	{
		NEW_GAME = 0,
		SETTINGS = 1,
		INFO = 2,
		EXIT = 3
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

				DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ARROW_UP:

				if (selected_item > 0)
				{
					selected_item--;
				}
				else selected_item = AMOUNT_OF_ITEMS - 1;

				DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, selected_item);
				break;

			case KEY_ENTER:

				switch (selected_item)
				{

				case NEW_GAME:
					DrawNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 1, 2, 3, 4, 1, 0);
					for (int i = 0; i < 10; ++i)
					{
						for (int j = 0; j < 10; ++j)
						{
							your_field[i][j] = 0;
						}
					}
					ControlNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, Sh4, Sh3, Sh2, Sh1, active, your_field, 4, enemy_field, if_ready, level_of_difficulty);
					if (if_ready)
					{
						StartNewGame(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, your_field, enemy_field, level_of_difficulty);
						Sh1 = 4, Sh2 = 3, Sh3 = 2, Sh4 = 1;
						active = 1;
						if_ready = false;
					}
					break;

				case SETTINGS:

					DrawSettings(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 0);
					ControlSettings(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 1, DrawInterface, level_of_difficulty);
					break;

				case INFO:

					Info(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, 2, DrawInterface);
					break;

				case EXIT:

					ExitGame(output_handle, CSBufInf, INACTIVE_COLOUR, stop, ACTIVE_COLOUR);
					break;
				}
			}
		}
		fflush(stdin);
	}
}