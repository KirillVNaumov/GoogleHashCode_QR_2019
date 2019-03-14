#include "include.hpp"

void        initialize_images(t_info *info)
{
    int     i;

    i = 0;
    info->input = (t_image **)malloc(sizeof(t_image *) * info->number_of_images + 1);
    while (i < info->number_of_images)
    {
        info->input[i] = (t_image *)malloc(sizeof(t_image));
        info->input[i]->index = i;
        ++i;
    }
    info->input[i] = NULL;
}