#include "checker.hpp"

int         main(int argc, char **argv)
{
    t_info  *info;

    info = (t_info *)malloc(sizeof(t_info));
    if (argc != 2)
    {
        std::cout << "Usage: ./check [file]" << std::endl;
        return (0);
    }
    reading_file(info, argv[1]);
    reading_output(info);
    check_output_for_repetition(info);
    check_verticals(info);
    determine_tags(info);
    assess_output(info);
    return (0);
}