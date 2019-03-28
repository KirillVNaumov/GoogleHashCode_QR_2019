#include "executable.hpp"

void        initialize_output(t_info *info)
{
    int     i;

    info->output = (t_slide **)malloc(sizeof(t_slide *) * (info->number_of_slides + 1));
    i = 0;
    while (i < info->number_of_slides)
        info->output[i++] = (t_slide *)malloc(sizeof(t_slide));
    info->output[i] = NULL;
}