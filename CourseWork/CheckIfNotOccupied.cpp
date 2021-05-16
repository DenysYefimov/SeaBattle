#include "CheckIfNotOccupied.h"

bool CheckIfNotOccupied(int vertical_or_not, int sh_pos_v, int sh_pos_g, int size, int enemy_field[10][10])
{
	if (vertical_or_not)
	{
		if (sh_pos_g == 0)
		{
			if (sh_pos_v == 0)
			{
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v++][sh_pos_g + 1])
						return false;
				}
			}
			else if (sh_pos_v == (10 - size))
			{
				--sh_pos_v;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v++][sh_pos_g + 1])
						return false;
				}
			}
			else
			{
				--sh_pos_v;
				for (int i = 0; i <= size + 1; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v++][sh_pos_g + 1])
						return false;
				}
			}
		}
		else if (sh_pos_g == 9)
		{
			if (sh_pos_v == 0)
			{
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v++][sh_pos_g - 1])
						return false;
				}
			}
			else if (sh_pos_v == (10 - size))
			{
				--sh_pos_v;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v++][sh_pos_g - 1])
						return false;
				}
			}
			else
			{
				--sh_pos_v;
				for (int i = 0; i <= size + 1; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v++][sh_pos_g - 1])
						return false;
				}
			}
		}
		else
		{
			if (sh_pos_v == 0)
			{
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v][sh_pos_g - 1] || enemy_field[sh_pos_v++][sh_pos_g + 1])
						return false;
				}
			}
			else if (sh_pos_v == (10 - size))
			{
				--sh_pos_v;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v][sh_pos_g - 1] || enemy_field[sh_pos_v++][sh_pos_g + 1])
						return false;
				}
			}
			else
			{
				--sh_pos_v;
				for (int i = 0; i <= size + 1; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v][sh_pos_g - 1] || enemy_field[sh_pos_v++][sh_pos_g + 1])
						return false;
				}
			}
		}
	}
	else
	{
		if (sh_pos_g == 0)
		{
			if (sh_pos_v == 0)
			{
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v + 1][sh_pos_g++])
						return false;
				}
			}
			else if (sh_pos_v == 9)
			{
				--sh_pos_v;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v + 1][sh_pos_g++])
						return false;
				}
			}
			else
			{
				--sh_pos_v;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v + 1][sh_pos_g] || enemy_field[sh_pos_v + 2][sh_pos_g++])
						return false;
				}
			}
		}
		else if (sh_pos_g == (10 - size))
		{
			if (sh_pos_v == 0)
			{
				--sh_pos_g;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v + 1][sh_pos_g++])
						return false;
				}
			}
			else if (sh_pos_v == 9)
			{
				--sh_pos_g;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v - 1][sh_pos_g++])
						return false;
				}
			}
			else
			{
				--sh_pos_v;
				--sh_pos_g;
				for (int i = 0; i <= size; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v + 1][sh_pos_g] || enemy_field[sh_pos_v + 2][sh_pos_g++])
						return false;
				}
			}
		}
		else
		{
			if (sh_pos_v == 0)
			{
				--sh_pos_g;
				for (int i = 0; i <= size + 1; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v + 1][sh_pos_g++])
						return false;
				}
			}
			else if (sh_pos_v == 9)
			{
				--sh_pos_g;
				for (int i = 0; i <= size + 1; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v - 1][sh_pos_g++])
						return false;
				}
			}
			else
			{
				--sh_pos_v;
				--sh_pos_g;
				for (int i = 0; i <= size + 1; ++i)
				{
					if (enemy_field[sh_pos_v][sh_pos_g] || enemy_field[sh_pos_v + 1][sh_pos_g] || enemy_field[sh_pos_v + 2][sh_pos_g++])
						return false;
				}
			}
		}
	}
	return true;
}
