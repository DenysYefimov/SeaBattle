#pragma once
#include <conio.h>
#include <thread>
#include "DrawNewGame.h"
#include "DrawMenu.h"
#include "ControlMenu.h"
#include "SetSh1.h"
#include "SetSh2.h"
#include "SetSh3.h"
#include "SetSh4.h"
#include "ComputerSet.h"

void ControlNewGame(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int & Sh4, int & Sh3, int & Sh2, int & Sh1, int & active, int your_field[10][10], int AMOUNT_OF_ITEMS_G, int enemy_field[10][10], bool& if_ready, int& level_of_difficulty);