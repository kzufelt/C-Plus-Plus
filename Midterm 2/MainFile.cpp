#include <iostream>
#include <string>
#include <vector>
#include <new>


using namespace std;
#include "Circle.h"

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

int main()
{
	int done=0, menuchoice;
	int players, skipcount;
	Circle Josephus;

	while (done==0)
	{
	cout << "Menu\n\t1 - Get Names\n\t2 - Play Game\n\t3 - Report Safe Index\n\t4 - Quit\n";
	menuchoice=getOption(1,4);

	if (menuchoice==1)//Get Names
	{
		Josephus.getNames();
		for (int t=0;t<20;t++)
		{
		cout << Josephus.getNames()[t] << endl;
		}
	}
	
	else if (menuchoice==2)//Play Game
	{
		cout << "How many players?\n";
		players=getOption(10,20);
		cout << "How many between deaths?\n";
		skipcount=getOption(0,10000);
		if (players<10 || players>20)
		{cout << "Fail.\n";}
		else if (players>=10 && players<=20)
		{
		for (int t=0;t<players-1;t++)
		{
		cout << Josephus.playGame(players, skipcount)[t] << endl;
		}
		}
	}

	else if (menuchoice==3)//Report Safe Index
	{
		cout << "How many players?\n";
		players=getOption(10,20);
		cout << "How many between deaths?\n";
		skipcount=getOption(0,10000);
		if (Josephus.reportSafeIndex(players, skipcount) == -1)
		{cout << "Fail.\n";}
		else
		{
		cout << "Stand at position " << Josephus.reportSafeIndex(players, skipcount) << endl;
		}
	}

	else if (menuchoice==4)//Quit
	{
		done=1;
	}
	}

	return 0;
}