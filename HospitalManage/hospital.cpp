#include "hospital.h"
#include <iostream>
#include <algorithm> 

void Hospital::addPatient(const Patient& newPatient) {
    patients.push_back(newPatient);
}

bool Hospital::removePatient(int id) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->getId() == id) {
            patients.erase(it);
            return true;
        }
    }
    return false;
}

Patient* Hospital::findPatientById(int id) {
    for (auto& patient : patients) {
        if (patient.getId() == id) {
            return &patient;
        }
    }
    return nullptr;
}

void Hospital::displayAllPatients() const {
    if (patients.empty()) {
       cout << "No patients in the hospital.\n";
        return;
    }

    vector<Patient> sortedPatients = patients;

    sort(sortedPatients.begin(), sortedPatients.end(),
        [](const Patient& a, const Patient& b) {
            return a.getUrgency() < b.getUrgency(); // 1 = הכי דחוף
        });

    cout << "Patients list (sorted by urgency):\n";
    for (const auto& patient : sortedPatients) {
       cout << "ID: " << patient.getId()
            << ", Name: " << patient.getName()
            << ", Age: " << patient.getAge()
            << ", Condition: " << patient.getCondition()
            << ", Urgency: " << patient.getUrgency()
            << endl;
    }
}
