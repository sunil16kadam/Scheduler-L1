//***************************************************************************************
//UserInterface.cpp
//***************************************************************************************
#include "../Headers/UserInterface.h"
#include <iostream>

void UserInterface::showMenu() {
    std::cout << "Scheduler Menu:\n"
              << "1. Add Task\n"
              << "2. Remove Task\n"
              << "3. List Tasks\n"
              << "4. Select Scheduling Algorithm\n"
              << "5. Execute Tasks\n"
              << "6. Exit\n";
}

