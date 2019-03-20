#include "checker.hpp"

void        reading_output (t_info *info) {

    int index;

    index = 0;
    info->number_of_slides = 0;
    for (std::string line; std::getline(std::cin, line);) {

        if (line.compare("") == 0)
            break ;
        if (!info->number_of_slides)
            read_number_of_slides(info, line);
        else
            if (index < info->number_of_slides)
            {
                if (read_slides(info, line, index++) == -1)
                    error("Wrong input");
            }
            else
                error("The listed number of slides doesn't match the actual");
    }
    if (!info->number_of_slides || index != info->number_of_slides)
        error("The listed number of slides doesn't match the actual");
}