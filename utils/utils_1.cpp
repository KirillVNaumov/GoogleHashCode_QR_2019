#include "utils.hpp"

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

void        error(std::string reason) {

    std::cout << CRED << "Error: " << reason << std::endl;
    exit(0);
}

std::list<char *>       arr_to_list(char **arr)
{
    int     i;
    std::list<char *> list;

    i = 0;
    while (arr[i])
        list.push_back(arr[i++]);
    return (list);
}

char       **list_to_arr(std::list<char *> list)
{
    int     i;
    int     length;
    char    **arr;

    i = 0;
    length = list.size();
    arr = (char **)malloc(sizeof(char *) * (length + 1));
    for (std::list<char *>::iterator it=list.begin(); it!=list.end(); ++it)
        arr[i++] = *it;
    arr[i] = NULL;
    return (arr);
}