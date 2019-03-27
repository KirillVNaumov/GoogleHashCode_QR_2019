#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <cmath>
#include <algorithm>

# define CRED       "\x1B[31m"

typedef struct      s_image
{
    int             index;
    int             position; //1 - vertical 0 - horizontal
    int             number_of_tags;
    long long       *tags;
}                   t_image;

typedef struct      s_slide
{
    int             index_1;
    int             index_2;
    int             number_of_tags;
    long long       *tags;
}                   t_slide;

typedef struct      s_info
{
    int             number_of_images;
    int             number_of_vertical_images;
    int             number_of_horizontal_images;
    int             number_of_slides;
    int             number_of_horizontal_slides;
    int             number_of_vertical_slides;
    t_image         **input;
    t_image         **horizontal_images;
    t_image         **vertical_images;
    t_slide         **output;
    t_slide         **horizontal_slides;
    t_slide         **vertical_slides;
}                   t_info;

long long           from_string_to_num(char *str);

/*
    Utils_1
*/

int                     check_for_number(std::string line);
int                     check_for_integer(int n);
void                    error(std::string reason);
std::list<long long>    arr_to_list(long long *arr, int length);
long long               *list_to_arr(std::list<long long> list);

/*
    Utils_2
*/

t_slide             **sort_slides(t_slide **arr);
t_image             **sort_images(t_image **arr);

/*
    Utils_bool
*/

bool                compare_nocase (long long first, long long second);
bool                same_word (long long first, long long second);
bool                number_of_tags_images (t_image *first, t_image *second);
bool                number_of_tags_slides (t_slide *first, t_slide *second);

/*
    Struct_operations
*/

void                        initialize_images(t_info *info);
t_image                     **list_to_images(std::list<t_image *> list);
std::list<t_image *>        image_to_list(t_image **arr);
void                        initialize_slides(t_info *info);
t_slide                     **list_to_slides(std::list<t_slide *> list);
std::list<t_slide *>        slides_to_list(t_slide **arr);

/*
    Printing
*/

void                print_horizontal_images(t_info *info);
void                print_vertical_images(t_info *info);
void                print_horizontal_slides(t_info *info);
void                print_vertical_slides(t_info *info);
void                print_output(t_info *info);
void                print_input(t_info *info);
void                print_answer(t_info *info);

#endif