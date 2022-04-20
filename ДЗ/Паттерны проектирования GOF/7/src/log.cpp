#include "include/log.h"

std::string dateStr()
{
    auto now = time(0);
    auto tm = localtime(&now);

    char s[20];
    sprintf(s, "%02d.%02d.%4d %02d:%02d:%02d",
                        tm->tm_mday, tm->tm_mon, 1900 + tm->tm_year,
                        tm->tm_hour, tm->tm_min, tm->tm_sec);

    return s;
}
void Log::write(const std::string& data, Flags pathToWrite, const std::string &fileName)
{
    if(pathToWrite == Flags::WRITE_TO_STDOUT_ONLY)
        writeToStdOut(data);
    else if(pathToWrite == Flags::WRITE_TO_STDERR_ONLY)
        writeToStdErr(data);
    else if(pathToWrite == Flags::WRITE_TO_FILE_ONLY)
        writeToFile(fileName, data);
    else if(pathToWrite == Flags::WRITE_TO_FILE_AND_STDOUT)
    {
        writeToStdOut(data);
        writeToFile(fileName, data);
    }
    else if(pathToWrite == Flags::WRITE_TO_FILE_AND_STDERR)
    {
        writeToStdErr(data);
        writeToFile(fileName, data);
    }
}

void Log::writeToFile(const std::string &fileName, const std::string &data)
{
    std::ofstream file(fileName, std::ios::app);
    if(!file.is_open())
    {
        std::cerr << "Error write to file " << fileName << '\n';
        return;
    }

    file << dateStr() << ": " << data <<'\n';
    file.close();
}

void Log::writeToStdOut(const std::string &data)
{
    std::cout << dateStr() << ": " << data <<'\n';
}

void Log::writeToStdErr(const std::string &data)
{
    std::cerr << dateStr() << ": " << data <<'\n';
}
