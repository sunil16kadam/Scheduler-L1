//***************************************************************************************
//ExecutionEngine.cpp
//***************************************************************************************
#include "../Headers/ExecutionEngine.h"
#include "../Headers/Logger.h"
#include "../Headers/Scheduler.h"

void ExecutionEngine::executeTasks(std::vector<Task>& tasks, Scheduler& scheduler) {

    if (tasks.empty()) {
        std::cout << "No tasks to execute.\n";
        return;
    }

    std::string algo = scheduler.getAlgorithm();
    std::string logMessage = "\nExecuting tasks using Scheduling algorithm " + algo + "\n"; 
    logger.log(logMessage); 

    std::vector<std::thread> threads;  // Store threads for concurrent execution

    // Iterate through tasks and launch each in a separate thread
    for (auto& task : tasks) {
        threads.emplace_back(&Task::execute, &task);
    }

    // Ensure all threads complete execution before function returns
    for (auto& th : threads) {
        th.join();
    }
}
/*
How It Works:
threads.emplace_back(&Task::execute, &task); 
    - Creates a new std::thread object that starts executing Task::execute on the given task instance.
    - This new std::thread object is then added to the threads vector.
    - Each thread begins executing the Task::execute method as soon as it is created.Arguments:
    - &Task::execute: A pointer to the member function execute() of Task.
      &task: The object on which execute() is called.
    - Key Benefit: emplace_back() constructs the thread in place, avoiding unnecessary copying or temporary objects.
      It more efficient than push_back().
*/


