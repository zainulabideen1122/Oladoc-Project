#include <iostream>
#include "./oladoc.h"
#include <fstream>
#include <string>
using namespace std;


void Recipt(double charges, double fine)
{
    cout << "\n         ************  RECIPT  **************\n";
    cout << "\n\tCharges\t|\tFine\t|\tTotal\n";
    cout << "\t" << charges << "\t|\t" << fine << "\t|\t" << charges + fine << "\n";
}

void exit()
{
    cout << "\n*************************** Good Bye ***************************\n";
    exit(3);
}
string toUpper(string str) //convert string to uppercase
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 97 && str[i] <= 122)
        {
            str[i] -= 32;
        }
    }

    return str;
}

int checkAvailability(int num, Doctor temp)
{
    Appointment extraTemp;
    int nStatus = 0;

    //nStatus = 0;

    ifstream myFile1("appointment.bin", ios::binary);
    while (myFile1.read((char*)&extraTemp, sizeof(extraTemp)))
    {
        if (extraTemp.getDoctorEmail() == temp.getEmail())
        {
            if (extraTemp.getStartTime() == num)
            {
                nStatus = 1;
                myFile1.close();
            }
        }
    }

    if (nStatus)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int DateToDays(Date date)
{
    int sum = 0;

    sum += date.getDay();
    sum += date.getMonth() * 30; // a month has 30 days
    sum += date.getYear() * 365; // a year has 365 days

    return sum;

}

int checkCNIC(User* user, string cnic)
{
    if (cnic.length() < 13 || cnic.length() > 13)
    {
        cout << "\n **** NOTE: Length of cnic must be of 13 **** \n";
        return 0;
    }
    else
    {
        if (user->giveSize() == "patient")
        {
            Patient temp;
            ifstream myFile("Patient.bin", ios::binary);
            while (myFile.read((char*)&temp, sizeof(temp))) {
                if (temp.getCNIC() == cnic)
                {
                    cout << "\n NOTE: **** This CNIC already exists **** \n";
                    return 0;
                }
            }
            myFile.close();
            return 1;
        }
        else
        {
            Doctor temp;
            ifstream myFile("Doctor.bin", ios::binary);
            while (myFile.read((char*)&temp, sizeof(temp))) {
                if (temp.getCNIC() == cnic)
                {
                    cout << "\n NOTE: **** This CNIC already exists **** \n";
                    return 0;
                }
            }
            myFile.close();
            return 1;
        }
    }
}


int checkEmail(User* user, string email)
{

    if (user->giveSize() == "patient")
    {
        Patient temp;
        ifstream myFile("Patient.bin", ios::binary);
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (temp.getEmail() == email)
            {
                cout << "\n NOTE: **** This CNIC already exists **** \n";
                return 0;
            }
        }
        myFile.close();
        return 1;
    }
    else
    {
        Doctor temp;
        ifstream myFile("Doctor.bin", ios::binary);
        while (myFile.read((char*)&temp, sizeof(temp))) {
            if (temp.getEmail() == email)
            {
                cout << "\n NOTE: **** This email already exists **** \n";
                return 0;
            }
        }
        myFile.close();
        return 1;
    }
}



//password checker
int passwordChecker(string pass, string re_pass)
{
    bool capitalLetter = false, smallLetter = false, specialLetter = false, numericLetter = false;
    if (pass == re_pass)
    {
        for (int i = 0; i < pass.length(); i++)
        {
            if ((pass[i] > 32 && pass[i] <= 47) || (pass[i] >= 58 && pass[i] <= 64) || (pass[i] >= 91 && pass[i] <= 96) || (pass[i] >= 123 && pass[i] <= 126))
            {
                specialLetter = true;

            }

            if (pass[i] >= 65 && pass[i] <= 90)
            {
                capitalLetter = true;

            }

            if (pass[i] >= 97 && pass[i] <= 122)
            {
                smallLetter = true;
            }

            if (pass[i] >= 48 && pass[i] <= 57)
            {
                numericLetter = true;
            }

        }

        if (capitalLetter && smallLetter && specialLetter && numericLetter && pass.length() >= 8)
        {
            return 1;
        }
        else
        {
            if (pass.length() < 8)
            {
                cout << "\n************ Password length must be greator than 8 ************\n";
            }
            else if (!capitalLetter)
            {
                cout << "\n************ Password must contain minimum of one capital letter ************\n";
            }
            else if (!smallLetter)
            {
                cout << "\n************ Password must contain minimum of one small letter ************\n";
            }
            else if (!specialLetter)
            {
                cout << "\n************ Password must contain minimum of one special letter ************\n";
            }
            else if (!numericLetter)
            {
                cout << "\n************ Password must contain minimum of one numeric letter ************\n";
            }

            return 0;
        }
    }
    else
    {
        cout << "Password didn't match, Please try again\n\n";
        return 0;
    }
}

