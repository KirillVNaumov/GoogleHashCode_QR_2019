#include "executable.hpp"

void        initialize_slides(t_info *info)
{
    int     i;

    i = 0;
    info->output = (t_slide **)malloc(sizeof(t_slide *) * info->number_of_slides + 1);
    while (i < info->number_of_slides)
    {
        info->output[i] = (t_slide *)malloc(sizeof(t_slide));
        info->output[i]->tags = NULL;
        ++i;
    }
    info->output[i] = NULL;
}

t_slide     **sort_slides(t_slide **arr)
{
    int     i;
    int     if_sorted;
    t_slide *tmp;

    if_sorted = 0;
    while (!if_sorted)
    {
        i = 0;
        if_sorted = 1;
        while (arr[i + 1])
        {
            if (arr[i]->number_of_tags < arr[i + 1]->number_of_tags)
            {
                if_sorted = 0;
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
            }
            ++i;
        }
    }
    return (arr);
}