#pragma once

#pragma warning(disable: 4996);
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Date
{
	int day;
	int month;
	int year;
public:
	Date() 
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	};

	//accessor
	int getDay()
	{
		return this->day;
	}
	int getMonth()
	{
		return this->month;
	}
	int getYear()
	{
		return this->year;
	}

	//mutators

	void setDay(int day)
	{
		this->day = day;
	}
	void setMonth(int month)
	{
		this->month = month;
	}
	void setYear(int year)
	{
		this->year = year;
	}

};

class Time
{
	int seconds;
	int minutes;
	int hours;
public:
	Time() {};

	//accessors
	int getSeconds()
	{
		return this->seconds;
	}
	int getMinutes()
	{
		return this->minutes;
	}
	int getHours()
	{
		return this->hours;
	}

	//mutators
	void setSeconds(int sec)
	{
		this->seconds = sec;
	}
	void setMinutes(int min)
	{
		this->minutes = min;
	}
	void setHours(int hour)
	{
		this->hours = hour;
	}

};
//
class Availability
{
public:

	int startTime[20];
	int endTime[20];
	int timeCounter;


	Availability() 
	{
		this->timeCounter = 0;
	};

	//accessors
	int getStartTime(int n) { return this->startTime[n]; };
	int getEndTime(int n) { return this->endTime[n]; };

	int getTimeCounter()
	{
		return this->timeCounter;
	}

	//mutators
	void setStartTime(int n)
	{
		this->startTime[this->timeCounter] = n;
	};
	void setEndTime(int n)
	{
		this->endTime[this->timeCounter] = n;
	};
	void increaseTimeCounter()
	{
		this->timeCounter++;
	}

	void display()
	{
		for (int i = 0; i < this->timeCounter; i++)
		{
			cout <<"\t" << i + 1 << "-  " << this->startTime[i] << "-" << this->endTime[i] << endl;
		}
	}
};



#include "appointment.h"
int passwordChecker(string pass, string re_pass);
void exit();

class Authorization
{
	string email;
	string password;
	bool authStatus;

public:
	Authorization()
	{
		email = "";
		password = "";
		authStatus = false;
	}

	//accessors
	string getEmail()
	{
		return this->email;
	}
	string getPassword()
	{
		return this->password;
	}
	bool getAuth()
	{
		return this->authStatus;
	}

	//mutators
	void setEmail(string email)
	{
		this->email = email;
	}
	void setPassword(string pass)
	{
		this->password = pass;
	}
	void setAuth(bool auth)
	{
		this->authStatus = auth;
	}
};
//user

class User
{
protected:
	char name[30];
	char password[30];
	char CNIC[15];
	char email[50];
	//Date date;
	int age;
	char gender[10];
	double balance;
	char phoneNo[15];
	char city[50];
	bool loginStatus = false;
public:
	User();

	//accessors
	string getName()
	{
		return this->name;
	}
	string getPassword()
	{
		return this->password;
	}
	string getCNIC()
	{
		return this->CNIC;
	}
	string getEmail()
	{
		return this->email;
	}
	//Date getDate();
	int getAge()
	{
		return this->age;
	}
	string getGender()
	{
		return this->gender;
	}
	double getBalance()
	{
		return this->balance;
	}
	string getPhone()
	{
		return this->phoneNo;
	}
	string getCity()
	{
		return this->city;
	}
	bool getLoginStatus()
	{
		return this->loginStatus;
	}
	
	//mutators
	void setName(string name)
	{
		strcpy(this->name, name.c_str());
	}
	void setPassword(string pass)
	{
		strcpy(this->password, pass.c_str());
	}
	void setCNIC(string cnic)
	{
		strcpy(this->CNIC, cnic.c_str());
	}
	void setEmail(string email)
	{
		strcpy(this->email, email.c_str());
	}
	//void setDate(Date);
	void setAge(int age)
	{
		this->age = age;
	}
	void setGender(string gender)
	{
		strcpy(this->gender, gender.c_str());
	}
	void setBalance(double balance)
	{
		this->balance = balance;
	}
	void setPhone(string phone)
	{
		strcpy(this->phoneNo, phone.c_str());
	}
	void setCity(string city)
	{
		strcpy(this->city, city.c_str());
	}

