#ifndef EXECUTABLE_HPP
# define EXECUTABLE_HPP

#include "utils.hpp"

/*
    Create_possible_slides
*/

void        create_possible_slides(t_info *info);

/*
    Reading_input
*/

void        reading_input (t_info *info);
void        read_number_of_images(t_info *info, std::string line);
int         read_images(t_info *info, std::string line, int index);

/*
    Separate_vertical
*/

void        separate_vertical(t_info *info);

/*
    Main
*/

void        error(std::string reason);

#endif