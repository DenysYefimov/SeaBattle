#pragma once
#include "DrawNewGame.h"
#include "DrawMenu.h"
#include "ControlMenu.h"
#include "DrawV.h"
#include "YourMove.h"
#include "ComputerMove.h"
#include "NextGenComputerMove.h"
#include "EasyComputerMove.h"
#include "IfSmbWon.h"
#include "YouWon.h"
#include "ComputerWon.h"

void StartNewGame(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int your_field[10][10], int enemy_field[10][10], int& level_of_difficulty);