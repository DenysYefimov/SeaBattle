#include <iostream>
#include <windows.h>
#include <conio.h>
#include "DrawInterface.h"
#include "ControlInterface.h"
#define WHITE_ON_VIOLET 0137
#define TURQOISE_ON_VIOLET 0133
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ENTER 13
#define KEY_ESC 27
#define LENGTH_OF_MENU_ITEMS 20
#define AMOUNT_OF_MENU_ITEMS 3
#define AMOUNT_OF_SETTINGS_ITEMS 4

int your_field[10][10]{}, enemy_field[10][10]{};
HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO CSBufInf;

int main()
{
	system("title Sea Battle");
	DrawInterface(output_handle, CSBufInf, WHITE_ON_VIOLET, TURQOISE_ON_VIOLET);
	ControlInterface(output_handle, CSBufInf, WHITE_ON_VIOLET, TURQOISE_ON_VIOLET, your_field, enemy_field);

	return 0;
}