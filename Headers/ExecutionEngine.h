//***************************************************************************************
//ExecutionEngine.h
//***************************************************************************************
#ifndef EXECUTIONENGINE_H
#define EXECUTIONENGINE_H

#include "Task.h"
#include "Scheduler.h"
#include "Logger.h"
#include <vector>
#include <thread>

class ExecutionEngine {
    Logger& logger;
public:
    ExecutionEngine(Logger& logger) : logger(logger) {};

    void executeTasks(std::vector<Task>& tasks, Scheduler& scheduler);
};

#endif

