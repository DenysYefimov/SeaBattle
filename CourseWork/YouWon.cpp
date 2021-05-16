#include "YouWon.h"

void YouWon(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf)
{
	int Key = 33, KEY_ENTER = 13, KEY_ESC = 27;
	bool stop = false;
	ControlScreen(output_handle, CSBufInf, 0137);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 5, (CSBufInf.srWindow.Bottom / 2) - 3 };
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "You've won";
	interval.Y += 3;
	interval.X -= 20;
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
}