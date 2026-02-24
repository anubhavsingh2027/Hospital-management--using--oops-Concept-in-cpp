# Hospital Management System

A comprehensive C++ application for managing hospital operations using Object-Oriented Programming (OOP) concepts. This system enables efficient management of patients, doctors, and medical appointments.

## Features

- **Patient Management**
  - Register new patients with personal details and medical history
  - View all registered patients
  - Persistent storage of patient records

- **Doctor Management**
  - Register doctors with specialization and contact information
  - View all available doctors
  - Track doctor information including room assignments

- **Appointment Booking**
  - Book appointments between patients and doctors
  - View all hospital doctors with IDs before booking
  - View appointment history
  - Automatic validation of patient and doctor records

- **Data Persistence**
  - Automatic saving of all records to text files
  - Load previous records on program startup
  - File-based storage for patients, doctors, and appointments

- **User-Friendly Interface**
  - Interactive menu-driven system
  - Clear error messages and notifications
  - Empty record indicators when no data is available

## Project Structure

```
Hospital-management--using--oops-Concept-in-cpp/
├── index.cpp           # Main application with all class definitions
├── patients.txt        # Persistent patient records
├── doctors.txt         # Persistent doctor records
├── appointments.txt    # Persistent appointment records
└── README.md          # Project documentation
```

## Class Hierarchy

### Person (Base Class)

- Protected attributes: id, name, age
- Methods: getId(), getName(), getAge()

### Patient (Inherits from Person)

- Additional attribute: disease
- Methods: input(), display(), setters, getters

### Doctor (Inherits from Person)

- Additional attributes: specialization, phone, roomNo
- Methods: input(), display(), setters, getters

### Appointment

- Attributes: patientName, patientId, doctorName, doctorId
- Methods: book(), display(), setters, getters

## Requirements

- C++ Compiler (GCC, Clang, or MSVC)
- Windows/Linux/MacOS

## Compilation

```bash
g++ index.cpp -o index
```

## Usage

Run the compiled executable:

```bash
./index
```

### Menu Options

1. **Register Patient** - Add a new patient to the system
2. **Register Doctor** - Add a new doctor to the system
3. **Book Appointment** - Schedule an appointment between patient and doctor
4. **Display Patients** - View all registered patients
5. **Display Doctors** - View all registered doctors
6. **Display Appointments** - View all booked appointments
7. **Exit** - Close the application

## Sample Workflow

1. Register at least one doctor
2. Register at least one patient
3. Book an appointment by selecting a patient name, viewing available doctors, and entering the doctor ID
4. View records using display options

## Data Format

### patients.txt

```
[
{name:Patient Name,id:1,age:25,disease:disease name},
...
]
```

### doctors.txt

```
[
{name:Doctor Name,id:1,age:45,phone:contact number,room:room number},
...
]
```

### appointments.txt

```
[
{patient_name:Patient Name,patient_id:1,doctor_name:Doctor Name,doctor_id:1},
...
]
```

## OOP Concepts Used

- **Inheritance** - Patient and Doctor inherit from Person base class
- **Encapsulation** - Private attributes with public getter/setter methods
- **Polymorphism** - Virtual display() methods across classes
- **Abstraction** - Complex file I/O hidden behind simple function calls
- **Data Persistence** - File handling for permanent storage

## Features in Detail

### Automatic Data Loading

The application loads all previous records from text files when started, ensuring no data loss between sessions.

### Doctor List on Appointment Booking

When booking an appointment, the system displays all available doctors with their IDs, helping users make informed decisions.

### Empty Record Handling

The system displays appropriate messages when no records exist for each category (Patients, Doctors, Appointments).

### ID Management

Automatic ID generation ensures each new patient or doctor receives a unique, incremented ID.



## License

This project is open source and available for educational purposes.

## Author

Created as a learning project for OOP concepts in C++

## Contributing

Contributions are welcome! Feel free to fork, modify, and submit improvements.