User::User()/*:name(new char[20]), password(new char[20]),CNIC(new char[13]), email(new char[20]), gender(new char[10]), city()*/ {};
void User::Register()
{
    string userInput, userInput1;
    int userInputInt;
    cout << "\n******* REGISTERATION PANEL ************\n\n";
    getline(cin, userInput);
    cout << "Name: ";
    //getline(cin, this->name);
    getline(cin, userInput);
    strcpy(this->name, userInput.c_str());


    //getting password
    while (true)
    {
        cout << "\nNote: Password must be 8 characters long and the use of a minimum of one special character,uppercase, lowercase, and the numeric digit is a must.\n";
        cout << "Password : ";
        cin >> userInput;

        cout << "Re-enter Password: ";
        cin >> userInput1;

        int n = passwordChecker(userInput, userInput1);

        if (n)
        {
            //this->password = userInput;
            strcpy(this->password, userInput.c_str());

            break;
        }
    }

    cout << "CNIC: ";
    cin >> userInput;
    strcpy(this->CNIC, userInput.c_str());

    // ************************************************** CNIC COndition ??????????????? ( 13-digit , existance )

    cout << "Email: ";
    //cin >> this->email;
    cin >> userInput;
    strcpy(this->email, userInput.c_str());

    cout << "Age: ";
    cin >> this->age;

    cout << "Gender: \n";
    cout << "\t1- Male\n\t2- Female\n\t3- Other\n";
    cin >> userInputInt;

    switch (userInputInt)
    {
    case 1: strcpy(this->gender, "Male");
        break;
    case 2: strcpy(this->gender, "Female");
        break;
    case 3: strcpy(this->gender, "Other");
    }

    cout << "Phone Number: ";
    cin >> userInput;
    strcpy(this->phoneNo, userInput.c_str());

    cout << "City: ";
    //cin >> this->city;
    cin >> userInput;
    strcpy(this->city, userInput.c_str());

    //initially balance to 3000
    this->balance = 3000;

}
void User::Login(User* user)
{
    string email, pass;
    int status = 0;

    cout << "\n******* LOGIN PANEL ************\n\n";
    while (!status)
    {
        cout << "Enter your email: ";
        cin >> email;

        cout << "Enter your password: ";
        cin >> pass;

        if (user->retrieveByEmail(user, email) && user->retrieveByPassword(user, pass))
        {
            strcpy(this->email, email.c_str());
            strcpy(this->password, pass.c_str());
            this->loginStatus = true;
            cout << "\n*********** Login successfully, " << user->getName() << " **********" << endl << endl;
            break;
        }
        else
        {
            cout << "********** Wrong credentials, Please try again. **********\n";
        }


    }
}

Patient::Patient() {};
void Patient::Register()
{
    User::Register();
    //intially patient balance = 3000
}
void Patient::Login(User* user)
{
    User::Login(user);
}
void Patient::appointment(User* user, Appointment* appoint)
{

}



Doctor::Doctor() {};
void Doctor::Register()
{
    User::Register();
    int userInputInt, userInputInt1;
    while (true)
    {
        cout << "\tAvailability hours (24-hour format): \n";

        cout << "Start Time: ";
        cin >> userInputInt;
        cout << "End Time: ";
        cin >> userInputInt1;

        this->setAvailability(userInputInt, userInputInt1);
        this->availability.increaseTimeCounter();
        cout << "\n Want to add more avialable hours?\n\t1- Yes\n\t2- No\n\t3- Exit\n > ";
        cin >> userInputInt;
        if (userInputInt == 2)
        {
            break;
        }
        else if (userInputInt == 3)
        {
            exit();
        }
    }


    cout << "Year of experience: ";
    cin >> this->yearOfExperience;

    string userInput;
    cout << "Specialization: ";
    cin >> userInput;
    strcpy(this->specilization, userInput.c_str());

    cout << "Hospital Name: ";
    cin >> userInput;
    strcpy(this->hospitalName, userInput.c_str());

    cout << "Hourly Rate: ";
    cin >> this->hourlyRate;
}
void Doctor::Login(User* user)
{
    User::Login(user);
}

void Doctor::appointment(User* user, Appointment* appoint)
{

}



Admin::Admin() {};
Admin::Admin(string name, string email, string pass, string cnic)
{
    strcpy(this->name, name.c_str());
    strcpy(this->email, email.c_str());
    strcpy(this->password, pass.c_str());
    strcpy(this->CNIC, cnic.c_str());
    this->age = 20;
    strcpy(this->gender, "");
    strcpy(this->phoneNo, "");
    strcpy(this->city, "");
    this->balance = 0;
};

void Admin::Login(User* user)
{
    User::Login(user);
}



