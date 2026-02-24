#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Person
{
protected:
  int id;
  string name;
  int age;

public:
  int getId() const { return id; }
  string getName() const { return name; }
  int getAge() const { return age; }
};

class Patient : public Person
{
  string disease;

public:
  void input(int newId)
  {
    id = newId;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Disease: ";
    getline(cin, disease);
  }

  void display() const
  {
    cout << "ID: " << id
         << "\nName: " << name
         << "\nAge: " << age
         << "\nDisease: " << disease
         << "\n----------------------\n";
  }

  string getDisease() const { return disease; }
  void setId(int newId) { id = newId; }
  void setName(const string &newName) { name = newName; }
  void setAge(int newAge) { age = newAge; }
  void setDisease(const string &newDisease) { disease = newDisease; }
};

class Doctor : public Person
{
  string specialization;
  string phone;
  string roomNo;

public:
  void input(int newId)
  {
    id = newId;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Specialization: ";
    getline(cin, specialization);
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter Room No: ";
    getline(cin, roomNo);
  }

  void display() const
  {
    cout << "ID: " << id
         << "\nName: " << name
         << "\nAge: " << age
         << "\nSpecialization: " << specialization
         << "\nPhone: " << phone
         << "\nRoom No: " << roomNo
         << "\n----------------------\n";
  }

  string getPhone() const { return phone; }
  string getRoom() const { return roomNo; }
  void setId(int newId) { id = newId; }
  void setName(const string &newName) { name = newName; }
  void setAge(int newAge) { age = newAge; }
  void setSpecialization(const string &newSpec) { specialization = newSpec; }
  void setPhone(const string &newPhone) { phone = newPhone; }
  void setRoom(const string &newRoom) { roomNo = newRoom; }
};

class Appointment
{
  string patientName;
  int patientId;
  string doctorName;
  int doctorId;

public:
  void book(const Patient &p, const Doctor &d)
  {
    patientName = p.getName();
    patientId = p.getId();
    doctorName = d.getName();
    doctorId = d.getId();
  }

  void display() const
  {
    cout << "\n----- Appointment -----\n";
    cout << "Patient: " << patientName
         << " (ID: " << patientId << ")"
         << "\nDoctor: " << doctorName
         << " (ID: " << doctorId << ")"
         << "\n------------------------\n";
  }

  string getPatientName() const { return patientName; }
  int getPatientId() const { return patientId; }
  string getDoctorName() const { return doctorName; }
  int getDoctorId() const { return doctorId; }
  void setPatientName(const string &name) { patientName = name; }
  void setPatientId(int id) { patientId = id; }
  void setDoctorName(const string &name) { doctorName = name; }
  void setDoctorId(int id) { doctorId = id; }
};

int getNextPatientId(const vector<Patient> &patients)
{
  if (patients.empty())
    return 1;
  return patients.back().getId() + 1;
}

int getNextDoctorId(const vector<Doctor> &doctors)
{
  if (doctors.empty())
    return 1;
  return doctors.back().getId() + 1;
}

void savePatients(const vector<Patient> &patients)
{
  ofstream file("patients.txt");
  file << "[\n";
  for (int i = 0; i < patients.size(); i++)
  {
    file << "{name:" << patients[i].getName()
         << ",id:" << patients[i].getId()
         << ",age:" << patients[i].getAge()
         << ",disease:" << patients[i].getDisease()
         << "}";
    if (i != patients.size() - 1)
      file << ",";
    file << "\n";
  }
  file << "]";
}

void saveDoctors(const vector<Doctor> &doctors)
{
  ofstream file("doctors.txt");
  file << "[\n";
  for (int i = 0; i < doctors.size(); i++)
  {
    file << "{name:" << doctors[i].getName()
         << ",id:" << doctors[i].getId()
         << ",age:" << doctors[i].getAge()
         << ",phone:" << doctors[i].getPhone()
         << ",room:" << doctors[i].getRoom()
         << "}";
    if (i != doctors.size() - 1)
      file << ",";
    file << "\n";
  }
  file << "]";
}

