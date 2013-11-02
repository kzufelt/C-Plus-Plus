#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "Battle.h"
#include "ArenaInterface.h"
#include "Arena.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

using namespace std;

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
	Arena fightClub;
	int menuOption=0;
	string info;
	
	while(menuOption!=9)
	{
		cout << "Menu\n\t1 - Add Fighter\n\t2 - Remove Fighter\n\t3 - Get Fighter\n\t4 - Get Size\n\t5 - Mess with character\n\t9 - End Program\n";
		menuOption=getOption(1,9);

		if (menuOption==1)//Add Fighter
		{
			info=getName("Enter fighter name, type, hit points, strength, speed, and magic, separated by spaces.\n");
			fightClub.addFighter(info);
		}

		else if (menuOption==2)//Remove Fighter
		{
			info=getName("Enter a fighter name to remove.\n");
			fightClub.removeFighter(info);
		}

		else if (menuOption==3)//Get Fighter
		{
			info=getName("Enter a fighter to display.\n");
			cout << fightClub.getFighter(info) << endl;
		}

		else if (menuOption==4)//Get Size
		{
			cout << "There are currently " << fightClub.getSize() << " fighter(s) in the arena.\n";
		}

		else if (menuOption==5)//Character
		{
			info=getName("Enter a fighter to display.\n");
			cout << fightClub.inArena[0] << (*fightClub.inArena[0]).getName() << endl;
			cout << (*fightClub.getFighter(info)).getName() << endl;
			cout << (*fightClub.getFighter(info)).getMaximumHP() << endl;
			cout << (*fightClub.getFighter(info)).getStrength() << endl;
			cout << (*fightClub.getFighter(info)).getSpeed() << endl;
			cout << (*fightClub.getFighter(info)).getMagic() << endl;
			(*fightClub.getFighter(info)).useAbility();
		}
	}
	return 0;
}