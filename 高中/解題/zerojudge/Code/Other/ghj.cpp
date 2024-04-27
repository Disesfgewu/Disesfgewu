#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>\
//#define first f
//#define second s
using namespace std;
int main ()
{
	string s ;
	while ( getline( cin , s ) )
	{
		int count = 0 , count2 = 1 ;
		char a = s[0] , b ;
		for ( int i = 1 ; i < s.size() ; i++)
		{
			if ( a != s[i] )
			{
				count2-- ;
				if ( count2 > count )
				{
					b = a ;
					count = count2 ;
				}
				count2 = 1 ;
				a = s[i] ;
			 } 
			else
				count2++ ;
		}
		if ( count2 > count )
		{
			b = a ;
			count = count2 ;
		}
		cout << b << " " << count << endl;
	}
}
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.sync_with_stdio(false), cin.tie(nullptr);
	string input;
	int maximumContinueTimes, nowTimes;
	char maximumCharacter, nowCharacter;
	while (cin >> input) {
		maximumContinueTimes = 0, nowCharacter = input[0], nowTimes = 1;
		for (int i = 1; i != input.size(); i++)
			if (input[i] != nowCharacter) {
				if (nowTimes > maximumContinueTimes)
					maximumContinueTimes = nowTimes, maximumCharacter = nowCharacter;
				nowCharacter = input[i], nowTimes = 1;
			}
			else
				nowTimes++;
		if (nowTimes > maximumContinueTimes)
			maximumContinueTimes = nowTimes, maximumCharacter = nowCharacter;
		cout << maximumCharacter << ' ' << maximumContinueTimes << '\n';
	}
}*/
