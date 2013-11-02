#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "ArenaInterface.h"
#include "Arena.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"



int Arena::findName(string info)
{
	int name_end=info.find(" ");//Pulls out everything before the first space (the name)
	if (name_end==string::npos)//If the string is only a name, this will search for the whole string
		name_end=info.size();
	
	string name = info.substr(0,name_end);
	for (int n=0;n<inArena.size();n++)
	{
		if(name==(*inArena[n]).getName())
			{
				return n;
			}
	}
	return -1;
}

bool Arena::correctFormat(string info)
{
	int found=info.find(" ");//Checks for the first space 
	if (found==string::npos)
	{
		cout << "There is not enough data to create a character.\n";
		return false;
	}
	else
	{
		for (int t=0;t<found-1;t++)//Makes sure there are no numbers in the name
		{
			if (!isalpha(info[t]))
			{
				//return false;
			}
		}
	}
	found=info.find(" ",found+1);// Move forward to the character type
	string charType= info.substr(found-1,1);
	
		if (found==string::npos)
		{
			cout << "There is not enough data to create a character.\n";
			return false;
		}
		else if (charType!="R" && charType!="A" && charType!="C")
		{
			cout << "Valid character types are A, C, or R.\n";
			return false;
		}

	double stats[4];//Here we will make sure that the numbers are positive
	int intstats[4];
	string numbers = info.substr(found,100);
	stringstream ss (stringstream::in | stringstream::out);
	ss << numbers;
	for (int n=0; n<4; n++)
	{
			ss >> stats[n];
			intstats[n]=stats[n];
	}

	for (int n=0;n<3;n++)//This loops through to make sure that there are 4 numeric entries separated by spaces
	{
		found=info.find(" ",found+1);
		if (found==string::npos)
		{
			cout << "There is not enough data to create a character.\n";
			return false;
		}
		else if (!isdigit(info[found-1]))
		{
			cout << "You must use numbers for your character stats.\n";
			return false;
		}
		else if (stats[n]<=0||stats[n] != intstats[n])//Return False if negative or non-integer
		{
			cout << "No negative numbers!\n";
			return false;
		}
	}
	if (stats[3]<=0||stats[3] != intstats[3])//Return False if negative
	{
		cout << "No negative numbers!\n";
		return false;
	}
	return true;
}

bool Arena::addFighter(string info)
{

	if(findName(info)!=-1)
	{
		cout << "That character name has already been used.\n";
		return false;
	}
	else if (!correctFormat(info))
	{
		cout << "That character data is incorrectly formatted.\n";
		return false;
	}
	
	else if (info.find(" R ")!=string::npos)
	{
		    inArena.push_back(new Robot(info));
			size+=1;
			return true;
	}
	else if (info.find(" A ")!=string::npos)
	{
			inArena.push_back(new Archer(info));
			size+=1;
			return true;
	}
	else if (info.find(" C ")!=string::npos)
	{
			inArena.push_back(new Cleric(info));
			size+=1;
			return true;
	}
		cout << "All loops executed and did not find anything.\n";
	return false;
	
}

bool Arena::removeFighter(string name)
{
	int name_end=name.find(" ");//Looks for a space (stats)
	if (name_end!=string::npos)
	{
		cout << "Please only enter the fighter name, without stats. Names may not include spaces.\n";
		return false;
	}
	else if(findName(name)==-1)
	{
		cout << "That character name is not in use.\n";
		return false;
	}
	inArena[findName(name)]=inArena[size-1];
	inArena.pop_back();
	size-=1;
	cout << "Removed " << name << ".\n";
	return true;
}

FighterInterface* Arena::getFighter(string name)
{
	int name_end=name.find(" ");//Looks for a space (stats)
	if (name_end!=string::npos)
	{
		cout << "Please only enter the fighter name, without stats. Names may not include spaces.\n";
		return NULL;
	}
	else if(findName(name)==-1)
	{
		cout << "That character name is not in use.\n";
		return NULL;
	}
	int found=findName(name);
	if (found!=string::npos)
	{
		return inArena[found];
		
	}
	cout << "All loops executed and did not find anything.\n";
	return NULL;
	
}

int Arena::getSize()
{
	return size;
}