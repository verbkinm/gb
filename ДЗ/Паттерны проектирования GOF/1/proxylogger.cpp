#include "proxylogger.h"

ProxyLogger::~ProxyLogger()
{
    std::cout << "Number of records: " << _counter << '\n';
}

void ProxyLogger::OpenLogFile(const std::string &FN)
{
    std::clog << "Open log file\n";
    LogSingleton::getInstance().OpenLogFile(FN);
}

void ProxyLogger::CloseLogFile()
{
    std::clog << "Close log file\n";
    LogSingleton::getInstance().CloseLogFile();
}

void ProxyLogger::WriteToLog(const std::string &str)
{
    _counter++;
    LogSingleton::getInstance().WriteToLog(str);
}

void ProxyLogger::WriteToLog(const std::string &str, int n)
{
    _counter++;
    LogSingleton::getInstance().WriteToLog(str, n);
}

void ProxyLogger::WriteToLog(const std::string &str, double d)
{
    _counter++;
    LogSingleton::getInstance().WriteToLog(str, d);
}
