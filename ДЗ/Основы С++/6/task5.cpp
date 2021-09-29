#include "task5.h"

namespace fs = std::experimental::filesystem;

void task5()
{
    std::cout << "Task #5:" << std::endl;

    std::ifstream inFile;
    std::string findString, inFileName;

    std::cout << "Input file name: ";
    std::cin >> inFileName;

    if(!fs::exists(fs::path(inFileName)))
    {
        std::cerr << "File is not exists!" << std::endl;
        return;
    }

    inFile.open(inFileName);
    if(!inFile.is_open())
    {
        std::cerr << "File is can not open!" << std::endl;
        return;
    }

    std::cout << "Input string to find: ";
    std::cin >> findString;

    size_t strNumber = 1;
    while (!inFile.eof())
    {
        std::string line;
        std::getline(inFile, line);

        if(line.find(findString) != std::string::npos)
            std::cout << "Found in " << strNumber << " string." << std::endl;

        strNumber++;
    }
    std::cout << "Done." << std::endl << std::endl;
}
