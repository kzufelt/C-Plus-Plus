#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include <iostream>
#include <string>
#include <vector>
#include "Employee.h"
#include "Salaried.h"

using namespace std;


class Administrator:public Salaried
{
	public:
		Administrator(){};
		Administrator(string info):Salaried(info){
			
			Bonus=false;
			Type = "A";

		};
		~Administrator(){};

		double amountPaid();
		
};

#endif