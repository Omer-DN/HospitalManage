#include "Patient.h"
#include <iostream>
#include <fstream>
using namespace std;


int Patient::nextId = 1;

// מטופל חדש – מקבל ID אוטומטי
Patient::Patient(const std::string& name, int age, const std::string& injury, int urgency)
    : id(nextId++), name(name), age(age), injury(injury), urgency(urgency) {
}

// מטופל משוחזר מקובץ – עם ID קיים
Patient::Patient(int id, const std::string& name, int age, const std::string& injury, int urgency)
    : id(id), name(name), age(age), injury(injury), urgency(urgency) {
    if (id >= nextId) {
        nextId = id + 1; // דואגים שהמונה לא ידרוך אחורה
    }
}

/*UrgencyLevel::Level Patient::getUrgency() const {
    return urgency;
}*/

string Patient::getCondition() const {
    return condition;
}

string Patient::getName() const {
    return name;
}

string Patient::toCSV() const {
    return name + "," + to_string(age) + "," + condition + "," + to_string(urgency);
}

int Patient::getAge() const {
    return age;
}

int Patient::getId() const {
    return id;
}

int Patient::getUrgency()const {
    return urgency;
}