#include "task3.h"

namespace fs = std::experimental::filesystem;

void task3()
{
    std::cout << "Task #3:" << std::endl;

    createFile();
    createFile();

    std::cout << "Done." << std::endl << std::endl;
}

void createFile()
{
    std::string fileName;

    std::cout << "Input file name: ";
    std::cin >> fileName;

    fs::path path(fileName);
    path += ".txt";

    if(fs::exists(path))
    {
        std::cerr << "File " << path << " is exists." << std::endl;
        return;
    }

    std::ofstream outFile(path.string());
    if(!outFile.is_open())
    {
        std::cerr << "Can not open " << path << " file." << std::endl;
        return;
    }

    fillFile(outFile);

    outFile.close();
}

void fillFile(std::ofstream &outFile)
{
    srand(time(0));

    for (int i = 0; i < 50; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            char c =  33 + rand() % 126;
            outFile.put(c);
        }
        outFile << std::endl;
    }
}
