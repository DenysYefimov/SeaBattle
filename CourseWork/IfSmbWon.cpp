#include "IfSmbWon.h"

int IfSmbWon(int & enemy_counter, int & your_counter, int enemy_useful[10][10], int your_useful[10][10])
{
	your_counter = 0;
	enemy_counter = 0;

	for (int line = 0; line < 10; ++line)
	{
		for (int column = 0; column < 10; ++column)
		{
			if (enemy_useful[line][column] == 3)
			{
				++enemy_counter;
			}
		}
	}
	if (enemy_counter == 20)
		return 1;

	for (int line = 0; line < 10; ++line)
	{
		for (int column = 0; column < 10; ++column)
		{
			if (your_useful[line][column] == 3)
			{
				++your_counter;
			}
		}
	}
	if (your_counter == 20)
		return 2;

    return 0;
}