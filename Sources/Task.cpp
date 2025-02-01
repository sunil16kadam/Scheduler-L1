//***************************************************************************************
//Task.cpp
//***************************************************************************************
#include "../Headers/Task.h"

Task::Task(int id, std::string name, int execTime, int priority, bool isRepeating)
    : id(id), name(name), executionTime(execTime), priority(priority), isRepeating(isRepeating) {}

void Task::execute() const {
    std::cout << "Executing Task: " << name << " (ID: " << id << ")\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(executionTime));
    std::cout << "Task " << name << " completed.\n";
}

int Task::getId() const { return id; }
int Task::getExecutionTime() const { return executionTime; }
int Task::getPriority() const { return priority; }
std::string Task::getName() const { return name; }

