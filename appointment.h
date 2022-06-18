#pragma once
#include <iostream>
#include "oladoc.h"

using namespace std;


class Appointment
{
	char patientName[20];
	char DoctorName[20];

	char patientCNIC[20];
	char DoctorCNIC[20];

	char patientEmail[30];
	char doctorEmail[30];
	

	char status[20];
	char appointMode[20];

	Date apoint_date;

	int startTime;
	int endTime;

public:
	Appointment() {};

	//accessor
	string getPatientEmail()
	{
		return this->patientEmail;
	}
	string getPatientName()
	{
		return this->patientName;
	}
	string getPatientCNIC()
	{
		return this->patientCNIC;
	}

	string getDoctorEmail()
	{
		return this->doctorEmail;
	}
	string getDoctorName()
	{
		return this->DoctorName;
	}
	string getDoctorCNIC()
	{
		return this->DoctorCNIC;
	}

	string getStatus()
	{
		return this->status;
	}
	string getAppointMode()
	{
		return this->appointMode;
	}

	Date getDate()
	{
		return this->apoint_date;
	}

	int getStartTime()
	{
		return this->startTime;
	}

	int getEndTime()
	{
		return this->endTime;
	}



	//mutators
	void setPatientEmail(string mail)
	{
		strcpy(this->patientEmail, mail.c_str());
	}
	void setDoctorEmail(string mail)
	{
		strcpy(this->doctorEmail, mail.c_str());
	}
	void setStatus(string status)
	{
		strcpy(this->status, status.c_str());
	}
	void setAppointMode(string mode)
	{
		strcpy(this->appointMode, mode.c_str());
	}

	void setDate(Date date)
	{
		this->apoint_date.setDay(date.getDay());
		this->apoint_date.setMonth(date.getMonth());
		this->apoint_date.setYear(date.getYear());
	}

	void setStartTime(int time)
	{
		this->startTime = time;
	}

	void setEndTime(int time)
	{
		this->endTime = time;
	}
	void setDoctorName(string name)
	{
		strcpy(this->DoctorName, name.c_str() );
	}
	void setDoctorCNIC(string cnic)
	{
		 strcpy(this->DoctorCNIC,cnic.c_str());
	}
	void setPatientName(string name)
	{
		strcpy(this->patientName, name.c_str());
	}
	void setPatientCNIC(string cnic)
	{
		strcpy(this->patientCNIC, cnic.c_str());
	}

	void display()
	{
		cout << "\tPatient Name: " << this->patientName << "\n\tPatient CNIC: " << this->patientCNIC << "\n\tPatient email: " << this->patientEmail << "\n\tDoctor Name: " << this->DoctorName << "\n\tDoctor Cnic: " << this->DoctorCNIC << "\n\tDoctor email: " << this->doctorEmail
			<< "\n\tAppointment Status: " << this->status << "\n\tAppointment Mode: " << this->appointMode 
			<< "\n\tDate: " << this->apoint_date.getDay() << " : " << this->apoint_date.getMonth() << " : "
			<< this->apoint_date.getYear() << "\n\tTiming: " << this->startTime << " to " << this->endTime << endl;
	}

};