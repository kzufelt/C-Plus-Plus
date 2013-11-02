#include "userinfoClass.h"

void userinfo::addNewUser (string new_name)
{
			firstname=new_name;
			string new_food = getName("Please enter the new user's favorite food:");
			favoritefood=new_food;
			cout << new_name << " added to VisageTome Network" << endl;
}