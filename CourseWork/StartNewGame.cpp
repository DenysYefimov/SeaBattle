#include "StartNewGame.h"

void StartNewGame(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int INACTIVE_COLOUR, int ACTIVE_COLOUR, int your_field[10][10], int enemy_field[10][10], int & level_of_difficulty)
{

	srand(time(NULL));
	int enemy_counter = 0, your_counter = 0, enemy_temp = 0, your_temp = 0, random_start = rand() % 2, your_useful[10][10]{}, enemy_useful[10][10]{};
	bool f, stop = false;
	if (random_start)
	{
		f = true;
	}
	else
	{
		f = false;
	}

	do
	{
		if (enemy_counter > enemy_temp)
		{
			enemy_temp = enemy_counter;
			your_temp = your_counter;
			YourMove(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, your_field, enemy_field, your_useful, enemy_useful, stop, level_of_difficulty);
			IfSmbWon(enemy_counter, your_counter, enemy_useful, your_useful);
		}
		else if (your_counter > your_temp)
		{
			enemy_temp = enemy_counter;
			your_temp = your_counter;
			if (level_of_difficulty == 2)
			{
				NextGenComputerMove(your_field, your_useful);
			}
			else if (level_of_difficulty == 1)
			{
				ComputerMove(your_field, your_useful);
			}
			else
			{
				EasyComputerMove(your_field, your_useful);
			}
			IfSmbWon(enemy_counter, your_counter, enemy_useful, your_useful);
		}
		else if (f)
		{
			enemy_temp = enemy_counter;
			your_temp = your_counter;
			YourMove(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR, your_field, enemy_field, your_useful, enemy_useful, stop, level_of_difficulty);
			IfSmbWon(enemy_counter, your_counter, enemy_useful, your_useful);
			f = !f;
		}
		else
		{
			enemy_temp = enemy_counter;
			your_temp = your_counter;
			if (level_of_difficulty == 2)
			{
				NextGenComputerMove(your_field, your_useful);
			}
			else if (level_of_difficulty == 1)
			{
				ComputerMove(your_field, your_useful);
			}
			else
			{
				EasyComputerMove(your_field, your_useful);
			}
			IfSmbWon(enemy_counter, your_counter, enemy_useful, your_useful);
			f = !f;
		}
	} while ((!IfSmbWon(enemy_counter, your_counter, enemy_useful, your_useful)) && !stop);
	if (enemy_counter == 20)
	{
		YouWon(output_handle, CSBufInf);
		DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
	}
	else if (your_counter == 20)
	{
		ComputerWon(output_handle, CSBufInf);
		DrawInterface(output_handle, CSBufInf, INACTIVE_COLOUR, ACTIVE_COLOUR);
	}
}