#pragma once
#include <windows.h>
#include <conio.h>
#include "DrawSettings.h"

void ControlSettings(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int from_where_item, void (*FromWhere)(HANDLE, CONSOLE_SCREEN_BUFFER_INFO&, int, int, int), int& level_of_difficulty);