Oladoc::Oladoc() {};
void Oladoc::startUp(User* user)
{
    this->user = user;
    if (user != NULL)
    {
        int userInput;

        if (user->giveSize() != "admin")
        {
            cout << "\t1- Register\n\t2- Login\n\t3- Reset Password\n\t4- Exit\n\t> ";
            cin >> userInput;

            if (userInput == 1)
            {
                user->Register();
                user->insertUser(user);
                cout << "\n*********** Congrats " << user->getName() << ", you are registered successfully. ***********\n\n";
                //user->retrieveAllUsers(user);
                cout << endl << endl;

                cout << "Do you want to Login?\n1-Yes\n2-No\n >";
                cin >> userInput;

                if (userInput == 1)
                {
                    user->Login(user);
                    this->Menu();
                }
                else if (userInput == 2)
                {
                    Oladoc::startUp(user);
                }

            }
            else if (userInput == 2)
            {
                user->Login(user);
                this->Menu();
                //user->retrieveAllUsers(user);
            }
            else if (userInput == 3)
            {
                string userInput, userInput1, email;
                while (true)
                {
                    while (true)
                    {
                        cout << "Enter the email to reset your password: ";
                        cin >> email;

                        int n = user->retrieveByEmail(user, email);
                        if (n)
                        {
                            break;
                        }
                        else
                        {
                            cout << "This email doesnot exist, please try again with different email address!\n\n";
                        }
                    }

                    cout << "Enter new Password : ";
                    cin >> userInput;

                    cout << "Re-enter new Password: ";
                    cin >> userInput1;

                    int n = passwordChecker(userInput, userInput1);

                    if (n)
                    {
                        //this->password = userInput;
                        //strcpy(this->password, userInput.c_str());

                        user->paswordReset(user, email, userInput);
                        break;
                    }
                }

                user->Login(user);
                this->Menu();
            }
            else if (userInput == 4)
            {
                exit();
            }
        }
        else
        {
            cout << "\t1- Login\n\t2- Exit\n\t> ";
            cin >> userInput;
            if (userInput == 1)
            {
                //adding predefine admins
                Admin admin1("Zain Ul Abideen", "zain@gmail.com", "Zain@123", "3740575146385");

                User* temp1;
                temp1 = &admin1;

                user->insertUser(temp1);

                user->Login(user);
                this->Menu();
                //user->retrieveAllUsers(user);
            }
            else if (userInput == 2)
            {
                exit();
            }
        }


        //delete user;
    }
}
void Oladoc::Menu()
{
    if (user->giveSize() == "patient")
    {
        while (true)
        {
            int userChoice, userInputInt;
            string userInput, userInput1;
            cout << "1- Reset Password\n2- Recharge Account\n3- Search Doctor\n4- Check Doctor's availability and charges\n5- Book/Update/Cancel appointment\n6- Show profile\n7- Update Profile\n8- Show scheduled appointments and their status\n9- Show Balance\n10- Complete an appointment\n11- Exit\n\n > ";
            cin >> userChoice;

            if (userChoice == 1)
            {

                while (true)
                {
                    cout << "Enter new Password : ";
                    cin >> userInput;

                    cout << "Re-enter new Password: ";
                    cin >> userInput1;

                    int n = passwordChecker(userInput, userInput1);

                    if (n)
                    {
                        //this->password = userInput;
                        //strcpy(this->password, userInput.c_str());
                        user->paswordReset(user, user->getEmail(), userInput);
                        break;
                    }
                }
            }
            else if (userChoice == 2)
            {
                cout << "Enter the amount: ";
                cin >> userInputInt;


                user->rechargeAccount(user, user->getEmail(), userInputInt);
                cout << "\n *** Recharge account Successfully! ***\n\n";
                cout << "\tYour new balance is:  " << user->getBalance() << endl << endl;
            }
            else if (userChoice == 3)
            {
                cout << "\t1- Search by specialization\n\t2- Search by Area\n\t3- Search by Hospital Name\n\t4- Back \n\n > ";
                cin >> userInputInt;

                if (userInputInt == 1)
                {
                    cout << "Enter specialization: ";
                    cin >> userInput;

                    cout << "\n **** Available doctors having specialization in " << userInput << " are ****\n\n";
                    this->searchDoctorsBySpecialization(user, userInput);
                    cout << endl;
                }
                else if (userInputInt == 2)
                {
                    cout << "Enter Area: ";
                    cin >> userInput;

                    cout << "\n **** Available doctors are available in " << userInput << " ****\n\n";
                    this->searchDoctorsByArea(user, userInput);
                    cout << endl;
                }
                else if (userInputInt == 3)
                {
                    cout << "Enter Hospital Name: ";
                    cin >> userInput;

                    cout << "\n **** Available doctors from " << userInput << " hospital are ****\n\n";
                    this->searchDoctorsByHospital(user, userInput);
                    cout << endl;
                }
                else if (userInputInt == 4)
                {
                    cout << endl;
                    Menu();
                }
            }
            else if (userChoice == 4)
            {
                cout << "\n\n**********************  Here are the list of Doctors with available hours and hourly fees: ******************\n\n";
                Doctor temp;
                Appointment extraTemp;
                int num, nStatus;
                ifstream myFile("Doctor.bin", ios::binary);
                while (myFile.read((char*)&temp, sizeof(temp))) {
                    cout << "\n\tName: " << temp.getName() << "\n\tCNIC: " << temp.getCNIC() << "\n\tEmail: " << temp.getEmail() << "\n\tAvailability hours: \n";
                    //temp.getAvailability().display();
                    for (int i = 0; i < temp.getAvailability().getTimeCounter(); i++)
                    {

                        num = temp.getAvailability().getStartTime(i);

                        nStatus = checkAvailability(num, temp);


                        cout << "\t\t" << i + 1 << "-  " << temp.getAvailability().getStartTime(i) << "-" << temp.getAvailability().getEndTime(i);
                        if (nStatus)
                        {
                            cout << " ( Booked ) ";
                        }
                        cout << endl;
                    }
                    cout << "\tCharges: " << temp.getHourlyRate() << "\n\tSpecialization: " << temp.getSpecialization() << "\n\tHospital Name: " << temp.getHospitalName() << "\n\tCity: " << temp.getCity() << "\n\n\n";
                }
                myFile.close();
            }
            else if (userChoice == 5)
            {
                cout << "\t1- Book an Apointment\n\t2- Update an appointment\n\t3- Cancel an appointment\n\t > ";
                cin >> userInputInt;

                if (userInputInt == 1)
                {
                    cout << "\n\n****************************  Here are the list of Doctors with available hours and hourly fees: *************************\n\n";
                    Doctor temp;
                    Appointment extraTemp;
                    int availabilityArr[20]{}, availArrCount = 0;
                    int num, nStatus;
                    Doctor* tempp = NULL;
                    ifstream myFile("Doctor.bin", ios::binary);
                    while (myFile.read((char*)&temp, sizeof(temp))) {
                        cout << "\n\tName: " << temp.getName() << "\n\tEmail: " << temp.getEmail() << "\n\tAvailability hours: \n";
                        for (int i = 0; i < temp.getAvailability().getTimeCounter(); i++)
                        {
                            //nStatus = 0;
                            num = temp.getAvailability().getStartTime(i);

                            nStatus = checkAvailability(num, temp);

                            cout << "\t\t" << i + 1 << "-  " << temp.getAvailability().getStartTime(i) << "-" << temp.getAvailability().getEndTime(i);
                            if (nStatus)
                            {
                                cout << " ( Booked ) ";
                            }
                            cout << endl;
                        }

                        cout << "\tCharges: " << temp.getHourlyRate() << "\n\tSpecialization: " << temp.getSpecialization() << "\n\tHospital Name: " << temp.getHospitalName() << "\n\tCity: " << temp.getCity() << "\n\n\n";
                    }
                    myFile.close();

                    cout << "Enter the doctor email to appoint that doctor: ";
                    cin >> userInput;
                    cout << "Time slot (Enter only startTime) : ";
                    cin >> userInputInt;

                    Doctor temp2;
                    ifstream myFile1("Doctor.bin", ios::binary);
                    while (myFile1.read((char*)&temp2, sizeof(temp2)))
                    {
                        availArrCount = 0;
                        if (temp2.getEmail() == userInput)
                        {


                            this->appointment->setDoctorEmail(temp2.getEmail());
                            this->appointment->setPatientEmail(user->getEmail());

                            this->appointment->setDoctorName(temp2.getName());
                            this->appointment->setPatientName(user->getName());

                            this->appointment->setDoctorCNIC(temp2.getCNIC());
                            this->appointment->setPatientCNIC(user->getCNIC());

                            for (int i = 0; i < temp2.getAvailability().getTimeCounter(); i++)
                            {
                                if (temp2.getAvailability().getStartTime(i) == userInputInt)
                                {
                                    this->appointment->setStartTime(temp2.getAvailability().getStartTime(i));
                                    this->appointment->setEndTime(temp2.getAvailability().getEndTime(i));
                                }
                            }
                            break;
                        }
                    }
                    myFile1.close();

                    Date tempDate;
                    cout << "Date: \n";
                    cout << "Day: ";
                    cin >> userInputInt;
                    tempDate.setDay(userInputInt);
                    cout << "Month: ";
                    cin >> userInputInt;
                    tempDate.setMonth(userInputInt);
                    cout << "Year: ";
                    cin >> userInputInt;
                    tempDate.setYear(userInputInt);

                    cout << "Consultation mode: \n\t1- In-person Mode\n\t2- Video Mode\n\t3- Exit\n\t > ";
                    cin >> userInputInt;

                    if (userInputInt == 1)
                    {
                        this->appointment->setAppointMode("In-Person Mode");
                    }
                    else if (userInputInt == 2)
                    {
                        this->appointment->setAppointMode("video Mode");
                    }
                    else if (userInputInt == 3)
                    {
                        exit();
                    }

                    this->appointment->setDate(tempDate);
                    this->appointment->setStatus("Pending");

                    user->insertAppointment(user, this->appointment);

                    cout << "\n**********  Appointment Scheduled successfully  **************\n\n";

                    cout << endl;
                    user->retrieveAllAppointment(user, appointment);
                    cout << endl;
                }
                else if (userInputInt == 2)
                {
                    cout << "All of your schedule appointments are: \n\n";
                    Appointment temp;
                    ifstream myFile1("appointment.bin", ios::binary);
                    while (myFile1.read((char*)&temp, sizeof(temp)))
                    {
                        if (temp.getPatientEmail() == user->getEmail())
                        {
                            cout << "\t Time: " << temp.getStartTime() << " - " << temp.getEndTime() << endl;
                        }

                    }
                    myFile1.close();

                    cout << "Enter the start time of the appointment that you want to update: ";
                    cin >> userInputInt;

                    fstream myFile("appointment.bin", ios::in | ios::out | ios::binary);
                    while (myFile.read((char*)&temp, sizeof(temp)))
                    {
                        if (temp.getPatientEmail() == user->getEmail())
                        {
                            if (temp.getStartTime() == userInputInt)
                            {
                                cout << "Available Hours: \n";
                                Doctor temp2;
                                ifstream myFile1("Doctor.bin", ios::binary);
                                while (myFile1.read((char*)&temp2, sizeof(temp2)))
                                {
                                    if (temp2.getEmail() == temp.getDoctorEmail())
                                    {
                                        for (int i = 0; i < temp2.getAvailability().getTimeCounter(); i++)
                                        {
                                            cout << "\t" << temp2.getAvailability().getStartTime(i) << " - " << temp2.getAvailability().getEndTime(i) << endl;
                                        }
                                        myFile1.close();
                                    }
                                }
                                cout << "\nEnter new Start time from the above available hours of the same doctor: ";
                                cin >> userInputInt;
                                temp.setStartTime(userInputInt);
                                cout << "New End time: ";
                                cin >> userInputInt;
                                temp.setEndTime(userInputInt);
                                int current = myFile.tellg(); //will tell where is our pointer at current time
                                int oneblock = sizeof(temp);
                                myFile.seekg(current - oneblock); // seekg will move the pointer location
                                myFile.write((char*)&temp, sizeof(temp));
                                myFile.close();

                                cout << "\n\t******** Appointment updated successfully *******\n\n";
                            }

                        }

                    }

                }
                else if (userInputInt == 3)
                {
                    cout << "All of your schedule appointments are: \n\n";
                    Appointment temp2;
                    ifstream myFile1("appointment.bin", ios::binary);
                    while (myFile1.read((char*)&temp2, sizeof(temp2)))
                    {
                        if (temp2.getPatientEmail() == user->getEmail())
                        {
                            cout << "\t Time: " << temp2.getStartTime() << " - " << temp2.getEndTime() << endl;
                        }

                    }
                    myFile1.close();

                    cout << "Enter the start time of the appointment that you want to delete: ";
                    cin >> userInputInt;


                    /*Date tempDate;
                    cout << "\tEnter today's date: \n";
                    cout << "Day: "; cin >> userInputInt;
                    tempDate.setDay(userInputInt);

                    cout << "Month: "; cin >> userInputInt;
                    tempDate.setMonth(userInputInt);

                    cout << "Year: "; cin >> userInputInt;
                    tempDate.setYear(userInputInt);

                    Date dueDate;

                    Appointment temp2;
                    ifstream myFile1("appointment.bin", ios::binary);
                    while (myFile1.read((char*)&temp2, sizeof(temp2)))
                    {
                        if (temp2.getDoctorEmail() == userInput)
                        {
                            appointMode = temp2.getAppointMode();
                            appointmentHours = temp2.getEndTime() - temp2.getStartTime();
                            dueDate.setDay(temp2.getDate().getDay());
                            dueDate.setMonth(temp2.getDate().getMonth());
                            dueDate.setYear(temp2.getDate().getYear());
                            break;
                        }

                    }
                    myFile1.close();*/



                    Appointment temp;
                    fstream myFile("appointment.bin", ios::in | ios::out | ios::binary);
                    ofstream myFile_temp("temp.bin", ios::app | ios::binary);
                    while (myFile.read((char*)&temp, sizeof(temp))) {
                        if (temp.getStartTime() != userInputInt) {
                            myFile_temp.write((char*)&temp, sizeof(temp));
                        }
                    }
                    myFile.close();
                    myFile_temp.close();
                    remove("appointment.bin");
                    rename("temp.bin", "appointment.bin");

                    cout << "\n\t******** Appointment deleted successfully *******\n\n";
                }

            }
            else if (userChoice == 6)
            {
                user->display();
                cout << endl;
            }
            else if (userChoice == 7)
            {
                cout << "\n *** Your current information is: ****\n\n";
                user->showRetrieveByEmail(user, user->getEmail());
                cout << endl;

                while (true)
                {
                    user->updateInformation(user);
                    cout << "Want to update anything else?\n1- Yes\n2- No\n3- Exit\n > ";
                    cin >> userInputInt;

                    if (userInputInt == 2)
                    {
                        string email = user->getEmail();
                        user->updateData(user, email);
                        break;
                    }
                    else if (userInputInt == 3)
                    {
                        exit();
                    }
                }


            }
            else if (userChoice == 8)
            {
                cout << "\n********************* All of your schedule appointments are: *********************\n\n";
                cout << endl;
                user->retrieveAllAppointment(user, appointment);
                cout << endl;
            }
            else if (userChoice == 9)
            {
                user->rechargeAccount(user, user->getEmail(), 0);
                cout << "\n\tYour current balance is: " << user->getBalance() << endl << endl;
            }
            else if (userChoice == 10)
            {
                string doctorEmail, appointMode;
                int appointmentHours, startTime;
                cout << "\n********************* All of your schedule appointments are: *********************\n\n";
                cout << endl;
                user->retrieveAllAppointment(user, appointment);
                cout << endl;

                cout << "Enter the doctor email:";
                cin >> userInput;

                doctorEmail = userInput;

                cout << "Enter the starting time of your booked slot: ";
                cin >> userInputInt;
                startTime = userInputInt;

                Date tempDate;
                cout << "\tEnter today's date: \n";
                cout << "Day: "; cin >> userInputInt;
                tempDate.setDay(userInputInt);

                cout << "Month: "; cin >> userInputInt;
                tempDate.setMonth(userInputInt);

                cout << "Year: "; cin >> userInputInt;
                tempDate.setYear(userInputInt);

                Date dueDate;

                Appointment temp2;
                ifstream myFile1("appointment.bin", ios::binary);
                while (myFile1.read((char*)&temp2, sizeof(temp2)))
                {
                    if (temp2.getDoctorEmail() == userInput)
                    {
                        appointMode = temp2.getAppointMode();
                        appointmentHours = temp2.getEndTime() - temp2.getStartTime();
                        dueDate.setDay(temp2.getDate().getDay());
                        dueDate.setMonth(temp2.getDate().getMonth());
                        dueDate.setYear(temp2.getDate().getYear());
                        break;
                    }

                }
                myFile1.close();

                double doctorCharges, charges = 0;
                Doctor temp;
                ifstream myFile("Doctor.bin", ios::binary);
                while (myFile.read((char*)&temp, sizeof(temp))) {
                    if (temp.getEmail() == doctorEmail)
                    {
                        doctorCharges = temp.getHourlyRate();
                    }
                }
                myFile.close();


                int dueDateDays = DateToDays(dueDate);
                int completenessDateDays = DateToDays(tempDate);

                int daysDifference = dueDateDays - completenessDateDays;

                if (daysDifference < 0)
                {
                    daysDifference *= -1;
                }

                cout << "days diff: " << daysDifference << endl;

                double fine = 0;
                charges = doctorCharges * appointmentHours;
                cout << "appointmentHours: " << appointmentHours << endl;
                cout << "charges: " << charges << endl;
                if (daysDifference == 1)
                {
                    cout << "\t *******  Your due date was yesterday *******\n";
                    fine = (charges * 0.3);
                }
                else if (daysDifference == 2)
                {
                    cout << "\t *******  Your due date was day before yesterday *******\n";
                    fine = (charges * 0.6);
                }
                else if (daysDifference == 3)
                {
                    cout << "\t *******  Your due date was 2 days before yesterday *******\n";
                    fine = (charges * 1);

                    cout << "\n\t****  YOU HAVE TO SCHEDULE NEW APPOINTMENT  *****\n";
                    this->Menu();
                }

                char userInputChar;
                Recipt(charges, fine);

                cout << "\n\nHow would you like to pay?\n";
                cout << "\tA- E-Transaction\n\tB- Bank Transfer\n\t\t > ";
                cin >> userInputChar;

                if (userInputChar == 'A')
                {
                    cout << "\t\t1- JazzCash\n\t\t2- EasyPaisa\n\t\t > ";
                    cin >> userInputInt;

                    if (userInputInt == 1)
                    {
                        this->payment = new Jazzcash;
                    }
                    else if (userInputInt == 2)
                    {
                        this->payment = new EasyPaisa;
                    }
                }
                else if (userInputChar == 'B')
                {
                    cout << "\t\t1- Paypak\n\t\t2- UnionPay\n> ";
                    cin >> userInputInt;
                    if (userInputInt == 1)
                    {
                        this->payment = new Paypak;
                    }
                    else if (userInputInt == 2)
                    {
                        this->payment = new UnionPay;
                    }
                }
                charges += fine;
                int paymentStatus;
                string doctorEmailCpy = doctorEmail;
                //this->payment->setCharges(charges);
                paymentStatus = this->payment->askForPayment(user, appointment, charges);
                if (!paymentStatus)
                {
                    cout << "\n\t ********** TRANSACTION FAILED, PLEASE MAKE A NEW PAYMENT ********** \n\n";
                }
                else
                {
                    Appointment temp;
                    fstream myFile("appointment.bin", ios::in | ios::out | ios::binary);
                    ofstream myFile_temp("temp.bin", ios::app | ios::binary);
                    while (myFile.read((char*)&temp, sizeof(temp))) {
                        if (temp.getDoctorEmail() == doctorEmail && temp.getStartTime() == startTime) {

                        }
                        else
                        {
                            myFile_temp.write((char*)&temp, sizeof(temp));
                        }
                    }
                    myFile.close();
                    myFile_temp.close();
                    remove("appointment.bin");
                    rename("temp.bin", "appointment.bin");


                    string comment;
                    int rating;
                    cout << "\n ************************* KINDLY PROVIDE US YOUR FEEDBACK **************************\n";
                    cout << "\t1-      *\n";
                    cout << "\t2-     **\n";
                    cout << "\t3-    ***\n";
                    cout << "\t4-   ****\n";
                    cout << "\t5-  *****\n";

                    cout << "\nChoose rating: ";
                    cin >> rating;
                    getline(cin, comment);
                    cout << "\n Please write a review: ";
                    getline(cin, comment);

                    cout << doctorEmailCpy << endl;

                    this->feedback->setComment(comment);
                    this->feedback->setRating(rating);
                    this->feedback->setDoctorEmail(doctorEmailCpy);
                    this->feedback->setPatientEmail(user->getEmail());
                    ofstream myFile2("feedback.bin", ios::binary | ios::app);
                    myFile2.write((char*)feedback, sizeof(Feedback));
                    myFile2.close();

                    cout << "\n***************************** THANKS FOR YOUR FEEDBACK ************************\n";

                }
            }
            else if (userChoice == 11)
            {
                exit();
            }

        }
    }
    else if (user->giveSize() == "doctor")
    {
        int userChoice, userInputInt;
        string userInput;// , userInput1;
        while (true)
        {
            cout << "\n1- Add/Edit/Delete availability hours\n2- Change hourly fees\n3- See scheduled appointments\n4- See patient data (that has an appointment)\n5- Change status of appointments\n6- Show status of appointmnents\n7- Update Profile\n8- Show profile\n9- Show feedbacks\n10- Show my rating\n11- Exit\n > ";
            cin >> userChoice;

            if (userChoice == 1)
            {
                cout << "Add/Edit/Delete availability hours\n";
            }
            else if (userChoice == 2)
            {
                cout << "\n\t Your current hourly fees is: " << user->getHourlyRate() << endl;
                cout << "Enter new hourly fees: ";
                cin >> userInputInt;
                user->setHourlyRate(userInputInt);
                string email = user->getEmail();
                user->updateData(user, email);

            }
            else if (userChoice == 3)
            {
                cout << "\n****************** All of your schedule appointments are: **************\n\n";
                Appointment temp;
                ifstream myFile1("appointment.bin", ios::binary);
                while (myFile1.read((char*)&temp, sizeof(temp)))
                {
                    if (temp.getDoctorEmail() == user->getEmail())
                    {
                        temp.display();
                        cout << endl;
                    }

                }
                myFile1.close();
            }
            else if (userChoice == 4)
            {
                cout << "\n****************** All of your schedule appointments are: **************\n\n";
                Appointment temp;
                ifstream myFile1("appointment.bin", ios::binary);
                while (myFile1.read((char*)&temp, sizeof(temp)))
                {
                    if (temp.getDoctorEmail() == user->getEmail())
                    {
                        temp.display();
                        cout << endl;
                    }

                }
                myFile1.close();

                string patientEmail;
                cout << "Enter the patient email to see his/her data: ";
                cin >> patientEmail;
                cout << endl << endl;
                user->showRetrieveByEmail(user, patientEmail);
                cout << endl;
            }
            else if (userChoice == 5)
            {
                cout << "\n****************** All of your schedule appointments are: **************\n\n";
                Appointment temp2;
                ifstream myFile1("appointment.bin", ios::binary);
                while (myFile1.read((char*)&temp2, sizeof(temp2)))
                {
                    if (temp2.getDoctorEmail() == user->getEmail())
                    {
                        temp2.display();
                        cout << endl;
                    }

                }
                myFile1.close();

                cout << "Enter the email of that patient of which you want to change his/her status: ";
                cin >> userInput;

                int n;
                cout << "Enter the start time of his/her appointment: ";
                cin >> n;

                string status;
                cout << "Select the status: \n\t1- Approve\n\t2- Pending\n\t3- Reject\n\t > ";
                cin >> userInputInt;

                if (userInputInt == 1)
                {
                    status = "Approve";
                }
                else if (userInputInt == 2)
                {
                    status = "Pending";
                }
                else if (userInputInt == 3)
                {
                    status = "Reject";
                }

                Appointment temp;
                fstream myFile("appointment.bin", ios::in | ios::out | ios::binary);
                while (myFile.read((char*)&temp, sizeof(temp)))
                {
                    if (temp.getPatientEmail() == userInput && temp.getStartTime() == n)
                    {
                        temp.setStatus(status);
                        cout << temp.getStatus() << endl;
                        int current = myFile.tellg(); //will tell where is our pointer at current time
                        int oneblock = sizeof(temp);
                        myFile.seekg(current - oneblock); // seekg will move the pointer location
                        myFile.write((char*)&temp, sizeof(temp));
                        myFile.close();
                    }

                }

            }
            else if (userChoice == 6)
            {

                Appointment temp;
                ifstream myFile1("appointment.bin", ios::binary);
                while (myFile1.read((char*)&temp, sizeof(temp)))
                {
                    if (temp.getDoctorEmail() == user->getEmail())
                    {
                        cout << "\n\tPatient Name: " << temp.getPatientName() << endl;
                        cout << "\tPatient email: " << temp.getPatientEmail() << endl;
                        cout << "\tAppointment Status: " << temp.getStatus() << endl;
                        cout << endl;
                    }

                }
                myFile1.close();
            }
            else if (userChoice == 7)
            {
                while (true)
                {
                    user->updateInformation(user);
                    cout << "Want to update anything else?\n1- Yes\n2- No\n3- Exit\n > ";
                    cin >> userInputInt;

                    if (userInputInt == 2)
                    {
                        string email = user->getEmail();
                        user->updateData(user, email);
                        break;
                    }
                    else if (userInputInt == 3)
                    {
                        exit();
                    }
                }
            }
            else if (userChoice == 8)
            {
                cout << endl;
                user->display();
            }
            else if (userChoice == 9)
            {
                user->showAllFeedbacks(user, user->getEmail());
                //user->showFeedbacks(user, user->getEmail());
            }
            else if (userChoice == 10)
            {
                float ratingSum = 0;
                int counter = 0;
                Feedback temp;
                fstream myFile("feedback.bin", ios::in | ios::out | ios::binary);
                while (myFile.read((char*)&temp, sizeof(temp))) {
                    if (temp.getDoctorEmail() == user->getEmail())
                    {
                        ratingSum += temp.getRating();
                        counter++;
                    }
                }
                myFile.close();

                float avg = ratingSum / (float)counter;

                cout << "\n\n\tYour rating rate is: " << avg << "\n\n";

            }
            else if (userChoice == 11)
            {
                exit();
            }
        }
    }
    else if (user->giveSize() == "admin")
    {
        while (true)
        {
            int userInputInt, userChoice, userInputInt1;
            string userInput;
            cout << "\n1- Add/Edit/Delete/view Doctors\n2- View all Patients Data\n3- Edit/Delete doctor availability\n4- View all appointments\n5- Exit\n > ";
            cin >> userChoice;
            if (userChoice == 1)
            {
                cout << "\t1- Add\n\t2- Edit\n\t3- Delete\n\t4- View\n\t5- Exit\n > ";
                cin >> userInputInt;

                if (userInputInt == 1)
                {
                    Doctor temp;
                    temp.Register();

                    ofstream myFile("Doctor.bin", ios::binary | ios::app);
                    myFile.write((char*)&temp, sizeof(Doctor));
                    myFile.close();

                    cout << "\n**********************\Doctor Added successfully **********************\n\n";
                }
                else if (userInputInt == 2)
                {
                    string doctorEmail;
                    Doctor temp;
                    int userChoice, userInputInt;
                    string userInput, userInput1;
                    cout << "Enter doctor email: "; cin >> doctorEmail;
                    cout << "\nWhat do you want to update: \n";
                    cout << "\t1- Name\n\t2- Password\n\t3- CNIC\n\t4- Email\n\t5- Age\n\t6- Gender\n\t7- Phone Number\n\t8- City\n\t9- Year of experience\n\t10- Specialization\n\t11- Hospital Name\n\t12- Houry Rate\n > ";
                    cin >> userChoice;

                    if (userChoice == 1)
                    {
                        getline(cin, userInput);
                        cout << "Enter new name: ";
                        getline(cin, userInput);

                        temp.setName(userInput);
                    }
                    else if (userChoice == 2)
                    {
                        while (true)
                        {
                            cout << "Enter new Password : ";
                            cin >> userInput;

                            cout << "Re-enter new Password: ";
                            cin >> userInput1;

                            int n = passwordChecker(userInput, userInput1);

                            if (n)
                            {
                                temp.setPassword(userInput);
                                break;
                            }
                        }
                    }
                    else if (userChoice == 3)
                    {
                        cout << "Enter new CNIC: ";
                        cin >> userInput;

                        temp.setCNIC(userInput);
                    }
                    else if (userChoice == 4)
                    {
                        cout << "Enter new Email: ";
                        cin >> userInput;

                        temp.setEmail(userInput);
                    }
                    else if (userChoice == 5)
                    {
                        cout << "Enter new Age: ";
                        cin >> userInputInt;

                        temp.setAge(userInputInt);
                    }
                    else if (userChoice == 6)
                    {
                        cout << "Gender: \n";
                        cout << "\t1- Male\n\t2- Female\n\t3- Other\n";
                        cin >> userInputInt;

                        switch (userInputInt)
                        {
                        case 1: temp.setGender("Male");
                            break;
                        case 2: temp.setGender("Female");
                            break;
                        case 3: temp.setGender("Other");
                        }
                    }
                    else if (userChoice == 7)
                    {
                        cout << "Enter new Phone number: ";
                        cin >> userInput;

                        temp.setPhone(userInput);
                    }
                    else if (userChoice == 8)
                    {
                        cout << "Enter new City: ";
                        cin >> userInput;

                        temp.setCity(userInput);
                    }
                    else if (userChoice == 9)
                    {
                        cout << "Enter updated year of experience: ";
                        cin >> userInputInt;
                        temp.setYearOfExperience(userInputInt);
                    }
                    else if (userChoice == 10)
                    {
                        cout << "Enter updated specialization: ";
                        cin >> userInput;
                        temp.setSpecialization(userInput);
                    }
                    else if (userChoice == 11)
                    {
                        getline(cin, userInput);
                        cout << "Enter new hospital name: ";
                        getline(cin, userInput);
                        temp.setHospitalName(userInput);
                    }
                    else if (userChoice == 12)
                    {
                        cout << "\n\t Your current hourly fees is: " << user->getHourlyRate() << endl;
                        cout << "Enter new hourly fees: ";
                        cin >> userInputInt;
                        temp.setHourlyRate(userInputInt);
                    }

                    cout << "\n *** Update Successfully! ***\n\n";
                }
                else if (userInputInt == 3)
                {

                    Doctor temp2;
                    ifstream myFile2("Doctor.bin", ios::binary);
                    while (myFile2.read((char*)&temp2, sizeof(temp2)))
                    {
                        cout << endl << endl;
                        temp2.display();

                    }
                    myFile2.close();

                    string email;
                    cout << "Enter doctor email that you want to delete: ";
                    cin >> email;

                    Doctor temp;
                    fstream myFile("Doctor.bin", ios::in | ios::out | ios::binary);
                    ofstream myFile_temp("temp.bin", ios::app | ios::binary);
                    while (myFile.read((char*)&temp, sizeof(temp)))
                    {
                        if (temp.getEmail() != email)
                        {
                            myFile_temp.write((char*)&temp, sizeof(temp));
                        }

                    }
                    myFile.close();
                    myFile_temp.close();
                    remove("Doctor.bin");
                    rename("temp.bin", "Doctor.bin");

                    cout << "\n********************* Doctor deleted successfully *********************\n\n";
                }
                else if (userInputInt == 4)
                {
                    Doctor temp;
                    ifstream myFile("Doctor.bin", ios::binary);
                    while (myFile.read((char*)&temp, sizeof(temp)))
                    {
                        cout << endl << endl;
                        temp.display();

                    }
                    myFile.close();
                    cout << endl;
                }
                else if (userInputInt == 5)
                {
                    exit();
                }

            }
            else if (userChoice == 2)
            {
                Patient temp;
                ifstream myFile("Patient.bin", ios::binary);
                while (myFile.read((char*)&temp, sizeof(temp))) {
                    temp.display();
                }
                myFile.close();
                cout << endl << endl;
            }
            else if (userChoice == 3)
            {
                cout << "\t1- Edit\n\t2- Delete\n\t3- Exit\n\t > ";
                cin >> userInputInt;
                if (userInputInt == 1)
                {
                    cout << "\n ********************** ALL Availability hours are *********************** \n";
                    Doctor temp;
                    ifstream myFile("Doctor.bin", ios::binary);
                    while (myFile.read((char*)&temp, sizeof(temp))) {
                        cout << "Doctor name: " << temp.getName() << endl;
                        cout << "Doctor email: " << temp.getEmail() << endl;
                        temp.getAvailability().display();
                    }
                    myFile.close();

                    cout << "Enter doctor email: ";
                    cin >> userInput;

                    cout << "Enter the start time of the slot: ";
                    cin >> userInputInt;
                    Doctor temp2;
                    fstream myFile2("Doctor.bin", ios::in | ios::out | ios::binary);
                    while (myFile2.read((char*)&temp2, sizeof(temp2))) {
                        for (int i = 0; i < temp2.getAvailability().getTimeCounter(); i++)
                        {
                            if (temp2.getAvailability().getStartTime(i) == userInputInt && temp2.getEmail() == userInput)
                            {
                                cout << "Enter new startTime: ";
                                cin >> userInputInt;

                                cout << "Enter new endTime: ";
                                cin >> userInputInt1;

                                temp.setAvailability(userInputInt, userInputInt1);

                                int current = myFile.tellg(); //will tell where is our pointer at current time
                                int oneblock = sizeof(temp);
                                myFile2.seekg(current - oneblock); // seekg will move the pointer location
                                myFile2.write((char*)&temp, sizeof(temp));
                                myFile2.close();

                                cout << "\t ************* Update successfully *********\n";
                            }
                        }
                    }

                }
                else if (userInputInt == 2)
                {

                }
                else if (userInputInt == 3)
                {
                    exit();

                }
            }
            else if (userChoice == 4)
            {
                cout << "\n ********************** ALL appointments are *********************** \n";
                Appointment temp;
                ifstream myFile("appointment.bin", ios::binary);
                while (myFile.read((char*)&temp, sizeof(temp))) {
                    temp.display();
                }
                myFile.close();
            }
            else if (userChoice == 5)
            {
                exit();
            }

        }
    }
}

void Oladoc::mainMenu()
{
    int userInput, userInput_2;
    cout << "\n*************************** WELLCOME TO OLADOC APP ************************\n";
    cout << "1- Admin\n2- Patient\n3- Doctor\n4- Exit\n > ";
    cin >> userInput;

    this->appointment = new Appointment;
    this->feedback = new Feedback;

    if (userInput == 1)
    {
        startUp(new Admin);
    }
    else if (userInput == 2)
    {
        startUp(new Patient);

    }
    else if (userInput == 3)
    {
        startUp(new Doctor);
    }
    else if (userInput == 4)
    {
        exit();
    }

}

int main()
{
    Oladoc oladoc;
    oladoc.mainMenu();


    return 0;

}