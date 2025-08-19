📄 README – HospitalManage
🏥 Project Overview

HospitalManage is a hospital emergency room management simulator written in C++.
The system simulates patient intake, triage (classification by injury severity), priority queue management, and patient status tracking.

In the extended version, an Arduino hardware simulation was integrated to demonstrate a control panel with lights and a display:

🟢 New patient arrival → light indicator ON

🔴 Queue full → alert light ON

🟡 Patient under treatment → status displayed on screen

The project combines Object-Oriented Programming (OOP), STL (Standard Template Library) structures such as priority_queue, map, and vector, along with real-time system concepts.

⚙️ Features

📌 Priority Queue Management – patients are ranked by injury severity and arrival time

📌 Triage System – categorization of injuries with corresponding wait times

📌 Core Logic Module – manage patients, update statuses, add/remove dynamically

📌 CSV Integration – export and import patient data

📌 Hardware Simulation (Arduino) – light indicators and a simple screen simulation (no physical hardware required)

🛠️ Technologies

C++ (OOP, STL)

Arduino Simulation (virtual demo)

File Handling (CSV)

Basic Multithreading (optional, for managing waiting/treatment times)

📂 Project Structure
HospitalManage/
│
├── main.cpp              # Entry point
├── Patient.h / Patient.cpp # Patient class definition and logic
├── InjuryManager.h/.cpp  # Manages injury types and wait times
├── QueueManager.h/.cpp   # Priority queue for patients
├── CSVWriter.h/.cpp      # Handles CSV export/import
├── HardwareSim.h/.cpp    # Hardware simulation (lights and screen)
│
├── data/                 # Patient data storage
│   └── patients.csv
│
└── README.md             # Documentation

🚀 Installation & Usage
Prerequisites

C++17 or newer

Development environment: Visual Studio / CLion / g++

(Optional) Arduino IDE for hardware simulation

Installation
# Clone repository
git clone https://github.com/username/HospitalManage.git
cd HospitalManage

# Compile
g++ main.cpp Patient.cpp InjuryManager.cpp QueueManager.cpp CSVWriter.cpp HardwareSim.cpp -o hospitalManage

# Run
./hospitalManage

Basic Usage

Launch the program – the main menu will appear.

Options include:

➕ Add a new patient

📋 Display the current queue

⏱️ Update waiting times

💾 Save/Load patients to/from CSV

🟢 Run hardware simulation

📊 Example Run
Welcome to HospitalManage
-------------------------
1. Add new patient
2. Show queue
3. Update waiting times
4. Save to CSV
5. Load from CSV
6. Hardware simulation
0. Exit

🔮 Future Improvements

Full GUI support using frameworks like Qt / wxWidgets

Integration with a database system for scalable patient management

Expansion of hardware module to support real sensors/actuators

Advanced queue algorithms (e.g., Weighted Priority, dynamic scheduling)

👨‍💻 Author

Developed by Omer Dayan
📧 [omer94@egmail.com
]
🔗 [LinkedIn](https://www.linkedin.com/in/omer-dayan/)
