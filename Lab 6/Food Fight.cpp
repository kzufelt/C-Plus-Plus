#include <iostream>
#include <array>
#include <string>
#include <time.h>
using namespace std;


int findrestaurant(string a, string b[], int c)
{
	int r=-1;// This value shows that the restaurant is not in the array
	for (int n=0;n<c;n++)
	{
		if (a == b[n])
		{
			r=n;
		}
	}
	return r;
}
void shuffle(string a[], int b)
{
	int c,d;
		srand ( time(NULL) );
		for (int n=0;n<10;n++)
		{
			c=rand() % b/2 + b/2;
			d=rand() % b/2;
			swap(a[c],a[d]);
		}
}
int main()
{
	string restaurantnames[16]={"Five Guys","In N' Out","India Palace","Brick Oven","El Gallo Giro","Thai Mango","Happy Sumo","Gloria's Little Italy"};
	string newrestaurantname, round1[8], round2[4], round3[2], winner;
	int menuoption=0, totalrestaurants=8, inlist, nextround=0, roundnumber, totalrounds;



	cout << "Food Fight\n";

	do
	{
	cout << "\n\n\nMenu\n\n\t1 - Display all restaurants\n\t2 - Add a restaurant\n\t3 - Remove a restaurant\n\t4 - Shuffle the array\n\t5 - Begin the tournament\n\t6 - Quit\n";
	cin >> menuoption;
	cout << "\n\n";
	if (menuoption==1)//Display
	{
		for (int n=0;n<totalrestaurants-1;n++)
		{
			cout << restaurantnames[n] << ", ";
		}
		cout << restaurantnames[totalrestaurants-1] << endl;
		cout << "Total Restaurants: " << totalrestaurants << endl;
	}


	else if (menuoption==2)//Add
	{
			cout << "\nWhich restaurant would you like to add?:";
			getline (cin,newrestaurantname);
			getline (cin,newrestaurantname);
			if (findrestaurant(newrestaurantname, restaurantnames, totalrestaurants)!=-1)
			{
				cout << "That restaurant is already in the list";
				continue;
			}
			else if (findrestaurant(newrestaurantname, restaurantnames, totalrestaurants)==-1)
			{
				restaurantnames[totalrestaurants]=newrestaurantname;
				totalrestaurants += 1;
			}
	}
	else if (menuoption==3)//Remove
	{
		cout << "\nWhich restaurant would you like to remove?:";
			getline (cin,newrestaurantname);
			getline (cin,newrestaurantname);
			inlist=findrestaurant(newrestaurantname, restaurantnames, totalrestaurants);
			if (inlist==-1)
			{
				cout << "That restaurant is not on the list";
				continue;
			}
			else if (inlist!=-1)
			{
				for (int n=inlist;n<totalrestaurants; n++)
				{
					restaurantnames[n]=restaurantnames[n+1];
				}
				restaurantnames[totalrestaurants]="";
				totalrestaurants -= 1;
			}
	}


	else if (menuoption==4)//Shuffle
	{
		shuffle(restaurantnames,totalrestaurants);
		for (int n=0;n<totalrestaurants-1;n++)
		{
			cout << restaurantnames[n] << ", ";
		}
		cout << restaurantnames[totalrestaurants-1] << endl;
		cout << "Total Restaurants: " << totalrestaurants << endl;
	}


	else if (menuoption==5)//Tournament
	{
		totalrounds=0;
		for (double n=1;n<5;n++)
		{
		if (totalrestaurants == pow(2.0,n))
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


		nextround=0;
		for (int n=0; n<totalrestaurants/2; n++)//Round1
		{
			roundnumber=1;
		do
		{
			cout << "\nMatch " << n+1 << "/" << totalrestaurants/2 << ", Round " << roundnumber << "/" << totalrounds << endl;
			cout << "\nWhich restaurant would you prefer?\n" << restaurantnames[n] << " or " << restaurantnames[n+totalrestaurants/2] << endl;
			getline (cin,newrestaurantname);
			if (n==0)
			{
				getline (cin,newrestaurantname);
			}
			round1[n]=newrestaurantname;
			nextround+=1;
		}
		while (newrestaurantname!=restaurantnames[n] && newrestaurantname!=restaurantnames[n+totalrestaurants/2]);
		}

		
		if (nextround == 1)
		{
			cout << "\n\nTonight we will eat dinner at " << round1[0] << endl;
			system ("pause");
			continue;
		}


		
		nextround=0;
		for (int n=0; n<totalrestaurants/4; n++)//Round 2
		{
			roundnumber=2;
		do
		{
			cout << "\nMatch " << n+1 << "/" << totalrestaurants/4 << ", Round " << roundnumber << "/" << totalrounds << endl;
			cout << "\nWhich restaurant would you prefer?\n" << round1[n] << " or " << round1[n+totalrestaurants/4] << endl;
			getline (cin,newrestaurantname);
			round2[n]=newrestaurantname;
			nextround+=1;
		}
		while (newrestaurantname!=round1[n] && newrestaurantname!=round1[n+totalrestaurants/4]);
		}
		
		if (nextround == 1)
		{
			cout << "\n\nTonight we will eat dinner at " << round2[0] << endl;
			system ("pause");
			continue;
		}


		
		nextround=0;
		for (int n=0; n<totalrestaurants/8; n++)//Round 3
		{
			roundnumber=3;
		do
		{
			cout << "\nMatch " << n+1 << "/" << totalrestaurants/8 << ", Round " << roundnumber << "/" << totalrounds << endl;
			cout << "\nWhich restaurant would you prefer?\n" << round2[n] << " or " << round2[n+totalrestaurants/8] << endl;
			getline (cin,newrestaurantname);
			round3[n]=newrestaurantname;
			nextround+=1;
		}
		while (newrestaurantname!=round2[n] && newrestaurantname!=round2[n+totalrestaurants/8]);
		}
		if (nextround == 1)
		{
			cout << "\n\nTonight we will eat dinner at " << round3[0] << endl;
			system ("pause");
			continue;
		}


		
		nextround=0;
		for (int n=0; n<totalrestaurants/16; n++)//Round 4
		{
			roundnumber=4;
		do
		{
			cout << "\nMatch " << n+1 << "/" << totalrestaurants/16 << ", Round " << roundnumber << "/" << totalrounds << endl;
			cout << "\nWhich restaurant would you prefer?\n" << round3[n] << " or " << round3[n+totalrestaurants/16] << endl;
			getline (cin,newrestaurantname);
			winner=newrestaurantname;
			nextround+=1;
		}
		while (newrestaurantname!=round3[n] && newrestaurantname!=round3[n+totalrestaurants/16]);
		}

		cout << "\n\nTonight we will eat dinner at " << winner << endl;
		system ("pause");

	}
	
	}
	while (menuoption != 6);

	return 0;
}