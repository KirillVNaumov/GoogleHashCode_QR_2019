#include "checker.hpp"

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
