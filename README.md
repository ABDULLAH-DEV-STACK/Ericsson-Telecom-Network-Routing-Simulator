Ericsson Telecom Network Routing Simulation

«A C++-based telecom network simulation that models tower load monitoring, tower identification, input validation, and simulated subscriber information through an interactive console application.»

📌 Overview

Ericsson Telecom Network Routing Simulation is an educational C++ project designed to simulate a simplified telecom network-management scenario.

The application allows the user to interact with a simulated telecom tower by providing its Tower ID, updating its network load percentage, and entering a simulated phone number.

The project was created to connect fundamental C++ programming concepts with a practical telecommunications use case.

«Note: This is an independent educational project and is not an official Ericsson product or representation of Ericsson's internal systems.»

---

🎯 Project Objectives

The main objectives of this project are to:

- Simulate a basic telecom tower-management workflow.
- Represent tower network load using a percentage from 0–100.
- Accept and process a simulated tower ID.
- Validate user input.
- Accept a phone number in a predefined format.
- Apply C++ programming concepts to a real-world-inspired scenario.
- Build a foundation for future telecom-network simulations.

---

⚙️ How It Works

The current simulation follows a simple interactive workflow:

Start Program
     ↓
Check Tower Load
     ↓
Enter Tower ID
     ↓
Enter New Load (0–100)
     ↓
Enter Phone Number
     ↓
Process Input
     ↓
Simulation Completed Successfully

Example

=========================================
 Ericsson Telecom Network Routing System
=========================================

Check Tower Load? (Yes/No): Yes

Enter Tower ID: TOWER-001

Enter new load (0-100): 72

Enter phone number (format: 555-0192): 555-0192

Simulation completed successfully.

---

📡 Telecom Concept

In a real telecommunications environment, network towers handle varying amounts of traffic.

This project represents tower utilization using a simple percentage:

0%    → Low utilization
25%   → Low utilization
50%   → Moderate utilization
75%   → High utilization
100%  → Maximum utilization

For example:

Tower ID: TOWER-001
Load: 72%

represents a simulated tower operating at 72% load.

The load values in this project are simulated data and do not represent live telecom-network measurements.

---

🛠️ Technologies Used

- C++
- Object-Oriented Programming concepts
- Conditional statements
- Functions
- User input/output
- Input validation
- Console-based application
- Git & GitHub

---

🧠 C++ Concepts Practiced

This project provides practical experience with:

- Variables and data types
- "if/else" conditions
- Functions
- User input
- String handling
- Numeric validation
- Loops
- Program flow
- Console output
- Basic software structure

---

▶️ How to Run

Requirements

You need:

- A C++ compiler
- Visual Studio Code, Visual Studio, or another C++ IDE
- Git (optional)

Compile

Using GCC:

g++ main.cpp -o telecom_simulation

Run on Windows

telecom_simulation.exe

Run on Linux/macOS

./telecom_simulation

---

🧪 Example Test Case

Input:

Tower Load Check: Yes
Tower ID: TOWER-001
Load: 72
Phone Number: 555-0192

Result:

Simulation completed successfully.

The application validates and processes the provided information as part of the simulated telecom workflow.

---

⚠️ Current Scope

This project is intentionally a simplified simulation.

It does not currently connect to:

- Real telecom towers
- Ericsson network equipment
- Live cellular networks
- Real subscriber databases
- Production network infrastructure
- Live network traffic

All tower information, load values, and phone numbers are simulated for educational purposes.

---

🚀 Future Improvements

The project can be expanded into a more advanced telecom-network simulation.

Potential future features include:

- Multiple telecom towers
- Real-time tower-load monitoring
- Network topology visualization
- Traffic distribution simulation
- Tower overload detection
- Alternative routing
- Network failure simulation
- Data logging
- Performance statistics
- Graph-based routing algorithms
- AI-assisted network optimization

Future development could eventually transform the project from a basic console simulation into a more comprehensive telecom network-management simulator.

---

📚 Learning Outcome

This project helped me apply C++ programming concepts to a practical engineering scenario rather than working only with isolated programming exercises.

It provided hands-on experience with:

Programming → Input Validation → Simulation → Network Concepts → Software Engineering

---

👨‍💻 Author

Abdullah Khan

Computer Science Student | C++ Developer | Aspiring AI & Technology Engineer

Interests

- Software Engineering
- Artificial Intelligence
- Computer Networks
- Telecommunications
- Network Automation
- Distributed Systems

---

⭐ Project Status

Status: Completed — Initial Simulation

Type: Educational / Student Portfolio Project

Language: C++

Domain: Telecommunications / Network Simulation

---

«Built with C++ to explore the intersection of software engineering and telecommunications.»
