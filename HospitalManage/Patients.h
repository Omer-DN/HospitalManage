#pragma once
#ifndef PATIENTS_H
#define PATIENTS_H

#include <vector>
#include "Patient.h"

using namespace std;

class Patients {
private:
    vector<Patient> patientList;

public:
    void addPatient(const Patient& patient);

    void sortPatients();

    void printPatients() const;

    bool isEmpty()const;

    Patient getNextPatient();

    const vector<Patient>& getPatientList() const;
};

#endif // PATIENTS_H
