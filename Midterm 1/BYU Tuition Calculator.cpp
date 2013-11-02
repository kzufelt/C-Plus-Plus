#include <iostream>
#include <string>
using namespace std;

int main()
{
	//Kyle Zufelt
	//CS 142 Winter 2012 Midterm 1

	int errorcounter = 0, totalentries = 0, creditmin = 5, studentnumber = 0;
	double credithours[100], tuition[100], averagecredits = 0.0, totalcredits = 0.0, averagetuition = 0.0, totaltuition = 0.0, maxtuition = 0, mintuition = 4560.00;
	string newstudent = "yes", undergrad = "yes", churchmember;

	cout << "BYU Winter 2012 Tuition Calculator";

	while (newstudent == "yes") // This section will allow the user to enter a new student's information
	{
		//Begin to determine if student is an undergrad
		cout << "\n\nAre you entering information about an undergraduate student (\"yes\" or \"no\")?" << endl;
		getline (cin,undergrad); // This command came from the C++ reference
		totalentries = totalentries + 1;

		if (undergrad == "no")
		{
			cout << "This program deals only with undergraduate students." << endl;
			cout << "Enter another student (\"yes\" or \"no\")?" << endl;
			getline (cin,newstudent);
			continue;// This command came from the C++ reference
			
		}
		if (undergrad != "no" && undergrad != "yes")
		{
			cout << "Only \"yes\" or \"no\" are acceptable answers to this question." << endl;
			errorcounter = errorcounter + 1;
			cout << "Enter another student (\"yes\" or \"no\")?" << endl;
			getline (cin,newstudent);
			continue;
		}

		//End determine if student is an undergrad

		//Begin to determine if student is LDS
		cout << "Does the student belong to the LDS Church (\"yes\" or \"no\")?" << endl;
		getline (cin,churchmember);
		totalentries = totalentries + 1;

		if (churchmember != "no" && churchmember != "yes")
		{
			cout << "Only \"yes\" or \"no\" are acceptable answers to this question." << endl;
			errorcounter = errorcounter + 1;
			cout << "Enter another student (\"yes\" or \"no\")?" << endl;
			getline (cin,newstudent);
			continue;
		}
		//End determine if student is LDS

		//Begin to determine credit hours

		cout << "Credit hours Winter 2012:" << endl;
		cin >> credithours[studentnumber];
		totalentries = totalentries + 1;

		int credithours10 = 10 * credithours[studentnumber]; // This is so that I can use the % command in the next line
		while (credithours10 % creditmin > 0)
		{
			errorcounter = errorcounter + 1;
			cout << "A student cannot enroll for " << credithours[studentnumber] << " credit hours." << endl;
			cout << "Credit hours Winter 2012:" << endl;
			cin >> credithours[studentnumber];
			totalentries = totalentries + 1;
			credithours10 = 10 * credithours[studentnumber];
		}
		
		if (credithours[studentnumber] < 0.5 || credithours[studentnumber] > 25.0)
		{
			cout << "The number of credit hours must be between 0.5 and 25.0, inclusive." << endl;
			errorcounter = errorcounter + 1;
			cout << "Enter another student (\"yes\" or \"no\")?" << endl;
			getline (cin,newstudent);
			getline (cin,newstudent);
			continue;
		}
		//End determine credit hours

		//Begin Calculate Tuition
		if (churchmember == "yes")
		{
			if (credithours[studentnumber] >= 12)
			{
				tuition[studentnumber] = 2280.00;
				
			}
			else if (credithours[studentnumber] >= 9 && credithours[studentnumber] <= 11.5)
			{
				tuition[studentnumber] = 2210.00;
				
			}
			else if (credithours[studentnumber] <= 8.5)
			{
				tuition[studentnumber] = 234.00 * credithours[studentnumber];
				
			}
		}

		else if (churchmember == "no")
		{
			if (credithours[studentnumber] >= 12)
			{
				tuition[studentnumber] = 4560.00;
				
			}
			else if (credithours[studentnumber] >= 9 && credithours[studentnumber] <= 11.5)
			{
				tuition[studentnumber] = 4435.00;
				
			}
			else if (credithours[studentnumber] <= 8.5)
			{
				tuition[studentnumber] = 468.00 * credithours[studentnumber];
				
			}
		}
		int tuitionint = tuition[studentnumber];//These next 3 lines ensure that two decimal points are printed. They are repeated several times in the "summary" section.
		int tuitiondecimal1 = (tuition[studentnumber] - tuitionint) * 10;
		int tuitiondecimal2 = (tuition[studentnumber] - tuitionint - 0.1 * tuitiondecimal1) * 100;
		cout << "Tuition is $" << tuition[studentnumber] << "." << tuitiondecimal1 << tuitiondecimal2  << " for Winter 2012" << endl;
		//End Calculate Tuition

		cout << "Enter another student (\"yes\" or \"no\")?" << endl;
		getline (cin,newstudent);
		getline (cin,newstudent);
		studentnumber = studentnumber + 1;
		if (studentnumber >= 100)//This is to make sure that the number of students doesn't exceed the size of the initialized arrays
		{
			cout << "This program can only accept information for 100 students." << endl;
			studentnumber = 99;
			newstudent = "no";
		}
	}
	
	if (studentnumber >= 1)
	{
	//Begin Summary
	cout << "\n\nYou entered valid information for " << studentnumber << " students" << endl;

	//Begin Average credit calculation
	for (int n=0; n<=studentnumber-1; n=n+1)
	{
		totalcredits = totalcredits + credithours[n];
	}
	averagecredits = totalcredits / studentnumber;
	int averagecreditsint = averagecredits;
	int averagecreditsdecimal = (averagecredits - averagecreditsint) * 10;
	cout << "The average credit-hour enrollment is " << averagecreditsint << "." << averagecreditsdecimal << endl;
	//End Average credit calculation

	//Begin Average tuition calculation
	for (int n=0; n<=studentnumber-1; n=n+1)
	{
		totaltuition = totaltuition + tuition[n];
	}
	averagetuition = totaltuition / studentnumber;
	int averagetuitionint = averagetuition;
	int averagetuitiondecimal1 = (averagetuition - averagetuitionint) * 10;
	int averagetuitiondecimal2 = (averagetuition - averagetuitionint - 0.1 * averagetuitiondecimal1) * 100;
	cout << "The average tuition is $" << averagetuitionint << "." << averagetuitiondecimal1 << averagetuitiondecimal2 << endl;
	//End Average tuition calculation

	//Begin highest tuition calculation
	for (int n=0; n<=studentnumber-1; n=n+1)
	{
		if (tuition[n] > maxtuition)
		{
			maxtuition = tuition[n];
		}
	}
	int maxtuitionint = maxtuition;
	int maxtuitiondecimal1 = (maxtuition - maxtuitionint) * 10;
	int maxtuitiondecimal2 = (maxtuition - maxtuitionint - 0.1 * maxtuitiondecimal1) * 100;
	cout << "The highest tuition is $" << maxtuitionint << "." << maxtuitiondecimal1 << maxtuitiondecimal2 << endl;
	//End highest tuition calculation

	//Begin lowest tuition calculation
	for (int n=0; n<=studentnumber-1; n=n+1)
	{
		if (tuition[n] < mintuition)
		{
			mintuition = tuition[n];
		}
	}
	int mintuitionint = mintuition;
	int mintuitiondecimal1 = (mintuition - mintuitionint) * 10;
	int mintuitiondecimal2 = (mintuition - mintuitionint - 0.1 * mintuitiondecimal1) * 100;
	cout << "The lowest tuition is $" << mintuitionint << "." << mintuitiondecimal1 << mintuitiondecimal2 << endl;
	//End lowest tuition calculation

	//Begin error % calculation
	double errorpercent = 1.0 - 1.0 * errorcounter / totalentries;
	int errorpercentrounded = errorpercent * 100;
	cout << errorpercentrounded << "% of your entries required no reprompting" << endl;
	//End error % calculation
	//End Summary
	}
	else if (studentnumber == 0)
	{
		cout << "You did not enter any valid information.\n";
	}

	system("pause");
}