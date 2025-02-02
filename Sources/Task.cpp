//***************************************************************************************
//Task.cpp
//***************************************************************************************
#include "../Headers/Task.h"
#include "../Headers/Logger.h"

Task::Task(int id, std::string name, int execTime, int priority, bool isRepeating, Logger* pLogger)
    : id(id), name(name), executionTime(execTime), priority(priority), isRepeating(isRepeating), pLogger(pLogger) {}

void Task::execute() const {

    std::ostringstream oss;
    oss << "Executing " << name << " (ID: " << std::to_string(id)  << " Exec duration: " << 
    std::to_string(executionTime) << ", Priority: " << std::to_string(priority) << std::endl;
    std::string logMessage = oss.str();
    oss.str("");  // Clear the string content
    oss.clear();  // Reset error state if any
    pLogger->log(logMessage);  // spk

    std::this_thread::sleep_for(std::chrono::milliseconds(executionTime));

    oss << "Task " << name << " completed." << std::endl;
    logMessage = oss.str();
    oss.str("");  // Clear the string content
    oss.clear();  // Reset error state if any
    pLogger->log(logMessage);  // spk
}

int Task::getId() const { return id; }
int Task::getExecutionTime() const { return executionTime; }
int Task::getPriority() const { return priority; }
std::string Task::getName() const { return name; }

