//This program guesses a number that the user has selected
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

 
 
int main() {
  int number, setgenerator, array1[16], array2[16], array3[16], array4[16], array5[16], carray1[16], carray2[16], carray3[16], carray4[16], carray5[16];
  int guessarray[16], guessarray2[16], guessarray3[16], guessarray4[16], guessarray5[16];
  int counter=0, counter2=0, counter3=0, counter4=0;
  string endvar="yes", inarray1, inarray2, inarray3, inarray4, inarray5, incarray1, incarray2, incarray3, incarray4, incarray5;
	

	while (endvar == "yes")
	{
	cout << "Pick a number between 0 and 31, but do not reveal it!" << endl;
	inarray1 = "no";
	inarray2 = "no";
	inarray3 = "no";
	inarray4 = "no";
	inarray5 = "no";
	incarray1 = "no";
	incarray2 = "no";
	incarray3 = "no";
	incarray4 = "no";
	incarray5 = "no";
	
 setgenerator = rand() % 2 + 1;
  
	 counter=0;
	for(int n=1; n<=31; n=n+2) //This is the 2^0 set
	{
	if (setgenerator == 1)
	{
		cout << n << "\t";
	}
	array1[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 1)
	{
		cout << endl;
	}
	}
	cout << endl;//End 2^0 set

	if (setgenerator == 1)
	{
	cout << "Is your number in this set? yes or no" << endl;
	getline (cin,inarray1);
	if (inarray1 == "no")
		incarray1 = "yes";
	}
 
	

 
 
	 counter=0;
	for(int n=0; n<=31; n=n+2) //This is the 2^0 complementary set
	{
		if (setgenerator == 2)
		{
	cout << n << "\t";
		}
	carray1[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 2)
	{
		cout << endl;
	}
	}
	cout << endl;//End 2^0 complementary set
	if (setgenerator == 2)
		{
	cout << "Is your number in this set? yes or no" << endl;
	getline (cin,incarray1);
	if (incarray1 == "no")
		inarray1 = "yes";
	}
 

 setgenerator = rand() % 2 + 1;

	 counter=0;
	for(int n=2; n<=31; n++) //This is the 2^1 set
	{
		if (setgenerator == 1)
{
	cout << n << "\t";
		}
	array2[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 1)
	{
		cout << endl;
	}
	if ((n+1) % 4 == 0)
	{
		n=n+2;
	}
	}
		cout << endl;//End 2^1 set
		if (setgenerator == 1)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,inarray2);
	if (inarray2 == "no")
		incarray2 = "yes";
		}

 
	 counter=0;
	for(int n=0; n<=31; n++) //This is the 2^1 complementary set
	{
		if (setgenerator == 2)
{
	cout << n << "\t";
		}
	carray2[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 2)
	{
		cout << endl;
	}
	if ((n+1) % 2 == 0)
	{
		n=n+2;
	}
	}
		cout << endl;//End 2^1 complementary set
		if (setgenerator == 2)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,incarray2);
	if (incarray2 == "no")
		inarray2 = "yes";
		}


setgenerator = rand() % 2 + 1;

	 counter=0;
	for(int n=4; n<=31; n++) //This is the 2^2 set
	{
		if (setgenerator == 1)
{
	cout << n << "\t";
		}
	array3[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 1)
	{
		cout << endl;
	}
	if ((n+1) % 8 == 0)
	{
		n=n+4;
	}
	}
		cout << endl;//End 2^2 set
		if (setgenerator == 1)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,inarray3);
	if (inarray3 == "no")
		incarray3 = "yes";
		}



	 counter=0;
	for(int n=0; n<=31; n++) //This is the 2^2 complementary set
	{
		if (setgenerator == 2)
{
	cout << n << "\t";
		}
	carray3[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 2)
	{
		cout << endl;
	}
	if ((n+1) % 4 == 0)
	{
		n=n+4;
	}
	}
		cout << endl;//End 2^2 complementary set
		if (setgenerator == 2)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,incarray3);
	if (incarray3 == "no")
		inarray3 = "yes";
		}


