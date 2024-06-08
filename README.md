# DoctorAppointmentSystem
Explanation
Classes:

Doctor: Represents a doctor with an ID, name, and specialty.
Patient: Represents a patient with an ID, name, and age.
Appointment: Represents an appointment with an ID, doctor, patient, date, and time.
AppointmentSystem: Manages the doctors, patients, and appointments.
Methods:

addDoctor: Adds a doctor to the system.
addPatient: Adds a patient to the system.
bookAppointment: Books an appointment for a patient with a doctor on a specified date and time.
viewAppointments: Displays all booked appointments.
Usage
Compile the code using a C++ compiler (e.g., g++ DoctorAppointmentSystem.cpp -o DoctorAppointmentSystem).
Run the compiled program (./DoctorAppointmentSystem).
The example provided will add two doctors, two patients, book two appointments, and then display the booked appointments.
This is a basic implementation to get you started. You can expand it by adding more features such as:

Error handling for invalid inputs.
Removing doctors, patients, and appointments.
Persistent storage (using files or a database).
A graphical user interface (GUI) using libraries like Qt or a web interface using frameworks like Flask (with a C++ backend).
