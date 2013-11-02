#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "This program converts a temperature from degrees Farenheit to degrees Celcius" << endl;
	double usertemp=0, celctemp=0;
	int tempcheck=0, dispcelctemp=0;
	
	cout << endl << endl << "Input a temperature:" << endl;
	cin >> usertemp;
	tempcheck = usertemp;
	cout << "You entered: " << tempcheck << endl;
	celctemp = (5.0 / 9.0) * (usertemp - 32);
	dispcelctemp = celctemp;
	cout << "Your temperature in Celcius: " << celctemp << endl << "Your temperature in Celcius (rounded to the nearest degree): " << dispcelctemp << endl;
	cin.get();
	cin.get();
	
	return 0;
}