#include <iostream>
#include <string>
#include <vector>
#include <new>


using namespace std;
#include "userinfoClass.h"


int findUserint(userinfo user[], int size, string name)
{
	for (int i=0; i<size; i++)
	{
		if ((user[i]).firstname==name)
		{
		return i;
		}
	}
	return -1;	
}
int findUserrelation(userinfo user[], int size, string user_name, string friend_name)//Returns the element where the friend is listed, -1 if they are not
{
	for (size_t t=0;t<user[findUserint(user, size, user_name)].friends.size();t++)
	{
			if (user[findUserint(user, size, user_name)].friends[t]==user[findUserint(user, size, friend_name)].firstname)
			{
			return t;
			}

		
	}
	return -1;	
}
string findFood(userinfo user[], int size, string user_name)
{
	string s;
	for(size_t t=0;t<size;t++)
	{
		if (t!=findUserint(user, size, user_name) && user[t].favoritefood==user[findUserint(user, size, user_name)].favoritefood)
		{
			s.append(user[t].firstname);
			s.append("\n\t");
		}
	}
	return s;
}
int getOption(int range);
string getName(string message);


int main()
{
	const int MAXIMUM_SIZE = 100;
	int option;
	int size = 0;
	userinfo userlist[MAXIMUM_SIZE];
	

	cout << "Welcome to VisageTome!\n\n";

	do{
	cout << "Menu\n\t1 - Register a new user\n\t2 - Add a friendship\n\t3 - Remove a friendship\n\t4 - Modify a user's favorite food\n\t5 - Display all current users\n\t6 - Display all users that share your favorite food\n\t7 - Quit\n";
	option = getOption(7);

	if (option == 1)//Register a new user
	{
		string new_name = getName("Please enter the new user's first name:");
		if (findUserint(userlist, size, new_name)==-1)
		{
			userlist[size].addNewUser (new_name);
			size++;
			
		}
		else if (findUserint(userlist, size, new_name)!=-1)
		{
			cout << "A user with that name has already registered!\n";
		}
		
	}

	else if (option == 2)//Add a friendship
	{
		string user_name = getName("What is your first name?:");
		if (findUserint(userlist, size, user_name)==-1)
		{
			cout << "You have not yet registered with VisageTome.\n";
		}
		else if (findUserint(userlist, size, user_name)!=-1)
		{
			string friend_name = getName("With whom would you like to establish a friendship?:");
			if (friend_name==user_name)
			{
				cout << "You cannot add yourself as a friend!\n";
			}
			else if (findUserint(userlist, size, friend_name)==-1)
			{
				cout << friend_name << " has not yet registered with VisageTome.\n";
			}
			else if (findUserrelation(userlist, size, user_name, friend_name)!=-1)
			{
				cout << "You are already friends with " << friend_name << ".\n";
			}
			else if (findUserint(userlist, size, friend_name)!=-1)
			{
				userlist[findUserint(userlist, size, user_name)].friends.push_back( friend_name );//Add friend to the new user's list
				userlist[findUserint(userlist, size, friend_name)].friends.push_back( user_name );//Add new user to the friend's list
			}
		}

	}

	else if (option == 3)//Remove a friendship
	{
		string user_name = getName("What is your first name?:");
		if (findUserint(userlist, size, user_name)==-1)
		{
			cout << "You have not yet registered with VisageTome.\n";
		}
		else if (findUserint(userlist, size, user_name)!=-1)
		{
			string friend_name = getName("With whom would you like to end a friendship?:");
			if (findUserint(userlist, size, friend_name)==-1)
			{
				cout << friend_name << " has not yet registered with VisageTome.\n";
			}
			else if (findUserrelation(userlist, size, user_name, friend_name)==-1)
			{
				cout << "You are not currently friends with " << friend_name << ".\n";
			}
			else if (findUserint(userlist, size, friend_name)!=-1)
			{
				userlist[findUserint(userlist, size, user_name)].friends.erase (userlist[findUserint(userlist, size, user_name)].friends.begin()+findUserrelation(userlist, size, user_name, friend_name));//Remove friend from the user's list
				userlist[findUserint(userlist, size, friend_name)].friends.erase (userlist[findUserint(userlist, size, friend_name)].friends.begin()+findUserrelation(userlist, size, friend_name, user_name));//Remove user from the friend's list
			}
		}
	}

	else if (option == 4)//Modify a user's favorite food
	{
		string user_name = getName("What is your first name?:");
		if (findUserint(userlist, size, user_name)==-1)
		{
			cout << "You have not yet registered with VisageTome.\n";
		}
		else if (findUserint(userlist, size, user_name)!=-1)
		{
			string new_food = getName("What is your favorite food?:");
			userlist[findUserint(userlist, size, user_name)].favoritefood = new_food;
		}
	}

	else if (option == 5)//Display all current users
	{
		for (int i=0;i<size;i++)
		{
			cout << "User: " << userlist[i].firstname << endl;
			cout << "\tFavorite Food: " << userlist[i].favoritefood << endl;
			cout << "\tFriends:\t";
			for (size_t t=0;t<userlist[i].friends.size();t++)
			{
				cout << userlist[i].friends[t] << "\n\t\t\t";
			}
			if (userlist[i].friends.size( )==0)
			{
				cout << "None";
			}
			cout << endl;
		}
	}

	else if (option == 6)//Display all users that share your favorite food
	{
		string user_name = getName("What is your first name?:");
		if (findUserint(userlist, size, user_name)==-1)
		{
			cout << "You have not yet registered with VisageTome.\n";
		}
		else if (findUserint(userlist, size, user_name)!=-1)
		{
			cout << "The following people share your love of "<< userlist[findUserint(userlist, size, user_name)].favoritefood << ":\n\t" << findFood(userlist, size, user_name);
			if (findFood(userlist, size, user_name)=="")
				cout << "None" << endl;
			cout << endl;
		}
	}



	}
	while (option != 7);

	system("pause");
	return 0;
}
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