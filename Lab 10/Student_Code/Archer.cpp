#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "Archer.h"
#include "Fighter.h"




/*string Archer::getName()
{
	return name;
}

int Archer::getMaximumHP()
{
	return MaximumHP;
}

int Archer::getCurrentHP()
{
	return CurrentHP;
}

int Archer::getStrength()
{
	return Strength;
}

int Archer::getSpeed()
{
	return Speed;
}

int Archer::getMagic()
{
	return Magic;
}
*/
int Archer::getDamage()
{
	return Fighter::CurrentSpeed;
}

void Archer::takeDamage(int damage)
{
	int reducedDamage= damage-Fighter::CurrentSpeed/4;
	if (reducedDamage<=0)
	{
		reducedDamage=1;
	}
	Fighter::CurrentHP=Fighter::CurrentHP-reducedDamage;
}

void Archer::reset()
{
	Fighter::CurrentHP=Fighter::MaximumHP;
	Fighter::CurrentSpeed=Fighter::Speed;
}

void Archer::regenerate()
{
	int HPHealed=Fighter::Strength/6;
	if (HPHealed==0)
		HPHealed=1;
	if (Fighter::CurrentHP+HPHealed>Fighter::MaximumHP)
		Fighter::CurrentHP=Fighter::MaximumHP;
	else
		Fighter::CurrentHP=Fighter::CurrentHP+HPHealed;

}

bool Archer::useAbility()
{
	Fighter::CurrentSpeed+=1;
	return true;
}

bool Archer::isSimplified()
{
	return false;
}
