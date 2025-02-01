//***************************************************************************************
//Logger.cpp
//***************************************************************************************

#include "../Headers/Logger.h"
#include <fstream>
//#include <vector>
#include <string>
#include <iostream>
#include <mutex>

std::mutex Logger::logMutex;    // This allocates memory for logMutex and 
                                // ensures there is only one mutex shared across all instances of Logger.
const std::string Logger::logFileName = "executionLog.txt";

void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);
    std::ofstream logFile(logFileName, std::ios::app);     // , std::ios::app
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}

void Logger::displayExecutionLog() {
    std::lock_guard<std::mutex> lock(logMutex);
    std::ifstream logFile(Logger::logFileName);
    if (logFile.is_open()) {
        std::string line;
        std::cout << "\nTask Execution Log:\n";
        while (std::getline(logFile, line)) {
            std::cout << line << std::endl;
        }
    } else {
        std::cout << "No execution log found.\n";
    }
}