#include "include.hpp"

void        reading_input (t_info *info) {

    int index;

    index = 0;
    for (std::string line; std::getline(std::cin, line);) {

        if (!info->number_of_images)
            read_number_of_images(info, line);
        else
            if (index < info->number_of_images)
            {
                if (read_images(info, line, index++) == -1)
                    error("Wrong input");
            }
            else
                error("The listed number of images doesn't match the actual");
    }
    if (index != info->number_of_images)
        error("The listed number of images doesn't match the actual");
}