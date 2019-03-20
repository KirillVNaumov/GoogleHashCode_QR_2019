#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>
#include <fstream>

# define CRED       "\x1B[31m"

typedef struct      s_image
{
    int             index;
    int             position; //1 - vertical 0 - horizontal
    int             number_of_tags;
    char            **tags;
}                   t_image;

typedef struct      s_slide
{
    int             index_1;
    int             index_2;
    int             number_of_tags;
    char            **tags;
}                   t_slide;

typedef struct      s_info
{
    int             number_of_images;
    int             number_of_slides;
    t_image         **input;
    t_image         **horizontal_images;
    t_image         **vertical_images;
    t_slide         **output;
}                   t_info;

/*
    Utils_1
*/

int         check_for_number(std::string line);
int         check_for_integer(int n);
void        error(std::string reason);

/*
    Struct_operations
*/

void        initialize_images(t_info *info);
void        initialize_slides(t_info *info);

/*
    Printing
*/

void        print_horizontal(t_info *info);
void        print_vertical(t_info *info);
void        print_input(t_info *info);


#endif