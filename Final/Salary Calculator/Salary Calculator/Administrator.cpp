#include <iostream>
#include <math.h>
#include "Employee.h"
#include "Salaried.h"
#include "Administrator.h"


double Administrator::amountPaid()
{
	if (HoursWorked>=HOURS_EXPECTED)
	{
		double paid = 1.1 * payrate;
		int PaidInt=paid;
		int PaidDecimal=(paid-PaidInt)*100;
		paid= PaidInt + .01 * PaidDecimal;
		Bonus=true;
		return paid;
	}
	else if (HoursWorked>=(HOURS_EXPECTED/2))
	{
		return payrate;
	}
	return 0;
}