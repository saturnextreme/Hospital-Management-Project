#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

class Person
{
    char name[100], gender[100];
    int age, date, month, year;
    long long phone_num;
    int zip_code, person_ID;
    char city[100], country[100], state[100], blood_group[100];

public:
    void personInfo()
    {
        cout << "\nEnter Name :\n";
        cin.clear();
        cin.ignore();
        cin.getline(name,100);
        cout << "Enter Gender :\n";
        cin >> gender;
        cout << "Enter age :\n";
        cin >> age;
        cout << "Enter Phone Number:\n";
        cin >> phone_num;
        cout << "Enter Address (country state city zip_code):\n";
        cin >> country >> state >> city >> zip_code;
        cout << "Enter Blood group:\n";
        cin.ignore();
        cin.getline(blood_group,100);
    }

    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Phone Number: " << phone_num << endl;
        cout << "Address: " << this->country << " " << this->state << " " << this->city << " " << this->zip_code << " " << endl;
        cout << "Blood Group:" << blood_group << endl;
    }
};

class Staff : public Person
{
    int salary;
    char time_from[100], time_to[100];

public:
    void staffInfo()
    {
        personInfo();
        cout << "Enter salary:";
        cin >> salary;
        cout << "\nEnter Duty time!";
        cout << "\nFrom: ";
        cin >> time_from;
        cout << "\nTo: ";
        cin >> time_to;
    }

    void showStaff()
    {
        cout << "\nSalary: " << salary;
        cout << "\nDuty Time: " << time_from << " -- " << time_to << endl;
        displayInfo();
    }
};

class Patient : public Person
{
    int reg_no;
    char occupation[100];
    char problem[100];
    char date_admit[100];
    char date_discharge[100];
    int bill, total;

public:
    char medicine[100];
    void patientBill() 
    {
        system("CLS");
        cout << "********************************************************************************";
        cout << "\n\n\t\t\t\tPatient Fee Charge\n\n ";
        cout << "*******************************************************************************";
        cout << "\nHospital Room Charges                      :\t  1000";
        cout << "\nHospital Care Charges                      :\t  50";
        cout << "\nHospital Maintaince Charges                :\t  50";
        cout << "\nPatient Individual  Charges                :\t " << bill;
        total = 1000 + 50 + 50 + bill;
        cout << "\nTotal Fee Charge                           :\t" << total << "\n";
        cout << "********************************************************************************";
    }

    void getData()
    {

        personInfo();
        cout << "\nEnter The registration number of the Patient: ";
        cin >> reg_no;
    
        cout << "\nEnter The occupation of the Patient: ";
        cin.ignore();
		cin.getline(occupation,100);
        cout << "\nEnter The problem of the Patient: ";
		cin >> problem;
        cout << "\nEnter The bill of the Patient:";
        cin >> bill;
        cout << "\nEnter The date admitted(dd/mm/yyyy):";
        cin.ignore();
		cin.getline(date_admit,100);
        cout << "\nEnter The date discharged(dd/mm/yyyy):";
		cin >> date_discharge;
        patientBill();
        strncpy(medicine, "null", sizeof(medicine) - 1);
        medicine[sizeof(medicine) - 1] = 0;
    }

    void showData()
    {
        cout << "\nRegistration number of Patient: " << reg_no << "\n";
        displayInfo();
        cout << "\nProblem : " << problem;
        cout << "\nOccupation : " << occupation;
        cout << "\nAdmit date : " << date_admit;
        cout << "\nDischarge date :" << date_discharge;
        cout << "\nBill :" << total;
        cout << "\nPrescribed Medicine: " << medicine;
    }

    int returnRegNo()
    {
        return reg_no;
    }

