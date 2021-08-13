#include "employee.h"

void employee::saveToFile(std::string fileName)
{
    std::ofstream outFile(fileName);

    if(outFile.is_open())
    {
        outFile << (int)id << std::endl
                << name << std::endl
                << phone << std::endl
                << std::endl;

        outFile.close();
    }
}

void employee::printData()
{
    std::cout << "ID: " << (int)id << std::endl
              << "Name: " << name << std::endl
              << "Phone: " << phone << std::endl
              << std::endl;

}