setgenerator = rand() % 2 + 1;

	 counter=0;
	for(int n=8; n<=31; n++) //This is the 2^3 set
	{
		if (setgenerator == 1)
{
	cout << n << "\t";
		}
	array4[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 1)
	{
		cout << endl;
	}
	if ((n+1) % 16 == 0)
	{
		n=n+8;
	}
	}
		cout << endl;//End 2^3 set
		if (setgenerator == 1)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,inarray4);
	if (inarray4 == "no")
		incarray4 = "yes";
		}



	 counter=0;
		for(int n=0; n<=31; n++) //This is the 2^3 complementary set
	{
		if (setgenerator == 2)
{
	cout << n << "\t";
		}
	carray4[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 2)
	{
		cout << endl;
	}
	if ((n+1) % 8 == 0)
	{
		n=n+8;
	}
	}
		cout << endl;//End 2^3 complementary set
		if (setgenerator == 2)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,incarray4);
	if (incarray4 == "no")
		inarray4 = "yes";
		}


setgenerator = rand() % 2 + 1;

	 counter=0;
	for(int n=16; n<=31; n++) //This is the 2^4 set
	{
		if (setgenerator == 1)
{
	cout << n << "\t";
		}
	array5[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 1)
	{
		cout << endl;
	}
	}
		cout << endl;//End 2^4 set
		if (setgenerator == 1)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,inarray5);
	if (inarray5 == "no")
		incarray5 = "yes";
		}


	 counter=0;
		for(int n=0; n<=15; n++) //This is the 2^4 complementary set
	{
		if (setgenerator == 2)
{
	cout << n << "\t";
		}
	carray5[counter]=n;
	counter = counter + 1;
	if (counter % 4 == 0 && setgenerator == 2)
	{
		cout << endl;
	}
	}
		cout << endl;//End 2^4 complementary set
		if (setgenerator == 2)
{
		cout << "Is your number in this set? yes or no" << endl;
	getline (cin,incarray5);
	if (incarray5 == "no")
		inarray5 = "yes";
		}

    


//Now we will determine what the number is
if (inarray1 == "yes")
{
	for (int n=0; n<=15; n++)
	{
	guessarray[n]=array1[n];
	}
}

else if (incarray1 == "yes")
{
	for (int n=0; n<=15; n++)
	{
	guessarray[n]=carray1[n];
	}
}

//First round of eliminations
if (inarray2 == "yes")
{ counter=0;
	for (int n=0; n<=15; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray[n] == array2[g])
			{
				guessarray2[counter]=guessarray[n];
				counter=counter+1;
			}
		}
	}
}

else if (incarray2 == "yes")
{
	counter=0;
	for (int n=0; n<=15; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray[n] == carray2[g])
			{
				guessarray2[counter]=guessarray[n];
				counter=counter+1;
			}
		}
	}
}

//Second round of eliminations
if (inarray3 == "yes")
{ counter2=0;
	for (int n=0; n<counter; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray2[n] == array3[g])
			{
				guessarray3[counter2]=guessarray2[n];
				counter2=counter2+1;
			}
		}
	}
}

else if (incarray3 == "yes")
{counter2=0;
	for (int n=0; n<counter; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray2[n] == carray3[g])
			{
				guessarray3[counter2]=guessarray2[n];
				counter2=counter2+1;
			}
		}
	}
}

//Third round of eliminations
if (inarray4 == "yes")
{ counter3=0;
	for (int n=0; n<counter2; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray3[n] == array4[g])
			{
				guessarray4[counter3]=guessarray3[n];
				counter3=counter3+1;
			}
		}
	}
}

else if (incarray4 == "yes")
{counter3=0;
	for (int n=0; n<counter2; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray3[n] == carray4[g])
			{
				guessarray4[counter3]=guessarray3[n];
				counter3=counter3+1;
			}
		}
	}
}

//Final round of eliminations
if (inarray5 == "yes")
{ counter4=0;
	for (int n=0; n<counter3; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray4[n] == array5[g])
			{
				guessarray5[counter4]=guessarray4[n];
				counter4=counter4+1;
			}
		}
	}
}

else if (incarray5 == "yes")
{counter4=0;
	for (int n=0; n<counter3; n++)
	{
		for (int g=0; g<=15; g++)
		{
			if (guessarray4[n] == carray5[g])
			{
				guessarray5[counter4]=guessarray4[n];
				counter4=counter4+1;
			}
		}
	}
}


if (counter4 > 1)
{
	cout << "There has been a mistake." << endl;
}

else if (counter4 == 1)
{
	cout << "Your number was " << guessarray5[0] << endl;
}




//The user will now select if they wish to play again
	cout << "Play again? yes or no" << endl;
	getline (cin,endvar);


	}
}
 
