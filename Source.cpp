#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Doctor {
public:
    int id;
    string name;
    string specialty;

    Doctor(int id, string name, string specialty) : id(id), name(name), specialty(specialty) {}
};

class Patient {
public:
    int id;
    string name;
    int age;

    Patient(int id, string name, int age) : id(id), name(name), age(age) {}
};

class Appointment {
public:
    int id;
    Doctor doctor;
    Patient patient;
    string date;
    string time;

    Appointment(int id, Doctor doctor, Patient patient, string date, string time)
        : id(id), doctor(doctor), patient(patient), date(date), time(time) {}
};

class AppointmentSystem {
private:
    vector<Doctor> doctors;
    vector<Patient> patients;
    vector<Appointment> appointments;
    int nextDoctorId;
    int nextPatientId;
    int nextAppointmentId;

public:
    AppointmentSystem() : nextDoctorId(1), nextPatientId(1), nextAppointmentId(1) {}

    void addDoctor(string name, string specialty) {
        doctors.push_back(Doctor(nextDoctorId++, name, specialty));
        cout << "Doctor added: " << name << ", Specialty: " << specialty << endl;
    }

    void addPatient(string name, int age) {
        patients.push_back(Patient(nextPatientId++, name, age));
        cout << "Patient added: " << name << ", Age: " << age << endl;
    }

    void bookAppointment(int doctorId, int patientId, string date, string time) {
        Doctor* doctor = findDoctorById(doctorId);
        if (!doctor) {
            cout << "Doctor ID not found." << endl;
            return;
        }

        Patient* patient = findPatientById(patientId);
        if (!patient) {
            cout << "Patient ID not found." << endl;
            return;
        }

        appointments.push_back(Appointment(nextAppointmentId++, *doctor, *patient, date, time));
        cout << "Appointment booked: Doctor " << doctor->name << ", Patient " << patient->name
            << ", Date: " << date << ", Time: " << time << endl;
    }

    void viewAppointments() {
        if (appointments.empty()) {
            cout << "No appointments booked." << endl;
            return;
        }

        for (const auto& appointment : appointments) {
            cout << "Appointment ID: " << appointment.id << ", Doctor: " << appointment.doctor.name
                << ", Patient: " << appointment.patient.name << ", Date: " << appointment.date
                << ", Time: " << appointment.time << endl;
        }
    }

private:
    Doctor* findDoctorById(int id) {
        for (auto& doctor : doctors) {
            if (doctor.id == id) {
                return &doctor;
            }
        }
        return nullptr;
    }

    Patient* findPatientById(int id) {
        for (auto& patient : patients) {
            if (patient.id == id) {
                return &patient;
            }
        }
        return nullptr;
    }
};

int main() {
    AppointmentSystem system;

    // Add doctors
    system.addDoctor("Dr. Smith", "Cardiology");
    system.addDoctor("Dr. Johnson", "Neurology");

    // Add patients
    system.addPatient("Alice", 30);
    system.addPatient("Bob", 40);

    // Book appointments
    system.bookAppointment(1, 1, "2024-06-10", "10:00 AM");
    system.bookAppointment(2, 2, "2024-06-11", "11:00 AM");

    // View appointments
    system.viewAppointments();

    return 0;
}
