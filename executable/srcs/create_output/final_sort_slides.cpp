#include "executable.hpp"

int             find_common_tags(t_slide *first, t_slide *second)
{
    std::list<long long>   list_1 = arr_to_list(first->tags, first->number_of_tags);
    std::list<long long>   list_2 = arr_to_list(second->tags, second->number_of_tags);    
    std::list<long long>::const_iterator i1 = list_1.begin();
    std::list<long long>::const_iterator i2 = list_2.begin();
    int     score;

    score = 0;
    while(i1 != list_1.end() && i2 != list_2.end()){
        if(*i1 == *i2)
        {
            ++score;
            ++i1;
            ++i2;
        }
        else if (*i1 > 0)
            ++i2;
        else
            ++i1;
    }   
    return (score);
}

std::list<t_slide *>::iterator        find_best_slide(t_slide *slide, std::list<t_slide *> list)
{
    std::list<t_slide *>::iterator  best_slide;
    int                             best_score;
    int                             current_score;

    best_score = 0;
    for (std::list<t_slide *>::iterator it=list.begin(); it!=list.end(); ++it)
    {
        current_score = find_common_tags(slide, *it);
        if (current_score > best_score)
        {
            best_score = current_score;
            best_slide = it;
        }
    }
    if (best_score == 0)
        return (list.begin());
    return (best_slide);
}

void        final_sort_slides(t_info *info, std::list<t_slide *> list)
{
    int     index;
    std::list<t_slide *>::iterator it=list.begin();

    index = 0;
    info->output[index] = *it;
    std::cout << "1";
    list.remove(*it);
    std::cout << "2";
    while (!list.empty())
    {
        it = find_best_slide(info->output[index], list);
        ++index;
        info->output[index] = *it;
        list.remove(*it);
    }
    ++index;
    info->output[index] = NULL;
}