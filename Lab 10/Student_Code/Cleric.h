#ifndef CLERIC_H
#define CLERIC_H
#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "Fighter.h"
#include "ArenaInterface.h"
using namespace std;


class Cleric:public Fighter
{
	public:
		Cleric(string info):Fighter(info){CurrentMagic = Magic*5;
		};
		~Cleric(){};

		/*virtual string getName();
		virtual int getMaximumHP();
		virtual int getCurrentHP();
		virtual int getStrength();
		virtual int getSpeed();
		virtual int getMagic();*/
		virtual int getDamage();
		virtual void takeDamage(int damage);
		virtual void reset();
		virtual void regenerate();
		virtual bool useAbility();
		virtual bool isSimplified();
		
		
};

#endif