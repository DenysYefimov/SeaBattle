#include "DrawMenu.h"

void DrawMenu(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item = 0)
{
	int AMOUNT_OF_ITEMS = 3;
	const char* MenuArr[]{ "Settings", "Info", "Exit" };
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 2, (CSBufInf.srWindow.Bottom / 2) - 5 };

	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Menu";
	interval.X -= 2;
	interval.Y += 3;

	for (int i = 0; i < AMOUNT_OF_ITEMS; i++)
	{
		SetConsoleCursorPosition(output_handle, interval);
		if (i == selected_item)
			SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
		std::cout << MenuArr[i];
		SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
		interval.Y += 3;
		if (i == 0) interval.X += 2;
	}
}