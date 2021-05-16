#include "CheckIfCorrect.h"

bool CheckIfCorrect(int sh_pos_v, int sh_pos_g, int your_useful[10][10])
{
    if (your_useful[sh_pos_v][sh_pos_g] == 2)
        return false;
    if (sh_pos_v == 0)
    {
        if (sh_pos_g == 0)
        {
            for (sh_pos_v; sh_pos_v < 2; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 2; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 2;
            }
        }
        else if (sh_pos_g == 9)
        {
            --sh_pos_g;
            for (sh_pos_v; sh_pos_v < 2; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 2; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 2;
            }
        }
        else
        {
            --sh_pos_g;
            for (sh_pos_v; sh_pos_v < 2; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 3; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 3;
            }
        }
    }
    else if (sh_pos_v == 9)
    {
        if (sh_pos_g == 0)
        {
            --sh_pos_v;
            for (sh_pos_v; sh_pos_v < 2; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 2; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 2;
            }
        }
        else if (sh_pos_g == 9)
        {
            --sh_pos_v;
            --sh_pos_g;
            for (sh_pos_v; sh_pos_v < 2; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 2; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 2;
            }
        }
        else
        {
            --sh_pos_v;
            --sh_pos_g;
            for (sh_pos_v; sh_pos_v < 2; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 3; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 3;
            }
        }
    }
    else
    {
        if (sh_pos_g == 0)
        {
            --sh_pos_v;
            for (sh_pos_v; sh_pos_v < 3; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 2; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 2;
            }
        }
        else if (sh_pos_g == 9)
        {
            --sh_pos_v;
            --sh_pos_g;
            for (sh_pos_v; sh_pos_v < 3; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 2; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 2;
            }
        }
        else
        {
            --sh_pos_v;
            --sh_pos_g;
            for (sh_pos_v; sh_pos_v < 3; ++sh_pos_v)
            {
                for (sh_pos_g; sh_pos_g < 3; ++sh_pos_g)
                {
                    if (your_useful[sh_pos_v][sh_pos_g] == 3)
                        return false;
                }
                sh_pos_g -= 3;
            }
        }
    }
    return true;;
}
