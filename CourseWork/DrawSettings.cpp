#include "DrawSettings.h"

void DrawSettings(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO &CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item = 0)
{
	ControlScreen(output_handle, CSBufInf, INACTIVE_COLOUR);
	
	int AMOUNT_OF_ITEMS = 4;
	const char * SettingsArr[]{ "Easy", "Medium", "Hard",  "Return to Menu" };
	enum Settings
	{
		EASY = 0,
		MEDIUM = 1,
		HARD = 2,
		RETURN_TO_MENU = 3
	};


	COORD interval{ (CSBufInf.srWindow.Right / 2) - 4, (CSBufInf.srWindow.Bottom / 2) - 9 };
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Settings\n\n";

	interval.Y += 3;
	interval.X -= 6;
	SetConsoleCursorPosition(output_handle, interval);
	std::cout << "Level of Difficulty";

	interval.Y += 3;
	interval.X += 8;

	for (int i = 0; i < AMOUNT_OF_ITEMS; i++)
	{
		SetConsoleCursorPosition(output_handle, interval);
		if (i == selected_item)
			SetConsoleTextAttribute(output_handle, ACTIVE_COLOUR);
		std::cout << SettingsArr[i];
		SetConsoleTextAttribute(output_handle, INACTIVE_COLOUR);
		interval.Y += 3;

		switch (i)
		{

		case EASY:
			interval.X -= 1;
			break;

		case MEDIUM:
			interval.X += 1;
			break;

		case HARD:
			interval.X -= 5;
			break;

		default:
			break;
		}
	}
}