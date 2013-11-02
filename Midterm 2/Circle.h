//Kyle Zufelt

//CS 142 Winter 2012 Midterm 2

#ifndef CIRCLE	//Do not modify this line
#define CIRCLE	//Do not modify this line
//You may add "#include" statements here
#include <iostream>
#include <string>
#include <vector>

using namespace std;	//Do not modify this line

class Circle	//Do not modify this line
{	//Do not modify this line
	//You may insert visibility modifiers anywhere within this document
public:
	//You may declare member variables anywhere within this document
	//-----------------------------------------------------------------
		Circle();	//Do not modify this line
		~Circle(){}	//Do not modify this line
	//-----------------------------------------------------------------
		/*
			getNames
		
			Returns a list of names in the order in which the people will be standing for the "game".
			Although fewer people may be playing, you must return 20 names here. Do not provide 
			duplicate names.
			
			For the sake of the test driver, this method must return the list of 20 names in the 
			same order every time it is called, and this list of 20 names in this order must be used 
			to play the "game".

			This method will be called repeatedly.
		*/
		vector<string> getNames();	//Do not modify this line
		//You may not implement this method here; you must do so in a .cpp document
		
		/*
			playGame

			Plays a "game" with the first n people from the list (above) counting forward every m. An 
			explanation for how the "game" works can be found in the exam specs. 
	
			This method should return a list of names in the order in which the lot fell upon them (including 
			the survivor, who should be last).  If n is not between 10 and 20 or if m is non-positive, 
			return an empty vector.

			This method will be called repeatedly.
		*/
		vector<string> playGame(int n, int m);	//Do not modify this line
		//You may not implement this method here; you must do so in a .cpp document

		/*
			reportSafeIndex

			Returns the "safe index", the last index/location in the circle that will be chosen when 
			the "game" is played. The point of this method is to permit someone to cheat the system 
			by finding the safe location ahead of time.
		
			If n is not between 10 and 20 or if m is non-positive, return -1.

			This method may be called repeatedly.
		*/
		int reportSafeIndex(int n, int m);	//Do not modify this line
		//You may not implement this method here; you must do so in a .cpp document
	//-----------------------------------------------------------------
};		//Do not modify this line
#endif	//Do not modify this line
