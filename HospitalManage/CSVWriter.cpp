#include "CSVWriter.h"
#include <fstream>
#include <sstream>
#include <iostream>

void CSVWriter::writeToFile(const Patient& patient, const string& filename) {
    ofstream outputFile(filename, ios::app);
    if (outputFile.is_open()) {
        outputFile << patient.toCSV() << endl;
        outputFile.close();
    }
    else {
        cerr << "Error saving file.\n";
    }
}

vector<Patient> CSVWriter::readFromFile(const std::string& filename) {
    std::vector<Patient> patients;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: Cannot open file " << filename << std::endl;
        return patients;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, ageStr, condition, urgencyStr;
        std::getline(ss, name, ',');
        std::getline(ss, ageStr, ',');
        std::getline(ss, condition, ',');
        std::getline(ss, urgencyStr, ',');

        int age = std::stoi(ageStr);
        int urgency = std::stoi(urgencyStr);

        Patient p(name, age, condition, urgency);
        patients.push_back(p);

        // הדפסת המטופל
        std::cout << "Name: " << name
            << ", Age: " << age
            << ", Condition: " << condition
            << ", Urgency: " << urgency
            << std::endl;
    }

    file.close();
    return patients;
}
