#include "executable.hpp"

void        initialize_specific_array(t_info *info, t_image **array, int length, int if_vertical)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    array = (t_image **)malloc(sizeof(t_image *) * length + 1);
    while (i < length)
    {
        if (info->input[i]->position == if_vertical)
        {
            array[j] = (t_image *)malloc(sizeof(t_image));
            array[j]->index = i;
            array[j]->position = if_vertical;
            array[j]->number_of_tags = info->input[i]->number_of_tags;
            array[j]->tags = info->input[i]->tags;
            ++j;
        }
        ++i;
    }
    array[j] = NULL;
}

void        separate_vertical(t_info *info)
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
    initialize_specific_array(info, info->vertical_images, length, 1);
    initialize_specific_array(info, info->horizontal_images, info->number_of_images - length, 0);
}  