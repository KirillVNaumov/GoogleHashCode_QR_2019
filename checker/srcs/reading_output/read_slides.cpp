#include "checker.hpp"

int         read_slides(t_info *info, std::string line, int index) {

    char    *str = new char[line.length() + 1];

    strcpy(str, line.c_str());
    info->output[index]->index_1 = atoi(&str[0]);
    if (info->output[index]->index_1 < 0 || info->output[index]->index_1 >= info->number_of_images)
        error("The listed number for images is invalid");
    while (*str >= '0' && *str <= '9')
        ++str;
    if (*str != ' ' && *str != '\0')
        return (-1);
    info->output[index]->index_2 = -1;
    if (*str == '\0')
        return (1);
    ++str;
    info->output[index]->index_2 = atoi(&str[0]);
    if (info->output[index]->index_2 < 0 || info->output[index]->index_2 >= info->number_of_images)
        error("The listed number for images is invalid");
    while (*str >= '0' && *str <= '9')
        ++str;
    if (*str != '\0')
        return (-1);
    return (1);
}