	void setLoginStatus(bool status)
	{
		this->loginStatus = status;
	}


	//to access doctors accessors and mutators
	virtual int getYearOfExperience() { return 1; };
	virtual string getSpecialization() { return ""; };
	virtual string getHospitalName() { return ""; };
	virtual int getHourlyRate() { return 1; };
	//Availability getAvailability();
	virtual void setYearOfExperience(int years) {};
	virtual void setSpecialization(string spec) {};
	virtual void setHospitalName(string name) {}
	virtual void setHourlyRate(int rate) {};
	virtual Availability getAvailability() { Availability temp; return temp; };
	virtual void setAvailability(int start, int end) {};
	virtual void insertAppointment(User* user, Appointment* appoint) {};
	virtual void retrieveAllAppointment(User*, Appointment*) {};
	//virtual void checkAvailbility(User*, Appointment*) {};






	/*Authorization* authorization(string email, string passowrd, bool auth)
	{
		cout << "-- " << email << " " << passowrd << " " << auth << endl;
		Authorization temp;
		temp.setEmail(email);
		temp.setPassword(passowrd);
		temp.setAuth(auth);

		return &temp;
	}*/

	//functionalities
	virtual void Register();
	virtual void Login(User*);

	virtual void display()
	{
		cout << "Name: " << this->name << "\nPassword: " << this->password << "\nCNIC: " << this->CNIC << "\nEmail: " << this->email
			<< "\nAge: " << this->age << "\nGender: " << this->gender << /*"\nBalance: " << this->balance <<*/ "\nPhone Num: " << this->phoneNo << "\nCity: " << this->city << endl;
		//cout << "Age: " << this->age << "\n PhoneNum: " << this->phoneNo << endl;
		/*cout << "Name: " << this->name;*/
	}

	virtual string giveSize()
	{
		return "user";
	}

	virtual void insertUser(User* user) {};
	virtual void retrieveAllUsers(User* user) {};

	virtual int retrieveByEmail(User* user, string email) { return 0; };

	virtual int retrieveByPassword(User* user, string pass) { return 0; };
	virtual void showRetrieveByEmail(User* user, string email) {};
	virtual void showRetrieveByPassword(User* user, string pass) {};
	virtual void paswordReset(User* user, string email, string newPass) {}
	virtual void rechargeAccount(User* user, string email, double balance) {};
	virtual void serachDoctorsBySpecialization(User* user, string spec) {};
	virtual void updateInformation(User* user) {};
	//virtual void retrieveAllDoctorsForAppoint(User* user) {};
	virtual void updateData(User* user, string email) {};
	virtual int makePayment(User*, double) { return 0; };
	virtual void appointment(User*, Appointment*) {};
	virtual void showAllFeedbacks(User*, string) {};
	virtual void showFeedbacks(User*, string) {};


};

#include "Payment.h"; //  ********************* Patient..h file link *********************

class Patient :public User
{
public:
	Patient();

	char* getPassword()
	{
		return this->password;
	}

	void Register();
	void Login(User*);

	void display()
	{
		User::display();
	}
	string giveSize()
	{
		return "patient";
	}

	void operator=( User& user)
	{
		strcpy(this->name, user.getName().c_str());
		strcpy(this->password, user.getPassword().c_str());
		strcpy(this->CNIC, user.getCNIC().c_str());
		strcpy(this->email, user.getEmail().c_str());
		strcpy(this->phoneNo, user.getPhone().c_str());
		strcpy(this->city, user.getCity().c_str());
		strcpy(this->gender, user.getGender().c_str());
		this->age = user.getAge();

		//this->balance = user.getBalance();
	}

	void insertUser(User * user)
	{
		ofstream myFile("Patient.bin", ios::binary | ios::app);
		myFile.write((char*)user, sizeof(Patient));
		myFile.close();
	}

