#include "executable.hpp"

void        initialize_vertical_array(t_info *info, int length)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    info->vertical_images = (t_image **)malloc(sizeof(t_image *) * (length + 1));
    while (i < info->number_of_images)
    {
        if (info->input[i]->position == 1)
        {
            info->vertical_images[j] = (t_image *)malloc(sizeof(t_image));
            info->vertical_images[j]->index = i;
            info->vertical_images[j]->position = 1;
            info->vertical_images[j]->number_of_tags = info->input[i]->number_of_tags;
            info->vertical_images[j]->tags = info->input[i]->tags;
            ++j;
        }
        ++i;
    }
    info->vertical_images[j] = NULL;
    info->number_of_vertical_images = j;
}