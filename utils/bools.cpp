#include "utils.hpp"

bool compare_nocase (long long first, long long second)
{
  return (first < second ? true : false);
}

bool same_word (long long first, long long second)
{
    return (first == second ? true : false);
}

bool number_of_tags_images (t_image *first, t_image *second)
{
  return (first->number_of_tags > second->number_of_tags ? true : false);
}

bool number_of_tags_slides (t_slide *first, t_slide *second)
{
  return (first->number_of_tags > second->number_of_tags ? true : false);
}