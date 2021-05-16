#pragma once
#include <iostream>
#include "ControlScreen.h"

void DrawNewGame(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int Sh4, int Sh3, int Sh2, int Sh1, int active, bool active_menu);