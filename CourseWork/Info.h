#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include "ControlScreen.h"

void Info(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INNACTIVE_COLOUR, int ACTIVE_COLOUR, int from_where_item, void (*FromWhere)(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item));