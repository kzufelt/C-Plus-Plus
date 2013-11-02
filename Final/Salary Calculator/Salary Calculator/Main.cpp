#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Hourly.h"
#include "Salaried.h"
#include "Administrator.h"
#include "Faculty.h"

using namespace std;

vector<Employee*> EmployeeList;

int getOption(int minrange, int maxrange)//This function is more or less taken from one of the labs we did
{
	int input = 0;
	bool done = false;
	while(!done)
	{
		cout << "Please select an option:" << endl;
		input = 0;
		cin >> input;
		cin.ignore(1000,'\n');
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Error: Invalid option" << endl;
		}
		else if(input < minrange  ||  input > maxrange)
		{
			cout << "Error: Invalid option number" << endl;
		}
		else
		{
			done = true;
		}
	}
	return input;
}

string getName(string message)//This function is more or less taken from one of the labs we did
{
	string input = "";
	bool done = false;
	while(!done)
	{
		cout << message << endl;
		input = "";
		getline(cin, input);
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(1000,'\n');
			cout << "Error: Invalid name" << endl;
		}
		else
		{
			done = true;
		}
	}
	return input;
}

bool correctFormat(string info)
{
	int foundType=info.find(" ");//Checks for the first space 
	if (foundType==string::npos)
	{
		cout << "Need more data.\n";
		return false;
	}
	string employeeType= info.substr(foundType-1,1);
	if (employeeType!="H" && employeeType!="S" && employeeType!="A" && employeeType!="F")
	{
		cout << "The requested employee type is not valid.\n";
		return false;
	}

	int foundSalary=info.find(" ",foundType+1);// Move forward to the hourly rate
	
		if (foundSalary==string::npos)
		{
			cout << "There is not enough data (no name).\n";
			return false;
		}
		string SalaryString = info.substr(foundType+1,(foundSalary-foundType-1));
		for (int n=0;n<SalaryString.length();n++)
		{
			if (!isdigit(SalaryString[n]) && SalaryString.find(".")==string::npos)
				{
					cout << "The hourly rate must be a number.\n";
					cout << SalaryString;
					return false;
				}
		}
	double salary;//Here we will make sure that the salary is positive
	stringstream ss (stringstream::in | stringstream::out);
	ss << SalaryString;
	ss >> salary;
	
		if (salary<=0)
		{
			cout << "No negative salary (as much as we would love that)!\n";
			return false;
		}
//I'm assuming here that the name will be fine, and in whatever format they want to store it in
	
	return true;
}

int findName(string info, int size)
{
	int found=info.find(" ");//Pulls out everything after the hourly rate
	found=info.find(" ",found+1);
	if (found==string::npos)//If the string is only a name, this will search for the whole string
		found=-1;
	
	string name = info.substr(found+1);
	for (int n=0;n<size;n++)
	{
		if(name==(*EmployeeList[n]).name)
			{
				
				return n;
			}
	}
	return -1;
}

int repeatName(string info, vector<string> Data)
{
	int found=info.find(" ");//Pulls out everything after the hourly rate
	found=info.find(" ",found+1);
	
	string name = info.substr(found+1);
	for (int n=0;n<Data.size();n++)
	{
		int found2=Data[n].find(" ");//Pulls out everything after the hourly rate
		found2=Data[n].find(" ",found2+1);
		string DataName = Data[n].substr(found2+1);
		if(name==DataName)
			{
				cout << name << " " << DataName << endl;
				return n;
			}
	}
	return -1;
}

