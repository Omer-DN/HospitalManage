#pragma once
#include <string>

using namespace std;

class HardwareInterface {
public:
    void lightUp(int urgency, int id);
    void displayPatient(const std::string& name, int urgency, int number);
    void clearDisplay();
};
