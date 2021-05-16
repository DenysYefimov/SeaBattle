#include "EasyComputerMove.h"

void EasyComputerMove(int your_field[10][10], int your_useful[10][10])
{
	int sh_pos_v, sh_pos_g;
	srand(time(NULL));
	sh_pos_g = rand() % 10;
	sh_pos_v = rand() % 10;
	if (your_field[sh_pos_v][sh_pos_g] == 1)
	{
		your_useful[sh_pos_v][sh_pos_g] = 3;
	}
	else
	{
		your_useful[sh_pos_v][sh_pos_g] = 2;
	}
	return;
}
