#pragma once
#include <iostream>
#include <windows.h>
#include "ControlScreen.h"

void DrawMenu(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO & CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item);