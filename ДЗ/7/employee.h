#pragma once

#include <string.h>
#include <fstream>
#include <iostream>

#pragma pack(push, 1)
struct employee
{
    char name[10];
    int phone;
    uint8_t id;

    void saveToFile(std::string fileName);
    void printData();
};
#pragma pack(pop)

