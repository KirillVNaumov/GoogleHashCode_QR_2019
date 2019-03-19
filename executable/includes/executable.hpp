#ifndef EXECUTABLE_HPP
# define EXECUTABLE_HPP

#include <iostream>
#include <string>

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
    t_image         *image1;
    t_image         *image2;
    int             number_of_tags;
    char            **tags;
}                   t_slide;

typedef struct      s_info
{
    int             number_of_images;
    t_image         **input;
    t_image         **horizontal_images;
    t_image         **vertical_images;
    t_slide         **output;
}                   t_info;

/*
    Create_possible_slides
*/

void        create_possible_slides(t_info *info);

/*
    Printing
*/

void        print_horizontal(t_info *info);
void        print_vertical(t_info *info);
void        print_input(t_info *info);

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
    Struct_operations
*/

void        initialize_images(t_info *info);

/*
    Main
*/

void        error(std::string reason);

#endif