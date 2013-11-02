#include <iostream>
#include <string>
#include <vector>
#include "ArenaInterface.h"
#include "Arena.h"



int Arena::findName(string info)
{
	int name_end=info.find(" ");//Pulls out everything before the first space (the name)
	if (name_end==string::npos)//If the string is only a name, this will search for the whole string
		name_end=info.size();
	size_t found;
	for (int n=0;n<inArena.size();n++)
	{
		found=inArena[n].find(info.substr(0,name_end));
		if(found!=string::npos)
			{
				fighterName=info.substr(0,name_end);
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
		return false;
	}
	else
	{
		for (int t=0;t<found-1;t++)
		{
			if (!isalpha(info[t]))
			{
				return false;
			}
		}
	}
	found=info.find(" ",found+1);
		if (found==string::npos)
		{
			return false;
		}
		else if (!isalpha(info[found-1]))
		{
			return false;
		}
	for (int n=0;n<3;n++)//This loops through to make sure that there are 4 numeric entries separated by spaces
	{
		found=info.find(" ",found+1);
		if (found==string::npos||!isdigit(info[found-1]))
		{
			return false;
		}
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
	inArena.push_back(info);
	size+=1;
	return true;
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
	size_t stringLength=inArena[findName(name)].size();
	inArena[findName(name)].erase (inArena[findName(name)].begin(),inArena[findName(name)].begin()+stringLength);
	size-=1;
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
		if (inArena[findName(name)].find(" R ")!=string::npos)
		{
			Robot* R = new Robot;
			R*.info=inArena[findName(name)];
			return R;
		}
		else if (inArena[findName(name)].find(" A ")!=string::npos)
		{
			Archer* R = new Archer;
			R*.info=inArena[findName(name)];
			return R;
		}
		else if (inArena[findName(name)].find(" C ")!=string::npos)
		{
			Cleric* R = new Cleric;
			R*.info=inArena[findName(name)];
			return R;
		}
		
	}
	
}

int Arena::getSize()
{
	return size;
}