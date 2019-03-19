#include "executable.hpp"

void        error(std::string reason) {

    std::cout << CRED << "Error: " << reason << std::endl;
    exit(0);
}

int         main()
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    reading_input(info);
    separate_vertical(info);
    create_possible_slides(info);
    print_vertical(info);
    print_horizontal(info);
    return (0);
}