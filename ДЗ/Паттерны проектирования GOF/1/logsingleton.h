#pragma once

#include <string>
#include <cstring>
#include <fstream>
#include <chrono>

class LogSingleton
{
public:
    static LogSingleton& getInstance()
    {
        static LogSingleton theInstance;
        return theInstance;
    }
    void __fastcall OpenLogFile(const std::string& FN);
    void CloseLogFile();
    void __fastcall WriteToLog(const std::string& str);
    void __fastcall WriteToLog(const std::string& str, int n);
    void __fastcall WriteToLog(const std::string& str, double d);

private:
    LogSingleton() { }
    LogSingleton(const LogSingleton& root) = delete;
    LogSingleton& operator=(const LogSingleton&) = delete;

    std::string GetCurDateTime();

    std::ofstream logOut;
};
