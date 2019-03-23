#include "executable.hpp"

void        create_horizontal_slides(t_info *info)
{
    int     i;
    std::list<long long>   list;

    info->horizontal_slides = (t_slide **)malloc(sizeof(t_slide *) * (info->number_of_horizontal_images + 1));
    i = 0;
    info->number_of_horizontal_slides = info->number_of_horizontal_images;
    while (i < info->number_of_horizontal_images)
    {
        info->horizontal_slides[i] = (t_slide *)malloc(sizeof(t_slide));
        info->horizontal_slides[i]->index_1 = info->horizontal_images[i]->index;
        info->horizontal_slides[i]->index_2 = -1;
        list = arr_to_list(info->horizontal_images[i]->tags, info->horizontal_images[i]->number_of_tags);
        list.sort(compare_nocase);
        info->horizontal_slides[i]->number_of_tags = info->horizontal_images[i]->number_of_tags;
        info->horizontal_slides[i]->tags = list_to_arr(list);
        ++i;
    }
    info->horizontal_slides[i] = NULL;
}