	void retrieveAllUsers(User* user)
	{
		Patient temp;
		ifstream myFile("Patient.bin", ios::binary);
		    while (myFile.read((char*)&temp, sizeof(temp))) {
				temp.display();
		    }
		    myFile.close();
		
	};

	int retrieveByEmail(User* user, string email)
	{
		Patient temp;
		ifstream myFile("Patient.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email)
			{
				user->setName(temp.getName());
				user->setCNIC(temp.getCNIC());
				user->setAge(temp.getAge());
				user->setGender(temp.getGender());
				user->setPhone(temp.getPhone());
				user->setCity(temp.getCity());
				user->setBalance(temp.getBalance());
				myFile.close();
				return 1;
			}
		}
		myFile.close();

		return 0;
	};

	int retrieveByPassword(User* user, string pass)
	{
		Patient temp;
		ifstream myFile("Patient.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getPassword() == pass)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();

		return 0;
	};

	void paswordReset(User* user, string email, string newPass)
	{
		Patient temp;
		fstream myFile("Patient.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email) {
				strcpy(temp.getPassword(), newPass.c_str());
				int current = myFile.tellg(); //will tell where is our pointer at current time
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock); // seekg will move the pointer location
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
				cout << "\n *** Password Reset successfully! ***\n\n";
			}
		}
	}

	void rechargeAccount(User* user, string email, double balance)
	{
		Patient temp;
		fstream myFile("Patient.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email) {
				temp.balance += balance;
				user->setBalance(temp.balance);
				int current = myFile.tellg(); //will tell where is our pointer at current time
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock); // seekg will move the pointer location
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
	}

	void showRetrieveByEmail(User* user, string email)
	{
		Patient temp;
		ifstream myFile("Patient.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email)
			{
				//cout << "Name: " << temp.name << ", Email: " << temp.email << ", Pass: " << temp.password << endl;
				temp.display();
			}
		}
		myFile.close();
	};

	void showRetrieveByPassword(User* user, string pass)
	{
		Patient temp;
		ifstream myFile("Patient.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getPassword() == pass)
			{
				//cout << "Name: " << temp.name << ", Email: " << temp.email << ", Pass: " << temp.password << endl;
				temp.display();
			}
		}
		myFile.close();
	};

	void updateInformation(User* user)
	{
		int userChoice, userInputInt;
		string userInput, userInput1;
		cout << "\nWhat do you want to update: \n";
		cout << "\t1- Name\n\t2- Password\n\t3- CNIC\n\t4- Email\n\t5- Age\n\t6- Gender\n\t7- Phone Number\n\t8- City\n > ";
		cin >> userChoice;

		if (userChoice == 1)
		{
			getline(cin, userInput);
			cout << "Enter new name: ";
			getline(cin, userInput);
			
			this->setName(userInput);
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
					this->setPassword(userInput);
					break;
				}
			}
		}
		else if (userChoice == 3)
		{
			cout << "Enter new CNIC: ";
			cin >> userInput;

			this->setCNIC(userInput);
		}
		else if (userChoice == 4)
		{
			cout << "Enter new Email: ";
			cin >> userInput;

			this->setEmail(userInput);
		}
		else if (userChoice == 5)
		{
			cout << "Enter new Age: ";
			cin >> userInputInt;

			this->setAge(userInputInt);
		}
		else if (userChoice == 6)
		{
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
		}
		else if (userChoice == 7)
		{
			cout << "Enter new Phone number: ";
			cin >> userInput;

			this->setPhone(userInput);
		}
		else if (userChoice == 8)
		{
			cout << "Enter new City: ";
			cin >> userInput;

			this->setCity(userInput);
		}
	}

	void updateData(User* user, string email) 
	{
		Patient temp;
		fstream myFile("Patient.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email) {
				temp.setName(user->getName());
				temp.setPassword(user->getPassword());
				temp.setCNIC(user->getCNIC());
				temp.setEmail(user->getEmail());
				temp.setAge(user->getAge());
				temp.setGender(user->getGender());
				temp.setPhone(user->getPhone());
				temp.setCity(user->getCity());
				
				int current = myFile.tellg(); //will tell where is our pointer at current time
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock); // seekg will move the pointer location
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
				cout << "\n *** Update Successfully! ***\n\n";
			}
		}
	};
	void appointment(User* user, Appointment* appoint);
	void insertAppointment(User* user, Appointment* appoint) 
	{
		ofstream myFile("appointment.bin", ios::binary | ios::app);
		myFile.write((char*)appoint, sizeof(Appointment));
		myFile.close();
	};
	void retrieveAllAppointment(User* user, Appointment* appoint)
	{
		Appointment temp;
		ifstream myFile("appointment.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			temp.display();
			cout << endl;
		}
		myFile.close();
	};


	int makePayment(User* user, double bal) 
	{
		Patient temp;
		fstream myFile("Patient.bin", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == user->getEmail()) {
				if (temp.getBalance() - bal < 0)
				{
					return 0;
				}
				else
				{
					temp.balance -= bal;
				}
				int current = myFile.tellg(); //will tell where is our pointer at current time
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock); // seekg will move the pointer location
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
			}
		}
		return 1;
	};


};



