#ifndef EXECUTABLE_HPP
# define EXECUTABLE_HPP

#include "utils.hpp"

/*
    Create_output
*/

void        create_output(t_info *info);

/*
    Create_possible_slides
*/

void        create_possible_slides(t_info *info);
void        create_vertical_slides(t_info *info);
void        create_horizontal_slides(t_info *info);
/*
    Reading_input
*/

void        reading_input (t_info *info);
void        read_number_of_images(t_info *info, std::string line);
int         read_images(t_info *info, std::string line, int index);

/*
    Separate_vertical
*/

void        separate_vertical_and_horizontal(t_info *info);
void        initialize_vertical_array(t_info *info, int length);
void        initialize_horizontal_array(t_info *info, int length);

/*
    Main
*/

void        error(std::string reason);

#endif