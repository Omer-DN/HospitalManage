#include "Patients.h"
#include "InjuryManager.h"
#include "CSVWriter.h"
#include "HardwareInterface.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void displayMenu() {
    cout << "Choose an option:\n";
    cout << "1. Add new patient\n";
    cout << "2. Display all patients (sorted by urgency)\n";
    cout << "0. Exit\n";
}

void displayInjuries(const vector<string>& injuries) {
    cout << "Please choose an injury type from the following list:\n";
    for (size_t i = 0; i < injuries.size(); ++i) {
        cout << i + 1 << ". " << injuries[i] << endl;
    }
}

int main() {
    CSVWriter csvFile;
    InjuryManager injuryManager;
    Patients patients;
    HardwareInterface hardware;

    vector<string> injuryList = injuryManager.getInjuryList();
    int choice;

    do {
        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string name;
            int age;
            int injuryIndex;

            cout << "\nEnter patient name: ";
            getline(cin, name);

            cout << "\nEnter patient age: ";
            while (!(cin >> age) || age <= 0) {
                cout << "Invalid age. Please enter a positive number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            displayInjuries(injuryList);
            cout << "\nEnter the number corresponding to the injury: ";
            while (!(cin >> injuryIndex) || injuryIndex < 1 || injuryIndex > static_cast<int>(injuryList.size())) {
                cout << "Invalid choice. Please enter a number between 1 and " << injuryList.size() << ": ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            string selectedInjury = injuryList[injuryIndex - 1];
            int urgency = injuryManager.getInjuryType(selectedInjury);

            Patient newPatient(name, age, selectedInjury, urgency);
            patients.addPatient(newPatient);
            patients.sortPatients();

            csvFile.writeToFile(newPatient, "patients.csv");

            cout << "Patient added to queue.\n";
            cout << "Current patient count: " << patients.getPatientList().size() << endl;

            // הדלקת נורה לפי דחיפות עבור המטופל החדש
            hardware.lightUp(newPatient.getUrgency(), newPatient.getId());
        }
        else if (choice == 2) {
            patients.printPatients();
        }
        else if (choice != 0) {
            cout << "Invalid option. Please try again.\n";
        }

        cout << endl;

    } while (choice != 0);

    return 0;
}
