#include "utils.hpp"

void        print_horizontal(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    std::cout << std::endl;
    while (info->input[i])
    {
        if (info->input[i]->position == 0)
        {
            j = 0;
            std::cout << "Image: " << info->input[i]->index << std::endl;
            std::cout << "Horizontal" << std::endl;
            std::cout << "Number of Tags: " << info->input[i]->number_of_tags << std::endl;
            while (info->input[i]->tags[j])
                std::cout << " - " << info->input[i]->tags[j++] << std::endl;
            std::cout << std::endl;
        }
        ++i;
    }
}