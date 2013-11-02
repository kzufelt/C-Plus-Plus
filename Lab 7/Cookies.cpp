#include <iostream>
#include <string>

using namespace std;

//-------------------------------------------------------------------------------------
string * findOrder(string * cookies[], int * size, string name);
void addOrder(string * cookies[], int * size, string new_name);
int deliverOrder(string * cookies[], int * size, string name);
bool modifyOrder(string * cookies[], int * size, string original_name, string new_name);
string displayOrders(string * cookies[], int * size);
//-------------------------------------------------------------------------------------
/*
	findOrder
	
	Returns a memory address found in the given array that references a string with the same data
	as the given string.  Returns null if no such string is found.
	
	It is recommended that you use this function within your other functions.  If you do not, you
	must still complete this function as described above.
*/
string * findOrder(string * cookies[], int * size, string name)
{
	for (int i=0; i<*size; i++)
	{
		if (*cookies[i]==name)
		{
		return cookies[i];
		}
	}
	return 0;	
}
int findOrder2(string * cookies[], int * size, string name)
{
	for (int i=0; i<*size; i++)
	{
		if (*cookies[i]==name)
		{
		return i;
		}
	}
	return -1;	
}
//-------------------------------------------------------------------------------------
/*
	addOrder
	
	Adds the memory address of a new string to the given array.  The new string should have the 
	same data as that of the given string.  
	
	A string may already exist containing the same data as the given string (ie, the string 
	passed to this function as a parameter) and whose memory address is already stored within 
	the given array.  In this situation, add to the array the memory address of the string that 
	already exists rather than creating a new string.
	
	Update the reference of size appropriately.
*/
void addOrder(string * cookies[], int * size, string new_name)
{
	
	if (findOrder(cookies, size, new_name) != 0)
	{
		cookies[*size]=findOrder(cookies, size, new_name);
	}
	else if (findOrder(cookies, size, new_name) == 0)
	{
		string * s = new string;
		cookies[*size]=s;
		*s=new_name;
	}
	(*size)++;
}
//-------------------------------------------------------------------------------------
/*
	deliverOrder
	
	Removes all references to strings containing the same data as the given string and reports 
	the number of string references removed.  The overall order of the list is unchanged.
	
	Update the reference of size appropriately.
*/
int deliverOrder(string * cookies[], int * size, string name)
{
	int boxes=0;
	while (findOrder2(cookies, size, name) != -1)
	{
		for (int i=findOrder2(cookies, size, name); i<*size; i++)
		{
		  cookies[i]=cookies[i+1];
		}
		(*size)--;
		boxes++;
	}
	return boxes;
	
	
}
//-------------------------------------------------------------------------------------
/*
	modifyOrder
	
	Searches the given array for a memory address to a string that contains the same data as the 
	first given string.  
	
	If found, the data of the found string is changed to match the data of the second given string,
	and the function returns true.  If not found, the function returns false.
*/
bool modifyOrder(string * cookies[], int * size, string original_name, string new_name)
{
	if (findOrder2(cookies, size, original_name) != -1)
	{
		if (findOrder2(cookies, size, new_name) != -1)
		{
			cookies[findOrder2(cookies, size, original_name)]=cookies[findOrder2(cookies, size, new_name)];
		}
		else if (findOrder2(cookies, size, new_name) == -1)
		{
			*cookies[findOrder2(cookies, size, original_name)]=new_name;
		}
			return true;
	}
	else if (findOrder2(cookies, size, original_name) == -1)
	{
			return false;
	}
	
}
//-------------------------------------------------------------------------------------
/*
	displayOrders
	
	Returns a string containing a list of names referred to in the given array.
	Each index in the array represents a particular box of cookies, and there may be more than 
	one box for each customer.  Therefore, this function's output may include the same name 
	multiple times.
*/
string displayOrders(string * cookies[], int * size)
{
	for (int i=0;i<*size;i++)
	{
		cout << *cookies[i] << ", ";
	}
	return "";
}

//-------------------------------------------------------------------------------------






//-------------------------------------------------------------------------------------
int getOption(int range);
string getName(string message);
//-------------------------------------------------------------------------------------
int main()
{
	const int MAXIMUM_SIZE = 10;
	string * cookies [MAXIMUM_SIZE] = {};
	int x = 0;
	int * size = &(x);
	
	bool done = false;


	while(!done)
	{
		//Get menu option
		cout << "MENU:" << endl;
		cout << "\t1. Add an order\n\t2. Deliver an order\n\t3. Modify an order\n\t4. Quit\n" << endl;
		int option = getOption(4);
		

		//Adding
		if(option==1)
		{
			if((*size) >= MAXIMUM_SIZE)
			{
				cout << "The car is full; cannot add more orders" << endl;
			}
			else
			{
				string new_name = getName("Please enter the customer's name for the new order:");
				addOrder(cookies, size, new_name);
				cout << "Cookies added for costumer [" << new_name << "]" << endl;
			}
		}

		//Delivering
		else if(option==2)
		{
			string name = getName("Please enter the customer's name for the delivery:");
			int delivered = deliverOrder(cookies, size, name);
			cout << "Delivered " << delivered << " boxes of cookies to [" << name << "]" << endl;
		}

		//Modifying
		else if(option==3)
		{
			string original_name = getName("Please enter the original customer's name:");
			string new_name = getName("Please enter the new customer's name:");
			bool changed = modifyOrder(cookies,size,original_name,new_name);
			if(changed)
			{
				cout << "Changed name from [" << original_name << "] to [" << new_name << "]" << endl;
			}
			else
			{
				cout << "Could not find a customer with the name: [" << original_name << "]" << endl;
			}
		}

		//Quitting
		else if(option==4)
		{
			done = true;
		}
		
		
		cout << displayOrders(cookies, size) << endl;
	}

	cout << "Thank you for using the cookie tracker!" << endl;
	//The following line may not work on all systems; therefore, you may change this line as needed
	system("pause");
	return 0;
}
//-------------------------------------------------------------------------------------
int getOption(int range)
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
		else if(input < 1  ||  input > range)
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
//-------------------------------------------------------------------------------------
string getName(string message)
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
//-------------------------------------------------------------------------------------