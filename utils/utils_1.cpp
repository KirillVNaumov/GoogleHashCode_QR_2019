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