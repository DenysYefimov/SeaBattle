#include "DrawAlreadySetShips.h"

void DrawAlreadySetShips(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int your_field[10][10], COORD position)
{
	for (int column = 0; column < 10; ++column)
	{
		for (int line = 0; line < 10; ++line)
		{
			if (your_field[column][line] == 1)
			{
				DrawV(CSBufInf, output_handle, position, 51, 1);
			}
			else if (your_field[column][line] == 2)
			{
				DrawV(CSBufInf, output_handle, position, 17, 1);
			}
			else if (your_field[column][line] == 3)
			{
				DrawV(CSBufInf, output_handle, position, 102, 1);
			}
			position.X += 2;
		}
		position.X -= 20;
		++position.Y;
	}
}
