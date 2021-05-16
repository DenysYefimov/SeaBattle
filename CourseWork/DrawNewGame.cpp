#include "DrawNewGame.h"

void DrawElement(COORD & interval, HANDLE output_handle, int a)
{
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << char(a);
}

void DrawSet(CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, HANDLE output_handle, COORD& coord, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int size, bool active)
{
	if (active) SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	DrawElement(coord, output_handle, 218);
	++coord.X;
	DrawElement(coord, output_handle, 196);
	--coord.X;
	for (int i = 0; i < size - 1; i++)
	{
		++coord.Y;
		DrawElement(coord, output_handle, 195);
		++coord.X;
		DrawElement(coord, output_handle, 196);
		--coord.X;
	}
	++coord.Y;
	DrawElement(coord, output_handle, 192);
	++coord.X;
	DrawElement(coord, output_handle, 196);
	++coord.X;
	DrawElement(coord, output_handle, 217);
	for (int i = 0; i < size - 1; i++)
	{
		--coord.Y;
		DrawElement(coord, output_handle, 180);
	}
	--coord.Y;
	DrawElement(coord, output_handle, 191);
	if (active) SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
}

void DrawNewGame(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int Sh4, int Sh3, int Sh2, int Sh1, int active, bool active_menu)
{
	char Letter[]{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);

	COORD interval = { (CSBufInf.srWindow.Right / 2) - 30, (CSBufInf.srWindow.Bottom / 2) - 5 }, menu = { (CSBufInf.srWindow.Right / 2) - 2, 2 };
	SetConsoleCursorPosition(output_handle, menu);
	if (active_menu) SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
	std::cout << "Menu";
	if (active_menu) SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
	for (int column = 0; column < 10; column++)
	{
		SetConsoleCursorPosition(output_handle, interval);
		std::cout << Letter[column];
		interval.X += 2;
	}

	interval.X += 9;
	for (int column = 0; column < 10; column++)
	{
		SetConsoleCursorPosition(output_handle, interval);
		std::cout << Letter[column];
		interval.X += 2;
	}
	
	interval.X -= 50;
	++interval.Y;
	DrawElement(interval, output_handle, 218);
	for (int column = 1; column < 10; column++)
	{
		++interval.X;
		DrawElement(interval, output_handle, 196);
		++interval.X;
		DrawElement(interval, output_handle, 194);
	}
	++interval.X;
	DrawElement(interval, output_handle, 196);
	++interval.X;
	DrawElement(interval, output_handle, 191);

	interval.X += 9;
	DrawElement(interval, output_handle, 218);
	for (int column = 1; column < 10; column++)
	{
		++interval.X;
		DrawElement(interval, output_handle, 196);
		++interval.X;
		DrawElement(interval, output_handle, 194);
	}
	++interval.X;
	DrawElement(interval, output_handle, 196);
	++interval.X;
	DrawElement(interval, output_handle, 191);

	for (int line = 1; line < 10; line++)
	{
		interval.X -= 50;
		SetConsoleCursorPosition(output_handle, interval);
		std::cout << line;
		++interval.Y;
		++interval.X;
		DrawElement(interval, output_handle, 195);
		for (int column = 1; column < 10; column++)
		{
			++interval.X;
			DrawElement(interval, output_handle, 196);
			++interval.X;
			DrawElement(interval, output_handle, 197);
		}
		++interval.X;
		DrawElement(interval, output_handle, 196);
		++interval.X;
		DrawElement(interval, output_handle, 180);

		interval.X += 8;
		--interval.Y;
		SetConsoleCursorPosition(output_handle, interval);
		std::cout << line;
		++interval.Y;
		++interval.X;
		DrawElement(interval, output_handle, 195);
		for (int column = 1; column < 10; column++)
		{
			++interval.X;
			DrawElement(interval, output_handle, 196);
			++interval.X;
			DrawElement(interval, output_handle, 197);
		}
		++interval.X;
		DrawElement(interval, output_handle, 196);
		++interval.X;
		DrawElement(interval, output_handle, 180);
	}

	interval.X -= 51;
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << 10;
	interval.X += 2;
	++interval.Y;
	DrawElement(interval, output_handle, 192);
	for (int i = 1; i < 10; i++)
	{
		++interval.X;
		DrawElement(interval, output_handle, 196);
		++interval.X;
		DrawElement(interval, output_handle, 193);
	}
	++interval.X;
	DrawElement(interval, output_handle, 196);
	++interval.X;
	DrawElement(interval, output_handle, 217);

	interval.X += 7;
	--interval.Y;
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << 10;
	++interval.Y;
	interval.X += 2;
	DrawElement(interval, output_handle, 192);
	for (int i = 1; i < 10; i++)
	{
		++interval.X;
		DrawElement(interval, output_handle, 196);
		++interval.X;
		DrawElement(interval, output_handle, 193);
	}
	++interval.X;
	DrawElement(interval, output_handle, 196);
	++interval.X;
	DrawElement(interval, output_handle, 217);

	COORD tips{ 76, 19 };
	SetConsoleCursorPosition(output_handle, tips);
	std::cout << "Use \"Arrows\" to move between items";
	tips.X -= 5;
	tips.Y += 2;
	SetConsoleCursorPosition(output_handle, tips);
	std::cout << "Use \"Enter\" to choose an active item";
	tips.Y += 2;
	SetConsoleCursorPosition(output_handle, tips);
	std::cout << "Use \"Space\" to change the ship location";
	tips.Y += 2;
	SetConsoleCursorPosition(output_handle, tips);
	std::cout << "Use \"Esc\" to enter the Menu";
		
	if (Sh1 || Sh2 || Sh3 || Sh4)
	{
		interval.X -= 59;
		interval.Y += 3;
		if (Sh4)
		{
			if (active == 1) DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 4, true);
			else DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 4, false);
			std::cout << 'x' << Sh4;
		}
		interval.X += 10;
		if (Sh3)
		{
			if (active == 2) DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 3, true);
			else DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 3, false);
			std::cout << 'x' << Sh3;
		}
		interval.X += 10;
		if (Sh2)
		{
			if (active == 3) DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 2, true);
			else DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 2, false);
			std::cout << 'x' << Sh2;
		}
		interval.X += 10;
		if (Sh1)
		{
			if (active == 4) DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 1, true);
			else DrawSet(CSBufInf, output_handle, interval, INACTIVE_COLOUR, ACTIVE_COLOUR, 1, false);
			std::cout << 'x' << Sh1;
		}
	}
}