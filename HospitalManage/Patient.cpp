#include "Patient.h"

int Patient::nextId = 1;

// קונסטרקטור עם 3 פרמטרים
Patient::Patient(const string& name, int severity, int arrivalTime)
    : id(nextId++), name(name), urgency(severity), arrivalTime(arrivalTime), age(0), condition("") {}

// קונסטרקטור עם 4 פרמטרים
Patient::Patient(const string& name, int severity, const string& condition, int arrivalTime)
    : id(nextId++), name(name), urgency(severity), condition(condition), arrivalTime(arrivalTime), age(0) {}

// קונסטרקטור עם ID לשחזור ממקור קיים
Patient::Patient(int id, const string& name, int age, const string& condition, int urgency)
    : id(id), name(name), age(age), condition(condition), urgency(urgency), arrivalTime(0) {
    if (id >= nextId) nextId = id + 1;
}

string Patient::getName() const { return name; }
int Patient::getAge() const { return age; }
int Patient::getId() const { return id; }
string Patient::getCondition() const { return condition; }
int Patient::getUrgency() const { return urgency; }

string Patient::toCSV() const {
    return name + "," + to_string(age) + "," + condition + "," + to_string(urgency);
}
