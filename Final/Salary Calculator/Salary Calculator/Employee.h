//CS 142 Winter 2012 Final Exam
//Kyle Zufelt

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

const int HOURS_EXPECTED = 170;

class Employee
{
	public:
		Employee(){};
		~Employee(){};

		virtual double amountPaid() = 0;
		
		string name;
		double payrate;
		int HoursWorked;
		double effectivePayRate;
		bool Bonus;
		int TotalGradStudents;
		string Type;
		
		
};

#endif