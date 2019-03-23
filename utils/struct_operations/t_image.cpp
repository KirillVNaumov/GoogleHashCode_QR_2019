#include "executable.hpp"

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

t_image     **sort_images(t_image **arr)
{
    int     i;
    int     if_sorted;
    t_image  *tmp;

    if_sorted = 0;
    while (!if_sorted)
    {
        i = 0;
        if_sorted = 1;
        while (arr[i + 1])
        {
            if (arr[i]->number_of_tags < arr[i + 1]->number_of_tags)
            {
                std::cout << arr[i]->index << "[" << arr[i]->number_of_tags << \
                "] and " << arr[i + 1]->index << "[" << arr[i + 1]->number_of_tags << "]" << std::endl;
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