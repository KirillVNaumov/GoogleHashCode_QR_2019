#include "checker.hpp"

void        check_output_for_repetition(t_info *info)
{
    int     *arr;
    int     i;

    arr = (int *)malloc(sizeof(int) * info->number_of_images);
    i = 0;
    while (i < info->number_of_images)
        arr[i++] = 0;
    i = 0;
    while (info->output[i])
    {
        if (arr[info->output[i]->index_1] != 0)
            error("There was a repetition of images in your output");
        ++arr[info->output[i]->index_1];
        if (info->output[i]->index_2 != -1)
        {
            if (arr[info->output[i]->index_2] != 0)
                error("There was a repetition of images in your output");
            ++arr[info->output[i]->index_2];
        }
        ++i;
    }
}