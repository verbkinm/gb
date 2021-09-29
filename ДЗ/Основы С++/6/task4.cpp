#include "task4.h"

namespace fs = std::experimental::filesystem;

void task4()
{
    std::cout << "Task #4:" << std::endl;

    std::ifstream inFile1, inFile2;
    std::ofstream outFile;
    std::string inFile1Name, inFile2Name, outFileName;

    std::cout << "Input first file name: ";
    std::cin >> inFile1Name;

    std::cout << "Input second file name: ";
    std::cin >> inFile2Name;

    std::cout << "Input result file name: ";
    std::cin >> outFileName;

    if(!fs::exists(fs::path(inFile1Name)) || !fs::exists(fs::path(inFile2Name)) )
    {
        std::cerr << "First or second file is not exists!" << std::endl;
        return;
    }
    if(fs::exists(fs::path(outFileName)))
    {
        std::cerr << "Result file is exists!" << std::endl;
        return;
    }

    inFile1.open(inFile1Name);
    inFile2.open(inFile2Name);
    outFile.open(outFileName);

    if(!inFile1.is_open() || !inFile2.is_open() || !outFile.is_open())
    {
        std::cerr << "One of the file can not open." << std::endl;
        return;
    }

    copyTextTo(inFile1, outFile);
    copyTextTo(inFile2, outFile);

    inFile1.close();
    inFile2.close();
    outFile.close();

    std::cout << "Done." << std::endl << std::endl;
}

void copyTextTo(std::ifstream &inFile, std::ofstream &outFile)
{
    while (!inFile.eof())
    {
        std::string line;
        std::getline(inFile, line);
        outFile << line << std::endl;
    }
}
