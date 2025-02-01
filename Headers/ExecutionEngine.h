//***************************************************************************************
//ExecutionEngine.h
//***************************************************************************************
#ifndef EXECUTIONENGINE_H
#define EXECUTIONENGINE_H

#include "Task.h"
#include <vector>
#include <thread>

class ExecutionEngine {
public:
    void executeTasks(std::vector<Task>& tasks);
};

#endif