class Doctor :public User
{
	int yearOfExperience;
	char specilization[30];
	char hospitalName[30];
	int hourlyRate;
	Availability availability;
public:
	Doctor();

	//accessor
	int getYearOfExperience()
	{
		return yearOfExperience;
	}
	string getSpecialization()
	{
		return specilization;
	}
	string getHospitalName()
	{
		return hospitalName;
	}
	int getHourlyRate()
	{
		return hourlyRate;
	}
	//Availability getAvailability();

	//mutators
	void setYearOfExperience(int years)
	{
		this->yearOfExperience = years;
	}
	void setSpecialization(string spec)
	{
		strcpy(this->specilization, spec.c_str());
	}
	void setHospitalName(string name)
	{
		strcpy(this->hospitalName, name.c_str());
	}
	void setHourlyRate(int rate)
	{
		this->hourlyRate = rate;
	}
	Availability getAvailability() 
	{
		return this->availability;
	};
	void setAvailability(int start, int end) 
	{
		this->availability.setStartTime(start);
		this->availability.setEndTime(end);
	};

	//void setAvailability(Availability);

	void Register();
	void Login(User*);
	void display()
	{
		User::display();
		cout << "Available Hours: \n";
		this->availability.display();
		cout << "Year of experience: " << this->yearOfExperience << "\nSpecialization: " << this->specilization << "\nHospital Name: " << this->hospitalName << "\nHourly Rate: " << this->hourlyRate << endl << endl;
	}
	string giveSize()
	{
		return "doctor";
	}


	void insertUser(User* user) 
	{
		ofstream myFile("Doctor.bin", ios::binary | ios::app);
		myFile.write((char*)user, sizeof(Doctor));
		myFile.close();
	};

	void retrieveAllUsers(User* user)
	{
		Doctor temp;
		ifstream myFile("Doctor.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			temp.display();

		}
		myFile.close();
	};


	int retrieveByEmail(User* user, string email)
	{
		Doctor temp;
		ifstream myFile("Doctor.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email)
			{
				user->setName(temp.getName());
				user->setCNIC(temp.getCNIC());
				user->setAge(temp.getAge());
				user->setGender(temp.getGender());
				user->setPhone(temp.getPhone());
				user->setCity(temp.getCity());
				user->setBalance(temp.getBalance());
				
				for (int i = 0; i < temp.getAvailability().getTimeCounter(); i++)
				{
					user->setAvailability(temp.getAvailability().getStartTime(i), temp.getAvailability().getEndTime(i));
				}

				setYearOfExperience(temp.getYearOfExperience());
				setSpecialization(temp.getSpecialization());
				setHospitalName(temp.getHospitalName());
				setHourlyRate(temp.getHourlyRate());
				myFile.close();
				return 1;
			}
		}
		myFile.close();

		return 0;
	};

