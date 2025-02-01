//***************************************************************************************
//Scheduler.h
//***************************************************************************************
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Task.h"
#include <vector>
#include <string>

class Scheduler {
private:
    std::string algorithm;

public:
    void setAlgorithm(const std::string& algo);
    std::vector<Task> scheduleTasks(std::vector<Task>& tasks);
};

#endif

