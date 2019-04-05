#include <utils.hpp>

void                print_list_slides(std::list<t_slide *> list)
{
    int     j;

    j= 0;
    for (std::list<t_slide *>::iterator it=list.begin(); it!=list.end(); ++it)
    {
        std::cout << "Slide: " << (*it)->index_1;
        if ((*it)->index_2 != -1)
            std::cout << " " << (*it)->index_2;
        std::cout << std::endl;
        std::cout << "Number of Tags: " << (*it)->number_of_tags << std::endl;
        j = 0;
        while (j < (*it)->number_of_tags)
            std::cout << " - " << (*it)->tags[j++] << std::endl;
        std::cout << std::endl;
    }
}