	int retrieveByPassword(User* user, string pass)
	{
		Doctor temp;
		ifstream myFile("Doctor.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getPassword() == pass)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();

		return 0;
	};

	void showRetrieveByEmail(User* user, string email)
	{
		Patient temp;
		ifstream myFile("Patient.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email)
			{
				//cout << "Name: " << temp.name << ", Email: " << temp.email << ", Pass: " << temp.password << endl;
				temp.display();
			}
		}
		myFile.close();
	};

	void showRetrieveByPassword(User* user, string pass)
	{};

	 void updateInformation(User* user) 
	 {

		 int userChoice, userInputInt;
		 string userInput, userInput1;
		 cout << "\nWhat do you want to update: \n";
		 cout << "\t1- Name\n\t2- Password\n\t3- CNIC\n\t4- Email\n\t5- Age\n\t6- Gender\n\t7- Phone Number\n\t8- City\n\t9- Year of experience\n\t10- Specialization\n\t11- Hospital Name\n\t12- Houry Rate\n > ";
		 cin >> userChoice;

		 if (userChoice == 1)
		 {
			 getline(cin, userInput);
			 cout << "Enter new name: ";
			 getline(cin, userInput);

			 this->setName(userInput);
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
					 this->setPassword(userInput);
					 break;
				 }
			 }
		 }
		 else if (userChoice == 3)
		 {
			 cout << "Enter new CNIC: ";
			 cin >> userInput;

			 this->setCNIC(userInput);
		 }
		 else if (userChoice == 4)
		 {
			 cout << "Enter new Email: ";
			 cin >> userInput;

			 this->setEmail(userInput);
		 }
		 else if (userChoice == 5)
		 {
			 cout << "Enter new Age: ";
			 cin >> userInputInt;

			 this->setAge(userInputInt);
		 }
		 else if (userChoice == 6)
		 {
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
		 }
		 else if (userChoice == 7)
		 {
			 cout << "Enter new Phone number: ";
			 cin >> userInput;

			 this->setPhone(userInput);
		 }
		 else if (userChoice == 8)
		 {
			 cout << "Enter new City: ";
			 cin >> userInput;

			 this->setCity(userInput);
		 }
		 else if (userChoice == 9)
		 {
			 cout << "Enter updated year of experience: ";
			 cin >> userInputInt;
			 user->setYearOfExperience(userInputInt);
		 }
		 else if (userChoice == 10)
		 {
			 cout << "Enter updated specialization: ";
			 cin >> userInput;
			 user->setSpecialization(userInput);
		 }
		 else if (userChoice == 11)
		 {
			 getline(cin, userInput);
			 cout << "Enter new hospital name: ";
			 getline(cin, userInput);
			 user->setHospitalName(userInput);
		 }
		 else if (userChoice == 12)
		 {
			 cout << "\n\t Your current hourly fees is: " << user->getHourlyRate() << endl;
			 cout << "Enter new hourly fees: ";
			 cin >> userInputInt;
		 }

	 };
	 void updateData(User* user, string email) 
	 {
		 Doctor temp;
		 fstream myFile("Doctor.bin", ios::in | ios::out | ios::binary);
		 while (myFile.read((char*)&temp, sizeof(temp))) {
			 if (temp.getEmail() == email) {
				 temp.setName(user->getName());
				 temp.setPassword(user->getPassword());
				 temp.setCNIC(user->getCNIC());
				 temp.setEmail(user->getEmail());
				 temp.setAge(user->getAge());
				 temp.setGender(user->getGender());
				 temp.setPhone(user->getPhone());
				 temp.setCity(user->getCity());
				 temp.setYearOfExperience(user->getYearOfExperience());
				 temp.setSpecialization(user->getSpecialization());
				 temp.setHourlyRate(user->getHourlyRate());
				 temp.setHospitalName(user->getHospitalName());

				 int current = myFile.tellg(); //will tell where is our pointer at current time
				 int oneblock = sizeof(temp);
				 myFile.seekg(current - oneblock); // seekg will move the pointer location
				 myFile.write((char*)&temp, sizeof(temp));
				 myFile.close();
				 cout << "\n *** Update Successfully! ***\n\n";
			 }
		 }

	 
	 };

	 void appointment(User* user, Appointment* appoint);

	 void showAllFeedbacks(User* user, string email)
	 {

		 Feedback temp;
		 fstream myFile("feedback.bin", ios::in | ios::out | ios::binary);
		 while (myFile.read((char*)&temp, sizeof(temp))) {
			 if (temp.getDoctorEmail() == email)
			 {
				 cout << "\n\tPatient Email: " << temp.getPatientEmail() << endl;
				 cout << "\tPatient review: " << temp.getComment() << endl;
				 cout << "\tRating: " << temp.getRating() << endl;
			 }
		 }
		 myFile.close();
	 };
	 void showFeedbacks(User* user, string email)
	 {
		 cout << "--\n";
		 Feedback temp;
		 fstream myFile("feedback.bin", ios::in | ios::out | ios::binary);
		 while (myFile.read((char*)&temp, sizeof(temp))) {

				 cout << "\n\tPatient Email: " << temp.getPatientEmail() << endl;
				 cout << "\tDoctor Email: " << temp.getDoctorEmail() << endl;
				 cout << "\tPatient review: " << temp.getComment() << endl;
				 cout << "\tRating: " << temp.getRating() << endl;

		 }
		 myFile.close();
	 };
};

