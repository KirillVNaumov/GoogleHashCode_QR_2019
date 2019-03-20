#include "checker.hpp"

void        check_verticals(t_info *info)
{
    int     i;

    i = 0;
    while (info->output[i])
    {
        if (info->input[info->output[i]->index_1]->position == 1)
        {
            if (info->output[i]->index_2 == -1)
                error("One of the slides contains only one vertical image");
            if (info->input[info->output[i]->index_2]->position != 1)
                error("One of the slides contains horizontal image with another image together");
        }
        else
        {
            if (info->output[i]->index_2 != -1)
                error("One of the slides contains horizontal image with another image together");
        }
        ++i;
    }
}