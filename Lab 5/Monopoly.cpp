#include <iostream>
#include <time.h>
#include <string>
using namespace std;



int diceroll(int a)
{
	int rollvalue;
	srand ( time(NULL) );
	rollvalue = rand() % a + rand() % a + 2;
	return rollvalue;

}


int addition(int a, int b)
{
	int newtotal;
	newtotal = a + b;
	return newtotal;
}


int subtraction(int a, int b)
{
	int newtotal;
	if (a >= b)
	{
		newtotal = a - b;
		return newtotal;
	}
	else if (a < b)
	{
		return -1;
	}
}

int passgo(int a)
{
	int newtotal;
	newtotal = a + 200;
	return newtotal;
}

int purchaseproperty(int a, int b, string c, string d)
{
	size_t found;
	int newtotal;
	found=d.find(c);
	if (found!=string::npos)
	{
		return -2;
	}
	else if (found==string::npos && a >= b)
	{
		newtotal = a - b;
		return newtotal;
	}
	else if (found==string::npos && a < b)
	{
		return -1;
	}

}

int sellproperty(int a, int b, string c, string d)
{
	size_t found;
	int newtotal;
	found=d.find(c);
	if (found==string::npos)
	{
		return -2;
	}
	else if (found!=string::npos)
	{
		newtotal = a + b;
		return newtotal;
	}

}

int eraseproperty(string c, string d)
{
	size_t found;
	found=d.find(c);
	return found;
}


int main()
{
	int menuchoice=0, totalcash=1500, addmoney, spendmoney;// Variables
	int diesides = 6;// Constants
	string newpropertyname, ownedproperties;

	cout << "Let's Play Monopoly!" << endl;

	while (menuchoice != 9)
	{
		cout << "\nMenu\n\t1 - Roll the Dice\n\t2 - View current money\n\t3 - Add money\n\t4 - Spend money\n\t5 - Pass GO\n\t6 - Buy property\n\t7 - Sell property\n\t8 - Display owned properties\n\t9 - Quit the program\n\nChoose an option:";
		cin >> menuchoice;
		
		if (menuchoice == 1)
		{
			cout << "\nYou rolled a " << diceroll(diesides) << ".\n";
		}

		if (menuchoice == 2)
		{
			cout << "\nYou have a total of $" << totalcash << ".\n";
		}

		if (menuchoice == 3)
		{
			cout << "\nHow much money do you wish to add?: $";
			cin >> addmoney;
			totalcash = addition(totalcash,addmoney);
			cout << "Your new total is $" << totalcash << ".\n";
		}

		if (menuchoice == 4)
		{
			cout << "\nHow much money do you wish to spend?: $";
			cin >> spendmoney;
			if (subtraction(totalcash,spendmoney) >= 0)
			{
				totalcash = subtraction(totalcash,spendmoney);
				cout << "Your new total is $" << totalcash << ".\n";
			}
			else if (subtraction(totalcash,spendmoney) == -1)
			{
				cout << "You do not have that much money to spend.\nYou have a total of $" << totalcash << ".\n";
			}
		}

		if (menuchoice == 5)
		{
			totalcash = passgo(totalcash);
			cout << "\nYour new total is $" << totalcash << ".\n";
		}
		
		if (menuchoice == 6)
		{
			cout << "\nWhich property would you like to purchase?:";
			getline (cin,newpropertyname);
			getline (cin,newpropertyname);
			if (purchaseproperty(totalcash, 0, newpropertyname, ownedproperties) == -2)
			{
				cout << "You already own " << newpropertyname << ".\n";
				continue;
			}
			cout << "How much does " << newpropertyname << " cost?: $";
			cin >> spendmoney;
			if (purchaseproperty(totalcash, spendmoney, newpropertyname, ownedproperties) >= 0)
			{
				totalcash = purchaseproperty(totalcash, spendmoney, newpropertyname, ownedproperties);
				ownedproperties.append(newpropertyname);
				ownedproperties.append("\n");
				cout << "You have purchased " << newpropertyname << " for $" << spendmoney << ".\nYour new total is $" << totalcash << ".\n";
			}
			else if (purchaseproperty(totalcash, spendmoney, newpropertyname, ownedproperties) == -1)
			{
				cout << "You do not enough money to purchase " << newpropertyname << ".\nYou have a total of $" << totalcash << ".\n";
			}

		}

		if (menuchoice == 7)
		{
			cout << "\nWhich property would you like to sell?:";
			getline (cin,newpropertyname);
			getline (cin,newpropertyname);
			if (sellproperty(totalcash, 0, newpropertyname, ownedproperties) == -2)
			{
				cout << "You do not own " << newpropertyname << ".\n";
				continue;
			}
			cout << "How much will you sell " << newpropertyname << " for?: $";
			cin >> addmoney;
			totalcash = sellproperty(totalcash, addmoney, newpropertyname, ownedproperties);
			ownedproperties.erase(eraseproperty(newpropertyname, ownedproperties),newpropertyname.length()+1);
			cout << "You have sold " << newpropertyname << " for $" << addmoney << ".\nYour new total is $" << totalcash << ".\n";

		}

		if (menuchoice == 8)
		{
			if (ownedproperties.length()==0)
			{
				cout << "You do not currently own any properties\n";
				continue;
			}
			cout << "You own the following properties:\n" << ownedproperties << endl;
		}
		
		if (menuchoice != 9)
		system("pause");
	}

	return 0;
}