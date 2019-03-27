#include "executable.hpp"

void        initialize_slides(t_info *info)
{
    int     i;

    i = 0;
    info->output = (t_slide **)malloc(sizeof(t_slide *) * info->number_of_slides + 1);
    while (i < info->number_of_slides)
    {
        info->output[i] = (t_slide *)malloc(sizeof(t_slide));
        info->output[i]->tags = NULL;
        ++i;
    }
    info->output[i] = NULL;
}

std::list<t_slide *>        slides_to_list(t_slide **arr)
{
    int     i;
    std::list<t_slide *> list;

    i = 0;
    while (arr[i])
        list.push_back(arr[i++]);
    return (list);
}

t_slide                     **list_to_slides(std::list<t_slide *> list)
{
    int     i;
    int     length;
    t_slide     **arr;

    i = 0;

    length = 0;
    for (std::list<t_slide *>::iterator it=list.begin(); it!=list.end(); ++it)
        ++length;
    arr = (t_slide **)malloc(sizeof(t_slide *) * (length + 1));
    for (std::list<t_slide *>::iterator it=list.begin(); it!=list.end(); ++it)
        arr[i++] = *it;
    arr[i] = NULL;
    return (arr);
}

t_slide     **sort_slides(t_slide **arr)
{
    std::list<t_slide *>    list;

    list = slides_to_list(arr);
    list.sort(number_of_tags_slides);
    arr = list_to_slides(list);
    return (arr);
}