void displayList(int start, int end)
{
	for (int n=start;n<=end;n++)
			{
						int PayRateInt=(*EmployeeList[n]).payrate;
						int amountPaidInt=(*EmployeeList[n]).amountPaid();
						int amountPaidDecimal = ((*EmployeeList[n]).amountPaid()-amountPaidInt)*100;
						int PayRateDecimal = ((*EmployeeList[n]).payrate-PayRateInt)*100;
						cout << (*EmployeeList[n]).name << ", " << (*EmployeeList[n]).HoursWorked << " hours, $" << amountPaidInt << ".";
						if (amountPaidDecimal==0)
							cout << "00 paid, $" << PayRateInt << ".";
						else
							cout << amountPaidDecimal << " paid, $" << PayRateInt << ".";
						if (PayRateDecimal==0)
							 cout << "00";
						else
							 cout << PayRateDecimal;

						if ((*EmployeeList[n]).Type == "H")
						{
							cout << "/hour.\n";
						
						}
						else if ((*EmployeeList[n]).Type == "S")
						{
							cout << "/month.\n";
						}
						else if ((*EmployeeList[n]).Type == "A")
						{
							cout << "/month, ";
							if ((*EmployeeList[n]).Bonus == true)
							{
								cout << "bonus.\n";
							}
							else
							{
								cout << "no bonus.\n";
							}
						}
						else if ((*EmployeeList[n]).Type == "F")
						{
							cout << "/month, ";
							cout << (*EmployeeList[n]).TotalGradStudents << " students.\n";
						}
	}
}

