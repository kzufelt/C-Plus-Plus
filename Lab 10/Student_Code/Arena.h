#ifndef ARENA_H
#define ARENA_H
#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "ArenaInterface.h"
using namespace std;


class Arena:public ArenaInterface
{
	public:
		Arena(){size=0;};

		int findName(string info);//Returns the index where the info is found, returns -1 if not found

		bool correctFormat(string info);

		virtual bool addFighter(string info);

		virtual bool removeFighter(string name);

		virtual FighterInterface* getFighter(string name);

		virtual int getSize();

		vector<FighterInterface*> inArena;
		int size;
		string fighterName;

};

#endif