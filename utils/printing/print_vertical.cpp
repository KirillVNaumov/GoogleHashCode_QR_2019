#include "executable.hpp"

void        print_vertical(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    std::cout << std::endl;
    while (info->input[i])
    {
        if (info->input[i]->position == 1)
        {
            j = 0;
            std::cout << "Image: " << info->input[i]->index << std::endl;
            std::cout << "Vertical" << std::endl;
            std::cout << "Number of Tags: " << info->input[i]->number_of_tags << std::endl;
            while (info->input[i]->tags[j])
                std::cout << " - " << info->input[i]->tags[j++] << std::endl;
            std::cout << std::endl;
        }
        ++i;
    }
}