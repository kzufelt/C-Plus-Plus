#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "This program will convert a time in seconds into" << endl << "a time in hours, minutes and seconds" << endl;
	double usertime, usertimesq, hourcount=0, minutecount=0, secondcount=0, hourcountsq=0, minutecountsq=0, secondcountsq=0;
	cout << endl << "Enter a time in seconds: " << endl;
	cin >> usertime;
	usertime = fabs(usertime);
	usertimesq = sqrt(usertime);
	while (usertime >= 3600)
	{
		usertime = usertime - 3600;
		hourcount = hourcount + 1;
	}
	while (usertime >= 60)
	{
		usertime = usertime - 60;
		minutecount = minutecount + 1;
	}
	secondcount = usertime;
	cout << "Your time is equivalent to : " << endl << hourcount << " hour(s), " << minutecount << " minutes, and " << secondcount << " seconds.";

	while (usertimesq >= 3600)
	{
		usertimesq = usertimesq - 3600;
		hourcountsq = hourcountsq + 1;
	}
	while (usertimesq >= 60)
	{
		usertimesq = usertimesq - 60;
		minutecountsq = minutecountsq + 1;
	}
	secondcountsq = usertimesq;
	cout << endl << endl << "The square root of your time is equivalent to : " << endl << hourcountsq << " hour(s), " << minutecountsq << " minutes, and " << secondcountsq << " seconds.";

	cin.get();
	cin.get();
	return 0;
}