void saveAppointments(const vector<Appointment> &apps)
{
  ofstream file("appointments.txt");
  file << "[\n";
  for (int i = 0; i < apps.size(); i++)
  {
    file << "{patient_name:" << apps[i].getPatientName()
         << ",patient_id:" << apps[i].getPatientId()
         << ",doctor_name:" << apps[i].getDoctorName()
         << ",doctor_id:" << apps[i].getDoctorId()
         << "}";
    if (i != apps.size() - 1)
      file << ",";
    file << "\n";
  }
  file << "]";
}

void loadPatients(vector<Patient> &patients)
{
  ifstream file("patients.txt");
  if (!file.is_open())
    return;

  string line;
  while (getline(file, line))
  {
    if (line.find("{") != string::npos && line.find("name:") != string::npos)
    {
      Patient p;
      int id, age;
      string name, disease;

      size_t nameStart = line.find("name:") + 5;
      size_t nameEnd = line.find(",", nameStart);
      name = line.substr(nameStart, nameEnd - nameStart);

      size_t idStart = line.find("id:") + 3;
      size_t idEnd = line.find(",", idStart);
      id = stoi(line.substr(idStart, idEnd - idStart));

      size_t ageStart = line.find("age:") + 4;
      size_t ageEnd = line.find(",", ageStart);
      age = stoi(line.substr(ageStart, ageEnd - ageStart));

      size_t diseaseStart = line.find("disease:") + 8;
      size_t diseaseEnd = line.find("}", diseaseStart);
      disease = line.substr(diseaseStart, diseaseEnd - diseaseStart);

      p.setId(id);
      p.setName(name);
      p.setAge(age);
      p.setDisease(disease);

      patients.push_back(p);
    }
  }
  file.close();
}

void loadDoctors(vector<Doctor> &doctors)
{
  ifstream file("doctors.txt");
  if (!file.is_open())
    return;

  string line;
  while (getline(file, line))
  {
    if (line.find("{") != string::npos && line.find("name:") != string::npos)
    {
      Doctor d;
      int id, age;
      string name, specialization, phone, roomNo;

      size_t nameStart = line.find("name:") + 5;
      size_t nameEnd = line.find(",", nameStart);
      name = line.substr(nameStart, nameEnd - nameStart);

      size_t idStart = line.find("id:") + 3;
      size_t idEnd = line.find(",", idStart);
      id = stoi(line.substr(idStart, idEnd - idStart));

      size_t ageStart = line.find("age:") + 4;
      size_t ageEnd = line.find(",", ageStart);
      age = stoi(line.substr(ageStart, ageEnd - ageStart));

      size_t phoneStart = line.find("phone:") + 6;
      size_t phoneEnd = line.find(",", phoneStart);
      phone = line.substr(phoneStart, phoneEnd - phoneStart);

      size_t roomStart = line.find("room:") + 5;
      size_t roomEnd = line.find("}", roomStart);
      roomNo = line.substr(roomStart, roomEnd - roomStart);

      specialization = "General";

      d.setId(id);
      d.setName(name);
      d.setAge(age);
      d.setSpecialization(specialization);
      d.setPhone(phone);
      d.setRoom(roomNo);

      doctors.push_back(d);
    }
  }
  file.close();
}

