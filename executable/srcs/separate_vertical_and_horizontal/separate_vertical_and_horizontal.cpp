#include "executable.hpp"

void        separate_vertical_and_horizontal(t_info *info)
{
    int     length;
    int     i;

    length = 0;
    i = 0;
    while (info->input[i])
    {
        if (info->input[i]->position == 1)
            ++length;
        ++i;
    }
    initialize_vertical_array(info, length);
    initialize_horizontal_array(info, info->number_of_images - length);
}  