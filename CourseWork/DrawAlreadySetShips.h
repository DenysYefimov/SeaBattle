#pragma once
#include <windows.h>
#include "DrawV.h"

void DrawAlreadySetShips(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int your_field[10][10], COORD position);