int main()
{
	int menuOption=0, newHours, sortOption=0;
	string info, FileName;
	vector<string> FileData;
	int size=0;
	Employee* TemporaryEmployee;
	
	while(menuOption!=9)
	{
		cout << "Menu\n\t1 - Add Employee Manually\n\t2 - Add Employee File\n\t3 - Remove Employee\n\t4 - Display Individual Employee Info\n\t5 - Sort Employees\n\t6 - Update Hours Worked\n\t7 - Display Sorted Employee Info\n\t8 - Advance to the Next Month\n\t9 - End Program\n";
		menuOption=getOption(1,9);

		
		if (menuOption==1)//Add Employee Manually
		{
			info=getName("Enter this employee's classification, pay rate, and name, separated by spaces:\n(H - Hourly, S - Salaried, A - Administrator, F - Faculty)\n");
			if (!correctFormat(info))
			{
				//Do Nothing, this prevents an incorrectly formatted string from being entered
			}
			else if (findName(info, size)!=-1)
			{
				cout << "That employee is already in our database.\n";
			}
			else if (info.find("H ")!=string::npos)
			{				
				EmployeeList.push_back(new Hourly(info));
				size+=1;
				
			}
			else if (info.find("S ")!=string::npos)
			{				
				EmployeeList.push_back(new Salaried(info));
				size+=1;
			}
			else if (info.find("A ")!=string::npos)
			{				
				EmployeeList.push_back(new Administrator(info));
				size+=1;
			}
			else if (info.find("F ")!=string::npos)
			{				
				EmployeeList.push_back(new Faculty(info));
				size+=1;
			}
			else
			{
				cout << "This user data was not entered.\n";
			}
			
		}
		

		else if (menuOption==2)//Add Employee File
		{
			FileData.clear();
			FileName=getName("Please enter the name of a text file to upload restaurant data.\n(Example - sample.txt)\n");//Start to load data file
		
			fstream userFile (FileName);
	
			while (!userFile.is_open())
			{
				cout << "Sorry. The filename you entered, \"" << FileName << "\", is not valid.\nPlease note that this program only accepts text files.\nPlease make sure that your file is in the same directory as this program.\n" << endl;
				FileName=getName("Please enter a filename to upload restaurant data:\n");
				userFile.open (FileName);
			}
			if (userFile.is_open())
			{
				while ( userFile.good() )
					{
						getline (userFile,info);
					  if (!correctFormat(info))
					  {
						  cout << "This line is incorrectly formatted:\n" << info << endl;
						  FileData.clear();
						  userFile.close();
					  }
					  else if (findName(info, size)!=-1)
					  {
						  cout << "One or more of the names in this file has already been entered into this database.\n";
						  FileData.clear();
						  userFile.close();
					  }
					  else if (repeatName(info, FileData)!=-1)
					  {
						  cout << "One or more of the names in this file is repeated within the file.\n";
						  FileData.clear();
						  userFile.close();
					  }
					  else if (correctFormat(info))
					  {
						  FileData.push_back(info);
					  }
					  
					}
			}//End to load data file

			if (FileData.size()>0)
			{
				for (int n=0;n<FileData.size();n++)
				{
						if (!correctFormat(FileData[n]))
						{
							//Do Nothing, this prevents an incorrectly formatted string from being entered
						}
						else if (FileData[n].find("H ")!=string::npos)
						{				
							EmployeeList.push_back(new Hourly(FileData[n]));
							size+=1;
				
						}
						else if (FileData[n].find("S ")!=string::npos)
						{				
							EmployeeList.push_back(new Salaried(FileData[n]));
							size+=1;
						}
						else if (FileData[n].find("A ")!=string::npos)
						{				
							EmployeeList.push_back(new Administrator(FileData[n]));
							size+=1;
						}
						else if (FileData[n].find("F ")!=string::npos)
						{				
							EmployeeList.push_back(new Faculty(FileData[n]));
							size+=1;
						}
						
				}
			}
		}

		else if (menuOption==3)//Remove Employee
		{
			info=getName("Who would you like to remove?\n");
			if(findName(info, size)==-1)
			{
				cout << "That employee does not exist in our database.\n";
			}
			else
			{
				EmployeeList[findName(info, size)]=EmployeeList[size-1];
				EmployeeList.pop_back();
				size-=1;
				cout << "Removed " << info << ".\n";
			}
		}

		else if (menuOption==4)//Display Individual Employee Info
		{
			info=getName("Enter an employee to display.\n");
			if(findName(info, size)==-1)
			{
				cout << "That employee does not exist in our database.\n";
			}
			else
			{
				displayList(findName(info, size),findName(info, size));
			}

		}

		else if (menuOption==5 && size > 1)//Sort Employees by Effective Hourly Pay or Name
		{
			cout << "Enter 1 to sort by increasing effective hourly pay, or 2 to sort alphabetically by name:\n";
			sortOption=getOption(1,2);
			if (sortOption==1)//By pay
			{
				for (int n=0;n<size;n++)
				{
					for (int t=size-1;t>n;t--)
					{
						if ((*EmployeeList[n]).effectivePayRate > (*EmployeeList[t]).effectivePayRate)
						{
							TemporaryEmployee=EmployeeList[n];
							EmployeeList[n]=EmployeeList[t];
							EmployeeList[t]=TemporaryEmployee;
						}
					}
				}
			}
			else if (sortOption==2)//By name
			{
				for (int n=0;n<size;n++)
				{
					for (int t=size-1;t>n;t--)
					{
						if ((*EmployeeList[n]).name > (*EmployeeList[t]).name)
						{
							TemporaryEmployee=EmployeeList[n];
							EmployeeList[n]=EmployeeList[t];
							EmployeeList[t]=TemporaryEmployee;
						}
					}
				}
			}
		}

		else if (menuOption==6)//Update Hours Worked
		{
			info=getName("Which employee's hours would you like to update?\n");
			if(findName(info, size)==-1)
			{
				cout << "That employee does not exist in our database.\n";
			}
			else 
			{
				cout << (*EmployeeList[findName(info, size)]).name << " has worked " << (*EmployeeList[findName(info, size)]).HoursWorked << " hours thus far this month.\n";
				cout << "How many hours would you like to add to this total?\n";
				cin >> newHours;
				(*EmployeeList[findName(info, size)]).HoursWorked+=newHours;
				cout << (*EmployeeList[findName(info, size)]).name << " has now worked " << (*EmployeeList[findName(info, size)]).HoursWorked << " hours thus far this month.\n";
			}
		}

		else if (menuOption==7 && size > 0)//Display Sorted Employee Info
		{
			displayList(0,size-1);
		}

		else if (menuOption==8 && size >0)//Advance to the Next Month
		{
			cout << "Data from the current month:\n";
			displayList(0,size-1);
			for (int n=0;n<size;n++)
			{
				(*EmployeeList[n]).HoursWorked=0;
				(*EmployeeList[n]).TotalGradStudents=rand() % 5;
			}
			cout << "Month now advanced. All employee hours reset to 0.\n";
		}
	}
	return 0;
}