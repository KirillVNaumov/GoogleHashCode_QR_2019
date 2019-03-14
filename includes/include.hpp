#ifndef INCLUDE_HPP
# define INCLUDE_HPP

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
    std::string     *tags;
}                   t_slide;

typedef struct      s_info
{
    int             number_of_images;
    t_image         **input;
    t_slide         **output;
}                   t_info;

/*
    Reading_input
*/

void        reading_input (t_info *info);
void        read_number_of_images(t_info *info, std::string line);
int         read_images(t_info *info, std::string line, int index);

/*
    Struct_operations
*/

void        initialize_images(t_info *info);

/*
    Main
*/

void        error(std::string reason);

#endif