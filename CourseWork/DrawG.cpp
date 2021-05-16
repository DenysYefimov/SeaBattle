#include "DrawG.h"

void DrawG(CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, HANDLE output_handle, COORD coord, int ACTIVE_COLOUR, int size)
{
	SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	//for (int i = 0; i < 2; i++)
	//{
		SetConsoleCursorPosition(output_handle, coord);
		for (int i = 0; i < size; i++)
			std::cout << "**";
		std::cout << "*";
		++coord.Y;
	//}
}