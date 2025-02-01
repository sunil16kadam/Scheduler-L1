//***************************************************************************************
//Logger.h
//***************************************************************************************
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>

class Logger {
private:
    static std::mutex logMutex;
    static const std::string logFileName;
public:
    static void log(const std::string& message);
    void displayExecutionLog();
};

#endif