    void modifyMedicine(int n)
    {
        bool found = false;
        Patient p;
        fstream File;
        File.open("patient.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        while (!File.eof() && found == false)
        {

            File.read(reinterpret_cast<char *>(&p), sizeof(Patient));
            if (p.returnRegNo() == n)
            {
                p.showData();
                cout << "\n\nPlease Enter The Medicine of Patient" << endl;
                cin >> p.medicine;
                int pos = (-1) * static_cast<int>(sizeof(p));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char *>(&p), sizeof(Patient));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record Not Found ";
        cin.ignore();
        cin.get();
    }

    void writePatient() // writing into file
    {
        Patient p;
        ofstream outFile;
        outFile.open("patient.dat", ios::binary | ios::app);
        p.getData();
        outFile.write(reinterpret_cast<char *>(&p), sizeof(Patient));
        outFile.close();
        cout << "\n\nPatient record Has Been Created ";
        cin.ignore();
        cin.get();
    }

    void displayAllPatients() // reading from file
    {
        Patient p;
        ifstream inFile;
        inFile.open("patient.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
        while (inFile.read(reinterpret_cast<char *>(&p), sizeof(Patient)))
        {
            p.showData();
            cout << "\n\n=======================================================================================\n";
        }
        inFile.close();
        cin.ignore();
        cin.get();
    }

    void displaySpecificPatient(int n) // reading specific file
    {
        Patient p;
        ifstream inFile;
        inFile.open("patient.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        bool flag = false;
        while (inFile.read(reinterpret_cast<char *>(&p), sizeof(Patient)))
        {
            if (p.returnRegNo() == n)
            {
                p.showData();
                flag = true;
            }
        }
        inFile.close();
        if (flag == false)
            cout << "\n\nrecord not exist";
        cin.ignore();
        cin.get();
    }

    void modifyPatient(int n) // modifying patient details
    {
        bool found = false;
        Patient p;
        fstream File;
        File.open("patient.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        while (!File.eof() && found == false)
        {

            File.read(reinterpret_cast<char *>(&p), sizeof(Patient));
            if (p.returnRegNo() == n)
            {
                p.showData();
                cout << "\n\nPlease Enter The New Details of Patient" << endl;
                p.getData();
                int pos = (-1) * static_cast<int>(sizeof(p));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char *>(&p), sizeof(Patient));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record Not Found ";
        cin.ignore();
        cin.get();
    }

    void deletePatient(int n) // deleting a particular file
    {
        Patient p;
        int pos,flag = 0;
        ifstream inFile;
        inFile.open("patient.dat", ios::in | ios::binary);
        ofstream outFile;
        outFile.open("Temp.dat", ios::out | ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
		while(!inFile.eof())
		{
			inFile.read((char*)this, sizeof(Patient));
			if(inFile)
			{
				if(n == this->reg_no)
				{
					flag = 1;
					sleep(2);
					cout << "\nRecord Deleted!!\n";
				}
				else
				{
					outFile.write((char*)this, sizeof(Patient));
				}
			}
		}
		outFile.close();
		inFile.close();
		
		remove("patient.dat");
		rename("Temp.dat","patient.dat");
		
		if(flag == 1)
		{
			sleep(2);
			cout << "\nRecord deleted successfully!!\n";
			sleep(2);
		}
		else
		{
			sleep(2);
			cout << "\nRecord not found!!\n";
			sleep(2);
		}
        
    }
};

class Doctor : public Staff
{
    int DocID;
    Patient p;
    char Spz[100];

public:
    bool checkRegNo(int n)
    {

        bool found = false;
        Doctor d;
        fstream File;
        File.open("Doctor.dat", ios::binary | ios::in);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
        }
        while (!File.eof() && found == false)
        {

            File.read(reinterpret_cast<char *>(&d), sizeof(Doctor));
            if (d.DocID == n)
            {
                found = true;
            }
        }
        File.close();
        return found;
        cin.ignore();
        cin.get();
    }

    void doctorInfo()
    {
        staffInfo();
    id:
        cout << "Enter Doctor ID(1200-1299):";
        int m;
        cin >> m;
        if (checkRegNo(m) == false)
        {
            DocID = m;
        }
        else
        {
            cout << "ID already taken\n";
            goto id;
        }

        cout << "Enter Doctor Specialize :";
        cin.ignore();
        cin.getline(Spz,100);
        system("pause");
    }

    void showDoctor()
    {
        cout << "Doctor ID: " << DocID;
        showStaff();

        cout << "\nDoctor Specialize: " << Spz;
    }

    int returnDoctorId()
    {
        return DocID;
    }

    void prescribeMedicine()
    {
        int n;
        cout << "\n\n\tEnter Reg Number Of Patient : ";
        cin >> n;
        p.modifyMedicine(n);
    }

    void writeDoctor()
    {
        Doctor d;
        ofstream outFile;
        outFile.open("Doctor.dat", ios::binary | ios::app);
        d.doctorInfo();
        outFile.write(reinterpret_cast<char *>(&d), sizeof(Doctor));

        cout << "\n\nDoctor record Has Been Created ";
        outFile.close();
        cin.ignore();
    }

    void displayAllDoctor()
    {
        Doctor d;
        ifstream inFile;
        inFile.open("Doctor.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
        while (inFile.read(reinterpret_cast<char *>(&d), sizeof(Doctor)))
        {
            d.showDoctor();
            cout << "\n\n=======================================================================================\n";
        }
        inFile.close();
        cin.ignore();
        cin.get();
    }

    void displaySpecificDoctor(int n)
    {
        Doctor d;
        ifstream inFile;
        inFile.open("Doctor.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        bool flag = false;
        while (inFile.read(reinterpret_cast<char *>(&d), sizeof(Doctor)))
        {
            if (d.DocID == n)
            {
                d.showDoctor();
                flag = true;
            }
        }
        inFile.close();
        if (flag == false)
            cout << "\n\nrecord not exist";
        cin.ignore();
        cin.get();
    }

    void modifyDoctor(int n)
    {
        bool found = false;
        Doctor d;
        fstream File;
        File.open("Doctor.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        while (!File.eof() && found == false)
        {

            File.read(reinterpret_cast<char *>(&d), sizeof(Doctor));
            if (d.DocID == n)
            {
                d.showDoctor();
                cout << "\n\nPlease Enter The New Details:" << endl;
                d.doctorInfo();
                int pos = (-1) * static_cast<int>(sizeof(d));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char *>(&d), sizeof(Doctor));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record Not Found ";
        cin.ignore();
        cin.get();
    }

    void doctorChoice()
    {
        char ch;

        do
        {
            int n;
            system("cls");

            cout << "\n\n\t01. Prescribe Medicine for Patient ";
            cout << "\n\n\t02. Search DOCTOR ";
            cout << "\n\n\t03. To exit.....";
            cout << "\n\n\tPlease Select Your Option (1-3) ";
            cin >> ch;

            switch (ch)
            {
            case '1':
                prescribeMedicine();
                break;
            case '2':
                cout << "Enter Doctor ID :";
                cin >> n;
                displaySpecificDoctor(n);
                break;
            case '3':
                break;
            default:
                cout << "\b";
            }
        } while (ch != '3');
    }

    void doctorMenu()
    {
        char ch;

        do
        {
            int n;
            system("cls");

            cout << "\n\n\t01. INSERT DOCTOR DATA";
            cout << "\n\n\t02. Search DOCTOR ";
            cout << "\n\n\t03. ALL DOCTOR ";
            cout << "\n\n\t04. MODIFY DOCTOR DATA";
            cout << "\n\n\t05. TO EXIT............";
            cout << "\n\n\tPlease Select Your Option (1-5) ";
            cin >> ch;
            system("cls");
            switch (ch)
            {
            case '1':
                writeDoctor();
                break;
            case '2':
                cout << "Enter Doctor ID :";
                cin >> n;
                displaySpecificDoctor(n);
                break;

            case '3':

                displayAllDoctor();
                break;
            case '4':
                cout << "Enter Doctor ID :";
                cin >> n;
                modifyDoctor(n);
                break;
                /*case '5':break;
                default :cout<<"\b";*/
            }
        } while (ch != '5');
    }
};

class Nurse : public Staff
{

    int NurseID;
    char ChargeRoom[100];
    Patient p;

public:
    void getNurseInfo()
    {

        cout << "--------------------------------" << endl;
        staffInfo();
        cout << "Enter Nurse ID:";
        cin >> NurseID;
        cout << "Enter Nurse Duty Room :";
        cin.ignore();
        cin.getline(ChargeRoom,100);
    }

    void displayNurseInfo()
    {
        cout << "--------------------------------" << endl;
        cout << "Nurse ID :" << NurseID;
        showStaff();

        cout << "\n"
             << "Nurse in charge Room :" << ChargeRoom;
        cout << endl;
    }

    void writeNurseInfo()
    {
        Nurse n;
        ofstream outFile;
        outFile.open("NurseInfo.dat", ios::binary | ios::app);
        n.getNurseInfo();

        outFile.write(reinterpret_cast<char *>(&n), sizeof(Nurse));
        outFile.close();
        cout << "\n\nrecord Has Been Created ";
        cin.ignore();
        cin.get();
    }
    void displaySpecificNurse(int m)
    {
        Nurse n;
        ifstream inFile;
        inFile.open("NurseInfo.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        bool flag = false;
        while (inFile.read(reinterpret_cast<char *>(&n), sizeof(Nurse)))
        {
            if (n.NurseID == m)
            {
                n.displayNurseInfo();
                flag = true;
            }
        }
        inFile.close();
        if (flag == false)
            cout << "\n\nrecord does not exist";
        cin.ignore();
        cin.get();
    }

    void modifyNurse(int m)
    {
        bool found = false;
        Nurse n;
        fstream File;
        File.open("NurseInfo.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        while (!File.eof() && found == false)
        {

            File.read(reinterpret_cast<char *>(&n), sizeof(Nurse));
            if (n.NurseID == m)
            {
                n.displayNurseInfo();
                cout << "\n\nPlease Enter The New Details of nurse" << endl;
                n.getNurseInfo();
                int pos = (-1) * static_cast<int>(sizeof(n));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char *>(&n), sizeof(Nurse));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record does Not Found ";
        cin.ignore();
        cin.get();
    }

    void displayAllNurse()
    {
        Nurse n;
        ifstream inFile;
        inFile.open("NurseInfo.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
        while (inFile.read(reinterpret_cast<char *>(&n), sizeof(Nurse)))
        {
            n.displayNurseInfo();
            cout << "\n\n=======================================================================================\n";
        }
        inFile.close();
        cin.ignore();
        cin.get();
    }

    void nurseMenu()
    {
        char ch;

        do
        {
            int n;
            system("cls");

            cout << "\n\n\t01. INSERT NURSE DATA";
            cout << "\n\n\t02. Search NURSE ";
            cout << "\n\n\t03. ALL NURSE ";
            cout << "\n\n\t04. MODIFY NURSE DATA";
            cout << "\n\n\t05. To EXIT..........";
            cout << "\n\n\tPlease Select Your Option (1-5) ";
            cin >> ch;

            switch (ch)
            {
            case '1':
                writeNurseInfo();
                break;
            case '2':
                cout << "Enter NURSE ID :";
                cin >> n;
                displaySpecificNurse(n);
                break;

            case '3':

                displayAllNurse();
                break;
            case '4':
                cout << "Enter Nurse ID :";
                cin >> n;
                modifyNurse(n);
                break;
            }
        } while (ch != '5');
    }
};

class Receptionist : public Staff
{
    Patient p;
    int RecID;

public:
    void recInfo()
    {
        staffInfo();
        cout << "Enter Receptionist ID :";
        cin >> RecID;
    }

    void showReceptionist()
    {

        showStaff();

        cout << "Receptionist ID: " << RecID;
    }

    void entryPatient()
    {
        char ch;
        int num;
        do
        {
            system("cls");
            cout << "\n\n\n\tENTRY MENU";
            cout << "\n\n\t1.CREATE Patient RECORD";
            cout << "\n\n\t2.DISPLAY ALL PATIENTS RECORDS";
            cout << "\n\n\t3.SEARCH PATIENT RECORD ";
            cout << "\n\n\t4.MODIFY PATIENT RECORD";
            cout << "\n\n\t5.DELETE PATIENT RECORD";
            cout << "\n\n\t6.TO EXIT";
            cout << "\n\n\tPlease Enter Your Choice (1-6) ";
            cin >> ch;
            system("cls");

            switch (ch)
            {
            case '1':
                p.writePatient();
                break;
            case '2':
                p.displayAllPatients();
                break;
            case '3':
                cout << "\n\n\tPlease Enter The reg  number ";
                cin >> num;
                p.displaySpecificPatient(num);
                break;
            case '4':
                cout << "\n\n\tPlease Enter The reg number ";
                cin >> num;
                p.modifyPatient(num);
                break;
            case '5':
                cout << "\n\n\tPlease Enter The reg number ";
                cin >> num;
                p.deletePatient(num);
                break;
            }
        } while (ch != '6');
    }

    void writeReceptionist()
    {
        Receptionist r;
        ofstream outFile;
        outFile.open("Receptionist.dat", ios::binary | ios::app);
        r.recInfo();
        outFile.write(reinterpret_cast<char *>(&r), sizeof(Receptionist));
        outFile.close();
        cout << "\n\nReceptionist record Has Been Created ";
        cin.ignore();
        cin.get();
    }

    void displayAllReceptionist()
    {
        Receptionist r;
        ifstream inFile;
        inFile.open("Receptionist.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        cout << "\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
        while (inFile.read(reinterpret_cast<char *>(&r), sizeof(Receptionist)))
        {
            r.showReceptionist();
            cout << "\n\n=======================================================================================\n";
        }
        inFile.close();
        cin.ignore();
        cin.get();
    }

    void displaySpecificReceptionist(int n)
    {
        Receptionist r;
        ifstream inFile;
        inFile.open("Receptionist.dat", ios::binary);
        if (!inFile)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        bool flag = false;
        while (inFile.read(reinterpret_cast<char *>(&r), sizeof(Receptionist)))
        {
            if (r.RecID == n)
            {
                r.showReceptionist();
                flag = true;
            }
        }
        inFile.close();
        if (flag == false)
            cout << "\n\nrecord not exist";
        cin.ignore();
        cin.get();
    }

    void modifyReceptionist(int n)
    {
        bool found = false;
        Receptionist r;
        fstream File;
        File.open("Receptionist.dat", ios::binary | ios::in | ios::out);
        if (!File)
        {
            cout << "File could not be open !! Press any Key...";
            cin.ignore();
            cin.get();
            return;
        }
        while (!File.eof() && found == false)
        {

            File.read(reinterpret_cast<char *>(&r), sizeof(Receptionist));
            if (r.RecID == n)
            {
                r.showReceptionist();
                cout << "\n\nPlease Enter The New Details " << endl;
                r.recInfo();
                int pos = (-1) * static_cast<int>(sizeof(r));
                File.seekp(pos, ios::cur);
                File.write(reinterpret_cast<char *>(&r), sizeof(Receptionist));
                cout << "\n\n\t Record Updated";
                found = true;
            }
        }
        File.close();
        if (found == false)
            cout << "\n\n Record Not Found ";
        cin.ignore();
        cin.get();
    }

    void receptionistMenu()
    {
        char ch;

        do
        {
            int n;
            system("cls");

            cout << "\n\n\t01. INSERT Receptionist DATA";
            cout << "\n\n\t02. Search Receptionist ";
            cout << "\n\n\t03. ALL Receptionist ";
            cout << "\n\n\t04. MODIFY Receptionist DATA";

            cout << "\n\n\t05. To EXIT..........";
            cout << "\n\n\tPlease Select Your Option (1-5) ";
            cin >> ch;

            switch (ch)
            {
            case '1':
                writeReceptionist();
                break;
            case '2':
                cout << "Enter Receptionist ID :";
                cin >> n;
                displaySpecificReceptionist(n);
                break;

            case '3':

                displayAllReceptionist();
                break;
            case '4':
                cout << "Enter Receptionist ID :";
                cin >> n;
                modifyReceptionist(n);
                break;
            }
        } while (ch != '5');
    }
};

class Admin
{
    Doctor d;
    Patient p;
    Receptionist r;
    Nurse n;

public:
    void staffMenu()
    {
        char ch;
        do
        {
            system("cls");
            cout << "\n\n\tStaff Menu";
            cout << "\n\n\t1.Doctor";
            cout << "\n\n\t2.Nurse";
            cout << "\n\n\t3.Receptionist";
            cout << "\n\n\t4.TO EXIT";
            cout << "\n\n\tPlease Enter Your Choice (1-4) ";
            cin >> ch;
            system("cls");

            switch (ch)
            {
            case '1':
                d.doctorMenu();
                break;
            case '2':
                n.nurseMenu();
                break;
            case '3':
                r.receptionistMenu();
                break;
            }
        } while (ch != '4');
    }
};

int main()
{
    // unordered_set<char> reg_no_patient;
    Admin a;
    Receptionist r;
    Doctor d;
    int ch;
    string pass;
    do
    {
        cout << "\t\t\n\n\n";
        cout << "\t\t1.Admin\n";
        cout << "\t\t2.Receptionist\n";
        cout << "\t\t3.Doctor\n";
        cout << "\t\t4.Exit From The SYSTEM\n";
        cin >> ch;
        cin.ignore();

        switch (ch)
        {
        case 1:
        login1:
            cout << "Enter Admin password: \n";
            getline(cin, pass);

            if (pass == "admin")
            {
                a.staffMenu();
            }
            else
            {
                cout << "WRONG PASSWORD!!!\n";
                goto login1;
            }
            break;
        case 2:
        login2:
            cout << "Enter Receptionist password: \n";

            getline(cin, pass);

            if (pass == "receptionist")
            {
                r.entryPatient();
            }
            else
            {
                cout << "WRONG PASSWORD!!!\n";
                goto login2;
            }
            break;
        case 3:

        login3:
            cout << "Enter Doctor password: \n";
            getline(cin, pass);

            if (pass == "doctor")
            {
                d.doctorChoice();
            }
            else
            {
                cout << "WRONG PASSWORD!!!\n";
                goto login3;
            }
            break;
        }
	}
	while (ch != 4);
}
