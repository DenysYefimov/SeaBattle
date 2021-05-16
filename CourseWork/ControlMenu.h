#pragma once
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include "DrawMenu.h"
#include "DrawNewGame.h"
#include "ExitFromNewGame.h"
#include "DrawSettings.h"
#include "ControlSettings.h"
#include "Info.h"
#include "DrawInterface.h"
#include "DrawAlreadySetShips.h"

void ControlMenu(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int selected_item, bool & stop, int& level_of_difficulty);