class Admin: public User
{
public:
	Admin();
	Admin(string, string, string, string);
	void Login(User*);
	
	string giveSize()
	{
		return "admin";
	}

	void insertUser(User* user)
	{
		ofstream myFile("Admin.bin", ios::binary);
		myFile.write((char*)user, sizeof(Admin));
		myFile.close();
	};

	int retrieveByEmail(User* user, string email)
	{
		Admin temp;
		ifstream myFile("Admin.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getEmail() == email)
			{
				user->setName(temp.getName());
				myFile.close();
				return 1;
			}
		}
		myFile.close();

		return 0;
	};

	int retrieveByPassword(User* user, string pass)
	{
		Admin temp;
		ifstream myFile("Admin.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getPassword() == pass)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();

		return 0;
	};

};


class Oladoc
{
	User* user;
	Appointment *appointment;
	Payment* payment;
	Feedback* feedback;
public:
	Oladoc();
	void startUp(User* = NULL);
	void displayAuth()
	{
		cout << user->getLoginStatus();
	};
	void Menu();
	void mainMenu();

	void searchDoctorsBySpecialization(User* user, string spec)
	{
		Doctor temp;
		ifstream myFile("Doctor.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getSpecialization() == spec)
			{
				cout << "Name: " << temp.getName() << endl << "Specialization: " << temp.getSpecialization() << "\nHourly fees: " << temp.getHourlyRate() << "\nPhone Num: " << temp.getPhone() << "\nHospital Name: " << temp.getHospitalName() << endl << endl;
			}
		}
		myFile.close();
	};

	void searchDoctorsByArea(User* user, string area)
	{
		Doctor temp;
		ifstream myFile("Doctor.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getCity() == area)
			{
				cout << "Name: " << temp.getName() << endl << "Specialization: " << temp.getSpecialization() << endl << "Hourly fees: " << temp.getHourlyRate() << "\nPhone Num: " << temp.getPhone()<< "\nHospital Name: " << temp.getHospitalName() << endl << endl;
			}
		}
		myFile.close();
	};

	void searchDoctorsByHospital(User* user, string name)
	{
		Doctor temp;
		ifstream myFile("Doctor.bin", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getHospitalName() == name)
			{
				cout << "Name: " << temp.getName() << endl <<"Specialization: " << temp.getSpecialization() << "\nHourly fees: " << temp.getHourlyRate() << "\nPhone Num: " << temp.getPhone() << "\nHospital Name: " << temp.getHospitalName() << endl << endl;
			}
		}
		myFile.close();
	};


	~Oladoc()
	{
		delete user;
		delete appointment;
		delete payment;
		delete feedback;
	}
};
