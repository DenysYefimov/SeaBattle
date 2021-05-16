#include "DrawInterface.h"

void DrawInterface(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO &CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item)
{
	int AMOUNT_OF_ITEMS = 4;
	const char *InterfaceArr[]{ "New Game", "Settings", "Info", "Exit" };
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	COORD interval = { (CSBufInf.srWindow.Right / 2) - 4, (CSBufInf.srWindow.Bottom / 2) - 5 };

	for (int i = 0; i < AMOUNT_OF_ITEMS; i++)
	{
		SetConsoleCursorPosition(output_handle, interval);
		if (i == selected_item) SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
		std::cout << InterfaceArr[i];
		SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
		interval.Y += 3;
		if (i == 1) interval.X += 2;
	}
}