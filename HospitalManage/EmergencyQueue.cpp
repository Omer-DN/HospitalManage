#include "EmergencyQueue.h"
#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, int> EmergencyQueue::conditionWaitTimes;

// אתחול זמני המתנה לכל מצב חירום
void EmergencyQueue::initializeWaitTimes() {
    conditionWaitTimes["Chest pain"] = 10;
    conditionWaitTimes["Sudden difficulty breathing"] = 10;
    conditionWaitTimes["Severe injury"] = 10;
    conditionWaitTimes["Severe bleeding"] = 10;
    conditionWaitTimes["Signs of stroke"] = 1;
    conditionWaitTimes["Seizures"] = 3;
    conditionWaitTimes["Suspected fractures"] = 60;
    conditionWaitTimes["Very high fever"] = 120;
    conditionWaitTimes["Poisoning"] = 10;
    conditionWaitTimes["Severe allergic reactions"] = 1;
    conditionWaitTimes["Persistent vomiting"] = 240;
    conditionWaitTimes["Severe abdominal pain"] = 120;
    conditionWaitTimes["Eye injuries"] = 120;
    conditionWaitTimes["Severe mental health crisis"] = 3;
    conditionWaitTimes["Loss of consciousness"] = 1;
    conditionWaitTimes["Sudden swelling or pain in limbs"] = 120;
    conditionWaitTimes["Animal or snake bites"] = 1;
}

// מחזיר את זמן ההמתנה למצב חירום נתון
int EmergencyQueue::getWaitTime(const std::string& condition) {
    auto it = conditionWaitTimes.find(condition);
    if (it != conditionWaitTimes.end()) {
        return it->second;
    }
    return 0;
}

// מציג את כל זמני ההמתנה
void EmergencyQueue::printWaitTimes() {
    std::cout << "Emergency Cases and Waiting Times (in minutes):\n";
    for (const auto& caseTime : conditionWaitTimes) {
        std::cout << caseTime.first << ": " << caseTime.second << " minutes" << std::endl;
    }
}
