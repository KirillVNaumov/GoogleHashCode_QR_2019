#include "utils.hpp"

void        print_output(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    std::cout << std::endl;
    while (info->output[i])
    {
        j = 0;
        std::cout << "Slide: " << info->output[i]->index_1;
        if (info->output[i]->index_2 != -1)
            std::cout << " " << info->output[i]->index_2;
        std::cout << std::endl;
        std::cout << "Number of Tags: " << info->output[i]->number_of_tags << std::endl;
        while (info->output[i]->tags[j])
            std::cout << " - " << info->output[i]->tags[j++] << std::endl;
        std::cout << std::endl;
        ++i;
    }
}