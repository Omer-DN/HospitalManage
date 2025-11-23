#pragma once
#ifndef PATIENT_H
#define PATIENT_H

#include <string>
using namespace std;

class Patient {
private:
    string name;
    int age;
    int id;
    static int nextId;          
    int urgency;
    int arrivalTime;
    string condition;

public:
    // קונסטרקטור ל־test_patient עם 3 פרמטרים
    Patient(const string& name, int severity, int arrivalTime);

    // קונסטרקטור חדש עם 4 פרמטרים (severity + condition)
    Patient(const string& name, int severity, const string& condition, int arrivalTime);

    // קונסטרקטור עם ID לשחזור ממקור קיים
    Patient(int id, const string& name, int age, const string& condition, int urgency);

    string getName() const;
    int getAge() const;
    int getId() const;
    string getCondition() const;
    int getUrgency() const;
    int getSeverity() const { return urgency; }
    int getArrivalTime() const { return arrivalTime; }
    string toCSV() const;
};

#endif
