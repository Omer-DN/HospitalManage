#include "Patients.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void Patients::addPatient(const Patient& patient) {
    patientList.push_back(patient);
}

bool Patients::isEmpty() const {
    return patientList.empty();
}


void Patients::sortPatients() {
    sort(patientList.begin(), patientList.end(),
        [](const Patient& a, const Patient& b) {
            return (a.getUrgency() != b.getUrgency())
                ? (a.getUrgency() < b.getUrgency())
                : (a.getName() < b.getName());
        });
}

void Patients::printPatients() const {
    cout << "=== Patients List ===" << endl;
    for (const auto& patient : patientList) {
        cout << "Name: " << patient.getName()
            << ", Condition: " << patient.getCondition()
            << ", Urgency: " << patient.getUrgency() << std::endl;
    }
}

const vector<Patient>& Patients::getPatientList() const {
    return patientList;
}

Patient Patients::getNextPatient() {
    if (patientList.empty()) {
        throw std::runtime_error("No patients in queue");
    }

    // המטופל הראשון אחרי מיון לפי דחיפות
    Patient next = patientList.front();

    // אם רוצים להסיר אותו מהרשימה:
    patientList.erase(patientList.begin());

    return next;
}