#include "executable.hpp"

void        initialize_horizontal_array(t_info *info, int length)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    info->horizontal_images = (t_image **)malloc(sizeof(t_image *) * (length + 1));
    while (i < info->number_of_images)
    {
        if (info->input[i]->position == 0)
        {
            info->horizontal_images[j] = (t_image *)malloc(sizeof(t_image));
            info->horizontal_images[j]->index = i;
            info->horizontal_images[j]->position = 0;
            info->horizontal_images[j]->number_of_tags = info->input[i]->number_of_tags;
            info->horizontal_images[j]->tags = info->input[i]->tags;
            ++j;
        }
        ++i;
    }
    info->horizontal_images[j] = NULL;
    info->number_of_horizontal_images = j;
}