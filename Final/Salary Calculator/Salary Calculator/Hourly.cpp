#include <iostream>
#include <math.h>
#include "Employee.h"
#include "Hourly.h"


double Hourly::amountPaid()
{
	if (HoursWorked>=HOURS_EXPECTED)
	{
		int overtime = HoursWorked - HOURS_EXPECTED;
		double paid = (HOURS_EXPECTED + 1.5 * overtime) * payrate;
		return paid;
	}
	else if (HoursWorked<HOURS_EXPECTED)
	{
		double paid = (HoursWorked) * payrate;
		return paid;
	}
	return 0;
}