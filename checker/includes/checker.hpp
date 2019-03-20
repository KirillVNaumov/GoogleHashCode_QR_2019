#ifndef CHECKER_HPP
# define CHECKER_HPP

#include "utils.hpp"

void        check_output_for_repetition(t_info *info);
void        check_verticals(t_info *info);

/*
    Reading_file
*/

void        reading_file (t_info *info, char *file);
void        read_number_of_images(t_info *info, std::string line);
int         read_images(t_info *info, std::string line, int index);

/*
    Reading_output
*/

void        reading_output (t_info *info);
int         read_slides(t_info *info, std::string line, int index);
void        read_number_of_slides(t_info *info, std::string line);

#endif