#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "ControlScreen.h"
#include "DrawInterface.h"

void ExitGame(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, bool& stop, int ACTIVE_COLOUR);