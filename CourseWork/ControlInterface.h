#pragma once
#include <windows.h>
#include <conio.h>
#include "DrawInterface.h"
#include "DrawNewGame.h"
#include "ControlNewGame.h"
#include "DrawSettings.h"
#include "ControlSettings.h"
#include "Info.h"
#include "ExitGame.h"
#include "StartNewGame.h"


void ControlInterface(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO &CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int your_field[10][10], int enemy_field[10][10]);