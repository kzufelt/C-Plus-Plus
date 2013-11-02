#include "Circle.h"


Circle::Circle()
{
}

vector<string> Circle::getNames()
{
	vector<string> NamesList;
	NamesList.clear();
	NamesList.push_back("Josephus");
	NamesList.push_back("Kyle");
	NamesList.push_back("Rob");
	NamesList.push_back("Cory");
	NamesList.push_back("Moses");
	NamesList.push_back("Frank");
	NamesList.push_back("Calvin");
	NamesList.push_back("Hobbes");
	NamesList.push_back("Mary");
	NamesList.push_back("Kvothe");
	NamesList.push_back("Connor");
	NamesList.push_back("Bucky");
	NamesList.push_back("Satchel");
	NamesList.push_back("Jacob");
	NamesList.push_back("Abraham");
	NamesList.push_back("Flavius");
	NamesList.push_back("Katniss");
	NamesList.push_back("Ged");
	NamesList.push_back("Ogion");
	NamesList.push_back("Adam");
	return NamesList;
}

vector<string> Circle::playGame(int n, int m)
{
	getNames();
	int stillAlive=n;
	int modcount=0;
	vector<string> players;
	vector<string> playerskilled;

	if (n < 10 || n>20 || m<0)//Rejects invalid inputs
	{
		return players;
	}
	for (int j=0;j<n;j++)//This puts the appropriate number of players in the circle
	{
		players.push_back(getNames()[j]);
	}

	while (stillAlive > 1)
	{
		modcount= (modcount + m) % stillAlive - 1;//This decides who is next to die, counting from the last person to die
		if (modcount < 0)
		{
			modcount=stillAlive-1;
		}
		playerskilled.push_back(players[modcount]);
		players.erase(players.begin()+modcount);
		stillAlive--;
		
	}
	
	return playerskilled;
}

int Circle::reportSafeIndex(int n, int m)//Note that this returns an index, so a position counting from 0.
{
	getNames();
	int safeplace=-1;
	int spot1=-1, spot2=-1;

	if (n < 10 || n>20 || m<0)//Rejects invalid inputs
	{
		return safeplace;
	}
	for (int i=0;i<n;i++)//This finds the spot where no one died
	{

		for (int j=0;j<n-1;j++)
		{
			if (getNames()[i]==playGame(n,m)[j])
			{
				spot1=spot2;
				spot2=i;
				if (spot1+1!=spot2)//Here we see if there was a safe spot between any two people who died
				{
					safeplace=spot1+1;
					return safeplace;
				}
			}
		}
	}
	
	return n-1;//If we found no safe spots, then the safe spot must be the last position
}
