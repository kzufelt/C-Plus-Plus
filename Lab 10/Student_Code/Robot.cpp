#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "FighterInterface.h"
#include "Robot.h"
#include "Fighter.h"




/*string Robot::getName()
{
	return name;
}

int Robot::getMaximumHP()
{
	return MaximumHP;
}

int Robot::getCurrentHP()
{
	return CurrentHP;
}

int Robot::getStrength()
{
	return Strength;
}

int Robot::getSpeed()
{
	return Speed;
}

int Robot::getMagic()
{
	return Magic;
}
*/

int Robot::getDamage()
{
	int totalDamage=Fighter::CurrentStrength+Fighter::BonusDamage;
	return totalDamage;
}

void Robot::takeDamage(int damage)
{	
	int reducedDamage= damage-Fighter::CurrentSpeed/4;
	if (reducedDamage<=0)
	{
		reducedDamage=1;
	}
	Fighter::CurrentHP=Fighter::CurrentHP-reducedDamage;
}

void Robot::reset()
{
	Fighter::CurrentHP=Fighter::MaximumHP;
	Fighter::CurrentMagic=Fighter::Magic*2;
	Fighter::BonusDamage=0;
}

void Robot::regenerate()
{
	int HPHealed=Fighter::Strength/6;
	if (HPHealed==0)
		HPHealed=1;
	if (Fighter::CurrentHP+HPHealed>Fighter::MaximumHP)
		Fighter::CurrentHP=Fighter::MaximumHP;
	else
		Fighter::CurrentHP=Fighter::CurrentHP+HPHealed;
}

bool Robot::useAbility()
{
	Fighter::BonusDamage=0;
	double newbonus=(1.0*Fighter::CurrentStrength * pow ((Fighter::CurrentMagic/(Fighter::Magic*2.0)),4));
	if (Fighter::CurrentMagic<ROBOT_ABILITY_COST)
	return false;
	else if (Fighter::CurrentMagic>=ROBOT_ABILITY_COST)
	{
		int bonus=newbonus;
		Fighter::CurrentMagic=Fighter::CurrentMagic-ROBOT_ABILITY_COST;
		Fighter::BonusDamage=bonus;
		//cout << BonusDamage << endl;
		return true;
	}
	return false;
}

bool Robot::isSimplified()
{
	return false;
}
