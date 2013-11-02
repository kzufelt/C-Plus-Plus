#include <iostream>
#include <math.h>
#include "Employee.h"
#include "Salaried.h"
#include "Faculty.h"


double Faculty::amountPaid()
{
	if (HoursWorked>=(HOURS_EXPECTED/2))
	{
		double paid = (1 + .05 * TotalGradStudents) * payrate;
		int PaidInt=paid;
		int PaidDecimal=(paid-PaidInt)*100;
		paid= PaidInt + .01 * PaidDecimal;
		return paid;
	}

	return 0;
}