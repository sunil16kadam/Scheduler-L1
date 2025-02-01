//***************************************************************************************
//TaskManager.cpp
//***************************************************************************************
#include "../Headers/TaskManager.h"
#include <iostream>

void TaskManager::addTask(const Task& task) {
    std::unique_lock<std::mutex> lock(mutexForTaskQueue);
    if (taskQueue.size() >= 10) {
        std::cerr << "Task limit reached! Cannot add more tasks.\n";
        return;
    }
    taskQueue.push_back(task);
}

void TaskManager::removeTask(int taskId) {
    std::unique_lock<std::mutex> lock(mutexForTaskQueue); // Locking the mutex to ensure thread safety
    
    size_t initialSize = taskQueue.size(); // Store the initial size of the queue
    
    // Remove the task with the given ID
    taskQueue.erase(std::remove_if(taskQueue.begin(), taskQueue.end(),
                        [taskId](const Task& t) { return t.getId() == taskId; }),
                        taskQueue.end());
    
    // Check if any task was removed
    if (taskQueue.size() < initialSize) {
        std::cout << "Task with ID " << taskId << " has been removed successfully.\n";
    } else {
        std::cout << "Task with ID " << taskId << " not found.\n";
    }
}

// void TaskManager::removeTask(int taskId) {
//     std::unique_lock<std::mutex> lock(mutexForTaskQueue); // Locking the mutex to ensure thread safety
    
//     bool taskFound = false;

//     // Using a range-based for loop to iterate over the task queue
//     for (auto& task : taskQueue) {
//         if (task.getId() == taskId) { // Check if the current task has the given task ID
//             taskQueue.erase(std::remove(taskQueue.begin(), taskQueue.end(), task), taskQueue.end());
//             taskFound = true;
//             break; // Exit the loop after removing the task
//         }
//     }

//     // Display appropriate message
//     if (taskFound) {
//         std::cout << "Task with ID " << taskId << " has been removed successfully.\n";
//     } else {
//         std::cout << "Task with ID " << taskId << " not found.\n";
//     }
// }

void TaskManager::listTasks() const {
    std::unique_lock<std::mutex> lock(mutexForTaskQueue);
    size_t sz = taskQueue.size(); // Store the initial size of the queue
    std::cout << "size: " << sz << std::endl;

    if (taskQueue.empty()) {
        std::cout << "No tasks scheduled.\n";
        return;
    }
    for (const auto& task : taskQueue) {
        std::cout << "Task ID: " << task.getId() << " | Name: " << task.getName()
                  << " | Execution Time: " << task.getExecutionTime() << "ms" 
                  << " | Priority: " << task.getPriority() 
                  << " | Repeatation: " << "\n";
    }
}

std::vector<Task> TaskManager::getTasks() {
    std::unique_lock<std::mutex> lock(mutexForTaskQueue);
    return taskQueue;
}


