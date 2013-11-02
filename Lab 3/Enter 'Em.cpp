#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "This program will calculate your CS 142 Grade" << endl;
	int student1labs[11];
	int student1exams[3];
	int student1latedays=0, student1examlatedays=0, student1totallatedays=0, student1total=0;
	
	int student2labs[11];
	int student2exams[3];
	int student2latedays=0, student2examlatedays=0, student2totallatedays=0, student2total=0;

	int sortvar;
	string studentname1, studentname2, student1grade, student2grade;

	
	
	cout << endl << "Enter the name of student 1: " << endl;
	getline (cin,studentname1);
	
	cout << endl << "Enter the name of student 2: " << endl;
	getline (cin,studentname2);

	
	//Begin Student 1 entry
	cout << endl << "Enter the grades for student 1: ";
	for (int n=0; n <= 9; n++)
	{
	cout << endl << "Lab " << n+1 << ": ";
	cin >> student1labs[n];

	if (n > 1 && n < 8)
	{
	if (student1labs[n] > 30 || student1labs[n] < 0)
	{
		cout << endl << "Sorry, the entered value is not within the allowed range!" << endl;
			system("pause");
			return 0;
	}
	}
	
	else if (n <= 1 || n >= 8)
	{
		if (student1labs[n] > 20 || student1labs[n] < 0)
	{
		cout << endl << "Sorry, the entered value is not within the allowed range!" << endl;
			system("pause");
			return 0;
	}
	}
	
	}

	cout << endl << "Lab 11: ";
	cin >> student1labs[10];
	if (student1labs[10] > 40)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student1labs[10] < 0)
		{
			cout << endl << "Sorry, the entered value must be a positive number!" << endl;
			system("pause");
			return 0;
		}



	for (int n=0; n <= 2; n++)
	{
		if (n <= 1)
	cout << endl << "Exam " << n+1 << ": ";
		else
			cout << endl << "Final: ";

	cin >> student1exams[n];
	if (student1exams[n] > 100)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student1exams[n] < 0)
		{
			cout << endl << "Sorry, the entered value must be a positive number!" << endl;
			system("pause");
			return 0;
		}
	}

	cout << endl << "Lab Late Days: ";
	cin >> student1latedays;
	if (student1latedays > 30)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student1latedays < -30)
		{
			cout << endl << "Sorry, the entered value must be greater than -30!" << endl;
			system("pause");
			return 0;
		}

	cout << endl << "Exam Late Days: ";
	cin >> student1examlatedays;
	if (student1examlatedays > 9)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student1examlatedays < 0)
		{
			cout << endl << "Sorry, no early days allowed for exams!" << endl;
			system("pause");
			return 0;
		}
	// End Student 1 entry

	// Begin Student 2 entry
	cout << endl << "Enter the grades for student 2: ";
	for (int n=0; n <= 9; n++)
	{
	cout << endl << "Lab " << n+1 << ": ";
	cin >> student2labs[n];

if (n > 1 && n < 8)
	{
	if (student2labs[n] > 30 || student2labs[n] < 0)
	{
		cout << endl << "Sorry, the entered value is not within the allowed range!" << endl;
			system("pause");
			return 0;
	}
	}
	
	else if (n <= 1 || n >= 8)
	{
		if (student2labs[n] > 20 || student2labs[n] < 0)
	{
		cout << endl << "Sorry, the entered value is not within the allowed range!" << endl;
			system("pause");
			return 0;
	}
	}
	}

	cout << endl << "Lab 11: ";
	cin >> student2labs[10];
	if (student2labs[10] > 40)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student2labs[10] < 0)
		{
			cout << endl << "Sorry, the entered value must be a positive number!" << endl;
			system("pause");
			return 0;
		}



	for (int n=0; n <= 2; n++)
	{
		if (n <= 1)
	cout << endl << "Exam " << n+1 << ": ";
		else
			cout << endl << "Final: ";

	cin >> student2exams[n];
	if (student2exams[n] > 100)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student2exams[n] < 0)
		{
			cout << endl << "Sorry, the entered value must be a positive number!" << endl;
			system("pause");
			return 0;
		}
	}

	cout << endl << "Lab Late Days: ";
	cin >> student2latedays;
	if (student2latedays > 30)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student2latedays < -30)
		{
			cout << endl << "Sorry, the entered value must be greater than -30!" << endl;
			system("pause");
			return 0;
		}

	cout << endl << "Exam Late Days: ";
	cin >> student2examlatedays;
	if (student2examlatedays > 9)
	{
		cout << endl << "Sorry, the entered value is above the maximum possible score!" << endl;
			system("pause");
			return 0;
	}
	if (student2examlatedays < 0)
		{
			cout << endl << "Sorry, no early days allowed for exams!" << endl;
			system("pause");
			return 0;
		}
	// End Student 2 entry

	// Begin Point Totaling
	for (int n=0; n <= 10; n++)
	{
		student1total=student1total + student1labs[n];
		student2total=student2total + student2labs[n];
	}
	for (int n=0; n <= 2; n++)
	{
		student1total=student1total + student1exams[n];
		student2total=student2total + student2exams[n];
	}

	student1total=student1total - (20 * student1examlatedays);
	student2total=student2total - (20 * student2examlatedays);
	
	if (student1latedays < -24)
		student1latedays = -24;
	if (student2latedays < -24)
		student2latedays = -24;

	if (student1latedays < 0)
		student1total=student1total - student1latedays;
	else
		student1total=student1total - (5 * student1latedays);

	

	
	if (student2latedays < 0)
		student2total = student2total - student2latedays;
	else
		student2total = student2total - (5 * student2latedays);

	if (student1total < 0)
		student1total=0;
	if (student2total < 0)
		student2total=0;

	// End point totaling

	//Begin Grade calculation
	if (student1total >= 570 && student1exams[2] >= 75)
	{
		student1grade="A";
	}
	if (student1total >= 540 && student1total <= 569)
	{
		student1grade="A-";
	}
	if (student1total >= 522 && student1total <= 539)
	{
		student1grade="B+";
	}
	if (student1total >= 498 && student1total <= 521)
	{
		student1grade="B";
	}
	if (student1total >= 480 && student1total <= 497)
	{
		student1grade="B-";
	}
	if (student1total >= 462 && student1total <= 479)
	{
		student1grade="C+";
	}
	if (student1total >= 438 && student1total <= 461)
	{
		student1grade="C";
	}
	if (student1total >= 420 && student1total <= 437)
	{
		student1grade="C-";
	}
	if (student1total >= 402 && student1total <= 419)
	{
		student1grade="D+";
	}
	if (student1total >= 378 && student1total <= 401)
	{
		student1grade="D";
	}
	if (student1total >= 360 && student1total <= 377)
	{
		student1grade="D-";
	}
	if (student1total <= 359)
	{
		student1grade="E";
	}

	if (student2total >= 570 && student2exams[2] >= 75)
	{
		student2grade="A";
	}
	if (student2total >= 540 && student2total <= 569)
	{
		student2grade="A-";
	}
	if (student2total >= 522 && student2total <= 539)
	{
		student2grade="B+";
	}
	if (student2total >= 498 && student2total <= 521)
	{
		student2grade="B";
	}
	if (student2total >= 480 && student2total <= 497)
	{
		student2grade="B-";
	}
	if (student2total >= 462 && student2total <= 479)
	{
		student2grade="C+";
	}
	if (student2total >= 438 && student2total <= 461)
	{
		student2grade="C";
	}
	if (student2total >= 420 && student2total <= 437)
	{
		student2grade="C-";
	}
	if (student2total >= 402 && student2total <= 419)
	{
		student2grade="D+";
	}
	if (student2total >= 378 && student2total <= 401)
	{
		student2grade="D";
	}
	if (student2total >= 360 && student2total <= 377)
	{
		student2grade="D-";
	}
	if (student2total <= 359)
	{
		student2grade="E";
	}

	// End grade calculation

	// Display Grades

	cout << "Enter 1 to sort by name or 2 to sort by grade: " << endl;
	cin >> sortvar;
	
	if (sortvar = 1)
	{
		if (studentname1 <= studentname2)
		{
			cout << studentname1 << " , " << student1total << " total points, Grade: " << student1grade << endl;
			cout << studentname2 << " , " << student2total << " total points, Grade: " << student2grade << endl;
		}
		else if (studentname1 > studentname2)
		{
			cout << studentname2 << " , " << student2total << " total points, Grade: " << student2grade << endl;
			cout << studentname1 << " , " << student1total << " total points, Grade: " << student1grade << endl;
		}
	else if (sortvar = 2)
	{
		if (student1total <= student2total)
		{
			cout << studentname1 << " , " << student1total << " total points, Grade: " << student1grade << endl;
			cout << studentname2 << " , " << student2total << " total points, Grade: " << student2grade << endl;
		}
		else if (student1total > student2total)
		{
			cout << studentname2 << " , " << student2total << " total points, Grade: " << student2grade << endl;
			cout << studentname1 << " , " << student1total << " total points, Grade: " << student1grade << endl;
		}
	}
	}

	


	system("pause");
	return 0;
}