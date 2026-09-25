Ericsson Telecom Network Routing Simulation

A C++-based telecom simulation project focused on tower load monitoring, input validation, and simulated subscriber information.

"C++" (https://img.shields.io/badge/C%2B%2B-17-blue?logo=cplusplus)
"Status" (https://img.shields.io/badge/Status-Completed-success)
"Project Type" (https://img.shields.io/badge/Project-Student%20Portfolio-purple)
"Domain" (https://img.shields.io/badge/Domain-Telecommunications-orange)

---

Overview

Ericsson Telecom Network Routing Simulation is an independent C++ project created to explore how programming concepts can be applied to a simplified telecommunications scenario.

The application provides an interactive console workflow where the user can:

- Check tower load
- Enter a tower ID
- Provide a tower load percentage
- Enter a simulated phone number
- Validate and process the provided information
- Complete the telecom simulation

The project focuses on connecting C++ programming fundamentals with a practical engineering use case.

«Disclaimer: This is an independent educational project. It is not an official Ericsson product and does not connect to Ericsson's internal or production systems.»

---

Project Goal

The goal of this project is to move beyond basic programming exercises and apply C++ concepts to a scenario inspired by real-world telecommunications.

The project explores the relationship between:

C++ Programming
       ↓
Input Processing
       ↓
Validation
       ↓
Telecom Simulation
       ↓
Network Concepts

---

How the Simulation Works

The current version follows a simple interactive workflow:

Start
  │
  ▼
Check Tower Load
  │
  ▼
Enter Tower ID
  │
  ▼
Enter Load (0–100)
  │
  ▼
Enter Phone Number
  │
  ▼
Process Information
  │
  ▼
Simulation Completed

Example Run

=========================================
 Ericsson Telecom Network Routing System
=========================================

Check Tower Load? (Yes/No): Yes

Enter Tower ID: TOWER-001

Enter new load (0-100): 72

Enter phone number (format: 555-0192): 555-0192

Simulation completed successfully.

---

Telecom Concept

Telecommunication towers can experience different levels of network traffic.

This project represents tower utilization using a percentage between 0 and 100.

Load| Simulated Meaning
0%| Very low utilization
25%| Low utilization
50%| Moderate utilization
75%| High utilization
100%| Maximum utilization

For example:

Tower ID : TOWER-001
Load     : 72%

represents a simulated tower with a 72% load level.

«The load values used by this project are simulated and do not represent live telecom-network measurements.»

---

Key Features

Tower Load Input

The program accepts a tower-load value between:

0 – 100

This provides a simple representation of tower utilization.

Tower Identification

Each simulated tower can be identified using a tower ID.

Example:

TOWER-001

Phone Number Input

The program accepts a phone number using the expected format:

555-0192

The number is used only as simulated input.

Input Validation

The program processes user input and applies validation to the provided values.

Interactive Console

The application operates through a simple command-line interface, making the simulation easy to run and test.

---

Technology Stack

Technology| Purpose
C++| Core application
C++ Standard Library| Basic programming functionality
Console I/O| User interaction
Git| Version control
GitHub| Source-code hosting

---

C++ Concepts

This project provides practical experience with:

- Variables and data types
- Conditional statements
- Functions
- Loops
- User input/output
- Strings
- Input validation
- Program control flow
- Basic error handling
- Console applications

---

Running the Project

Requirements

Before running the project, install:

- A C++ compiler
- Visual Studio Code, Visual Studio, or another C++ IDE

A compiler supporting modern C++ standards is recommended.

Clone the Repository

git clone https://github.com/YOUR-USERNAME/Ericsson-Telecom-Network-Routing-Simulation.git

Then:

cd Ericsson-Telecom-Network-Routing-Simulation

Compile

Using GCC:

g++ main.cpp -o telecom_simulation

Run on Windows

telecom_simulation.exe

Run on Linux/macOS

./telecom_simulation

---

Example Test

Input

Tower Load Check: Yes
Tower ID: TOWER-001
Load: 72
Phone Number: 555-0192

Output

Simulation completed successfully.

---

Project Scope

This project is a simulation, not a production telecommunications system.

It does not currently connect to:

- Real telecom towers
- Ericsson network equipment
- Live cellular networks
- Real subscriber databases
- Production network infrastructure
- Live network traffic

All tower IDs, load values, and phone numbers are simulated for educational purposes.

---

Future Development

The current implementation provides a foundation for expanding the project.

Possible future improvements include:

- [ ] Multiple tower management
- [ ] Real-time tower-load simulation
- [ ] Tower overload detection
- [ ] Network topology visualization
- [ ] Multiple network nodes
- [ ] Traffic distribution simulation
- [ ] Network failure simulation
- [ ] Automatic rerouting
- [ ] Data logging
- [ ] Network performance statistics
- [ ] Graph-based routing algorithms
- [ ] AI-assisted network optimization

A future version could evolve toward a more advanced telecom network-management and routing simulator.

---

Learning Outcome

This project helped apply C++ programming concepts to a practical engineering scenario.

Instead of using programming concepts only in isolated exercises, the project combines them into a single application:

Programming
     +
Input Validation
     +
Simulation
     +
Telecommunications
     ↓
Practical C++ Project

---

Project Information

Category| Details
Project Type| Student Portfolio
Language| C++
Domain| Telecommunications
Application Type| Console Simulation
Status| Initial Version
Purpose| Educational / Engineering Practice

---

Author

Abdullah Khan

Computer Science Student

Interested in:

- Software Engineering
- Artificial Intelligence
- Computer Networks
- Telecommunications
- Network Automation
- Distributed Systems

---

License

This project is intended for educational and portfolio purposes.

If you decide to open-source the project, an appropriate license such as the MIT License can be added to the repository.

---

<div align="center">Built with C++

Exploring the intersection of software engineering and telecommunications.

</div>
