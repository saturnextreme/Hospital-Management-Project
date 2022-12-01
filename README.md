# **Hospital-Management-Project**

A Console program is an Object-Oriented Approach written in C++ to implement Hospital Management
 System which monitors:

    1. Status of Active Patients
    2. List of Doctors according to their specialization
    3. Record of Patients includiing
        3.1 Patients who left
        3.2 Existing Patients
        3.3 Patient whose appointment to be confirmed
    4. Medicine Status.

  _This console application serves as an admin control to the privilaged user
  of the hospital who want to apply changes as an admin and also the local users 
  i.e. the patients who want to fix an appointement with the required doctor.
  to get their checkup done._
  

## _**Table of Content:**_
    1. How to install and run the project
    2. Explanation of Project
    3. Tutorial of project
    
    
### **1. How to install and run the project**

       1. Open the Github Page where project is located
       2. On top right corner click code button
       3. Copy HTTPS link 
       4. use command ' git clone copiedlink '
       5. Create Temp.dat, Doctor.dat, patient.dat, Receptionist.dat
       6. DONE
       
### **2. Explanation of Project**
    This project is based on Object-Oriented Programming 
    The aim of this code is to apply oops concept to reduce, reuse and
    encapsulate it for improver efficiency

__*Class Structure of Project:*__

    1. It Consist of 7 classes which are divded on two categories a Staff person and a Normal Person.
    2. A Staff Member class has the authority of making changes in the project.
    3. Staff class is inherited from Person class and have some additional features
 
        classes which inherit the staff members are
            Doctors 
            Nurse
            Receptionist
    4. Next is the Patient which is Derived from Person class and later Admin which 
        shows the Index page of Project.

__*Record Storing of Staff and Patients:*__

    This project contains four files which store data in the binary format with the 
    extension .dat . So make sure to create this file inside the same directory as the 
    code file(with .cpp extension).

    patient.dat stores the active number of patient with their required id and deleted 
    the inactive one.It helps to create bill of patient and keep valid record for 
    them.

    Doctor.dat stores the record of all doctors with their working house and their
    specialization in diffrent fields for better understandment of the people.

    Receptionist.dat stores the name of receptionist who controlls most of the task in 
    the project.

### **3. Tutorial of Project**

    After Compiling the program on terminal or command prompt using command 
    (g++ main.cpp -o main) in the same directory as of the code file.

    Run the file using command (./main) to start execution.

    It will give you a Command line Interface asking you for your status as : 

        Admin
        Receptionist
        Doctor 
        Exit
    
    Based on the choice it will ask you for a password verification.

    After that you would be elegible to use the diffrent functionality of the 
    members or take an appointment for the required doctor if availabel




    

                
    
