# **Hospital-Management-Project**

## Participants:

  1. Abineth 
  2. Aashay

A Console program is an Object-Oriented Approach written in C++ to implement Hospital Management
 System which monitors:

    1. Status of Active Patients
    2. List of Doctors according to their specialization
    3. Record of Patients includiing
        3.1 Patients who left
        3.2 Existing Patients
        3.3 Patients whose appointment is to be confirmed
    4. Medicine Status.

  _This console application serves as an admin control to the privileged user
  of the hospital who wants to apply changes as an admin and also the local users 
  i.e. the patients who want to fix an appointment with the required doctor
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
       5. Create Temp.dat, Doctor.dat, patient.dat, Receptionist.dat, NurseInfo.dat
       6. DONE
       
### **2. Explanation of Project**
    This project is based on Object-Oriented Programming 
    The aim of this code is to apply oops concept to reduce, reuse and
    encapsulate it to improve the efficiency.

__*Class Structure of Project:*__

    1. It Consist of 7 classes which are divided into two categories - a Staff person and a Normal Person.
    2. A Staff Member class has the authority of making changes in the project.
    3. Staff class is inherited from Person class and have some additional features
 
        classes which inherit the staff members are
            Doctor
            Nurse
            Receptionist
    4. Next is the Patient class which is Derived from Person class and later Admin class 
       for displaying the staff menu of the Project.

__*Record Storing of Staff and Patients:*__

    This project contains five files which store data in the binary format with the 
    extension .dat . So make sure to create this file inside the same directory as the 
    code file(with .cpp extension).

    patient.dat stores the active number of patient with their required id and delete
    the inactive one. It helps to create bill of patient and keep valid record for 
    them.

    Doctor.dat stores the record of all doctors with their working hours and their
    specialization in different fields for the better understanding of the people.

    Receptionist.dat stores the name of receptionist who controlls most of the task in 
    the project.

    Temp.dat is a temporary binary file which is used for the deletion of a particular 
    patient record.
    
    NurseInfo.dat stores the personal info of the nurse and also their working hours.

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

    After that you would be eligible to use the diffrent functionality of the 
    members or take an appointment for the required doctor if available.

### **4. UML Diagram of Project**

![miniproj](https://user-images.githubusercontent.com/97591189/206441425-8233acf8-488c-4a7d-a20f-462e3028e8e9.png)

### **5. Output**


![2022-12-08 (14)](https://user-images.githubusercontent.com/98078409/206648815-320bd8b9-f37f-47e5-bf22-5b0e02f0e03b.png)

![2022-12-09 (1)](https://user-images.githubusercontent.com/98078409/206648498-e4727d2e-2e1f-43f9-8dcb-97dbe282ee26.png)

![2022-12-09 (2)](https://user-images.githubusercontent.com/98078409/206648967-3c5b6943-affc-4420-9cf8-0dc86924b4e9.png)

![2022-12-09 (4)](https://user-images.githubusercontent.com/98078409/206649256-53a27faf-8ad9-484c-923a-cdf076d3be0c.png)

![2022-12-09 (5)](https://user-images.githubusercontent.com/98078409/206649372-6f2bac95-694b-4de0-b91b-394ea5a7744d.png)

![2022-12-09 (6)](https://user-images.githubusercontent.com/98078409/206649520-00773ef7-bc14-47b9-a2a7-1adaa0519f12.png)

![2022-12-09 (7)](https://user-images.githubusercontent.com/98078409/206649717-40a1e3eb-0291-49ab-b297-4d0a2c48163f.png)

![2022-12-09 (8)](https://user-images.githubusercontent.com/98078409/206649880-1a02977c-2e9b-4705-b57d-bf5cd3c715b9.png)

![2022-12-09 (9)](https://user-images.githubusercontent.com/98078409/206649974-b8b63d1b-5989-4dba-a63d-a62a78043c9c.png)

![2022-12-09 (11)](https://user-images.githubusercontent.com/98078409/206650200-9d6a739d-8d93-4739-88f7-31e160739da0.png)

![2022-12-09 (12)](https://user-images.githubusercontent.com/98078409/206650323-a82122d2-a603-44a6-92d2-90828472b0f1.png)

![2022-12-09 (13)](https://user-images.githubusercontent.com/98078409/206650768-8e23e75b-12bc-4fbd-bc7f-a2e1167598d6.png)

![2022-12-09 (14)](https://user-images.githubusercontent.com/98078409/206650810-4a10f7f7-6c2d-43c1-a8ef-8dda4bc6164a.png)

![2022-12-09 (15)](https://user-images.githubusercontent.com/98078409/206650895-8821bcae-45af-427f-904d-7182499175b5.png)

![2022-12-09 (16)](https://user-images.githubusercontent.com/98078409/206650966-23c22411-c4b9-476c-9f18-dc674d474d95.png)

![2022-12-09 (17)](https://user-images.githubusercontent.com/98078409/206651217-18d06e2e-0a24-4778-aca9-33adb752ac3b.png)

![2022-12-09 (18)](https://user-images.githubusercontent.com/98078409/206651252-df35e395-be6e-4ed4-b7fd-6117cbec206b.png)

![2022-12-09 (19)](https://user-images.githubusercontent.com/98078409/206651266-e6da02e0-7931-400e-b9a2-acf21921429f.png)

![2022-12-09 (20)](https://user-images.githubusercontent.com/98078409/206651301-3b4552b6-9370-40da-9b1a-60933df60abf.png)

![2022-12-09 (21)](https://user-images.githubusercontent.com/98078409/206651325-542f70e7-71b5-4332-82b9-82b94633dc39.png)

![2022-12-09 (22)](https://user-images.githubusercontent.com/98078409/206651339-636b757b-4053-44ba-888e-4e3ec7efb63f.png)

![2022-12-09 (23)](https://user-images.githubusercontent.com/98078409/206651367-ffee7b53-3636-4c96-8166-3027912da9b1.png)

![2022-12-09 (24)](https://user-images.githubusercontent.com/98078409/206651395-83193758-1ffb-40c0-b537-bc32114cb1cf.png)

![2022-12-09 (25)](https://user-images.githubusercontent.com/98078409/206651150-c899d5bd-f843-44a9-8e7f-bb2504630af4.png)

![2022-12-09 (37)](https://user-images.githubusercontent.com/98078409/206669386-51bdfd61-468d-4bc9-ae61-3b206ada9c14.png)

![2022-12-09 (38)](https://user-images.githubusercontent.com/98078409/206669605-bc2e5fd2-5827-439f-98a9-2b4547d3d890.png)

![2022-12-09 (39)](https://user-images.githubusercontent.com/98078409/206669693-69df9bd9-e0a0-42e2-bc51-39e930a37915.png)

![2022-12-09 (40)](https://user-images.githubusercontent.com/98078409/206669781-630312df-ff8f-453e-9d1c-04d0de2c94cf.png)

![2022-12-09 (41)](https://user-images.githubusercontent.com/98078409/206669878-cc539337-7359-43c3-b8db-6ef245a9013b.png)
