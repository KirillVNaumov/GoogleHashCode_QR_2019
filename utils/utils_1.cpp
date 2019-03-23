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

std::list<long long>       arr_to_list(long long *arr, int length)
{
    int     i;
    std::list<long long> list;

    i = 0;
    while (i < length)
        list.push_back(arr[i++]);
    return (list);
}

long long                   *list_to_arr(std::list<long long> list)
{
    int     i;
    int     length;
    long long *arr;

    i = 0;
    length = list.size();
    arr = (long long *)malloc(sizeof(long long) * length);
    for (std::list<long long>::iterator it=list.begin(); it!=list.end(); ++it)
        arr[i++] = *it;
    return (arr);
}