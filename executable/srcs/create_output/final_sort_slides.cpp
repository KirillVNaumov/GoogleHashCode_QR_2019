#include "executable.hpp"

int             find_common_tags(t_slide *first, t_slide *second)
{
    int     score;
    int     index_1;
    int     index_2;

    score = 0;
    index_1 = 0;
    index_2 = 0;
    while(index_1 < first->number_of_tags && index_2 < second->number_of_tags)
    {
        if(first->tags[index_1] == second->tags[index_2])
        {
            ++score;
            ++index_1;
            ++index_2;
        }
        else if (first->tags[index_1] > second->tags[index_2])
            ++index_2;
        else
            ++index_1;
    }   
    return (score);
}

int             optimization_formula(t_slide *first, t_slide *second, int score)
{
    t_slide     *minimum_slide;

    if (first->number_of_tags < second->number_of_tags)
        minimum_slide = first;
    else
        minimum_slide = second;
    if (minimum_slide->number_of_tags / 2 == score)
        return (1);
    return (0);
}

t_slide         *find_best_slide(t_slide *slide, std::list<t_slide *> list)
{
    std::list<t_slide *>::iterator  best_slide;
    int                             best_score;
    int                             current_score;

    best_score = 0;
    best_slide = list.begin();
    for (std::list<t_slide *>::iterator it=list.begin(); it!=list.end(); ++it)
    {
        current_score = find_common_tags(slide, *it);
        if (current_score > best_score)
        {
            best_score = current_score;
            best_slide = it;
            if (optimization_formula(slide, *it, best_score) == 1)
                return (*best_slide);
        }
    }
    return (*best_slide);
}

void        final_sort_slides(t_info *info, std::list<t_slide *> list)
{
    // std::list<t_slide *>    new_list;
    std::list<t_slide *>::iterator it=list.begin();    
    t_slide                 *to_save;

    std::cout << info->number_of_slides << std::endl;
    // new_list.push_back(*it);
    to_save = *it;
    list.remove(*it);

    std::cout << to_save->index_1;
    if (to_save->index_2 != -1)
        std::cout << " " << to_save->index_2;
    std::cout << std::endl;

    while (!list.empty())
    {
        to_save = find_best_slide(to_save, list);

        std::cout << to_save->index_1;
        if (to_save->index_2 != -1)
            std::cout << " " << to_save->index_2;
        std::cout << std::endl;

        // new_list.push_back(to_save);
        list.remove(to_save);
    }
    // info->output = list_to_slides(new_list);
}