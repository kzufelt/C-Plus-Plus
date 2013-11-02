#include "restaurantClass.h"


int restaurantClass::findrestaurant(string newName)//Returns the slot where the newName is located in restaurantNames, returns -1 otherwise
{
	int r=-1;// This value shows that the restaurant is not in the array
	for (int n=0;n<size;n++)
	{
		if (newName == restaurantNames[n])
		{
			r=n;
		}
	}
	return r;
}

void restaurantClass::shuffle()
{
	int c,d;
		srand ( time(NULL) );
		for (int n=0;n<100;n++)
		{
			c=rand() % size/2 + size/2;
			d=rand() % size/2;
			swap(restaurantNames[c],restaurantNames[d]);
			swap(rankings[c],rankings[d]);
		}
}

void restaurantClass::tournament(int totalRounds, int currentRound)
{
	string newrestaurantname;
	
	if (currentRound==0)//Load the current round of competitors
	{
		competitors=restaurantNames;
	}
	else
	{
		competitors=roundVictors;
	}
	roundVictors.clear();

	
	for (int n=0; n<competitors.size()/2; n++)// Divide the competitors list in half and for each pair do the following
	{
		do
		{
			cout << "\nMatch " << n+1 << "/" << competitors.size()/2 << ", Round " << currentRound+1 << "/" << totalRounds << endl;
			cout << "\nWhich restaurant would you prefer?\n" << competitors[n] << " (" << rankings[findrestaurant(competitors[n])] << " points)" << " or " << competitors[n+competitors.size()/2] << " (" << rankings[findrestaurant(competitors[n+competitors.size()/2])] << " points)" << endl;
			getline (cin,newrestaurantname);
			if (n==0 && currentRound==0)
			{
				getline (cin,newrestaurantname);
			}
		}
		while (newrestaurantname!=competitors[n] && newrestaurantname!=competitors[n+competitors.size()/2]);
		roundVictors.push_back(newrestaurantname);//Pass the victor to the next round
		rankings[findrestaurant(newrestaurantname)]++;//Increment the score for the victor
	}
}