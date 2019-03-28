#include "executable.hpp"

std::list<t_slide *>        create_semisorted_output(t_info *info)
{
    std::list<t_slide *> list;
    std::list<t_slide *> list1;
    
    list = slides_to_list(info->horizontal_slides);
    // list1 = slides_to_list(info->vertical_slides);
    // list.merge(list1);
    list.sort(number_of_tags_slides);
    return (list);
}

void        create_output(t_info *info)
{
    std::list<t_slide *> list;

    list = create_semisorted_output(info);
    info->number_of_slides = list.size();
    initialize_output(info);
    final_sort_slides(info, list);
}