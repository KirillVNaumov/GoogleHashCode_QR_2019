#include "utils.hpp"

void        print_horizontal_slides(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    std::cout << std::endl;
    while (info->horizontal_slides[i])
    {
        j = 0;
        std::cout << "Slide: " << info->horizontal_slides[i]->index_1;
        std::cout << std::endl;
        std::cout << "Number of Tags: " << info->horizontal_slides[i]->number_of_tags << std::endl;
        while (j < info->number_of_horizontal_slides)
            std::cout << " - " << info->horizontal_slides[i]->tags[j++] << std::endl;
        std::cout << std::endl;
        ++i;
    }
}