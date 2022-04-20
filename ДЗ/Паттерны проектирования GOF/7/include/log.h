#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>

#define LOG_FILE_NAME_DEFAULT "SBomber.log"

class Log
{
public:
    enum class Flags
    {
        WRITE_TO_FILE_ONLY,
        WRITE_TO_STDOUT_ONLY,
        WRITE_TO_STDERR_ONLY,
        WRITE_TO_FILE_AND_STDOUT,
        WRITE_TO_FILE_AND_STDERR
    };

    static void write(const std::string& data, Flags pathToWrite = Log::Flags::WRITE_TO_FILE_ONLY, const std::string &fileName = LOG_FILE_NAME_DEFAULT);

private:
    static void writeToFile(const std::string &fileName, const std::string &data);
    static void writeToStdOut(const std::string &data);
    static void writeToStdErr(const std::string &data);
};
