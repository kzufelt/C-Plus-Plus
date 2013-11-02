#ifndef HOURLY_H
#define HOURLY_H
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"

using namespace std;


class Hourly:public Employee
{
	public:
		Hourly(){};
		Hourly(string info){
			
			HoursWorked=0;
			int payrate_begin=info.find(" ");
			string numbers = info.substr(payrate_begin,100);
			stringstream ss (stringstream::in | stringstream::out);// These 3 lines are fairly similar to the example on the C++ reference site
			ss << numbers;
			ss >> payrate;//Set Pay Rate
			effectivePayRate=payrate;//Set Effective Pay Rate


			int name_begin=info.find(" ",payrate_begin+1);
			name=info.substr(name_begin+1);//Set Name

			int effectiveRateInt=effectivePayRate;
			int effectiveRateDecimal = (effectivePayRate-effectiveRateInt)*100;
			cout << "Entered " << name << " with an effective pay rate of $";
			if (effectiveRateDecimal!=0)
				cout << effectiveRateInt << "." << effectiveRateDecimal << "/hour.\n";
			else
				cout << effectiveRateInt << ".00/hour.\n";

			Type = "H";
			
		};
		~Hourly(){};

		double amountPaid();


		
		
};

#endif