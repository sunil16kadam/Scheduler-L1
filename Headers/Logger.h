//***************************************************************************************
//Logger.h
//***************************************************************************************
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>

class Logger {
private:
    static std::mutex logMutex;
    std::ofstream logFile;  // Persistent log file stream
    static const std::string logFileName;
public:
    // Constructor: Opens the log file in append mode.
    // The log file remains open throughout execution.
    // It closes only once when the program exits.
    // Performance improves, as there's no unnecessary file opening/closing.
    // Destructor closes the file when the Logger object is destroyed
    explicit Logger(const std::string& filename);

    // Destructor: Closes the log file only when the program exits
    ~Logger();

    void log(const std::string& message);
    void displayExecutionLog();
};

#endif

