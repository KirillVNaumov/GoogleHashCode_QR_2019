#include "include.hpp"

void        recording_tags(t_info *info, int index, char *str) {

    char    *tmp;
    int     i;
    int     j;

    info->input[index]->tags = (char **)malloc(sizeof(char *) * (info->input[index]->number_of_tags + 1));
    i = 0;
    while (i < info->input[index]->number_of_tags)
    {
        j = 0;
        while (str[j] != ' ' && str[j] != '\0')
            ++j;
        info->input[index]->tags[i] = (char *)malloc(sizeof(char) * (j + 1));
        j = 0;
        while (*str != ' ' && *str != '\0')
        {
            info->input[index]->tags[i][j++] = *str;
            ++str;
        }
        ++str;
        info->input[index]->tags[i++] += '\0';
    }
    info->input[index]->tags[i] = NULL;
}

int         read_images(t_info *info, std::string line, int index) {

    char    *str = new char[line.length() + 1];

    strcpy(str, line.c_str());
    if (*str == 'H')
        info->input[index]->position = 0;
    else if (*str == 'V')
        info->input[index]->position = 1;
    else
        return (-1);
    ++str;
    if (*str != ' ')
        return (-1);
    ++str;
    info->input[index]->number_of_tags = atoi(&str[0]);
    if (info->input[index]->number_of_tags < 0 || info->input[index]->number_of_tags > 100000)
        return (-1);
    while (*str >= '0' && *str <= '9')
        ++str;
    if (*str != ' ')
        return (-1);
    ++str;
    recording_tags(info, index, str);
    return (1);
}