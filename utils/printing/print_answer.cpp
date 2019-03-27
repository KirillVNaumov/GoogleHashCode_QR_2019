#include "utils.hpp"

void        print_answer(t_info *info)
{
    int     i;
    int     j;

    i = 0;
    std::cout << info->number_of_slides << std::endl;
    while (info->output[i])
    {
        std::cout << info->output[i]->index_1;
        if (info->output[i]->index_2 != -1)
            std::cout << " " << info->output[i]->index_2;
        std::cout << std::endl;
        ++i;
    }
}