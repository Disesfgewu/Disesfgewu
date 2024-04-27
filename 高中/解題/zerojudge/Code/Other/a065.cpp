#include <iostream>
#include <string>
#include <cmath> 
using namespace std;
int main ()
{
	string a ;
	while ( cin >> a )
	{
		for ( int i = 0 ; i < a.length() - 1 ; i++ )
		{
			cout << abs(int (a[i]) - int (a[i+1]) );
		}
		cout << endl;
	}
}
