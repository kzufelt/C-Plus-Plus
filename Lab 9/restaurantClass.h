#ifndef RESTAURANTCLASS
#define RESTAURANTCLASS	

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

class restaurantClass		
{	
	public:
		vector<string> restaurantNames;
		vector<int> rankings;
		int size;
		vector<string> competitors;
		vector<string> roundVictors;

		int findrestaurant(string newName);
		void shuffle();
		void tournament(int totalRounds, int currentRound);
};
#endif