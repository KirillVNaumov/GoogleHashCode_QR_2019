#include "utils.hpp"

void        print_horizontal_images(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    while (info->horizontal_images[i])
    {
        j = 0;
        std::cout << "Image: " << info->horizontal_images[i]->index << std::endl;
        std::cout << "Horizontal" << std::endl;
        std::cout << "Number of Tags: " << info->horizontal_images[i]->number_of_tags << std::endl;
        while (j < info->number_of_horizontal_images)
            std::cout << " - " << info->horizontal_images[i]->tags[j++] << std::endl;
        std::cout << std::endl;
        ++i;
    }
}