#include "executable.hpp"

void        read_number_of_images(t_info *info, std::string line) {

    if (check_for_number(line) == -1 || line.length() > 6)
        error("Invalid number of images");
    info->number_of_images = stoi(line);
    if (check_for_integer(info->number_of_images) == -1)
        error("Invalid number of images");
    initialize_images(info);
}