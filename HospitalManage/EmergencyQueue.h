#pragma once
#include <iostream>
#include <unordered_map>
#include <string>

class EmergencyQueue {
public:
    // אתחול זמני ההמתנה לכל מצב חירום
    static void initializeWaitTimes();

    // מקבל את זמן ההמתנה עבור מצב נתון
    static int getWaitTime(const std::string& condition);

    // מציג את כל זמני ההמתנה
    static void printWaitTimes();

private:
    static std::unordered_map<std::string, int> conditionWaitTimes;
};
