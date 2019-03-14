#include "include.hpp"

int         check_for_number(std::string line) {

    int     i;

    i = 0;
    while (line[i])
    {
        if (line[i] < '0' || line[i] > '9')
            return (-1);
        ++i;
    }
    return (1);
}

int         check_for_integer(int n) {

    if (n > 100000 || n < 1)
        return (-1);
    return (1);
}

void        read_number_of_images(t_info *info, std::string line) {

    if (check_for_number(line) == -1 || line.length() > 6)
        error("Invalid number of images");
    info->number_of_images = stoi(line);
    if (check_for_integer(info->number_of_images) == -1)
        error("Invalid number of images");
    initialize_images(info);
}