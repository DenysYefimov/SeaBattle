#pragma once
#include "DrawNewGame.h"
#include "DrawMenu.h"
#include "ControlMenu.h"
#include "DrawV.h"
#include "ControlIfDestroyed.h"

void YourMove(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int your_field[10][10], int enemy_field[10][10], int your_useful[10][10], int enemy_useful[10][10], bool& stop, int& level_of_difficulty);