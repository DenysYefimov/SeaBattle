#pragma once
#include <windows.h>
#include <iostream>

void DrawG(CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, HANDLE output_handle, COORD coord, int ACTIVE_COLOUR, int size);