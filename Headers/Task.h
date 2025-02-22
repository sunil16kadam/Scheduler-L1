//***************************************************************************************
//Task.h
//***************************************************************************************
#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "Logger.h"

class Task {
private:
    int id;
    std::string name;
    int executionTime;  // In milliseconds
    int priority;       // Higher number = Higher priority
    bool isRepeating;
    Logger* pLogger;

public:
    Task(int id, std::string name, int execTime, int priority, bool isRepeating, Logger* pLogger);
    void execute() const;
    int getId() const;
    int getExecutionTime() const;
    int getPriority() const;
    std::string getName() const;

    // Define operator== to compare tasks based on ID
    // bool operator==(const Task& other) const {
    //     return this->id == other.id;
    // }

};

#endif
