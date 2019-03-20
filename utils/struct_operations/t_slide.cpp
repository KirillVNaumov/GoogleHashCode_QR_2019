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