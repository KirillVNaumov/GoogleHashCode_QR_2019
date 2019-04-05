#include <utils.hpp>

int         get_score(std::string line)
{
    char    *str = new char[line.length() + 1];

    strcpy(str, line.c_str());
    return (atoi(&str[8]));
}

int         main()
{
    int          score;
    std::fstream infile;

    infile.open("inputs/total_score");
    if (infile == 0)
        error("Error with file");
    for (std::string line; std::getline(infile, line);) {

        score += get_score(line);
    }
    infile.close();
    std::cout << "Total score: " << score << std::endl;
}