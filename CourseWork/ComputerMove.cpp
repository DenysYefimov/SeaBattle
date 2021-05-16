#include "ComputerMove.h"

void ComputerMove(int your_field[10][10], int your_useful[10][10])
{
	int sh_pos_v, sh_pos_g, computer_choice;
	srand(time(NULL));
	for (int line = 0; line < 10; ++line)
	{
		for (int column = 0; column < 10; ++column)
		{
			if (your_useful[line][column] == 3)
			{
				if (line == 0)
				{
					if (column == 0)
					{
						if ((your_field[line][column + 1] == 1 && your_useful[line][column + 1] == 0) || (your_field[line + 1][column] == 1 && your_useful[line + 1][column] == 0))
						{
							computer_choice = rand() % 2;
							switch (computer_choice)
							{
							case 0:
								if (your_field[line + 1][column])
								{
									your_useful[line + 1][column] = 3;
								}
								else
								{
									your_useful[line + 1][column] = 2;
								}
								return;
								break;

							case 1:
								if (your_field[line][column + 1])
								{
									your_useful[line][column + 1] = 3;
								}
								else
								{
									your_useful[line][column + 1] = 2;
								}
								return;
								break;
							}
						}
					}
					else if (column == 9)
					{
						if ((your_field[line][column - 1] == 1 && your_useful[line][column - 1] == 0) || (your_field[line + 1][column] == 1 && your_useful[line + 1][column] == 0))
						{
							computer_choice = rand() % 2;
							switch (computer_choice)
							{
							case 0:
								if (your_field[line + 1][column])
								{
									your_useful[line + 1][column] = 3;
								}
								else
								{
									your_useful[line + 1][column] = 2;
								}
								return;
								break;

							case 1:
								if (your_field[line][column - 1])
								{
									your_useful[line][column - 1] = 3;
								}
								else
								{
									your_useful[line][column - 1] = 2;
								}
								return;
								break;
							}
						}
					}
					else
					{
						if ((your_field[line][column - 1] == 1 && your_useful[line][column - 1] == 0) || (your_field[line + 1][column] == 1 && your_useful[line + 1][column] == 0) || (your_field[line][column + 1] == 1 && your_useful[line][column + 1] == 0))
						{
							computer_choice = rand() % 3;
							switch (computer_choice)
							{
							case 0:
								if (your_field[line + 1][column])
								{
									your_useful[line + 1][column] = 3;
								}
								else
								{
									your_useful[line + 1][column] = 2;
								}
								return;
								break;

							case 1:
								if (your_field[line][column - 1])
								{
									your_useful[line][column - 1] = 3;
								}
								else
								{
									your_useful[line][column - 1] = 2;
								}
								return;
								break;

							case 2:
								if (your_field[line][column + 1])
								{
									your_useful[line][column + 1] = 3;
								}
								else
								{
									your_useful[line][column + 1] = 2;
								}
								return;
								break;
							}
						}
					}
				}
				else if (line == 9)
				{
				if (column == 0)
				{
					if ((your_field[line][column + 1] == 1 && your_useful[line][column + 1] == 0) || (your_field[line - 1][column] == 1 && your_useful[line - 1][column] == 0))
					{
						computer_choice = rand() % 2;
						switch (computer_choice)
						{
						case 0:
							if (your_field[line - 1][column])
							{
								your_useful[line - 1][column] = 3;
							}
							else
							{
								your_useful[line - 1][column] = 2;
							}
							return;
							break;

						case 1:
							if (your_field[line][column + 1])
							{
								your_useful[line][column + 1] = 3;
							}
							else
							{
								your_useful[line][column + 1] = 2;
							}
							return;
							break;
						}
					}
				}
				else if (column == 9)
				{
					if ((your_field[line][column - 1] == 1 && your_useful[line][column - 1] == 0) || (your_field[line - 1][column] == 1 && your_useful[line - 1][column] == 0))
					{
						computer_choice = rand() % 2;
						switch (computer_choice)
						{
						case 0:
							if (your_field[line - 1][column])
							{
								your_useful[line - 1][column] = 3;
							}
							else
							{
								your_useful[line - 1][column] = 2;
							}
							return;
							break;

						case 1:
							if (your_field[line][column - 1])
							{
								your_useful[line][column - 1] = 3;
							}
							else
							{
								your_useful[line][column - 1] = 2;
							}
							return;
							break;
						}
					}
				}
				else
				{
					if ((your_field[line][column - 1] == 1 && your_useful[line][column - 1] == 0) || (your_field[line - 1][column] == 1 && your_useful[line - 1][column] == 0) || (your_field[line][column + 1] == 1 && your_useful[line][column + 1] == 0))
					{
						computer_choice = rand() % 3;
						switch (computer_choice)
						{
						case 0:
							if (your_field[line - 1][column])
							{
								your_useful[line - 1][column] = 3;
							}
							else
							{
								your_useful[line - 1][column] = 2;
							}
							return;
							break;

						case 1:
							if (your_field[line][column - 1])
							{
								your_useful[line][column - 1] = 3;
							}
							else
							{
								your_useful[line][column - 1] = 2;
							}
							return;
							break;

						case 2:
							if (your_field[line][column + 1])
							{
								your_useful[line][column + 1] = 3;
							}
							else
							{
								your_useful[line][column + 1] = 2;
							}
							return;
							break;
						}
					}
				}
                }
				else
				{
				if (column == 0)
				{
					if ((your_field[line][column + 1] == 1 && your_useful[line][column + 1] == 0) || (your_field[line - 1][column] == 1 && your_useful[line - 1][column] == 0) || (your_field[line + 1][column] == 1 && your_useful[line + 1][column] == 0))
					{
						computer_choice = rand() % 3;
						switch (computer_choice)
						{
						case 0:
							if (your_field[line - 1][column])
							{
								your_useful[line - 1][column] = 3;
							}
							else
							{
								your_useful[line - 1][column] = 2;
							}
							return;
							break;

						case 1:
							if (your_field[line][column + 1])
							{
								your_useful[line][column + 1] = 3;
							}
							else
							{
								your_useful[line][column + 1] = 2;
							}
							return;
							break;

						case 2:
							if (your_field[line + 1][column])
							{
								your_useful[line + 1][column] = 3;
							}
							else
							{
								your_useful[line + 1][column] = 2;
							}
							return;
							break;
						}
					}
				}
				else if (column == 9)
				{
					if ((your_field[line][column - 1] == 1 && your_useful[line][column - 1] == 0) || (your_field[line - 1][column] == 1 && your_useful[line - 1][column] == 0) || (your_field[line + 1][column] == 1 && your_useful[line + 1][column] == 0))
					{
						computer_choice = rand() % 3;
						switch (computer_choice)
						{
						case 0:
							if (your_field[line - 1][column])
							{
								your_useful[line - 1][column] = 3;
							}
							else
							{
								your_useful[line - 1][column] = 2;
							}
							return;
							break;

						case 1:
							if (your_field[line][column - 1])
							{
								your_useful[line][column - 1] = 3;
							}
							else
							{
								your_useful[line][column - 1] = 2;
							}
							return;
							break;

						case 2:
							if (your_field[line + 1][column])
							{
								your_useful[line + 1][column] = 3;
							}
							else
							{
								your_useful[line + 1][column] = 2;
							}
							return;
							break;
						}
					}
				}
				else
				{
					if ((your_field[line][column - 1] == 1 && your_useful[line][column - 1] == 0) || (your_field[line - 1][column] == 1 && your_useful[line - 1][column] == 0) || (your_field[line][column + 1] == 1 && your_useful[line][column + 1] == 0) || (your_field[line + 1][column] == 1 && your_useful[line + 1][column] == 0))
					{
						computer_choice = rand() % 4;
						switch (computer_choice)
						{
						case 0:
							if (your_field[line - 1][column])
							{
								your_useful[line - 1][column] = 3;
							}
							else
							{
								your_useful[line - 1][column] = 2;
							}
							return;
							break;

						case 1:
							if (your_field[line][column - 1])
							{
								your_useful[line][column - 1] = 3;
							}
							else
							{
								your_useful[line][column - 1] = 2;
							}
							return;
							break;

						case 2:
							if (your_field[line][column + 1])
							{
								your_useful[line][column + 1] = 3;
							}
							else
							{
								your_useful[line][column + 1] = 2;
							}
							return;
							break;

						case 3:
							if (your_field[line + 1][column])
							{
								your_useful[line + 1][column] = 3;
							}
							else
							{
								your_useful[line + 1][column] = 2;
							}
							return;
							break;
						}
					}
				}
				}
			}
		}
	}

	do
	{
		sh_pos_g = rand() % 10;
		sh_pos_v = rand() % 10;
	} while (!CheckIfCorrect(sh_pos_v, sh_pos_g, your_useful));



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