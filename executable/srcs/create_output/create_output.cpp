#include "executable.hpp"

void        initialize_output(t_info *info)
{
    std::list<t_slide *> list;
    std::list<t_slide *> list1;
    
    list = slides_to_list(info->horizontal_slides);
    list1 = slides_to_list(info->vertical_slides);
    list.merge(list1);
    list.sort(number_of_tags_slides);
    info->number_of_slides = list.size();
    info->output = list_to_slides(list);
}

void        create_output(t_info *info)
{
    initialize_output(info);
}