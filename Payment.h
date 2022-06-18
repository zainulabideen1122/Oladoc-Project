#pragma once
#include <iostream>
#include "oladoc.h"

using namespace std;


class Feedback
{
	int rating;
	char comment[200];
	char patientEmail[30];
	char DoctorEmail[30];
public:
	Feedback() {};

	//accessor
	int getRating()
	{
		return this->rating;
	}
	string getComment()
	{
		return this->comment;
	}
	string getPatientEmail()
	{
		return this->patientEmail;
	}
	string getDoctorEmail()
	{
		return this->DoctorEmail;
	}

	//mutators
	void setRating(int n)
	{
		this->rating = n;
	}
	void setComment(string comment)
	{
		strcpy(this->comment, comment.c_str());
	}
	void setPatientEmail(string email)
	{
		strcpy(this->patientEmail, email.c_str());
	}
	void setDoctorEmail(string email)
	{
		strcpy(this->DoctorEmail, email.c_str());
	}


};


class Payment
{
protected:
	double charges;
	double fine;
	char accountNumber[20];
public:
	Payment(double charges = 0, double fine = 0)
	{
		this->charges = charges;
		this->fine = fine;
	};

	//accessors
	virtual double getCharges()
	{
		return this->charges;
	}

	virtual string getAccountNumber()
	{
		return this->accountNumber;
	}

	//mutators
	virtual void setCharges(double n)
	{
		this->charges = n;
	}

	virtual void setAccountNumber(string n)
	{
		strcpy(this->accountNumber, n.c_str());
	}


	virtual int askForPayment(User* user, Appointment* appoint, double) { return 0; };


};

class E_Transaction : public Payment
{
public:
	E_Transaction() {};
};

class Jazzcash : public E_Transaction
{
public:
	Jazzcash() {};
	int askForPayment(User* user, Appointment* appoint,  double charges)
	{
		int n;
		string num;
		cout << "Enter your Jazzcash account number: ";
		cin >> num;

		this->setAccountNumber(num);
		this->charges = charges;

		cout << "\t ARE YOU CONFORM?\n\t1- Yes\n\t2- No\n";
		cin >> n;
		if (n == 1)
		{
			int status;
			status = user->makePayment(user, this->charges);
			if (status)
			{
				cout << "\n\t *********************** Payment Successfully ***********************\n";
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (n == 2)
		{
			return 0;
		}

	};
};
class EasyPaisa : public E_Transaction
{
public:
	EasyPaisa() {};
	int askForPayment(User* user, Appointment* appoint, double charges)
	{
		int n;
		string num;
		cout << "Enter your EasyPaisa account number: ";
		cin >> num;

		this->setAccountNumber(num);
		this->charges = charges;

		cout << "\t ARE YOU CONFORM?\n\t1- Yes\n\t2- No\n";
		cin >> n;
		if (n == 1)
		{
			int status;
			status = user->makePayment(user, this->charges);
			if (status)
			{
				cout << "\n\t *********************** Payment Successfully ***********************\n";
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (n == 2)
		{
			return 0;
		}

	};
};

class Bank_Transfer : public Payment
{
public:
	Bank_Transfer() {};

};

class Paypak : public Bank_Transfer
{
public:
	Paypak() {};
	int askForPayment(User* user, Appointment* appoint, double charges)
	{
		int n;
		string num;
		cout << "Enter your Paypak bank account number: ";
		cin >> num;

		this->setAccountNumber(num);
		this->charges = charges;

		cout << "\t ARE YOU CONFORM?\n\t1- Yes\n\t2- No\n";
		cin >> n;
		if (n == 1)
		{
			int status;
			status = user->makePayment(user, this->charges);
			if (status)
			{
				cout << "\n\t *********************** Payment Successfully ***********************\n";
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (n == 2)
		{
			return 0;
		}

	};
};
class UnionPay : public Bank_Transfer
{
public:
	UnionPay() {};
	int askForPayment(User* user, Appointment* appoint, double charges)
	{
		int n;
		string num;
		cout << "Enter your UnionPay account number: ";
		cin >> num;

		this->setAccountNumber(num);
		this->charges = charges;

		cout << "\t ARE YOU CONFORM?\n\t1- Yes\n\t2- No\n";
		cin >> n;
		if (n == 1)
		{
			int status;
			status = user->makePayment(user, this->charges);
			if (status)
			{
				cout << "\n\t *********************** Payment Successfully ***********************\n";
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else if (n == 2)
		{
			return 0;
		}

	};
};