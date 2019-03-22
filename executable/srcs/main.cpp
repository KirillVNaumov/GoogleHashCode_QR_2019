#include "executable.hpp"

int         main()
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    reading_input(info);
    std::cout << "done!" << std::endl;
    separate_vertical_and_horizontal(info);
    std::cout << "done!" << std::endl;
    create_possible_slides(info);
    std::cout << "done!" << std::endl;
    return (0);
}