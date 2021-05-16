#include "ControlIfDestroyed.h"

void ControlIfDestroyed(HANDLE output_handle, CONSOLE_SCREEN_BUFFER_INFO& CSBufInf, int enemy_field[10][10], int enemy_useful[10][10])
{
	COORD enemy_field_position{ (CSBufInf.srWindow.Right / 2) - 2, (CSBufInf.srWindow.Bottom / 2) - 4 }, temp;

	for (int line = 0; line < 10; ++line)
	{
		for (int column = 0; column < 10; ++column)
		{
			temp = enemy_field_position;
			if (enemy_useful[line][column] == 3 && enemy_field[line][column] == 1)
			{
				if (column < 9 && enemy_field[line][column + 1] == 1 && enemy_useful[line][column + 1] == 3)
				{
					if (column < 8 && enemy_field[line][column + 2] == 1 && enemy_useful[line][column + 2] == 3)
					{
						if (column < 7 && enemy_field[line][column + 3] == 1 && enemy_useful[line][column + 3] == 3)
						{
							if (column > 0)
							{
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
							if (column < 6)
							{
								if (column == 0)
								{
									temp.X += 8;
								}
								else
								{
									temp.X += 10;
								}
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else if ((column < 7 && enemy_field[line][column + 3] == 0 && enemy_field[line][column - 1] == 0) || (enemy_field[line][9] == 1 && enemy_useful[line][9] == 3 && enemy_field[line][6] == 0))
						{
							if (column > 0)
							{
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
							if (column < 7)
							{
								if (column == 0)
								{
									temp.X += 6;
								}
								else
								{
									temp.X += 8;
								}
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
					}
					else if ((column < 8 && enemy_field[line][column + 2] == 0 && enemy_field[line][column - 1] == 0) || (enemy_field[line][9] == 1 && enemy_useful[line][9] == 3 && enemy_field[line][7] == 0))
					{
						if (column > 0)
						{
							temp.X -= 2;
							DrawV(CSBufInf, output_handle, temp, 17, 1);
						}
						if (column < 8)
						{
							if (column == 0)
							{
								temp.X += 4;
							}
							else
							{
								temp.X += 6;
							}
							DrawV(CSBufInf, output_handle, temp, 17, 1);
						}
					}
				}
				else if (line < 9 && enemy_field[line + 1][column] == 1 && enemy_useful[line + 1][column] == 3)
				{
					if (line < 8 && enemy_field[line + 2][column] == 1 && enemy_useful[line + 2][column] == 3)
					{
						if (line < 7 && enemy_field[line + 3][column] == 1 && enemy_useful[line + 3][column] == 3)
						{
							if (line > 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
							if (line < 6)
							{
								if (line == 0)
								{
									temp.Y += 4;
								}
								else
								{
									temp.Y += 5;
								}
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else if ((line < 7 && enemy_field[line + 3][column] == 0 && enemy_field[line - 1][column] == 0) || (enemy_field[9][column] == 1 && enemy_useful[9][column] == 3 && enemy_field[6][column] == 0))
						{
							if (line > 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
							if (line < 7)
							{
								if (line == 0)
								{
									temp.Y += 3;
								}
								else
								{
									temp.Y += 4;
								}
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
					}
					else if ((line < 7 && enemy_field[line + 2][column] == 0 && enemy_field[line - 1][column] == 0) || (enemy_field[9][column] == 1 && enemy_useful[9][column] == 3 && enemy_field[7][column] == 0))
					{
						if (line > 0)
						{
							--temp.Y;
							DrawV(CSBufInf, output_handle, temp, 17, 1);
						}
						if (line < 8)
						{
							if (line == 0)
							{
								temp.Y += 2;
							}
							else
							{
								temp.Y += 3;
							}
							DrawV(CSBufInf, output_handle, temp, 17, 1);
						}
					}
				}
				else
				{
					if (line == 0)
					{
						if (column == 0)
						{
							if (enemy_field[line][column + 1] == 0 && enemy_field[line + 1][column] == 0)
							{
								++temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								--temp.Y;
								temp.X += 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else if (column == 9)
						{
							if (enemy_field[line][column - 1] == 0 && enemy_field[line + 1][column] == 0)
							{
								++temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								--temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else
						{
							if (enemy_field[line][column + 1] == 0 && enemy_field[line + 1][column] == 0 && enemy_field[line][column - 1] == 0)
							{
								++temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								--temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								temp.X += 4;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
					}
					else if (line == 9)
					{
						if (column == 0)
						{
							if (enemy_field[line][column + 1] == 0 && enemy_field[line - 1][column] == 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X += 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else if (column == 9)
						{
							if (enemy_field[line][column - 1] == 0 && enemy_field[line - 1][column] == 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else
						{
							if (enemy_field[line][column + 1] == 0 && enemy_field[line - 1][column] == 0 && enemy_field[line][column - 1] == 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								temp.X += 4;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
					}
					else
					{
						if (column == 0)
						{
							if (enemy_field[line][column + 1] == 0 && enemy_field[line - 1][column] == 0 && enemy_field[line + 1][column] == 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X += 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else if (column == 9)
						{
							if (enemy_field[line][column - 1] == 0 && enemy_field[line - 1][column] == 0 && enemy_field[line + 1][column] == 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X += 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
						else
						{
							if (enemy_field[line][column + 1] == 0 && enemy_field[line - 1][column] == 0 && enemy_field[line][column - 1] == 0 && enemy_field[line + 1][column] == 0)
							{
								--temp.Y;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								temp.X += 4;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
								++temp.Y;
								temp.X -= 2;
								DrawV(CSBufInf, output_handle, temp, 17, 1);
							}
						}
					}
				}
			}
			enemy_field_position.X += 2;
		}
		enemy_field_position.X -= 20;
		++enemy_field_position.Y;
	}
}
