#include "executable.hpp"

void        create_vertical_slides(t_info *info)
{
    int     i;
    int     j;
    int     index;
    std::list<char *>   list;
    std::list<char *>   list1;

    info->number_of_vertical_slides = info->number_of_vertical_images * (info->number_of_vertical_images - 1) / 2;
    info->vertical_slides = (t_slide **)malloc(sizeof(t_slide *) * (info->number_of_vertical_images + 1));
    i = 0;
    index = 0;
    while (i < info->number_of_vertical_images)
    {
        j = i + 1;
        while (j < info->number_of_vertical_images)
        {
            info->vertical_slides[index] = (t_slide *)malloc(sizeof(t_slide));
            info->vertical_slides[index]->index_1 = info->vertical_images[i]->index;
            info->vertical_slides[index]->index_2 = info->vertical_images[j]->index;
            list = arr_to_list(info->vertical_images[i]->tags);
            list1 = arr_to_list(info->vertical_images[j]->tags);
            list.merge(list1);
            list.sort(compare_nocase);
            list.unique(same_word);
            info->vertical_slides[index]->number_of_tags = list.size();
            info->vertical_slides[index]->tags = list_to_arr(list);
            ++index;
            ++j;
        }
        ++i;
    }
    info->vertical_slides[index] = NULL;
}