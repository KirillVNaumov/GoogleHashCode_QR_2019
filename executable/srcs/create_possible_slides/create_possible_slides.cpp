#include "executable.hpp"

void        create_possible_slides(t_info *info)
{
    // sort_images(info->horizontal_images);
    create_horizontal_slides(info);
    // sort_images(info->vertical_images);
    create_vertical_slides(info);
}