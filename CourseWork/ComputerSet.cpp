#include "ComputerSet.h"

void ComputerSet(int enemy_field[10][10])
{
	int vertical_or_not, sh_pos_v, sh_pos_g;
	srand(time(NULL));

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			enemy_field[i][j] = 0;
		}
	}

	vertical_or_not = rand() % 2;
	if (vertical_or_not)
	{
		sh_pos_v = rand() % 7;
		sh_pos_g = rand() % 10;
		for (int i = 0; i < 4; i++)
		{
			enemy_field[sh_pos_v++][sh_pos_g] = 1;
		}
	}
	else
	{
		sh_pos_v = rand() % 10;
		sh_pos_g = rand() % 7;
		for (int i = 0; i < 4; i++)
		{
			enemy_field[sh_pos_v][sh_pos_g++] = 1;
		}
	}

	for (int i = 0; i < 2; i++)
	{
		do
		{
			vertical_or_not = rand() % 2;
			if (vertical_or_not)
			{
				sh_pos_v = rand() % 8;
				sh_pos_g = rand() % 10;
			}
			else
			{
				sh_pos_v = rand() % 10;
				sh_pos_g = rand() % 8;
			}
		} while (!CheckIfNotOccupied(vertical_or_not, sh_pos_v, sh_pos_g, 3, enemy_field));

		if (vertical_or_not)
		{
			for (int i = 0; i < 3; i++)
			{
				enemy_field[sh_pos_v++][sh_pos_g] = 1;
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				enemy_field[sh_pos_v][sh_pos_g++] = 1;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		do
		{
			vertical_or_not = rand() % 2;
			if (vertical_or_not)
			{
				sh_pos_v = rand() % 9;
				sh_pos_g = rand() % 10;
			}
			else
			{
				sh_pos_v = rand() % 10;
				sh_pos_g = rand() % 9;
			}
		} while (!CheckIfNotOccupied(vertical_or_not, sh_pos_v, sh_pos_g, 2, enemy_field));

		if (vertical_or_not)
		{
			for (int i = 0; i < 2; i++)
			{
				enemy_field[sh_pos_v++][sh_pos_g] = 1;
			}
		}
		else
		{
			for (int i = 0; i < 2; i++)
			{
				enemy_field[sh_pos_v][sh_pos_g++] = 1;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		do
		{
			sh_pos_v = rand() % 10;
			sh_pos_g = rand() % 10;
		} while (!CheckIfNotOccupied(1, sh_pos_v, sh_pos_g, 1, enemy_field));

		enemy_field[sh_pos_v][sh_pos_g] = 1;
	}
}