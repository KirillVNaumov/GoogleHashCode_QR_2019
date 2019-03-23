#include "utils.hpp"

long long       from_string_to_num(char *str)
{
    long long   num;
    long long   base;
    int         digit;
    int         i;

    base = 1;
    i = 0;
    num = 0;
    while (str[i])
        ++i;
    --i;
    while (i > -1)
    {
        if (str[i] >= '0' && str[i] <= '9')
            digit = str[i] - '0';
        else
            digit = str[i] - 'a' + 10;
        num = num + digit * base;
        --i;
        base = base * 36;
    }
    return (num);
}