void loadAppointments(vector<Appointment> &appointments)
{
  ifstream file("appointments.txt");
  if (!file.is_open())
    return;

  string line;
  while (getline(file, line))
  {
    if (line.find("{") != string::npos && line.find("patient_name:") != string::npos)
    {
      Appointment a;

      size_t patientNameStart = line.find("patient_name:") + 13;
      size_t patientNameEnd = line.find(",", patientNameStart);
      string patientName = line.substr(patientNameStart, patientNameEnd - patientNameStart);

      size_t patientIdStart = line.find("patient_id:") + 11;
      size_t patientIdEnd = line.find(",", patientIdStart);
      int patientId = stoi(line.substr(patientIdStart, patientIdEnd - patientIdStart));

      size_t doctorNameStart = line.find("doctor_name:") + 12;
      size_t doctorNameEnd = line.find(",", doctorNameStart);
      string doctorName = line.substr(doctorNameStart, doctorNameEnd - doctorNameStart);

      size_t doctorIdStart = line.find("doctor_id:") + 10;
      size_t doctorIdEnd = line.find("}", doctorIdStart);
      int doctorId = stoi(line.substr(doctorIdStart, doctorIdEnd - doctorIdStart));

      a.setPatientName(patientName);
      a.setPatientId(patientId);
      a.setDoctorName(doctorName);
      a.setDoctorId(doctorId);

      appointments.push_back(a);
    }
  }
  file.close();
}

int main()
{
  vector<Patient> patients;
  vector<Doctor> doctors;
  vector<Appointment> appointments;

  // Load data from files at startup
  loadPatients(patients);
  loadDoctors(doctors);
  loadAppointments(appointments);

  int choice;

  do
  {
    cout << "\n--- Hospital Management System ---\n";
    cout << "1. Register Patient\n";
    cout << "2. Register Doctor\n";
    cout << "3. Book Appointment\n";
    cout << "4. Display Patients\n";
    cout << "5. Display Doctors\n";
    cout << "6. Display Appointments\n";
    cout << "0. Exit\n";
    cout << "Enter Choice: ";
    cin >> choice;

    if (choice == 1)
    {
      Patient p;
      p.input(getNextPatientId(patients));
      patients.push_back(p);
      savePatients(patients);
    }

    else if (choice == 2)
    {
      Doctor d;
      d.input(getNextDoctorId(doctors));
      doctors.push_back(d);
      saveDoctors(doctors);
    }

    else if (choice == 3)
    {
      string pname;
      cout << "Enter Patient Name: ";
      cin.ignore();
      getline(cin, pname);

      Patient *foundPatient = nullptr;
      for (auto &p : patients)
      {
        if (p.getName() == pname)
        {
          foundPatient = &p;
          break;
        }
      }

      if (!foundPatient)
      {
        cout << "Patient not registered. Register first.\n";
        continue;
      }

      cout << "\n--- Available Doctors ---\n";
      if (doctors.empty())
      {
        cout << "No doctors available.\n";
        continue;
      }
      for (auto &d : doctors)
      {
        cout << "ID: " << d.getId() << " - Name: " << d.getName() << "\n";
      }
      cout << "------------------------\n";

      int did;
      cout << "Enter Doctor ID: ";
      cin >> did;

      Doctor *foundDoctor = nullptr;
      for (auto &d : doctors)
      {
        if (d.getId() == did)
        {
          foundDoctor = &d;
          break;
        }
      }

      if (!foundDoctor)
      {
        cout << "Doctor not belong to our hospital.\n";
        continue;
      }

      Appointment a;
      a.book(*foundPatient, *foundDoctor);
      appointments.push_back(a);
      saveAppointments(appointments);

      cout << "Appointment Booked Successfully.\n";
    }

    else if (choice == 4)
    {
      if (patients.empty())
        cout << "\nThere is no records of Patients.\n";
      else
        for (auto &p : patients)
          p.display();
    }

    else if (choice == 5)
    {
      if (doctors.empty())
        cout << "\nThere is no records of Doctors.\n";
      else
        for (auto &d : doctors)
          d.display();
    }

    else if (choice == 6)
    {
      if (appointments.empty())
        cout << "\nThere is no records of Appointments.\n";
      else
        for (auto &a : appointments)
          a.display();
    }

  } while (choice != 0);

  return 0;
}