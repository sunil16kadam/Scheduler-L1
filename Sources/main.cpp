/////////////////////////////////////////////////////////////////////////////////////
// Project name: 
// Author: Sunil Kadam
// Last modification date: 25 Jan 2025
/////////////////////////////////////////////////////////////////////////////////////

//***************************************************************************************
//Main Program - Client program (main.cpp)
//***************************************************************************************
#include <iostream>
#include <cctype>
#include "../Headers/TaskManager.h"
#include "../Headers/Scheduler.h"
#include "../Headers/ExecutionEngine.h"
#include "../Headers/UserInterface.h"

int main() {
    TaskManager taskManager;
    Scheduler scheduler;
    ExecutionEngine engine;
    UserInterface ui;
    int choice;

    do {
        ui.showMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: { // Add Task
                int id, execTime, priority;
                std::string name;
                bool repeating;

                // std::cout << "Enter Task ID: ";
                // std::cin >> id;
                // std::cin.ignore(); // Clear newline character
                // std::cout << "Enter Task Name: ";
                // std::getline(std::cin, name);
                // std::cout << "Enter Execution Time (ms): ";
                // std::cin >> execTime;
                // std::cout << "Enter Priority (higher number = higher priority): ";
                // std::cin >> priority;
                // std::cout << "Is it repeating? (1: Yes, 0: No): ";
                // std::cin >> repeating;
                // Task task(id, name, execTime, priority, repeating);

                // Hardcoded tasks (id, name, execTime, priority, repeating)
                Task Task1(1, "Task A", 1000, 2, false);
                Task Task2(2, "Task B", 1500, 1, true);
                Task Task3(3, "Task C", 500, 3, false);
                taskManager.addTask(Task1);
                taskManager.addTask(Task2);
                taskManager.addTask(Task3);
                break;
            }
            case 2: { // Remove Task
                int taskId;
                std::cout << "Enter Task ID to remove: ";
                std::cin >> taskId;
                taskManager.removeTask(taskId);
                break;
            }
            case 3: { // List Tasks
                taskManager.listTasks();
                break;
            }
            case 4: { // Set Scheduling Algorithm
                std::string algo;
                std::cout << "Enter Scheduling Algorithm (SJF/Priority/FCFS): ";
                std::cin >> algo;
                std::transform(algo.begin(), algo.end(), algo.begin(), ::toupper);
                scheduler.setAlgorithm(algo);
                break;
            }
            case 5: { // Execute Tasks
                std::vector<Task> tasks = taskManager.getTasks();
                tasks = scheduler.scheduleTasks(tasks);
                engine.executeTasks(tasks, scheduler);
                break;
            }
            case 6:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
