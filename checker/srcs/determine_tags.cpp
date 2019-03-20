#include "checker.hpp"

void            determine_tags(t_info *info)
{
    int     i;
    std::list<char *> list, list1;

    i = 0;
    while (info->output[i])
    {
        if (info->input[info->output[i]->index_1]->position == 0)
        {
            info->output[i]->number_of_tags = info->input[info->output[i]->index_1]->number_of_tags;
            info->output[i]->tags = info->input[info->output[i]->index_1]->tags;
        }
        else
        {
            list = arr_to_list(info->input[info->output[i]->index_1]->tags);
            list1 = arr_to_list(info->input[info->output[i]->index_2]->tags);
            list.merge(list1);
            list.sort(compare_nocase);
            list.unique(same_word);
            info->output[i]->number_of_tags = list.size();
            info->output[i]->tags = list_to_arr(list);
        }
        ++i;
    }
}