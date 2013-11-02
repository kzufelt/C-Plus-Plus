#include <iostream>
#include <array>
#include <string>
#include <time.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>


using namespace std;
#include "restaurantClass.h"


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
int main()
{
	restaurantClass restaurants;
	string newrestaurantname, newRankingString, restaurantFileName, writeFile;
	char newRankingChar[1];
	int menuoption=0, totalrounds, newRankingInt, newRankingIntTens;
	restaurants.size=0;

	cout << "Food Fight\n";

	restaurantFileName=getName("Please enter the name of a .txt file to upload restaurant data:\n");//Start to load data file
	restaurantFileName.append(".txt");

	fstream userFile (restaurantFileName);
	
	while (!userFile.is_open())
	{
		cout << "Sorry. The filename you entered, \"" << restaurantFileName << "\", is not valid.\nPlease note that this program only accepts text files.\nPlease make sure that your file is in the same directory as this program.\n" << endl;
		restaurantFileName=getName("Please enter a filename to upload restaurant data:\n");
		restaurantFileName.append(".txt");
		userFile.open (restaurantFileName);
	}
	if (userFile.is_open())
	{
		while ( userFile.good() )
			{
			  getline(userFile,newrestaurantname,',');
			  restaurants.restaurantNames.push_back(newrestaurantname);
			  cout << newrestaurantname << " with a score of ";

			  getline(userFile,newRankingString);//This converts whatever comes after the "," to a string
			  newRankingChar[0]=newRankingString[newRankingString.size()-1];//This pulls the last digit of the string into a char
			  newRankingInt = atoi (newRankingChar);//This converts the ones digit to an int
			  if (newRankingString.size() > 1)
			  {
			  newRankingChar[0]=newRankingString[newRankingString.size()-2];//This pulls the tens digit of the string into a char
			  newRankingIntTens = atoi (newRankingChar);//This converts the tens digit to an int
			  }
			  else newRankingIntTens=0;
			  restaurants.rankings.push_back(newRankingInt+10*newRankingIntTens);
			  cout << newRankingString << "\n";
			  restaurants.size++;

			}
	}//End to load data file
 

	do
	{
	cout << "\n\n\nMenu\n\n\t1 - Display all restaurants\n\t2 - Add a restaurant\n\t3 - Remove a restaurant\n\t4 - Shuffle the array\n\t5 - Begin the tournament\n\t6 - Save and Quit\n\t7 - Quit without saving\n";
	cin >> menuoption;
	cout << "\n\n";
	if (menuoption==1)//Display
	{
		for (int n=0;n<restaurants.size;n++)
		{
			cout << restaurants.restaurantNames[n] << " with a score of " << restaurants.rankings[n] << endl;
		}
		cout << "Total Restaurants: " << restaurants.size << endl;
	}


	else if (menuoption==2)//Add
	{
			getline(cin,newrestaurantname);
			newrestaurantname=getName("Which restaurant would you like to add?: ");
			if (restaurants.findrestaurant(newrestaurantname)!=-1)
			{
				cout << "That restaurant is already in the list.\n";
				continue;
			}
			else if (restaurants.findrestaurant(newrestaurantname)==-1)
			{
				restaurants.restaurantNames.push_back(newrestaurantname);
				restaurants.rankings.push_back(0);
				restaurants.size++;
				cout << "Added " << newrestaurantname << " to the list.\n";
			}
	}


	else if (menuoption==3)//Remove
	{
		cout << "\nWhich restaurant would you like to remove?:";
			getline (cin,newrestaurantname);
			getline (cin,newrestaurantname);
			if (restaurants.findrestaurant(newrestaurantname)==-1)
			{
				cout << "That restaurant is not on the list";
				continue;
			}
			else if (restaurants.findrestaurant(newrestaurantname)!=-1)
			{
				restaurants.rankings.erase (restaurants.rankings.begin() + restaurants.findrestaurant(newrestaurantname));
				restaurants.restaurantNames.erase (restaurants.restaurantNames.begin() + restaurants.findrestaurant(newrestaurantname));
				cout << "Removed " <<  newrestaurantname << " from the list.\n";
				restaurants.size--;
			}
	}


	else if (menuoption==4)//Shuffle
	{
		restaurants.shuffle();
		for (int n=0;n<restaurants.size;n++)
		{
			cout << restaurants.restaurantNames[n] << " with a score of " << restaurants.rankings[n] << endl;
		}
		cout << "Total Restaurants: " << restaurants.size << endl;
	}


	else if (menuoption==5)//Tournament
	{
		totalrounds=0;
		for (double n=1;n<10;n++)//This loop check to make sure that the number of restaurants on the list is a power of 2
		{
		if (restaurants.size == pow(2.0,n))
		{
			totalrounds=n;
			cout << totalrounds;
		}
		}
		if (totalrounds==0)
		{
			cout << "The total number of restaurants must be a power of 2.\n";
			continue;
		}
		for(int n=0;n<totalrounds;n++)
		{
		restaurants.tournament(totalrounds,n);
		}

		

		cout << "\n\nTonight we will eat dinner at " << restaurants.roundVictors[0] << endl;
		system ("pause");

	}

	else if (menuoption==6)//Save to file
	{
		getline(cin,restaurantFileName);
		restaurantFileName=getName("What filename do you want to save to?:");
		restaurantFileName.append(".txt");
		ofstream writeFile;
		writeFile.open (restaurantFileName);
		while (!writeFile.is_open())
	{
		cout << "Sorry. The filename you entered, \"" << restaurantFileName << "\", is not valid.\n" << endl;
		restaurantFileName=getName("Please enter a filename to upload restaurant data:\n");
		restaurantFileName.append(".txt");
		writeFile.open (restaurantFileName);
	}
		if (userFile.is_open())
	{
		for (int n=0;n<restaurants.size;n++)
		{
			writeFile << restaurants.restaurantNames[n] << ", " << restaurants.rankings[n] << endl;
		}

	}
		writeFile.close();
	}
	
	}
	while (menuoption < 6);

	return 0;
}