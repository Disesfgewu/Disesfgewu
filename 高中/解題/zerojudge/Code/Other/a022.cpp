#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string a;
	while ( cin >> a )
	{
		int i = 0 , j = a.length();//, count = 0;
		while ( a[i] == a[j-i-1])
		{
			i++;
			if ( i == j )
				break;
		}
		if ( i == j )
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
	}
	return 0 ;
 } 
