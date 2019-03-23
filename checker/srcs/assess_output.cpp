#include "checker.hpp"

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

int             find_score_for_two_slides(t_slide *first, t_slide *second)
{
    int         common;
    int         only_first;
    int         only_second;

    common = find_common_tags(first, second);
    only_first = first->number_of_tags - common;
    only_second = second->number_of_tags - common;
    if (common <= only_first && common <= only_second)
        return (common);
    else if (only_first <= only_second)
        return (only_first);
    else
        return (only_second);
}

void            assess_output(t_info *info)
{
    int     i;
    int     score;

    i = 0;
    score = 0;
    while (info->output[i + 1])
    {
        score += find_score_for_two_slides(info->output[i], info->output[i + 1]);
        ++i;
    }
    std::cout << "Score : " << score << std::endl;
}
