#pragma once
#include <conio.h>
#include "DrawNewGame.h"
#include "DrawV.h"
#include "DrawG.h"
#include "DrawAlreadySetShips.h"

void SetSh2(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int& Sh4, int& Sh3, int& Sh2, int& Sh1, int & active, bool active_menu, int your_field[10][10]);
