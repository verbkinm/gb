#pragma once

#include <iostream>

#include "ilogger.h"
#include "logsingleton.h"

class ProxyLogger : public ILogger
{
private:
    int _counter;

public:
    ~ProxyLogger();

    // ILogger interface
    void OpenLogFile(const std::string &FN) override;
    void CloseLogFile() override;
    void WriteToLog(const std::string &str) override;
    void WriteToLog(const std::string &str, int n) override;
    void WriteToLog(const std::string &str, double d) override;
};

