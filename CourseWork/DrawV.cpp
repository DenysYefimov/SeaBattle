#include "DrawV.h"

void DrawV(CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, HANDLE output_handle, COORD coord, int ACTIVE_COLOUR, int size)
{
	SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	for (int i = 0; i < size; i++)
	{
		SetConsoleCursorPosition(output_handle, coord);
		std::cout << "***";
		++coord.Y;
	}
}