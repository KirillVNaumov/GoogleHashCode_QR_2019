#include "executable.hpp"

void        reading_file (t_info *info, char *file) {

    int index;
    std::fstream infile;

    infile.open(file);
    index = 0;
    for (std::string line; std::getline(infile, line);) {

        if (line.compare("") == 0)
            break ;
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
    if (!info->number_of_images || index != info->number_of_images)
        error("The listed number of images doesn't match the actual");
    infile.close();
}