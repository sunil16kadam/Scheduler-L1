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
    std::cout << "Executing tasks using " << algo << "\n";

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
threads.emplace_back(&Task::execute, &task); creates a new thread and adds it directly to the threads vector.
Arguments:
&Task::execute: A pointer to the member function execute() of Task.
&task: The object on which execute() is called.
emplace_back() constructs the thread in place, avoiding unnecessary copying or temporary objects.
Key Benefit: emplace_back() directly constructs threads inside the vector, making it more efficient than push_back().
*/


