#include "executable.hpp"

void        initialize_images(t_info *info)
{
    int     i;

    i = 0;
    info->input = (t_image **)malloc(sizeof(t_image *) * info->number_of_images + 1);
    while (i < info->number_of_images)
    {
        info->input[i] = (t_image *)malloc(sizeof(t_image));
        info->input[i]->index = i;
        ++i;
    }
    info->input[i] = NULL;
}

std::list<t_image *>        image_to_list(t_image **arr)
{
    int     i;
    std::list<t_image *> list;

    i = 0;
    while (arr[i])
        list.push_back(arr[i++]);
    return (list);
}

t_image                     **list_to_images(std::list<t_image *> list)
{
    int     i;
    int     length;
    t_image     **arr;

    i = 0;

    length = 0;
    for (std::list<t_image *>::iterator it=list.begin(); it!=list.end(); ++it)
        ++length;
    arr = (t_image **)malloc(sizeof(t_image *) * (length + 1));
    for (std::list<t_image *>::iterator it=list.begin(); it!=list.end(); ++it)
        arr[i++] = *it;
    arr[i] = NULL;
    return (arr);
}

t_image     **sort_images(t_image **arr)
{
    std::list<t_image *>    list;

    list = image_to_list(arr);
    list.sort(number_of_tags_images);
    arr = list_to_images(list);
    return (arr);
}