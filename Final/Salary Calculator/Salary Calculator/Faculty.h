#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Salaried.h"

using namespace std;


class Faculty:public Salaried
{
	public:
		Faculty(){};
		Faculty(string info):Salaried(info){
			
			TotalGradStudents=rand() % 5;
			Type = "F";

		};
		~Faculty(){};

		double amountPaid();

		
};

#endif