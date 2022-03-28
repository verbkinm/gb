#pragma once

#include <string>

class ILogger
{
public:
    virtual  ~ILogger(){};

    virtual void __fastcall OpenLogFile(const std::string& FN) = 0;
    virtual void CloseLogFile() = 0;
    virtual void __fastcall WriteToLog(const std::string& str) = 0;
    virtual void __fastcall WriteToLog(const std::string& str, int n) = 0;
    virtual void __fastcall WriteToLog(const std::string& str, double d) = 0;
};
