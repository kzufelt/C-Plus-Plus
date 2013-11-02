#include <iostream>
#include <string>
#include <vector>
#include "FighterInterface.h"
#include "Cleric.h"
#include "Fighter.h"



/*string Cleric::getName()
{
	return name;
}

int Cleric::getMaximumHP()
{
	return MaximumHP;
}

int Cleric::getCurrentHP()
{
	return CurrentHP;
}

int Cleric::getStrength()
{
	return Strength;
}

int Cleric::getSpeed()
{
	return Speed;
}

int Cleric::getMagic()
{
	return Magic;
}
*/
int Cleric::getDamage()
{
	return Fighter::Magic;
}

void Cleric::takeDamage(int damage)
{
	int reducedDamage= damage-Fighter::CurrentSpeed/4;
	if (reducedDamage<=0)
	{
		reducedDamage=1;
	}
	Fighter::CurrentHP=Fighter::CurrentHP-reducedDamage;
}

void Cleric::reset()
{
	Fighter::CurrentHP=Fighter::MaximumHP;
	Fighter::CurrentMagic=5*Fighter::Magic;
}

void Cleric::regenerate()
{
	int HPHealed=Fighter::Strength/6;
	int ManaRestored=Fighter::Magic/5;

	if (HPHealed==0)//HP Restore
		HPHealed=1;
	if (Fighter::CurrentHP+HPHealed>Fighter::MaximumHP)
		Fighter::CurrentHP=Fighter::MaximumHP;
	else
		Fighter::CurrentHP=Fighter::CurrentHP+HPHealed;

	if (ManaRestored==0)//Mana Restore
		ManaRestored=1;
	if ((Fighter::CurrentMagic+ManaRestored)>(Fighter::Magic*5))
		Fighter::CurrentMagic=Fighter::Magic*5;
	else
		Fighter::CurrentMagic=Fighter::CurrentMagic+ManaRestored;
}

bool Cleric::useAbility()
{
	int HPHealed=Fighter::Magic/3;
	if (HPHealed==0)
		HPHealed=1;
	if (Fighter::CurrentMagic<CLERIC_ABILITY_COST)
	return false;
	else if (Fighter::CurrentMagic>=CLERIC_ABILITY_COST)
	{
		Fighter::CurrentMagic-=CLERIC_ABILITY_COST;
		if (Fighter::CurrentHP<Fighter::MaximumHP)
			Fighter::CurrentHP+=HPHealed;
		return true;
	}
	
	return false;
}

bool Cleric::isSimplified()
{
	return false;
}
