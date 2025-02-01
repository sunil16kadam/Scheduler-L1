//***************************************************************************************
//TaskManager.h
//***************************************************************************************
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include "../Headers/Task.h"
#include <vector>
#include <mutex>
#include <algorithm>

class TaskManager {
private:
    std::vector<Task> taskQueue;
    mutable std::mutex mutexForTaskQueue;   // If mutexForTaskQueue is not declared mutable, 
                                            // it cannot be locked inside a const function.

public:
    void addTask(const Task& task);
    void removeTask(int taskId);
    void listTasks() const;
    std::vector<Task> getTasks();

};

#endif
