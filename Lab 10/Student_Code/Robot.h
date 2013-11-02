#ifndef ROBOT_H
#define ROBOT_H
#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "Fighter.h"
#include "ArenaInterface.h"
using namespace std;


class Robot:public Fighter
{
	public:
		Robot(string info):Fighter(info){CurrentMagic = Magic*2;
		};
		~Robot(){};

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