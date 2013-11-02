#ifndef ARCHER_H
#define ARCHER_H
#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "Fighter.h"
#include "ArenaInterface.h"
using namespace std;


class Archer:public Fighter
{
	public:
		Archer(string info):Fighter(info){};
		~Archer(){};

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