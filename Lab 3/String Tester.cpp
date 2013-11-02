#include <iostream>
#include <string>
using namespace std;

int main()
{
	int comparing1=0;
	string string1="Bob", string2="Kyle";
	cout << string1 << string2 << endl;
	comparing1 = string1.compare(string2);
	cout << comparing1;
	system("pause");
	return 0;
}