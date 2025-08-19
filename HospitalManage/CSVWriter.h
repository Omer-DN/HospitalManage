#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <string>
#include "Patient.h"
#include <vector>

class CSVWriter {
public:
    void writeToFile(const Patient& patient, const std::string& filename);

    vector<Patient> readFromFile(const std::string& filename);
};

#endif // CSVWRITER_H
