#include "HardwareInterface.h"
#include <iostream>

void HardwareInterface::lightUp(int urgency, int id) {
    std::string color;
    switch (urgency) {
    case 1: color = "\033[31m"; break; // RED
    case 2: color = "\033[33m"; break; // YELLOW
    case 3: color = "\033[32m"; break; // GREEN
    default: color = "\033[0m";
    }
    std::cout << color << "Patient #" << id << " -> Urgency " << urgency << "\033[0m\n";
}

void HardwareInterface::displayPatient(const std::string& name, int urgency, int number) {
    std::cout << "Patient #" << number << ": " << name
        << " (Urgency " << urgency << ")\n";
}

void HardwareInterface::clearDisplay() {
    std::cout << "\033[2J\033[1;1H"; // מנקה את הקונסול
}
