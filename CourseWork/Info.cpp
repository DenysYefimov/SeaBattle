#include "Info.h"

void Info(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INNACTIVE_COLOUR, int ACTIVE_COLOUR, int from_where_item, void (*FromWhere)(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item))
{
	int Key = 33, KEY_ENTER = 13, KEY_ESC = 27;
	bool stop = false;
	ControlScreen(output_handle, CSBufInf, INNACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 9, (CSBufInf.srWindow.Bottom / 2) - 4 };
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Classic Sea Battle";
	interval.Y += 3;
	interval.X -= 2;
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Prod. by Denys Yefimov";
	interval.Y += 3;
	interval.X -= 14;
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Press \"Esc\" or \"Enter\" to return to the Interface";
	while (!stop)
	{
		if (_kbhit())
		{
			Key = _getch();

			if (Key == KEY_ENTER || Key == KEY_ESC)
			{
				system("cls");
				stop = true;
				break;
			}
		}
	}
	FromWhere(output_handle, CSBufInf, INNACTIVE_COLOUR, ACTIVE_COLOUR, from_where_item);
}