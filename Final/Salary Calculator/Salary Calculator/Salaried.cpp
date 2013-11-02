#include <iostream>
#include <math.h>
#include "Employee.h"
#include "Salaried.h"


double Salaried::amountPaid()
{
	if (HoursWorked>=(HOURS_EXPECTED/2))
	{
		return payrate;
	}
	return 0;
}