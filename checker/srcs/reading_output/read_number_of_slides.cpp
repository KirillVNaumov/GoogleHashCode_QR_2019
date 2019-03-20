#include "checker.hpp"

void        read_number_of_slides(t_info *info, std::string line) {

    if (check_for_number(line) == -1 || line.length() > 6)
        error("Invalid number of slides");
    info->number_of_slides = stoi(line);
    if (check_for_integer(info->number_of_slides) == -1)
        error("Invalid number of slides");
    initialize_slides(info);
}