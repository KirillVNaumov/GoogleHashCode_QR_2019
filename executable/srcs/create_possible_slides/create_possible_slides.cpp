#include "executable.hpp"

void        create_possible_slides(t_info *info)
{
    create_horizontal_slides(info);
    info->horizontal_slides = sort_slides(info->horizontal_slides);
    create_vertical_slides(info);
    info->vertical_slides = sort_slides(info->vertical_slides);
}