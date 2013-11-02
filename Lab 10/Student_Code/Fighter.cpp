#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include "FighterInterface.h"
#include "Fighter.h"




string Fighter::getName()
{
	return name;
}

int Fighter::getMaximumHP()
{
	return MaximumHP;
}

int Fighter::getCurrentHP()
{
	return CurrentHP;
}

int Fighter::getStrength()
{
	return Strength;
}

int Fighter::getSpeed()
{
	return CurrentSpeed;
}

int Fighter::getMagic()
{
	return Magic;
}