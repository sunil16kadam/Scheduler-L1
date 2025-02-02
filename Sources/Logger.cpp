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

// Constructor: Open the file only once
Logger::Logger(const std::string& filename) {
    // logFile.open(filename, std::ios::app);
    // if (!logFile.is_open()) {
    //     std::cerr << "Error: Could not open log file!" << std::endl;
    // }

    logFile.open(filename, std::ios::trunc); // Open file in truncate mode
    if (logFile.is_open()) {
        logFile.close();
        std::cout << "File's past content is cleared." << std::endl;
    } else {
        std::cerr << "Failed to open the file." << std::endl;
    }

    // Now you can reopen the file in append mode if needed
    logFile.open(filename, std::ios::app); // Open file in append mode
    if (!logFile.is_open()) {
        std::cerr << "Error: Could not open log file!" << std::endl;
    }

    
}

// Logs the message while keeping the file open
void Logger::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(logMutex);  // Ensure thread-safety
    if (logFile.is_open()) {
        logFile << message << std::endl;
    }
}

// Constructor: Opens the log file in append mode.
// The log file remains open throughout execution.
// It closes only once when the program exits.
// Performance improves, as there's no unnecessary file opening/closing.
// Destructor: Closes the file when the Logger object is destroyed
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// The std::ofstream logFile is a local variable inside the function.
// When the function execution ends, the logFile goes out of scope.
// This automatically calls the destructor of std::ofstream, which closes the file.
// void Logger::log(const std::string& message) {
//     std::lock_guard<std::mutex> lock(logMutex);
//     std::ofstream logFile(logFileName, std::ios::app);     // , std::ios::app
//     if (logFile.is_open()) {
//         logFile << message << std::endl;
//     }
// }

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