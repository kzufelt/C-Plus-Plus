#ifndef FIGHTER_H
#define FIGHTER_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "FighterInterface.h"
#include "ArenaInterface.h"
using namespace std;


class Fighter:public FighterInterface
{
	public:
		Fighter(){};
		Fighter(string info)
		{
			int name_end=info.find(" ");
			int type_end=info.find(" ",name_end+1);
			int stats[4];
			string numbers = info.substr(type_end,100);
			stringstream ss (stringstream::in | stringstream::out);

			ss << numbers;
			for (int n=0; n<4; n++)
			{
						ss >> stats[n];
			}

			name=info.substr(0,name_end);
			MaximumHP = stats[0];
			Strength = stats[1];
			Speed = stats[2];
			Magic = stats[3];
			CurrentHP = MaximumHP;
			CurrentStrength = Strength;
			CurrentSpeed = Speed;
			BonusDamage=0;
			
		};
		~Fighter(){};

		string getName();
		int getMaximumHP();
		int getCurrentHP();
		int getStrength();
		int getSpeed();
		int getMagic();
		virtual int getDamage()=0;
		virtual void takeDamage(int damage)=0;
		virtual void reset()=0;
		virtual void regenerate()=0;
		virtual bool useAbility()=0;
		virtual bool isSimplified()=0;
		
		string name;
		int MaximumHP;
		int Strength;
		int Speed;
		int Magic;
		int CurrentHP;
		int CurrentStrength;
		int CurrentSpeed;
		int CurrentMagic;
		int BonusDamage;
};

#endif