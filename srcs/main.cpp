#include "include.hpp"

void        error(std::string reason) {

    std::cout << CRED << "Error: " << reason << std::endl;
    exit(0);
}

void        print_info(t_info *info) {

    int     i;
    int     j;

    i = 0;
    std::cout << std::endl;
    while (info->input[i])
    {
        j = 0;
        std::cout << "Image: " << info->input[i]->index << std::endl;
        std::cout << "Number of Tags: " << info->input[i]->number_of_tags << std::endl;
        while (info->input[i]->tags[j])
            std::cout << " - " << info->input[i]->tags[j++] << std::endl;
        std::cout << std::endl;
        ++i;
    }
}

int         main()
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    reading_input(info);
    print_info(info);
    return (0);
}