#include "utils.hpp"

void        print_vertical_slides(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    std::cout << std::endl;
    while (info->vertical_slides[i])
    {
        j = 0;
        std::cout << "Slide: " << info->vertical_slides[i]->index_1 << " " << info->vertical_slides[i]->index_2;
        std::cout << std::endl;
        std::cout << "Number of Tags: " << info->vertical_slides[i]->number_of_tags << std::endl;
        while (j < info->vertical_slides[i]->number_of_tags)
            std::cout << " - " << info->vertical_slides[i]->tags[j++] << std::endl;
        std::cout << std::endl;
        ++i;
    }
}