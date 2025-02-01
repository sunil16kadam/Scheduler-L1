//***************************************************************************************
//Scheduler.cpp
//***************************************************************************************
#include "../Headers/Scheduler.h"
#include <algorithm>

void Scheduler::setAlgorithm(const std::string& algo) {
    algorithm = algo;
}

std::vector<Task> Scheduler::scheduleTasks(std::vector<Task>& tasks) {
    if (algorithm == "SJF") {
        std::sort(tasks.begin(), tasks.end(),
                  [](const Task& a, const Task& b) { return a.getExecutionTime() < b.getExecutionTime(); });
    } else if (algorithm == "Priority") {
        std::sort(tasks.begin(), tasks.end(),
                  [](const Task& a, const Task& b) { return a.getPriority() > b.getPriority(); });
    }
    return tasks;
}
