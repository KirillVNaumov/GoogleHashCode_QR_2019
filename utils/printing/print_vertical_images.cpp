#include "utils.hpp"

void        print_vertical_images(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    std::cout << std::endl;
    while (info->vertical_images[i])
    {
        j = 0;
        std::cout << "Image: " << info->vertical_images[i]->index << std::endl;
        std::cout << "Vertical" << std::endl;
        std::cout << "Number of Tags: " << info->vertical_images[i]->number_of_tags << std::endl;
        while (info->vertical_images[i]->tags[j])
            std::cout << " - " << info->vertical_images[i]->tags[j++] << std::endl;
        std::cout << std::endl;
        ++i;
    }
}