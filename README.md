# Patient-Management-System

This project implements a Priority Queue for managing patients based on their severity and arrival time.
Patients with higher severity are prioritized. If two patients have the same severity, the one who arrived earlier is prioritized.

It uses a singly linked list to maintain the queue.

# Features

* Add (Enqueue) Patients:

    * Patients are added according to their severity and arrival time.

* Serve (Dequeue) Patients:

    * The patient at the front of the queue (highest priority) is served first.

* View Patients:

    * Displays the list of patients in the queue in the order they will be served.

* Input Validation:

    * Ensures severity is between 1 and 10.

* Re-prompts for invalid severity or invalid continuation choices (y/n).

# How It Works

* When adding a new patient:

    * If the queue is empty, the patient is added at the front.

    * Otherwise, the patient is inserted at the appropriate position based on:

    * Higher severity first.

    * For same severity, earlier arrival time first.

* Serving a patient:

    * The patient at the front is removed and displayed.

* After serving:

    * Remaining patients can be viewed.

# Files

* Patient.h — Header file included (currently empty but reserved for future use).

* main.cpp — Contains the Patient structure, PriorityQueue class, and the main() function with the program logic.

# How to Run

* Compile:
    Using g++:

      g++ main.cpp -o PatientQueue
* Run:

      ./PatientQueue
  
* Follow the prompts:


# Example

![image](https://github.com/user-attachments/assets/56ff5e36-ba18-49a0-83c8-a7891871aee1)

# Notes

* The program automatically deletes all dynamically allocated memory when closing.

* You can modify or extend it by adding features like patient search, editing patient details, etc.
